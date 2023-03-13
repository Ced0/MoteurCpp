#include "GameManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

GameManager* GameManager::singleton = nullptr;

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

    for (int cpt = (screenSize.y - 1); cpt >= 0; cpt--)
    {
        for (int i = 0; i < screenSize.x; i++)//Affichage
        {

            std::cout << getScreenValue(glm::ivec2(i, cpt));

        }

        printf("\n");
    }
}

void GameManager::createScreen(char c) 
{ 
    int size = screenSize.x * screenSize.y;

    screen = new char[size];

    for (int i = 0; i < size; i++)
    {
        screen[i] = c;
    }
}

void GameManager::update()
{
    char input = 0;

    Sleep(500);

    if (_kbhit() != 0)
    {
        input = _getch();
        fflush(stdin);
    }

    for (int i = 0; i < objects.size(); i++)
    {
        objects[i]->update(input);
    }

    //for()
}