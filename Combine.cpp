#include <iostream>
#include <vector>

using namespace std;

// 有两种处理策略，一种是安全模式，就是基类和叶子类只有共有方法，而组件类还有增加 删除等方法；一种是透明模式，就是leaf和composite处理为一样的，leaf中有些空方法
class Component {
public:
    Component() {}
    
    Component(const string& name) {
	m_name = name;
    }
    
    virtual void add(Component* com) = 0;
    virtual void remove(Component* com) = 0;
    virtual Component* getChild(int) = 0;
    virtual void operation() = 0;
    string getName() const {
	return m_name;
    }
    
protected:
    string m_name;
};
	
// 以下是叶子节点
class Office : public Component {
public:
    Office() {}
    Office(const string& name) {
	m_name = name;
    }
    
    void add(Component* com) override {
	cout << "leaf can not add" << endl;
    }
    
    void remove(Component* com) override {
	cout << "left can not remove" << endl;
    }
    
    Component* getChild(int index) {
	cout << "left has no child" << endl;
	return nullptr;
    }
};

// 行政办公室
class AdminOffice : public Office {
public:
    AdminOffice(const string& name) {
	m_name = name;
    }
    
    void operation() override {
	cout << "AdminOffice: " << m_name << endl;
    }
};

// 教务办公室
class DeanOffice : public Office {
public:
    DeanOffice(const string& name) {
	m_name = name;
    }
    
    void operation() override {
	cout << "DeanOffice: " << m_name << endl;
    }
};

// 容器构件
class SubComponent : public Component {
public:
    SubComponent(const string& name) {
	m_name = name;
    }
    
    void add(Component* com) {
	m_comVec.push_back(com);
    }
    
    void remove(Component* com) {
	for (int i = 0; i < m_comVec.size(); ++i) {
	    if (m_comVec[i]->getName() == com->getName()) {
		m_comVec.erase(m_comVec.begin() + i);
		break;
	    }
	}
    }
    
    Component* getChild(int index) {
	return (Component*)m_comVec[index];
    }
    
    void operation() {
	cout << m_name << endl;
	for (int i = 0; i < m_comVec.size(); ++i) {
	    m_comVec[i]->operation();
	}
    }
    
private:
    vector<Component*> m_comVec;
};

// class A {
// public:
//     virtual void funcA() = 0;
//     virtual void funcB() = 0;
// };
// 
// class B : public A {	// 只实现一个虚函数不能实例化，可作为一个中间抽象类使用
// public:
//     void funcA() {
// 	cout << "funcA" << endl;
//     }
//     
//     void funcB() {
// 	cout << "funcB" << endl;
//     }
// };
// 
// class BB : public B {
// public:
//     void funcA() {
// 	cout << "funA in BB" << endl;
//     }
//     
//     void funcB() {
// 	cout << "funB" << endl;
//     }
// };


int main() {
    
    Component *head, *sichuanBranch, *cdBranch, *myBranch, *office1, *office2, *office3,
	    *office4, *office5, *office6, *office7, *office8;

    head = new SubComponent("总部");
    sichuanBranch = new SubComponent("四川分部");
    office1 = new AdminOffice("行政办公室");
    office2 = new DeanOffice("教务办公室");
    
    cdBranch = new SubComponent("成都分部");
    myBranch = new SubComponent("绵阳分部");
    office3 = new AdminOffice("行政办公室");
    office4 = new DeanOffice("教务办公室");
    
    office5 = new AdminOffice("行政办公室");
    office6 = new DeanOffice("教务办公室");
    
    office7 = new AdminOffice("行政办公室");
    office8 = new DeanOffice("教务办公室");
    
    cdBranch->add(office5);
    cdBranch->add(office6);

    myBranch->add(office7);
    myBranch->add(office8);

    sichuanBranch->add(office3);
    sichuanBranch->add(office4);
    sichuanBranch->add(cdBranch);
    sichuanBranch->add(myBranch);

    head->add(office1);
    head->add(office2);
    head->add(sichuanBranch);
    
    head->operation();
    
    return 0;
}