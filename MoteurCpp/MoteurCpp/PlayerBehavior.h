#pragma once
#include "Component.h"
#include <glm.hpp>
class PlayerBehavior :
    public Component
{
    float playerMove(glm::vec2 playerPosition, char key);

    bool isGameOver(char screenValue);
};

