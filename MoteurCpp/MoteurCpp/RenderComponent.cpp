#include "RenderComponent.h"
#include "TAccessor.h"

RenderComponent::RenderComponent() : Component()
{
    this->render = 'X';
    this->active = false;
    TAccessor<RenderComponent>::Instance()->Add(*this);

}

RenderComponent::RenderComponent(char c) : Component()
{
    this->render = c;
    this->active = false;
    TAccessor<RenderComponent>::Instance()->Add(*this);
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
