#ifndef INC_2D_TEXTUREMANAGER_H
#define INC_2D_TEXTUREMANAGER_H

class SDL_Texture;
class SDL_Renderer;

class TextureManager{
public:
    static SDL_Texture* LoadTexture(const char* FileName, SDL_Renderer* Renderer);
};

#endif //INC_2D_TEXTUREMANAGER_H
