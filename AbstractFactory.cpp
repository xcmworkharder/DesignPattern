#include <iostream>
#include <memory>

using namespace std;

class AbstractBall {
public:
    virtual void play() = 0;
};

class BaseketBall : public AbstractBall {
public:
    BaseketBall() {
	play();
    }
    
    void play() override {
	cout << "play BaseketBall" << endl;
    }
};

class FootBall : public AbstractBall {
public:
    FootBall() {
	play();
    }
    
    void play() override {
	cout << "play FootBall" << endl;
    }
};

class PingpangBall : public AbstractBall {
public:
    PingpangBall() {
	play();
    }
    
    void play() override {
	cout << "play pingpang" << endl;
    }
};

class AbstractShirt {
public:
    virtual void wearShirt() = 0;
};

class BaseketShirt : public AbstractShirt {
public:
    BaseketShirt() {
	wearShirt();
    }
    
    void wearShirt() override {
	cout << "wear BaseketShirt" << endl;
    }
};

class FootShirt : public AbstractShirt {
public:
    FootShirt() {
	wearShirt();
    }
    
    void wearShirt() override {
	cout << "wear FootShirt" << endl;
    }
};

class PingpangShirt : public AbstractShirt {
public:
    PingpangShirt() {
	wearShirt();
    }
    
    void wearShirt() {
	cout << "wear pingpangshirt" << endl;
    }
};

class AbstractFactory {
public:
    virtual shared_ptr<AbstractBall> getBall() = 0;
    virtual shared_ptr<AbstractShirt> getShirt() = 0;
};

class BaseketBallFactory : public AbstractFactory {
public:
    BaseketBallFactory() {
	getBall();
	getShirt();
    }
    
    shared_ptr<AbstractBall> getBall() {
	return make_shared<BaseketBall>();
    }
    
    shared_ptr<AbstractShirt> getShirt() {
	return make_shared<BaseketShirt>();
    }
};

class FootBallFactory : public AbstractFactory {
public:
    FootBallFactory() {
	getBall();
	getShirt();
    }
    
    shared_ptr<AbstractBall> getBall() {
	return make_shared<FootBall>();
    }
    
    shared_ptr<AbstractShirt> getShirt() {
	return make_shared<FootShirt>();
    }
};

class PingpangFactory : public AbstractFactory {
public:
    PingpangFactory() {
	getBall();
	getShirt();
    }
    
    shared_ptr<AbstractBall> getBall() {
	return make_shared<PingpangBall>();
    }
    
    shared_ptr<AbstractShirt> getShirt() {
	return make_shared<PingpangShirt>();
    }
};



int main() {
    
    //shared_ptr<AbstractFactory> baseketBallFactory = make_shared<BaseketBallFactory>();
    shared_ptr<AbstractBall> footBall = make_shared<FootBallFactory>()->getBall();
    shared_ptr<AbstractShirt> pingpangShirt = make_shared<PingpangFactory>()->getShirt();
    return 0;
}