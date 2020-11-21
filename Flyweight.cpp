#include <iostream>
#include <mutex>
#include <unordered_map>

using namespace std;

// 内部状态可以通过ｈａｓｈｍａｐ来共享
class NetDevice {
public:
    virtual string getName() const = 0;
    
    // 没有外部状态
//     void print() {
// 	cout << "NetDevice: " << getName()  << endl;
//     }
    
    // 通过函数参数传入外部状态
    void print(int portNum) {
	cout << "NetDevice: " << getName() << "Port: " << portNum << endl;
    }
};

class Hub : public NetDevice {
public:
    string getName() const override {
	return "Hub";
    }
};

class Switch : public NetDevice {
public:
    string getName() const override {
	return "Switch";
    }
};

// 享元工厂
class NetDeviceFactory {
public:
    NetDevice* getDevice(char ch) {
	if (ch == 'S') {
	    return devicePool['S'];
	} else if (ch == 'H') {
	    return devicePool['H'];
	} else {
	    cout << "Wrong Input" << endl;
	}
	return nullptr;
    }
    
    // 单例模式：返回享元工厂的唯一实例
    static NetDeviceFactory* getFactory() {
	if (instance == nullptr) {
	    m_mutex.lock();
	    if (instance == nullptr) {
		instance = new NetDeviceFactory();
	    }
	    m_mutex.unlock();
	}
	return instance;
    }
    
private:
    NetDeviceFactory() {
	Hub* hub = new Hub();
	Switch* switch_ = new Switch();
	devicePool['H'] = hub;
	devicePool['S'] = switch_;
    }
    
    static NetDeviceFactory* instance;
    static mutex m_mutex;
    
    unordered_map<char, NetDevice*> devicePool;
};

NetDeviceFactory* NetDeviceFactory::instance = nullptr;
mutex NetDeviceFactory::m_mutex;

// 由外部状态的享元模式
// 内部状态是享元累的成员对象，而外部状态可以通过外部注入的方式添加到享元类中

int main() {
    NetDeviceFactory* factory = NetDeviceFactory::getFactory();
    
    // 客户创建一个hub
    NetDevice* device1 = factory->getDevice('H');
    device1->print(1);
    // 客户创建一个hub
    NetDevice* device2 = factory->getDevice('H');
    device2->print(2);
    cout << device1 << endl;
    cout << device2 << endl;
    return 0;
}