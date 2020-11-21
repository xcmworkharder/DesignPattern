#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

using namespace std;

// 使用双检查锁依然会面临1分配内存->2构造->3赋值3个步骤的reorder问题, java c#提高了volatile关键字
// c++11之后利用atomic关键字来解决这个问题，能够屏蔽编译器的优化
class SingleTon {
public:
    static SingleTon* getInstance() {
	// 如果直接在这里加锁，则影响读并发效率
	if (m_singleTon == nullptr) { // 锁前检查能够提高效率
	    m_mutex.lock();
	    if (m_singleTon == nullptr) { // 如果锁后不检查，则如果两个线程都进入第一个检查，还是会创建两个线程，不正确
		cout << "创建新的实例" << endl;
		m_singleTon = new SingleTon();
	    }
	    m_mutex.unlock();
	}
	return m_singleTon;
    }
    
private:
    SingleTon(){}
    static SingleTon* m_singleTon;
    static std::mutex m_mutex;
};

SingleTon* SingleTon::m_singleTon = nullptr;
std::mutex SingleTon::m_mutex;

void threadFunc(int num) {
    SingleTon* s = SingleTon::getInstance();
    int nThreadNum = num;
    usleep(100000);
    cout << "线程编号为: " << num << endl;
}
    

int main() {
    
//     SingleTon* singleTon1 = SingleTon::getInstance();
//     cout << singleTon1 << endl;
//     SingleTon* singleTon2 = SingleTon::getInstance();
//     cout << singleTon2 << endl;
    thread testThread[5];
    int threadNum = 0;
    while (threadNum < 5) {
	testThread[threadNum] = thread(threadFunc, threadNum);
	threadNum++;
    }
    
    for (int i = 0; i < 5; ++i) {
	testThread[i].join();
    }
    
    return 0;
}