#include "BonusSpawner.h"
#include "Utils.h"
#include "AsciiComponent.h"
#include "GameManager.h"

void BonusSpawner::update(char input)
{
	//int toSpawn = randInt(0, spawnMax);

	//int cpt = 0;
	//for (int i = 0; i < objects.size() && cpt < toSpawn; i++)
	//{
	//	if (objects[i]->active == false)
	//	{
	//		glm::ivec2 potatoes;
	//		potatoes.x = 49;

	//		do
	//		{
	//			potatoes.y = randInt(1, 19);

	//		} while (GameManager::getInstance()->getScreenValue(potatoes) == 'X');


	//		((AsciiComponent*)objects[i]->components[0])->pos = potatoes;

	//		objects[i]->active = true;
	//		cpt++;
	//	}
	//}
}