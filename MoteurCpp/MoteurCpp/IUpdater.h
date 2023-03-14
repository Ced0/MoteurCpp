#pragma once


class IUpdater
{
public:
	IUpdater() {};

	virtual ~IUpdater() = 0;

	virtual void SystemUpdate() = 0;
};


