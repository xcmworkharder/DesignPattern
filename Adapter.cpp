#include <iostream>

using namespace std;

class Target {
public:
    virtual void newTask() = 0;
};

class OldFuncClass1 {
public:
    void func1() {
	cout << "func1" << endl;
    }
};

class OldFuncClass2 {
public:
    void func2() {
	cout << "func2" << endl;
    }
};

// 可以根据原始已经存在的类，做出不同的新接口
class Adapter : public Target {
public:
    void newTask() override {
	cout << "new Task" << endl;
	class1->func1();
	class2->func2();
    }
    
private:
    OldFuncClass1* class1;
    OldFuncClass2* class2;
};

int main() {
    
    Target* target1 = new Adapter();
    target1->newTask();
    
    return 0;
}