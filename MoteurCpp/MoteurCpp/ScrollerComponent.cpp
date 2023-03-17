#include "ScrollerComponent.h"



ScrollerComponent::ScrollerComponent() : Component()
{
}

float ScrollerComponent::move(glm::vec2 position)
{
    return position.x--;
}
