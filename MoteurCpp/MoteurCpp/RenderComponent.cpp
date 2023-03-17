#include "RenderComponent.h"

RenderComponent::RenderComponent() : Component()
{
    this->render = 'X';
    this->active = false;
}

RenderComponent::RenderComponent(char c) : Component()
{
    this->render = c;
    this->active = false;
}

bool RenderComponent::isActive() 
{
    return this->active;
}

void RenderComponent::setIsActive(bool active) 
{
    this->active = active;
}

char RenderComponent::getRender()
{
    return render;
}
