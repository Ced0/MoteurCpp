#include "Scroller.h"
#include "AsciiComponent.h"
#include "GameManager.h"

void Scroller::update(char input)
{
    for (int i = 0; i < objects.size(); i++)
    {
        ((AsciiComponent*)objects[i]->components[0])->pos.x--;
    }

    GameManager* manager = GameManager::getInstance();

    for (int i = 0; i < objects.size(); i++)
    {
        AsciiComponent* comp = (AsciiComponent*)objects[i]->components[0];
        manager->setScreenValue(comp->pos, comp->c);
    }
}