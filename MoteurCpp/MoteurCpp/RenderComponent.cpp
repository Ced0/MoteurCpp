#include "RenderComponent.h"

RenderComponent::RenderComponent(char c) : Component()
{
    this->render = c;
}

char RenderComponent::getRender()
{
    return render;
}
