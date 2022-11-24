#ifndef INC_2D_KEYBOARDCONTROLLER_H
#define INC_2D_KEYBOARDCONTROLLER_H

#include "System/Template/Component.h"

class TransformComponent;

class KeyboardController : public Component{

public:

    TransformComponent* Transform;

    void Update(double DeltaTime) override;

    void Init() override;

    void Draw() override;

    void Destroy() override;

    virtual ~KeyboardController() override;
};


#endif //INC_2D_KEYBOARDCONTROLLER_H
