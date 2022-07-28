#ifndef INC_2D_MANAGER_H
#define INC_2D_MANAGER_H

#include <vector>
#include <memory>
#include "System/Template/Object.h"

class Entity;

class Manager : public Object{

    std::vector<std::unique_ptr<Entity>> Entities;

public:
    void Init() override;
    void Destroy() override;
    void Update(double DeltaTime) override;
    void Draw() override;

    void Refresh();

    Entity& AddEntity();

};
#endif //INC_2D_MANAGER_H
