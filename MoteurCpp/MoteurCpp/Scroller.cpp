#include "Scroller.h"
#include "AsciiComponent.h"

void Scroller::update(char input)
{

    for (int i = 0; i < objects.size(); i++)
    {
        if (((AsciiComponent*)objects[i]->components[0])->pos.y == 0)
        {

        }
    }

    for (int i = 0; i < objects.size(); i++)
    {
        ((AsciiComponent*)objects[i]->components[0])->pos.x--;
    }
}