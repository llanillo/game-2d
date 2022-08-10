#include "System/Components/PositionComponent.h"

PositionComponent::PositionComponent() {
    XPos = 0;
    YPos = 0;
}

PositionComponent::PositionComponent(int X, int Y) {
    XPos = X;
    YPos = Y;
}

void PositionComponent::Init() {
    Component::Init();
    XPos = 0;
    YPos = 0;
}

void PositionComponent::SetPos(int X, int Y){
    XPos = X;
    YPos = Y;
}

void PositionComponent::Update(double DeltaTime) {
    Component::Update(DeltaTime);
    XPos++;
    YPos++;
}
