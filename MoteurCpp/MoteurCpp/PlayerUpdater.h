#pragma once
#include "IUpdater.h"
class PlayerUpdater :
    public IUpdater
{

private:
	static PlayerUpdater singleton;



public:
	PlayerUpdater() {};

	static PlayerUpdater Instance()
	{
		static PlayerUpdater singleton = PlayerUpdater();
		return singleton;
	}

	void update();
};

