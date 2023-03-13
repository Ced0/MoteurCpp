#pragma once
#include "GameObject.h"
#include <glm.hpp>

class AsciiObject :
    public GameObject
{
public:
    AsciiObject(char c, glm::vec2 pos = glm::vec2());
};

