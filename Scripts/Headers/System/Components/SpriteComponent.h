#ifndef INC_2D_SPRITECOMPONENT_H
#define INC_2D_SPRITECOMPONENT_H

#include "../Template/Component.h"

class SDL_Texture;
class PositionComponent;
class SDL_Rect;

class SpriteComponent : public Object{

    PositionComponent* Position;
    SDL_Texture* Texture;
    SDL_Rect* SourceRect, *DestRect;

public:

    SpriteComponent() = default;
    SpriteComponent(const char* path);

    ~SpriteComponent() = default;

};

#endif //INC_2D_SPRITECOMPONENT_H
