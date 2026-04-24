#pragma once
#include "Component.h"
#include "Maths/Vector2.h"

class BulletEmitter : public Component
{
public:
    float fireRate = 0.2f;
    float timer = 0.f;

    int bulletCount = 12;
    float bulletSpeed = 200.f;

    void Update(float dt) override;
};
