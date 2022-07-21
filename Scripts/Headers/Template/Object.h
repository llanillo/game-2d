#ifndef INC_2D_OBJECT_H
#define INC_2D_OBJECT_H

#include <algorithm>

using ComponentId = std::size_t;

class Object{

public:
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Destroy() = 0;

    template <typename T> inline ComponentId GetComponentId() noexcept{
        static ComponentId LastId = 0;
        return LastId++;
    }

    inline ComponentId GetComponentId(){
        static ComponentId TypeId = GetComponentId();
        return TypeId;
    }
};

#endif //INC_2D_OBJECT_H
