#pragma once
#include <glm.hpp>
#include "GameObjectManager.h"
#include "GameObjectEnum.h"
#include "GameObject.h"
#include "Updater.h"
#include <mutex>

#define POOL_SIZE 1500

#ifdef _DEBUG // for unitary test
#include <stdlib.h>
#include <time.h>
#define MAX_RANDOM(X) rand() % X
#endif // _DEBUG

class GameManager
{
public:
    GameManager(GameManager& other) = delete;

    void operator=(const GameManager&) = delete;

    //Default values are set in the getInstance
    static GameManager* getInstance();

    void start();
    void display();

    void addScore(int value);

    inline void setScreen(glm::ivec2 _screenSize) { screenSize = _screenSize; }

    void createScreen(char c);
    void clearScreen();

    inline char getScreenValue(const glm::ivec2& pos) { return *getScreenCase(pos); }
    bool setScreenValue(const glm::ivec2& pos, char value);

    int getInput();

    //inline void addObject(GameObject* obj) { objects.push_back(obj); };
    inline void addUpdater(Updater* obj) { updaters.push_back(obj); };

    inline void gameOver() { exit = true; };
    inline bool getExit() { return exit; };

    void readInputs();
    void updateThread();
    void update();

    void unitaryTest();

    GameObjectManager* gameObjectManager;

protected:
    GameManager();;

    ~GameManager();

private:

    void initGameObjects();
    void initPlayer();
    void initObstacle(const int obstaclesCounter);
    void initWall(const int wallCounter);

    static GameManager* singleton;

    inline char* getScreenCase(const glm::ivec2& pos) {

        if (pos.x < screenSize.x && pos.x >= 0 && pos.y < screenSize.y && pos.y >= 0)
        {
            return (screen + pos.x * screenSize.y + pos.y);
        }

        return NULL;
    }

    std::vector<std::pair<int, GameObjectEnum>> gameObjects;

    std::vector<Updater*> updaters;

    glm::ivec2 screenSize;
    char* screen = nullptr;
    char defaultScreen;

    bool exit = false;
    int score = 0;
    char input = 0;
    std::mutex inputMtx;
};

