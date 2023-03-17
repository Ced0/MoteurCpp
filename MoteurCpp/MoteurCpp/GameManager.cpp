#include "GameManager.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "ThreadPool.h"
#include "GameObjectEnum.h"
#include "TransformComponent.h"
#include "PlayerBehavior.h"
#include "RenderComponent.h"

GameManager* GameManager::singleton = nullptr;

GameManager::GameManager()
{
    gameObjectManager = GameObjectManager::getInstance();
    gameObjectManager->init(POOL_SIZE);
    initGameObjects();
}

void GameManager::initGameObjects()
{
    initPlayer();
    initObstacle(50, 20);
    initWall(50);
}

void GameManager::initPlayer()
{
    auto newPair = std::make_pair(gameObjectManager->allocateGameObject(), GameObjectEnum::Player);
    gameObjectManager->addComponent(newPair.first, ComponentEnum::TransformComponent, (new TransformComponent())->getId());
    gameObjectManager->addComponent(newPair.first, ComponentEnum::RenderComponent, (new RenderComponent())->getId());
    gameObjectManager->addComponent(newPair.first, ComponentEnum::PlayerBehavior, (new PlayerBehavior())->getId());
    gameObjects.push_back(newPair);
}

void GameManager::initObstacle(const int x, const int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < j; j++)
        {
            allocateNewObstacle(0, 0);
        }
    }
}

void GameManager::initWall(const int wallCounter)
{
    for (int i = 0; i < wallCounter; i++)
    {
        // top side wall
        auto newTopWall = std::make_pair(gameObjectManager->allocateGameObject(), GameObjectEnum::Wall);
        gameObjectManager->addComponent(newTopWall.first, ComponentEnum::RenderComponent, (new RenderComponent('X'))->getId());
        auto transformComponentTop = new TransformComponent();
        transformComponentTop->setPositionX(i);
        transformComponentTop->setPositionY(0);
        gameObjectManager->addComponent(newTopWall.first, ComponentEnum::TransformComponent, transformComponentTop->getId());
        gameObjects.push_back(newTopWall);

        // bot side wall
        auto newBottomWall = std::make_pair(gameObjectManager->allocateGameObject(), GameObjectEnum::Wall);
        gameObjectManager->addComponent(newTopWall.first, ComponentEnum::RenderComponent, (new RenderComponent('X'))->getId());
        auto transformComponentBottom = new TransformComponent();
        transformComponentBottom->setPositionX(i);
        transformComponentBottom->setPositionY(19);
        gameObjectManager->addComponent(newBottomWall.first, ComponentEnum::TransformComponent, transformComponentBottom->getId());
        gameObjects.push_back(newBottomWall);
    }
}

void GameManager::allocateNewObstacle(const int x, const int y)
{
    auto newPair = std::make_pair(gameObjectManager->allocateGameObject(), GameObjectEnum::Obstacle);
    auto transformComponent = new TransformComponent();
    transformComponent->setPositionX(x);
    transformComponent->setPositionY(y);
    gameObjectManager->addComponent(newPair.first, ComponentEnum::TransformComponent, transformComponent->getId());
    gameObjectManager->addComponent(newPair.first, ComponentEnum::RenderComponent, (new RenderComponent('X'))->getId());
    gameObjects.push_back(newPair);
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
    clearScreen();

    /*for (int i = 0; i < updaters.size(); i++)
    {
        updaters[i]->update(cpyInput);
    }

    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i]->active == true) objects[i]->update(cpyInput);
    }*/
    input = 0;
    inputMtx.unlock();
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

int GameManager::getInput()
{
    return this->input;
}

void GameManager::unitaryTest()
{
}