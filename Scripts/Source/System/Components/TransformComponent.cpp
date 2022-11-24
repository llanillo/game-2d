#include "System/Components/TransformComponent.h"
#include "System/World/Core/Vector2D.h"

const int TransformComponent::Size = 32;

TransformComponent::TransformComponent() {
    Position->X = 0.f;
    Position->Y = 0.f;
}

TransformComponent::TransformComponent(float X, float Y) {
    Position->X = X;
    Position->Y = Y;
}

void TransformComponent::Init() {
    Component::Init();

    Width = Size;
    Height = Size;
    Scale = 1;
    Speed = 3.f;
    Position->X = 0;
    Position->Y = 0;
}

void TransformComponent::Update(double DeltaTime) {
    Component::Update(DeltaTime);
    Position->X += Velocity->X * Speed;
    Position->Y += Velocity->Y * Speed;
}
