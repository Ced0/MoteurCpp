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
	static GameObjectManager* getInstance(const uint32_t poolSize);

	int allocateGameObject();
	int deallocateGameObject(const int id, const bool tracker);
	int addComponent(const int id, ComponentEnum enumComponent, const int componentId);
	int removeComponent(const int id, ComponentEnum enumComponent);

private:
	GameObjectManager(const uint64_t& poolSize);
	GameObjectManager(const GameObjectManager& other) = delete;
	~GameObjectManager();

	void operator=(const GameObjectManager&) = delete;

	void updateTracker(const int id, const bool tracker);

	std::vector<GameObject> poolGameObjects;
	std::vector<Tracker> poolTracker;
	int currentFreeTracker;
};