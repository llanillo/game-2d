#ifndef INC_2D_COMPONENT_H
#define INC_2D_COMPONENT_H

#include <algorithm>
#include "Object.h"

class Entity;

using ComponentId = std::size_t;

class Component : Object{

public:
    Entity* Entity;

    void Update(double DeltaTime) override {};
    void Init() override {};
    void Draw() override {};
    void Destroy() override {}

public:
    virtual ~Component() = default;

    static inline ComponentId GetComponentId(){
        static ComponentId LastId = 0;
        return LastId++;
    }

    template <typename T> static inline ComponentId GetComponentTypeId() noexcept{
        static ComponentId TypeId = GetComponentId();
        return TypeId++;
    }
};
#endif //INC_2D_COMPONENT_H
