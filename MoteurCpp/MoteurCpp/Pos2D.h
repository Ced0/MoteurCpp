#pragma once
#include "Component.h"
#include <glm.hpp>

class Pos2D :
    public Component
{
public:
    Pos2D();

    glm::vec2 pos;
};

