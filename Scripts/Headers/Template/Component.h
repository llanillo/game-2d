#ifndef INC_2D_COMPONENT_H
#define INC_2D_COMPONENT_H

#include "Template/Object.h"

class Entity;

class Component : Object{

public:
    Entity* Entity;

    void Update() override {}
    void Init() override {};
    void Draw() override {};

    virtual ~Component() = default;

};
#endif //INC_2D_COMPONENT_H
