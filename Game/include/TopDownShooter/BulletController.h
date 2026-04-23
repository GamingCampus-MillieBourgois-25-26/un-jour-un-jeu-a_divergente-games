#pragma once
#include "Core/Component.h"
#include "Maths/Vector2.h"

class BulletController : public Component
{
public:
    BulletController(const Maths::Vector2f& dir, float speed);
   
    void Update(float dt) override;
    

private:
    Maths::Vector2f direction;
    float speed;
    

    
};
