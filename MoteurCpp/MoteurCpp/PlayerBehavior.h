#pragma once
#include "Component.h"
#include <glm.hpp>
class PlayerBehavior :
    public Component
{

public:
    PlayerBehavior(int ogId);

    ~PlayerBehavior() {};

    float playerMove(glm::vec2 playerPosition, char key);

    bool isGameOver(char screenValue);
};

