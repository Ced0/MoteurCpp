#include "GameManager.h"

GameManager* GameManager::singleton = nullptr;

GameManager* GameManager::getInstance()
{
    if (singleton == nullptr) {
        singleton = new GameManager();
    }

    return singleton;
}