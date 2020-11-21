#include <iostream>

using namespace std;

// 系统中存在两个变化的维度，比如手机玩游戏，手机和游戏分别是两个维度，增加手机对游戏没有影响，增加游戏对手机也没有影响
// 两个维度建立独立继承体系，互相之间关联使用就类似桥
class Game {
public:
    virtual void play() = 0;
};

class GameA : public Game {
public:
    GameA() {
// 	play();
    }
    
    void play() override {
	cout << "play GameA" << endl;
    }
};

class GameB : public Game {
public:
    GameB() {
// 	play();
    }
    
    void play() override {
	cout << "play GameB" << endl;
    }
};

class GameC : public Game {
public:
    GameC() {
// 	play();
    }
    
    void play() override {
	cout << "play GameC" << endl;
    }
};

class Phone {
public:
    virtual void setupGame(Game* game) = 0;
    virtual void play() = 0;
    
protected:
    Game* m_game;
};

class Pad : public Phone {
public:
    void setupGame(Game* game) {
	m_game = game;
    }
    
    void play() override {
	cout << "Pad:" << endl;
	m_game->play();
    }
};

class PhoneA : public Phone {
public:
    void setupGame(Game* game) {
	m_game = game;
    }
    
    void play() override {
	cout << "PhoneA:" << endl;
	m_game->play();
    }
};

class PhoneB : public Phone {
public:
    void setupGame(Game* game) {
	m_game = game;
    }
    
    void play() override {
	cout << "PhoneB:" << endl;
	m_game->play();
    }
};

int main() {
    
    Game* game = nullptr;
    Phone* phone = nullptr;
    
    // 购买手机A
    phone = new PhoneA();
    // 玩游戏A
    game = new GameA();
    phone->setupGame(game);
    phone->play(); 
    
    cout << "---------------------" << endl;
    // 玩游戏B
    game = new GameB();
    phone->setupGame(game);
    phone->play();
    
    phone = new Pad();
    game = new GameC();
    phone->setupGame(game);
    phone->play();
    
    return 0;
}