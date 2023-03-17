// MoteurCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "ThreadPool.h"
#include "GameManager.h"
#include "Player.h"
#include "Scroller.h"
#include "ObstacleSpawner.h"
#include "BonusSpawner.h"

int main()
{
    ThreadPool* pool = ThreadPool::getInstance();
    pool->start();
    GameManager* game = GameManager::getInstance();
    game->setScreen(glm::ivec2(50, 20));
    game->createScreen(' ');
    game->start();

    while (game->getExit() == false)
    {
        game->readInputs();
    }

    std::cout << "\nGame over\n";

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage
