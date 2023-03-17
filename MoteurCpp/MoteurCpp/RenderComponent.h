#pragma once
#include "Component.h"
class RenderComponent :
    public Component
{
private:
    char render;

public:
    RenderComponent();

    RenderComponent(char c);

    char getRender();
};

