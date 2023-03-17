#include "RenderComponent.h"

RenderComponent::RenderComponent()
{
    this->render = 'X';
}

RenderComponent::RenderComponent(char c) : Component()
{
    this->render = c;
}

char RenderComponent::getRender()
{
    return render;
}
