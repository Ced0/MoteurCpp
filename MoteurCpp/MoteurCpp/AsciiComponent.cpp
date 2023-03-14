#include "AsciiComponent.h"
#include "GameManager.h"

AsciiComponent::AsciiComponent(char _c, glm::vec2 _pos)
{
	//type = "AsciiComponent";

	c = _c;
	pos = _pos;

	GameManager::getInstance()->setScreenValue(pos, c);
}



