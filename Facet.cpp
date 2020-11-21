#include <iostream>

using namespace std;

// 为多个子系统的接口提供一个统一的入口，外观模式就是这个高层接口，使得使用子系统更方便
// 比如电脑的开机面板就是个门面，用户只需要开机就可以控制内存子系统自检 cpu运行 硬盘读写 操作系统导入
class Memory {
public:
    void selfCheck() {
	cout << "-----内存自检--------" << endl;
    }
};

class Cpu {
public:
    void run() {
	cout << "------Cpu运行--------" << endl;
    }
};

class HardDisk {
public:
    void read() {
	cout << "------HardDisk读写-----" << endl;
    }
};

class Os {
public:
    void load() {
	cout << "------操作系统导入------" << endl;
    }
};

// 定义外观类
class Facade {
public:
    Facade() {
	m_memory = new Memory();
	m_cpu = new Cpu();
	m_hardDisk = new HardDisk();
	m_os = new Os();
    }
    
    void powerOn() {
	cout << "正在开机" << endl;
	m_memory->selfCheck();
	m_cpu->run();
	m_hardDisk->read();
	m_os->load();
	cout << "开机完成" << endl;
    }
    
private:
    Memory* m_memory;
    Cpu* m_cpu;
    HardDisk* m_hardDisk;
    Os* m_os;
};

int main() {
    Facade* facade = new Facade();
    facade->powerOn();
    return 0;
}