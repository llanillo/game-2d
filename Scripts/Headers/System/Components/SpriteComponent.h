#ifndef INC_2D_SPRITECOMPONENT_H
#define INC_2D_SPRITECOMPONENT_H

#include "../Template/Component.h"

class SDL_Texture;
class PositionComponent;
class SDL_Rect;

class SpriteComponent : public Component{

    PositionComponent* Position;
    SDL_Texture* Texture;
    SDL_Rect* SourceRect, *DestRect;

public:

    SpriteComponent();
    explicit SpriteComponent(const char* path);

    void Init() override;
    void Update(double DeltaTime) override;
    void Draw() override;

    void SetTexture(const char* path);
};

#endif //INC_2D_SPRITECOMPONENT_H
