#pragma once
#include <vector>
#include "Component.h"
#include "ComponentEnum.h"

class GameObject
{
public:

	GameObject();
	~GameObject();

	bool hasComponent(const ComponentEnum componentType);
	void addComponent(const ComponentEnum componentType, const int componentId);
	void removeComponent(const int componentId);
	virtual void update(char a);

	std::vector<std::pair<ComponentEnum, int>> components;
	bool active = false;
};

