#pragma once
#include "IUpdater.h"

class SpawnerUpdater :
    public IUpdater
{
private:
	static SpawnerUpdater singleton;



public:
	SpawnerUpdater() {};

	static SpawnerUpdater* Instance()
	{
		static SpawnerUpdater* singleton = new SpawnerUpdater();
		return singleton;
	}

	void update();
};
