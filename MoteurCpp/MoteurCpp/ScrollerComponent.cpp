#include "ScrollerComponent.h"
#include "TAccessor.h"



ScrollerComponent::ScrollerComponent() : Component()
{
    TAccessor<ScrollerComponent>::Instance()->Add(*this);
}

float ScrollerComponent::move(glm::vec2 position)
{
    return position.x--;
}
