#pragma once
#include <vector>
#include "Component.h"
#include "GameObject.h"

constexpr int NULLPOSITION = -1;

class GameObjectManager
{
	struct Tracker
	{
		int nextFree = NULLPOSITION;
	};

public:
	static GameObjectManager* getInstance();
	void init(const uint64_t& poolSize);
	int allocateGameObject();
	int deallocateGameObject(const int id, const bool tracker);
	int addComponent(const int id, ComponentEnum componentType, const int componentId);
	int removeComponent(const int id, ComponentEnum componentType);
	bool hasComponent(const int id, ComponentEnum componentType);
	int getComponent(const int id, ComponentEnum componentType);

private:
	GameObjectManager();
	GameObjectManager(const GameObjectManager& other) = delete;
	~GameObjectManager();

	void operator=(const GameObjectManager&) = delete;

	void updateTracker(const int id, const bool tracker);

	std::vector<GameObject> poolGameObjects;
	std::vector<Tracker> poolTracker;
	int currentFreeTracker;
};