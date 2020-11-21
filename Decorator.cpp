#include <iostream>

using namespace std;

// 使用对象间的关联关系来替代继承关系
// 抽象构件类
class Component {
public:
    virtual void operation() = 0;
};

// 具体构件类, 实现一些基本配置
class Phone : public Component {
public:
    void operation() override {
	cout << "Phone" << endl;
    }
};

// 装饰类 继承构件类实现operation, 组合构件类
class Decorator : public Component {
public:
    Decorator() {}
    Decorator(Component* com) {
	m_component = com;
    }
    
    void operation() override {
	m_component->operation();
    }
    
    Component* getComponent() const {
	return m_component;
    }
    
    void setComponent(Component* com) {
	m_component = com;
    }
    
private:
    Component* m_component;
};

// 具体装饰类， 在基本配置上添加newBehavior()
// 手机壳
class DecoratorShell : public Decorator {
public:
    DecoratorShell() {}
    DecoratorShell(Component* com) {
	setComponent(com);
    }
    
    void operation() {
	getComponent()->operation();
	newBehavior();
    }
    
    void newBehavior() {
	cout << "装上手机壳" << endl;
    }  
};

// 手机挂绳
class DecoratorRope : public Decorator {
public:
    DecoratorRope() {}
    DecoratorRope(Component* com) {
	setComponent(com);
    }
    
    void operation() {
	getComponent()->operation();
	newBehavior();
    }
    
    void newBehavior() {
	cout << "挂上手机挂绳" << endl;
    }
};

int main() {
    
    cout << "第一部手机: " << endl;
    Component* com = new Phone();
    Component* com_shell = new DecoratorShell(com);
    com_shell->operation();
    Component* com_rope = new DecoratorRope(com);
    com_rope->operation();
    
    return 0;
}