#pragma once
#include "AsciiObject.h"
class Player :
    public AsciiObject
{
public:
    Player(char c, glm::vec2 pos = glm::vec2());

    virtual void update(char a);

};

