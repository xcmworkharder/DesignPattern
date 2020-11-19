#include <iostream>
#include <memory>

using namespace std;

class House {
public:
    void setFloor(const string& floor) {
	m_floor = floor;
    }
    
    void setWall(const string& wall) {
	m_wall = wall;
    }
    
    void setCeil(const string& ceil) {
	m_ceil = ceil;
    }
    
    void printHouseInfo() {
	cout << "Floor: " << m_floor << endl;
	cout << "Wall: " << m_wall << endl;
	cout << "Ceil: " << m_ceil << endl;
    }
    
private:
    string m_floor;
    string m_ceil;
    string m_wall;	
};

class AbstractBuilder {
public:
    AbstractBuilder() {
	m_house = new House();
    }
    
    virtual void constructCeil() = 0;
    virtual void constructWall() = 0;
    virtual void constructFloor() = 0;
    virtual House* getHouse() = 0;
    
protected:
    House* m_house;
};

class Builder1 : public AbstractBuilder {
public:
    void constructCeil() override {
	m_house->setCeil("Ceil_1");
    }
    
    void constructFloor() override {
	m_house->setFloor("Floor_1");
    }
    
    void constructWall() override {
	m_house->setWall("Wall_1");
    }
    
    House* getHouse() {
	return m_house;
    }	
};

class Builder2 : public AbstractBuilder {
public:
    void constructCeil() override {
	m_house->setCeil("Ceil_2");
    }
    
    void constructFloor() override {
	m_house->setFloor("Floor_2");
    }
    
    void constructWall() override {
	m_house->setWall("Wall_2");
    }
    
    House* getHouse() {
	return m_house;
    }	
};

class Direct {
public:
    void setBuilder(AbstractBuilder* builder) {
	m_builder = builder;
    }
    // 这里决定不同的不同的组装流程
    House* construct() {
	m_builder->constructFloor();
	m_builder->constructWall();
	m_builder->constructCeil();
	return m_builder->getHouse();
    }
    
private:
    AbstractBuilder* m_builder;
};


int main() {
    
    AbstractBuilder* builder1 = new Builder1();
    House* house = nullptr;
    Direct direct;
    
    direct.setBuilder(builder1);
    house = direct.construct();
    house->printHouseInfo();
    
    AbstractBuilder* builder2 = new Builder2();
    direct.setBuilder(builder2);
    house = direct.construct();
    house->printHouseInfo();
    
    return 0;  
}