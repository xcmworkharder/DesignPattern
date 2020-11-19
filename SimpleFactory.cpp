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

class Factory {
public:
    shared_ptr<AbstractProduct> createProduct(const string& productName) {
	if (productName == "BaseketBall") {
	    return make_shared<BaseketBall>();
	} else if (productName == "FootBall") {
	    return make_shared<FootBall>();
	} else if (productName == "ValleyBall") {
	    return make_shared<ValleyBall>();
	}
    }
};   

int main() {
    
    Factory factory;
    shared_ptr<AbstractProduct> baseketBall = factory.createProduct("BaseketBall");
    shared_ptr<AbstractProduct> footBall = factory.createProduct("FootBall");
    shared_ptr<AbstractProduct> valleyBall = factory.createProduct("ValleyBall");
    return 0;
}