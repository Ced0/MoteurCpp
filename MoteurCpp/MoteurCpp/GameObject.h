#pragma once
#include <vector>
#include "Component.h"

class GameObject
{
public:

	~GameObject();

	Component* getComponent(std::string type);

protected:
	std::vector<Component*> components;
};

