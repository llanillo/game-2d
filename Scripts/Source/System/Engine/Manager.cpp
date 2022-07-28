#include <algorithm>
#include "System/Engine/Manager.h"
#include "System/Template/Entity.h"

void Manager::Init() {

}

void Manager::Update(double DeltaTime){

    for(auto& Entity : Entities){
        Entity->Update(DeltaTime);
    }
}

void Manager::Draw() {
    for(auto& Entity : Entities){
        Entity->Draw();
    }
}

void Manager::Refresh(){
    Entities.erase(std::remove_if(std::begin(Entities), std::end(Entities), [](const std::unique_ptr<Entity> &MEntity){
        return !MEntity->IsActive();
    }),
    std::end(Entities));
}

Entity& Manager::AddEntity() {
    auto* Output = new Entity();
    std::unique_ptr<Entity> UniquePtr(Output);
    Entities.emplace_back(std::move(UniquePtr));
    return *Output;
}

void Manager::Destroy() {

}
