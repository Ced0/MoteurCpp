// MoteurCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "ThreadPool.h"
#include "GameManager.h"
#include "Player.h"
#include "Scroller.h"

int main()
{
    ThreadPool* pool = ThreadPool::getInstance();
    pool->start();

    GameManager* game = GameManager::getInstance();

    game->setScreen(glm::ivec2(50, 20));
    game->createScreen(' ');

    AsciiObject obj('X', glm::vec2(25, 3));

    for (int i = 0; i < 50; i++)
    {
        game->addObject(new AsciiObject('X', glm::vec2(i, 0)));
        game->addObject(new AsciiObject('X', glm::vec2(i, 19)));
    }

    Player player('O', glm::vec2(5, 10));

    Scroller scroller;

    scroller.addObject(&obj);

    game->addObject(&obj);
    game->addObject(&player);
    game->addUpdater(&scroller);

    while (game->getExit() == false)
    {
        game->update();
    }

    std::cout << "\nGame over\n";
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage
