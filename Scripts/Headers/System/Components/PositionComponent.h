#ifndef INC_2D_POSITIONCOMPONENT_H
#define INC_2D_POSITIONCOMPONENT_H

#include "System/Template/Component.h"

/*
 * Component for entity's position in world
 */
class PositionComponent: public Component{

    int XPos = 0;
    int YPos = 0;

public:

    PositionComponent();
    PositionComponent(int X, int Y);

    void Init() override;
    void Update(double DeltaTime) override;

public:

    /*
     * Set entity position
     */
    void SetPos(int X, int Y);

    /*
     * Return X position
     */
    inline int GetXPos() const { return XPos; };

    /*
     * Return Y position
     */
    inline int GetYPos() const { return YPos; };
};

#endif //INC_2D_POSITIONCOMPONENT_H
