#ifndef INC_2D_COLLIDERCOMPONENT_H
#define INC_2D_COLLIDERCOMPONENT_H

#include <System/Template/Component.h>
#include <string>

class SDL_Rect;
class TransformComponent;

class ColliderComponent : public Component{

    SDL_Rect* Collider;

    TransformComponent* Transform;

    std::string Tag;

public:

    void Update(double DeltaTime) override;

    void Init() override;

    void Draw() override;

    void Destroy() override;

    ~ColliderComponent() override = default;
};


#endif //INC_2D_COLLIDERCOMPONENT_H
