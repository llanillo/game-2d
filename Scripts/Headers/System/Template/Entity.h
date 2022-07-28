#ifndef INC_2D_ENTITY_H
#define INC_2D_ENTITY_H

#include <vector>
#include <memory>
#include <bitset>
#include "System/Template/Component.h"

constexpr std::size_t MaxComponents = 32;

using ComponentArray = std::array<Component*, MaxComponents>;
using ComponentBitSet = std::bitset<MaxComponents>;

class Entity : public Object{

private:
    bool bIsActive = false;

    std::vector<std::unique_ptr<Component>> Components;

    ComponentArray ComponentArray;
    ComponentBitSet ComponentBitSet;

public:

    void Init() override;
    void Update(double DeltaTime) override;
    void Draw() override;
    void Destroy() override;

    template <typename T> bool HasComponent() const{
        return ComponentBitSet[Component::GetComponentTypeId<T>()];
    }

    template <typename T, typename... TArgs> T& AddComponent(TArgs&&... Args){
        T* ComponentType (new T(std::forward<TArgs>(Args)...));
        ComponentType->Entity = this;

        std::unique_ptr<Component> UniquePtr (ComponentType);
        Components.emplace_back(std::move(UniquePtr));
        ComponentArray[Component::GetComponentTypeId<T>()] = ComponentType;
        ComponentBitSet[Component::GetComponentTypeId<T>()] = true;
        ComponentType->Init();
        return *ComponentType;
    }

    template <typename T> T& GetComponent() const{
        auto Pointer(ComponentArray[Component::GetComponentTypeId<T>()]);
        return *static_cast<T*>(Pointer);
    }

    inline bool IsActive() const { return bIsActive; };
};

#endif //INC_2D_ENTITY_H
