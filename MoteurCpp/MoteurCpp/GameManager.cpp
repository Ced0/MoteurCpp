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
    gameObjectManager = GameObjectManager<GameObject>::getInstance(200);
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