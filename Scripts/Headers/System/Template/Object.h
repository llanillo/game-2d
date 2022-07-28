#ifndef INC_2D_OBJECT_H
#define INC_2D_OBJECT_H

class Object{

public:
    /*
     * Called when the object is created for the first time
     */
    virtual void Init() = 0;

    /*
     * Called every frame
     */
    virtual void Update(double DeltaTime) = 0;

    /*
     * Called every frame
     */
    virtual void Draw() = 0;

    /*
     * Called when the object is destroyed
     */
    virtual void Destroy() = 0;
};

#endif //INC_2D_OBJECT_H
