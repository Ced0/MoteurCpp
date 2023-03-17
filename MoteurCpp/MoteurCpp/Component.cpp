#include "Component.h"

unsigned int Component::index = 0;

Component::Component()
{
	this->id = index++;
	this->goId = 0;
}

Component::Component(unsigned int index)
{
	this->id = index++;
	this->goId = index;
}

const unsigned int Component::getId()
{
	return this->id;
}

const unsigned int Component::getgoId()
{
	return goId;
}

void Component::setgoId(unsigned int id)
{
	goId = id;
}

bool Component::operator==(const Component& other) const
{
	return this->id == other.id;
}
