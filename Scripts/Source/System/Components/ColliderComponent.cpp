#include "System/Components/ColliderComponent.h"
#include "System/Components/TransformComponent.h"
#include "System/World/Core/Vector2D.h"
#include "System/Template/Entity.h"
#include "SDL.h"

void ColliderComponent::Init() {
    Component::Init();

    if (!Entity->HasComponent<TransformComponent>()) {
        Entity->AddComponent<TransformComponent>();
    }

    Transform = &Entity->GetComponent<TransformComponent>();
}

void ColliderComponent::Update(double DeltaTime) {
    Component::Update(DeltaTime);

    Collider->x = static_cast<int>(Transform->GetPosition()->X);
    Collider->y = static_cast<int>(Transform->GetPosition()->Y);
    Collider->w = Transform->GetWidth() * Transform->GetScale();
    Collider->h = Transform->GetHeight() * Transform->GetScale();
}

void ColliderComponent::Draw() {
    Component::Draw();
}

void ColliderComponent::Destroy() {
    Component::Destroy();
}
