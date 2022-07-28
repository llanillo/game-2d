#ifndef INC_2D_GAMEOBJECT_H
#define INC_2D_GAMEOBJECT_H

#include "System/Template/Object.h"

class SDL_Renderer;
class SDL_Texture;
class SDL_Rect;

class GameObject : public Object{

public:
    GameObject(const char* TextureSheet, int X, int Y);
    ~GameObject();

    void Init() override;
    void Draw() override;
    void Destroy() override;
    void Update(double DeltaTime) override;

private:
    int XPos;
    int YPos;

    SDL_Texture* Texture;
    SDL_Rect* SourceRect, *DestRect;
};

#endif //INC_2D_GAMEOBJECT_H
