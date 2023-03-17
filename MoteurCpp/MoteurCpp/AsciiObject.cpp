#include "AsciiObject.h"
#include "AsciiComponent.h"
#include "GameManager.h"

AsciiObject::AsciiObject(char c, glm::vec2 pos)
{
	//components.push_back(new AsciiComponent(c, pos));
}

void AsciiObject::update(char input)
{
	//GameManager* manager = GameManager::getInstance();

	//AsciiComponent* comp = (AsciiComponent*)components[0];
	//active = manager->setScreenValue(comp->pos, comp->c);
}