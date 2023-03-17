#pragma once
#include "IUpdater.h"
class RenderUpdater :
    public IUpdater
{
private:
	static RenderUpdater singleton;



public:
	RenderUpdater() {};

	static RenderUpdater Instance()
	{
		static RenderUpdater singleton = RenderUpdater();
		return singleton;
	}

	void update();
};

