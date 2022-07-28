#include "System/Components/PositionComponent.h"

void PositionComponent::Init() {
    Component::Init();
    XPos = 0;
    YPos = 0;
}

void PositionComponent::Update(double DeltaTime) {
    Component::Update(DeltaTime);
    YPos++;
    XPos++;
}

void PositionComponent::SetPos(int X, int Y){
    XPos = X;
    YPos = Y;
}