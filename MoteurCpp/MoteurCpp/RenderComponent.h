#pragma once
#include "Component.h"

class RenderComponent :
    public Component
{
private:
    char render;
    bool active;

public:
    RenderComponent(int ogId);

    RenderComponent(char c, int ogId);

    ~RenderComponent() {};

    bool isActive();

    void setIsActive(bool active);

    char getRender();
};

