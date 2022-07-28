#ifndef INC_2D_MAP_H
#define INC_2D_MAP_H

class SDL_Rect;
class SDL_Texture;

const int MapWidth = 20;
const int MapHeight = 25;

class Map{
public:

    explicit Map(int Array[MapWidth][MapHeight]);
    ~Map();

    void Load(int Array[MapWidth][MapHeight]);
    void Draw();

private:
    const char* DirtTexturePath = "../Assets/Sprites/World/Map/Dirt.png";
    const char* GrassTexturePath = "../Assets/Sprites/World/Map/Grass.png";
    const char* WaterTexturePath = "../Assets/Sprites/World/Map/Water.png";

    SDL_Rect* SourceRect, *DestRect;
    SDL_Texture* DirtTexture, *GrassTexture, *WaterTexture;

    int MapArray[20][25] = {0};
};
#endif //INC_2D_MAP_H
