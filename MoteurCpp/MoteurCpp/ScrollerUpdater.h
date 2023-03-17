#pragma once
#include "IUpdater.h"
class ScrollerUpdater :
    public IUpdater
{
private:
	static ScrollerUpdater singleton;


public:
	ScrollerUpdater() {};

	static ScrollerUpdater* Instance()
	{
		static ScrollerUpdater* singleton = new ScrollerUpdater();
		return singleton;
	}

	void update();
};

