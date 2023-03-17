#include "GameObjectManager.h"

#include <iostream>

GameObjectManager* GameObjectManager::getInstance(const uint32_t poolSize)
{
	static GameObjectManager* gameObjectManager = new GameObjectManager(poolSize);
	return gameObjectManager;
}

GameObjectManager::GameObjectManager(const uint64_t& poolSize)
{
	poolGameObjects = std::vector<GameObject>(poolSize);
	poolTracker = std::vector<Tracker>(poolSize);
	for (unsigned int idx = 0; idx < poolSize; ++idx)
	{
		if (idx + 1 < poolSize)
		poolTracker[idx].nextFree = idx + 1;
	}
	currentFreeTracker = 0;
}

GameObjectManager::~GameObjectManager()
{
	poolGameObjects.clear();
	poolTracker.clear();
}

int GameObjectManager::allocateGameObject()
{
	if (currentFreeTracker == NULLPOSITION)
		return -1;

	int newAllocatedIdx = currentFreeTracker;
	poolGameObjects[newAllocatedIdx].active = true;
	currentFreeTracker = poolTracker[newAllocatedIdx].nextFree;
	poolTracker[newAllocatedIdx].nextFree = NULLPOSITION;
	return newAllocatedIdx;
}

int GameObjectManager::deallocateGameObject(const int id, const bool tracker)
{
	if (id < poolTracker.size() && id >= 0 && id != currentFreeTracker)
	{
		if (poolGameObjects[id].active)
		{
			poolGameObjects[id].active = false;
			updateTracker(id, tracker);
		}
	}
	return NULLPOSITION;
};

void GameObjectManager::updateTracker(const int id, const bool tracker)
{
	if (tracker)
		std::cout << "current tracker before process : " << currentFreeTracker << std::endl;
	if (id < currentFreeTracker || currentFreeTracker == NULLPOSITION)
	{
		const int oldFreeTrackerGameObjectPosition = currentFreeTracker;
		currentFreeTracker = id;
		poolTracker[currentFreeTracker].nextFree = oldFreeTrackerGameObjectPosition;
	}
	else
	{
		const int swapedTracker = poolTracker[currentFreeTracker].nextFree;
		poolTracker[currentFreeTracker].nextFree = id;
		poolTracker[id].nextFree = swapedTracker;
	}

	if (tracker)
	{
		auto fackTracker = currentFreeTracker;

		std::cout << "current tracker after process : " << currentFreeTracker << std::endl;
		while (fackTracker != NULLPOSITION)
		{
			std::cout << fackTracker << ", ";
			fackTracker = poolTracker[fackTracker].nextFree;
		}
		std::cout << std::endl;
	}

}

int GameObjectManager::addComponent(const int id,const ComponentEnum componentType, const int componentId)
{
	if (id >= poolGameObjects.size() || id < 0)
		return EXIT_FAILURE;

	GameObject gameObject = poolGameObjects[id];
	if (gameObject.hasComponent(componentType))
		return EXIT_FAILURE;

	gameObject.addComponent(componentType, componentId);
	return EXIT_SUCCESS;
}

int GameObjectManager::removeComponent(const int id, ComponentEnum enumComponent)
{
	if (id >= poolGameObjects.size() || id < 0)
		return EXIT_FAILURE;

	GameObject gameObject = poolGameObjects[id];
	gameObject.removeComponent(enumComponent);
}