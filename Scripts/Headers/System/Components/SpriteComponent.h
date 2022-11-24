#ifndef INC_2D_SPRITECOMPONENT_H
#define INC_2D_SPRITECOMPONENT_H

#include "../Template/Component.h"

class SDL_Texture;
class TransformComponent;
class SDL_Rect;

class SpriteComponent : public Component{

    TransformComponent* Transform;
    SDL_Texture* Texture;
    SDL_Rect* SourceRect;
    SDL_Rect *DestRect;

public:

    SpriteComponent();

    explicit SpriteComponent(const char* path);

    void Init() override;

    void Update(double DeltaTime) override;

    void Draw() override;

    void SetTexture(const char* path);

    void Destroy() override;

    ~SpriteComponent() override;
};

#endif //INC_2D_SPRITECOMPONENT_H
