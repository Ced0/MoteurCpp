#include "AsciiObject.h"
#include "AsciiComponent.h"

AsciiObject::AsciiObject(char c, glm::vec2 pos)
{
	components.push_back(new AsciiComponent(c, pos));
}
