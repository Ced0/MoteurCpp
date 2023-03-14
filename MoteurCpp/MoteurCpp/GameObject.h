#pragma once
#include <vector>
#include "Component.h"

class GameObject
{
public:

	~GameObject();

	Component* getComponent(std::string type);
	void addComponent(Component* componentAdded);
	virtual void update(char a);

	std::vector<Component*> components;
	bool active = true;
};

