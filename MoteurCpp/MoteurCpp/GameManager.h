#pragma once
#include <glm.hpp>
#include "GameObjectManager.h"
#include "Updater.h"

class GameManager
{
public:
    GameManager(GameManager& other) = delete;

    void operator=(const GameManager&) = delete;

    //Default values are set in the getInstance
    static GameManager* getInstance();

    void display();

    inline void setScreen(glm::ivec2 _screenSize) { screenSize = _screenSize; }

    void createScreen(char c);
    void clearScreen();

    inline char getScreenValue(const glm::ivec2& pos) { return *getScreenCase(pos); }
    bool setScreenValue(const glm::ivec2& pos, char value);

    inline void addObject(GameObject* obj) { objects.push_back(obj); };
    inline void addUpdater(Updater* obj) { updaters.push_back(obj); };

    inline void gameOver() { exit = true; };
    inline bool getExit() { return exit; };

    void update();

    GameObjectManager* gameObjectManager;

protected:
    GameManager();;

    ~GameManager();

private:
    static GameManager* singleton;

    inline char* getScreenCase(const glm::ivec2& pos) {

        if (pos.x < screenSize.x && pos.x >= 0 && pos.y < screenSize.y && pos.y >= 0)
        {
            return (screen + pos.x * screenSize.y + pos.y);
        }
        
        return NULL;
    }

    std::vector<GameObject*> objects;

    std::vector<Updater*> updaters;

    glm::ivec2 screenSize;
    char* screen = nullptr;
    char defaultScreen;

    bool exit = false;
};

