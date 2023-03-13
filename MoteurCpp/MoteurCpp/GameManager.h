#pragma once
class GameManager
{
public:
    GameManager(GameManager& other) = delete;

    void operator=(const GameManager&) = delete;

    //Default values are set in the getInstance
    static GameManager* getInstance();

protected:
    GameManager() {};

    ~GameManager() {};

private:
    static GameManager* singleton;
};

