#pragma once
#include <vector>
#include "GameObject.h"

class Updater
{
public:
	inline void addObject(GameObject* obj) { objects.push_back(obj); };

	virtual void update(char input) = 0;

protected:
	std::vector<GameObject*> objects;
};

