// MoteurCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "ThreadPool.h"
#include <glm.hpp>
#include "Node2D.h"

int main()
{
    ThreadPool* pool = ThreadPool::getInstance();
    pool->start();

    Node2D test;

    Pos2D* comp = (Pos2D*) test.getComponent("Pos2D");

    if (comp != NULL)
    {
        std::cout << comp->getType() << "\n";
    }

    std::cout << "Hello World!\n";
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage
