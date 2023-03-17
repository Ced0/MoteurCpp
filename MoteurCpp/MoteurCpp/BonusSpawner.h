#pragma once
#include "Updater.h"
class BonusSpawner :
    public Updater
{
public:
    void update(char input);

protected:
    int spawnMax = 4;
};

