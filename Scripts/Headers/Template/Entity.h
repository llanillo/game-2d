#ifndef INC_2D_ENTITY_H
#define INC_2D_ENTITY_H

#include <vector>
#include <memory>
#include <bitset>
#include "Template/Object.h"

class Component;

constexpr std::size_t MaxComponents = 32;

using ComponentArray = std::array<Component*, MaxComponents>;
using ComponentBitSet = std::bitset<MaxComponents>;

class Entity : Object{

private:
    bool bIsActive = false;

    std::vector<std::unique_ptr<Component>> Components;

    ComponentArray ComponentArray;
    ComponentBitSet ComponentBitSet;

public:

    void Init() override;
    void Update() override;
    void Draw() override;
    void Destroy() override;

    template <typename T> bool HasComponent() const;

    inline bool IsActive() const { return bIsActive; };
};
#endif //INC_2D_ENTITY_H
