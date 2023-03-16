#pragma once
#include <string>

class Component
{
private:
	static unsigned int index;
	unsigned int id;
	unsigned int gameObjectId;

public:
	Component();

	Component(unsigned int goId);

	const unsigned int getId();

	const unsigned int getGameObjectId();

	bool operator== (const Component& other) const;
	
};

