#include "Component.h"

unsigned int Component::index = 0;

Component::Component(unsigned int goId)
{
	this->id = index++;
	this->gameObjectId = goId;
}

const unsigned int Component::getId()
{
	return this->id;
}

const unsigned int Component::getGameObjectId()
{
	return this->gameObjectId;
}

bool Component::operator==(const Component& other) const
{
	return this->id == other.id;
}
