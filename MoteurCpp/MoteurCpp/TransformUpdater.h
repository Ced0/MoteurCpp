#pragma once
#include "IUpdater.h"


class TransformUpdater : public IUpdater
{
private:
	static TransformUpdater singleton;
	


public:
	TransformUpdater() {};

	static TransformUpdater Instance()
	{
		static TransformUpdater singleton = TransformUpdater();
		return singleton;
	}

	void update();
};

