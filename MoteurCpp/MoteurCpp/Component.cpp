#include "Component.h"

int Component::getId()
{
	return this->id;
}

bool Component::operator==(const Component& other) const
{
	return this->id == other.id;
}
