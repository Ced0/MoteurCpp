#include "GameObject.h"

GameObject::GameObject()
{
	components = std::vector<std::pair<ComponentEnum, int>>();
}

GameObject::~GameObject()
{
}

bool GameObject::hasComponent(const ComponentEnum componentType)
{
	for (auto const& [key, value] : components)
	{
		if (key == componentType)
			return true;
	}
	return false;
}

void GameObject::addComponent(const ComponentEnum componentType, const int componentId)
{
	components.push_back(std::make_pair(componentType, componentId));
}

void GameObject::removeComponent(const ComponentEnum componentType)
{
	int i = 0;

	for (int idx = 0; i < components.size(); ++i)
	{
		if (components[i].first == componentType)
		{
			components.erase(components.begin() + idx);
			return;
		}
	}
}

void GameObject::update(char a)
{

}