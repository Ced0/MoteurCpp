#include "GameManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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
    delete screen;
}


void GameManager::display()
{
    system("cls");//Nettoyage juste avant d'afficher une nouvelle frame

    for (int i = 0; i < screenSize.x; i++)//Affichage
    {
        for (int cpt = 0; cpt < screenSize.y; cpt++)
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