#include "TransformComponent.h"
#include "TAccessor.h"

TransformComponent::TransformComponent()
{
    this->position = glm::vec2(0, 0);
    this->rotation = 0.f;
    this->scale = glm::vec2(0, 0);
    TAccessor<TransformComponent>::Instance().Add(*this);
}

TransformComponent::TransformComponent(float positionX, float positionY, float rotation, float scaleX, float scaleY)
{
    this->position = glm::vec2(positionX, positionY);
    this->rotation = rotation;
    this->scale = glm::vec2(scaleX, scaleY);
    TAccessor<TransformComponent>::Instance().Add(*this);
}

const float TransformComponent::getPositionX()
{
    return this->position.x;
}

const float TransformComponent::getPositionY()
{
    return this->position.y;
}

const glm::vec2 TransformComponent::getPosition()
{
    return this->position;
}

const float TransformComponent::getRotation()
{
    return this->rotation;
}

const float TransformComponent::getScaleX()
{
    return this->scale.x;
}

const float TransformComponent::getScaleY()
{
    return this->scale.y;
}

const glm::vec2 TransformComponent::getScale()
{
    return this->scale;
}

void TransformComponent::setPositionX(float x)
{
    this->position.x = x;
}

void TransformComponent::setPositionY(float y)
{
    this->position.y = y;
}

void TransformComponent::setPosition(float x, float y)
{
    this->position.x = x;
    this->position.y = y;
}

void TransformComponent::setRotation(float r)
{
    this->rotation = r;
}

void TransformComponent::setScaleX(float x)
{
    this->scale.x = x;
}

void TransformComponent::setScaleY(float y)
{
    this->scale.y = y;
}

void TransformComponent::setScale(float x, float y)
{
    this->scale.x = x;
    this->scale.y = y;
}
