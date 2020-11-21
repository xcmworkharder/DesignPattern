#include <iostream>

using namespace std;

class WorkModel {
public:
    void setWorkModelName(const string& name) {
	m_modelName = name;
    }
    
    string getModelName() const {
	return m_modelName;
    }
    
private:
    string m_modelName;
};

class AbstractPrototype {
public:
    virtual AbstractPrototype* clone() = 0;    
};

class ConcreteWork : public AbstractPrototype {
public:
    ConcreteWork() {}
    
    ConcreteWork(const string& name, int num, const string& modelName) :
    m_name(name), m_num(num) { 
	m_workModel = new WorkModel();
	m_workModel->setWorkModelName(modelName);
    }
    
    ConcreteWork* clone() override {
	ConcreteWork* work = new ConcreteWork();
	work->setName(m_name);
	work->setNum(m_num);
	work->setModel(m_workModel);
	return work;
    }
    
    void setName(const string& name) {
	m_name = name;
    }
    
    void setNum(int num) {
	m_num = num;
    }
    
    void setModel(WorkModel* workModel) {
	m_workModel = workModel;
    }
    
    void printWorkInfo() {
	cout << "name: " << m_name << endl;
	cout << "num: " << m_num << endl;
	cout << "modelName: " << m_workModel->getModelName() << endl;
    }
    
private:
    string m_name;
    int m_num;
    WorkModel* m_workModel;
};

class ConcreteWork1 : public AbstractPrototype {
public:
    ConcreteWork1() {}
    
    ConcreteWork1(const string& name, int num, const string& modelName) :
    m_name(name), m_num(num) { 
	m_workModel = new WorkModel();
	m_workModel->setWorkModelName(modelName);
    }
    
    ConcreteWork1* clone() override {
	ConcreteWork1* work = new ConcreteWork1();
	work->setName(m_name);
	work->setNum(m_num);
	work->setModel(m_workModel);
	return work;
    }
    
    void setName(const string& name) {
	m_name = name;
    }
    
    void setNum(int num) {
	m_num = num;
    }
    
    void setModel(WorkModel* workModel) {
	m_workModel = workModel;
    }
    
    void printWorkInfo() {
	cout << "name: " << m_name << endl;
	cout << "num: " << m_num << endl;
	cout << "modelName: " << m_workModel->getModelName() << endl;
    }
    
private:
    string m_name;
    int m_num;
    WorkModel* m_workModel;
};

int main() {
    ConcreteWork* singleWork = new ConcreteWork("Single", 1001, "Single_Moel");
    singleWork->printWorkInfo();
    
    // 浅拷贝
    cout << "以下是浅拷贝的情况-------------:" << endl;
    ConcreteWork* myWork = singleWork;
    myWork->setName("xcm");
    myWork->setNum(1002);
    WorkModel* workModel = new WorkModel();
    workModel->setWorkModelName("xcm_model");
    myWork->setModel(workModel);
    myWork->printWorkInfo();
    
    singleWork->printWorkInfo();
    
    // 深拷贝
    cout << "以下是深拷贝的情况-------------:" << endl;
    ConcreteWork* myWork1 = singleWork->clone();
    myWork1->setName("xcm1");
    myWork1->setNum(1003);
    WorkModel* workModel1 = new WorkModel();
    workModel1->setWorkModelName("xcm1_model");
    myWork1->setModel(workModel1);
    myWork1->printWorkInfo();
    
    singleWork->printWorkInfo();
    
    return 0;
}