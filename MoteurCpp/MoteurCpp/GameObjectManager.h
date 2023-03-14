#pragma once
#include <vector>

constexpr int MAX_DEGRAMENTATION_POOL = 25;

template<typename T>
class GameObjectManager
{
public:
	static GameObjectManager* getInstance(const uint32_t poolSize);
	
	int getNewGameObject();
	void destroyGameObject(const int id);
	void addComponent(const int id, T* component);
	void defragmentation();

private:
	~GameObjectManager();

	GameObjectManager(const uint32_t& poolSize);
	GameObjectManager(const GameObjectManager& other) = delete;
	void operator=(const GameObjectManager&) = delete;

	std::vector<T*> poolGameObjects;
	std::vector<int> idPoolGameObjects;
	unsigned int garbageCounter;
	unsigned int idxFreePool;
	unsigned int idxFreeId;
};

template<typename T>
GameObjectManager<T>* GameObjectManager<T>::getInstance(const uint32_t poolSize)
{
	static GameObjectManager* gameObjectManager = new GameObjectManager(poolSize);
	return gameObjectManager;
}

template<typename T>
GameObjectManager<T>::GameObjectManager(const uint32_t& poolSize)
{
	poolGameObjects = std::vector<GameObject*>(poolSize, nullptr);
	idPoolGameObjects = std::vector<int>(poolSize, -1);
	garbageCounter = 0;
	idxFreePool = 0;
	idxFreeId = 0;
}

template<typename T>
GameObjectManager<T>::~GameObjectManager()
{
	const int poolSize = poolGameObjects.size();

	for (size_t idx = 0; idx < poolSize; ++idx)
	{
		delete poolGameObjects[idx];
		poolGameObjects[idx] = nullptr;
		idPoolGameObjects[idx] = NULL;
	}
}

template<typename T>
int GameObjectManager<T>::getNewGameObject()
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

	poolGameObjects
}

template<typename T>
void GameObjectManager<T>::defragmentation()
{

}

template<typename T>
void GameObjectManager<T>::destroyGameObject(const int id)
{
	if (id >= idPoolGameObjects.size() || id < 0)
		return;

	const int idxId = idPoolGameObjects[id];

	if (idxId < 0)
		return;

	delete poolGameObjects[idxId];
	poolGameObjects[idxId] = nullptr;
	idPoolGameObjects[id] = -1;

	if (++garbageCounter == MAX_DEGRAMENTATION_POOL)
	{
		defragmentation();
	}
};

template<typename T>
void GameObjectManager<T>::addComponent(const int id, T* component)
{
	if (id >= idPoolGameObjects.size() || id < 0)
		return;

	const int idxId = idPoolGameObjects[id];
	auto gameObject = poolGameObjects[idxId];
	gameObject->addComponent(component);
}