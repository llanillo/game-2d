#include "Template/Entity.h"
#include "Template/Component.h"

void Entity::Init(){

}

void Entity::Update(){
    for(auto& Component: Components){
        Component->Update();
    }
}

void Entity::Draw(){
    for(auto& Component : Components){
        Component->Draw();
    }
}

void Entity::Destroy(){
    bIsActive = false;
}

template <typename T> bool Entity::HasComponent() const{
    return ComponentBitSet[GetComponentId<T>()];
}