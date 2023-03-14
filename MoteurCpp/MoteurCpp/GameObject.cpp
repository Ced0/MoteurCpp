#include "GameObject.h"

GameObject::~GameObject()
{
	for (int i = 0; i < components.size(); i++)
	{
		delete components[i];
	}
}

Component* GameObject::getComponent(std::string type)
{
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->getType() == type)
		{
			return components[i];
		}
	}

	return NULL;
}

void GameObject::addComponent(Component* componentAdded)
{
	for (auto& const component : components)
	{
		if (component->getType() == componentAdded->getType())
			return;
	}

	components.push_back(componentAdded);
}

void GameObject::update(char a)
{

}