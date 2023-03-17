#include "GameManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "ThreadPool.h"

GameManager* GameManager::singleton = nullptr;

GameManager::GameManager()
{
    gameObjectManager = GameObjectManager::getInstance(POOL_SIZE);
}

void GameManager::start()
{
    update();

    ThreadPool* pool = ThreadPool::getInstance();
    pool->queueJob(&GameManager::updateThread, this);
}

GameManager* GameManager::getInstance()
{
    if (singleton == nullptr) {
        singleton = new GameManager();
        srand(time(NULL));
    }

    return singleton;
}

GameManager::~GameManager()
{
    for (int i = 0; i < objects.size(); i++)
    {
        delete objects[i];
    }

    for (int i = 0; i < updaters.size(); i++)
    {
        delete updaters[i];
    }

    delete screen;
}

void GameManager::display()
{
    system("cls");//Nettoyage juste avant d'afficher une nouvelle frame

    //std::cout << "update \n\n\n";

    std::string toDisplay = "";

    for (int cpt = (screenSize.y - 1); cpt >= 0; cpt--)
    {
        for (int i = 0; i < screenSize.x; i++)//Affichage
        {

            toDisplay += getScreenValue(glm::ivec2(i, cpt));

        }

        toDisplay += "\n";
    }

    toDisplay += "Score: " + std::to_string(score) + "\n";

    std::cout << toDisplay;
}

void GameManager::createScreen(char c) 
{ 
    int size = screenSize.x * screenSize.y;

    screen = new char[size];
    defaultScreen = c;
    clearScreen();
}

void GameManager::clearScreen()
{
    int size = screenSize.x * screenSize.y;

    for (int i = 0; i < size; i++)
    {
        screen[i] = defaultScreen;
    }
}

void GameManager::readInputs()
{
    if (_kbhit() != 0)
    {
        inputMtx.lock();
        input = _getch();
        inputMtx.unlock();
        fflush(stdin);
    }
}

void GameManager::updateThread()
{
    while (exit == false)
    {
        Sleep(50);
        update();
    }
}

void GameManager::update()
{
    inputMtx.lock();
    char cpyInput = input;
    input = 0;
    inputMtx.unlock();

    clearScreen();

    for (int i = 0; i < updaters.size(); i++)
    {
        updaters[i]->update(cpyInput);
    }

    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i]->active == true) objects[i]->update(cpyInput);
    }

    score++;

    display();
}

bool GameManager::setScreenValue(const glm::ivec2& pos, char value)
{
    char* p = getScreenCase(pos); 

    if (p != NULL)
    {
        *p = value;
        return true;
    }

    return false;
}

void GameManager::unitaryTest()
{
    //gameObjectManagerUnitaryTest(20);
}

//void GameManager::gameObjectManagerUnitaryTest(uint32_t iteration)
//{
//	int gameObjectId[POOL_SIZE];
//    int gameObjectDoublon[POOL_SIZE];
//
//    for (int i = 0; i < POOL_SIZE; i++)
//    {
//        gameObjectId[i] = -1;
//        gameObjectDoublon[i] = 0;
//    }
//
//    for (int i = 0; i < iteration; i++)
//    {
//        std::cout << "! allocation !" << std::endl;
//        for (int j = 0; j < POOL_SIZE; j++)
//        {
//            if (gameObjectId[j] == -1)
//            {
//                gameObjectId[j] = gameObjectManager->allocateGameObject();
//            }
//            std::cout << gameObjectId[j] << ", ";
//        }
//        std::cout << std::endl;
//
//        std::cout << "! deallocation !" << std::endl;
//        for (int j = 0; j < POOL_SIZE; j++)
//        {
//            auto resultRandom = MAX_RANDOM(POOL_SIZE);
//            if (j < POOL_SIZE - 1)
//                gameObjectId[resultRandom] = gameObjectManager->deallocateGameObject(gameObjectId[resultRandom], false);
//            else
//                gameObjectId[resultRandom] = gameObjectManager->deallocateGameObject(gameObjectId[resultRandom], true);
//        }
//
//        for (int j = 0; j < POOL_SIZE; j++)
//        {
//            std::cout << gameObjectId[j] << ", ";
//        }
//        std::cout << std::endl;
//
//        //for (int i = 0; i < POOL_SIZE; i++)
//        //{
//        //    auto idx = gameObjectId[i];
//        //    if (idx >= 0)
//        //        gameObjectDoublon[idx] += 1;
//        //}
//
//        for (int i = 0; i < POOL_SIZE; i++)
//        {
//            if (gameObjectDoublon[i] > 1)
//            {
//                std::cout << "???" << std::endl;
//            }
//            //gameObjectDoublon[i] = 0;
//        }
//        std::cout << std::endl;
//    }
//
//    for (int i = 0; i < POOL_SIZE; i++)
//    {
//        auto idx = gameObjectId[i];
//        if (idx >= 0)
//            gameObjectDoublon[idx] += 1;
//    }
//
//    std::cout << "final result : " << std::endl;
//    for (int i = 0; i < POOL_SIZE; i++)
//    {
//        std::cout << gameObjectId[i] << ", ";
//    }
//    std::cout << std::endl;
//
//    bool isDoublon = false;
//    std::cout << "check doublon : " << std::endl;
//    for (int i = 0; i < POOL_SIZE; i++)
//    {
//        if (gameObjectDoublon[i] > 1)
//        {
//            isDoublon = true;
//            std::cout << "idx game object : " << i;
//            std::cout << " value : " << gameObjectDoublon[i] << std::endl;
//        }
//    }
//    if (!isDoublon)
//        std::cout << "no doublon" << std::endl;
//}