#pragma once
#include "Updater.h"
class Scroller :
    public Updater
{
public:
    virtual void update(char input);
};

