#pragma once
#include "GameObject.h"
#include <vector>

class GameObjectManager
{
public:
	static GameObjectManager* getInstance(const uint32_t poolSize);
	~GameObjectManager();

	int getNewGameObject();
	void destroyGameObject(const int id);
	void addComponent(const int id, Component* component);

private:
	GameObjectManager(const uint32_t& poolSize);
	GameObjectManager(const GameObjectManager& other) = delete;

	std::vector<GameObject*> poolGameObjects;
	std::vector<int> idPoolGameObjects;
	unsigned int garbageCounter;
	unsigned int idxFreePool;
	unsigned int idxFreeId;
};