#ifndef INC_2D_TEXTUREMANAGER_H
#define INC_2D_TEXTUREMANAGER_H

class SDL_Texture;
class SDL_Renderer;
class SDL_Rect;

class TextureManager{
public:
    static SDL_Texture* LoadTexture(const char* FileName);
    static void Draw(SDL_Texture* Texture, SDL_Rect* SourceRect, SDL_Rect* DestRect);
};

#endif //INC_2D_TEXTUREMANAGER_H
