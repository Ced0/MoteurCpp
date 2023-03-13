#pragma once
#include "Pos2D.h"

class AsciiComponent:
	public Pos2D
{
public:
	AsciiComponent(char c, glm::vec2 pos = glm::vec2());

	char c;
};

