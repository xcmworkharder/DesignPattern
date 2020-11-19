#include <iostream>
#include <memory>

using namespace std;

class AbstractProduct {
public:
    virtual void createProduct() = 0;
    virtual void runProduct() = 0;
};

class BaseketBall : public AbstractProduct {
public:
    BaseketBall() {
	createProduct();
	runProduct();
    }
    
    void createProduct() override {
	cout << "create baseketBall" << endl;
    }
    
    void runProduct() override {
	cout << "run baseketBall" << endl;
    }
};

class FootBall : public AbstractProduct {
public:
    FootBall() {
	createProduct();
	runProduct();
    }
    
    void createProduct() override {
	cout << "create FootBall" << endl;
    }
    
    void runProduct() override {
	cout << "run FootBall" << endl;
    }
};

class ValleyBall : public AbstractProduct {
public:
    ValleyBall() {
	createProduct();
	runProduct();
    }
    
    void createProduct() override {
	cout << "create ValleyBall" << endl;
    }
    
    void runProduct() override {
	cout << "run ValleyBall" << endl;
    }
};

class AbstractFactory {
public:
    virtual shared_ptr<AbstractProduct> getProduct() = 0;
};

class BaseketBallFactory : public AbstractFactory {
public:
    shared_ptr<AbstractProduct> getProduct() {
	return make_shared<BaseketBall>();
    }
};

class FootBallFactory : public AbstractFactory {
public:
    shared_ptr<AbstractProduct> getProduct() {
	return make_shared<FootBall>();
    }
};

class ValleyBallFactory : public AbstractFactory {
public:
    shared_ptr<AbstractProduct> getProduct() {
	return make_shared<ValleyBall>();
    }
};

class PingpangBall : public AbstractProduct {
public:
    PingpangBall() {
	createProduct();
	runProduct();
    }
    
    void createProduct() override {
	cout << "create PingpangBall" << endl;
    }
    
    void runProduct() override {
	cout << "run PingpangBall" << endl;
    } 
};

class PingpangBallFactory : public AbstractFactory {
public:
    shared_ptr<AbstractProduct> getProduct() {
	return make_shared<PingpangBall>();
    }
};

int main() {

    shared_ptr<AbstractFactory> baseketBallFactory = make_shared<BaseketBallFactory>();
    shared_ptr<AbstractProduct> baseketBallProduct = baseketBallFactory->getProduct();
    
    shared_ptr<AbstractFactory> footBallFactory = make_shared<FootBallFactory>();
    shared_ptr<AbstractProduct> footBallProduct = footBallFactory->getProduct();
    
    shared_ptr<AbstractFactory> valleyBallFactory = make_shared<ValleyBallFactory>();
    shared_ptr<AbstractProduct> valleyBallProduct = valleyBallFactory->getProduct();
    
    shared_ptr<AbstractFactory> pingpangBallFactory = make_shared<PingpangBallFactory>();
    shared_ptr<AbstractProduct> pingpangBallProduct = pingpangBallFactory->getProduct();
    
    return 0;
}