#pragma once
#include "Updater.h"
class ObstacleSpawner :
    public Updater
{
public:
    virtual void update(char input);

protected:
    int spawnMax = 4;
};

