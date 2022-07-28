#include "System/Template/Entity.h"

void Entity::Init(){

}

void Entity::Update(double DeltaTime) {
    for(auto& Component: Components){
        Component->Update(DeltaTime);
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