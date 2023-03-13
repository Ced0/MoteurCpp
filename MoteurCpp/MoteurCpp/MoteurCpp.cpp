// MoteurCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "ThreadPool.h"
#include "GameManager.h"
#include "AsciiObject.h"

int main()
{
    ThreadPool* pool = ThreadPool::getInstance();
    pool->start();

    GameManager* game = GameManager::getInstance();

    game->setScreen(glm::ivec2(10, 10));
    game->createScreen(' ');

    AsciiObject obj('c', glm::vec2(0, 1));

    game->display();
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage
