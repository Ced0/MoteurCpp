#pragma once
#include "Component.h"
#include "glm.hpp"

class ScrollerComponent :
    public Component
{

public:
    ScrollerComponent();

    ~ScrollerComponent() {};

    float move(glm::vec2 position);
};

