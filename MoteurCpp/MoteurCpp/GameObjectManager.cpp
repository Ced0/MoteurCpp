#include "GameObjectManager.h"

GameObjectManager* GameObjectManager::getInstance(const uint32_t poolSize)
{
	static GameObjectManager* gameObjectManager = new GameObjectManager(poolSize);
	return gameObjectManager;
}

GameObjectManager::GameObjectManager(const uint32_t& poolSize)
{
	poolGameObjects = std::vector<GameObject*>(poolSize, nullptr);
	idPoolGameObjects = std::vector<int>(poolSize, -1);
	garbageCounter = 0;
	idxFreePool = 0;
	idxFreeId = 0;
}

GameObjectManager::~GameObjectManager()
{
	const int poolSize = poolGameObjects.size();

	for (size_t idx = 0; idx < poolSize; ++idx)
	{
		delete poolGameObjects[idx];
		poolGameObjects[idx] = nullptr;
		idPoolGameObjects[idx] = NULL;
	}
}

int GameObjectManager::getNewGameObject()
{
	while (idxFreePool < poolGameObjects.size() && poolGameObjects[idxFreePool] != nullptr)
	{
		++idxFreePool;
	}

	while (idxFreeId < idPoolGameObjects.size() && idPoolGameObjects[idxFreeId] != -1)
	{
		++idxFreeId;
	}

	if (idxFreePool >= poolGameObjects.size() || idxFreeId >= idPoolGameObjects.size())
		return -1;

	poolGameObjects[idxFreePool] = new GameObject();
	idPoolGameObjects[idxFreeId] = idxFreePool;
	return idxFreeId;
}

void GameObjectManager::destroyGameObject(const int id)
{
	if (id >= idPoolGameObjects.size() || id < 0)
		return;

	const int idxId = idPoolGameObjects[id];

	if (idxId < 0)
		return;

	delete poolGameObjects[idxId];
	poolGameObjects[idxId] = nullptr;
	idPoolGameObjects[id] = -1;
};

void GameObjectManager::addComponent(const int id, Component* component)
{
	if (id >= idPoolGameObjects.size() || id < 0)
		return;

	const int idxId = idPoolGameObjects[id];
	auto gameObject = poolGameObjects[idxId];
	gameObject->addComponent(component);
}