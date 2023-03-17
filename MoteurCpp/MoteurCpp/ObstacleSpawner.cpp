#include "ObstacleSpawner.h"
#include "Utils.h"
#include "AsciiComponent.h"

void ObstacleSpawner::update(char input)
{
	int toSpawn = randInt(spawnMin, spawnMax);

    int cpt = 0;
    for (int i = 0; i < objects.size() && cpt < toSpawn; i++)
    {
        if (objects[i]->active == false)
        {
            ((AsciiComponent*)objects[i]->components[0])->pos.x = 49;
            ((AsciiComponent*)objects[i]->components[0])->pos.y = randInt(1, 19);
            objects[i]->active = true;
            cpt++;
        }
    }
}