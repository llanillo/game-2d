#include <algorithm>
#include "System/Engine/EntityManager.h"
#include "System/Template/Entity.h"

void EntityManager::Init() {
    for(auto& Entity : Entities){
        Entity->Init();
    }
}

void EntityManager::Update(double DeltaTime){
    for(auto& Entity : Entities){
        Entity->Update(DeltaTime);
    }
}

void EntityManager::Draw() {
    for(auto& Entity : Entities){
        Entity->Draw();
    }
}

void EntityManager::Refresh(){
    Entities.erase(std::remove_if(std::begin(Entities), std::end(Entities), [](const std::unique_ptr<Entity> &MEntity){
        return !MEntity->IsActive();
    }), std::end(Entities));
}

Entity& EntityManager::AddEntity() {
    auto* Output = new Entity();
    std::unique_ptr<Entity> UniquePtr{Output};
    Entities.emplace_back(std::move(UniquePtr));
    return *Output;
}

void EntityManager::Destroy() {
    for(auto& Entity : Entities){
        Entity->Destroy();
    }
}
