#pragma once
#include "Component.h"

class RenderComponent :
    public Component
{
private:
    char render;
    bool active;

public:
    RenderComponent();

    RenderComponent(char c);

    ~RenderComponent() {};

    bool isActive();

    void setIsActive(bool active);

    char getRender();
};

