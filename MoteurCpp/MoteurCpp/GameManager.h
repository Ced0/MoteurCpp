#pragma once
#include <glm.hpp>


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

    inline char getScreenValue(const glm::ivec2& pos) { return *getScreenCase(pos); }
    inline void setScreenValue(const glm::ivec2& pos, char value) { *getScreenCase(pos) = value;}

protected:
    GameManager() {};

    ~GameManager();

private:
    static GameManager* singleton;

    inline char* getScreenCase(const glm::ivec2& pos) {
        return screen + pos.x * screenSize.y + pos.y;
    }

    glm::ivec2 screenSize;
    char* screen = nullptr;
};

