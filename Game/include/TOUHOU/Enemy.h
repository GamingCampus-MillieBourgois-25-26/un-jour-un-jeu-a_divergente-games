#pragma once
#include "Component.h"
#include "RectangleShapeRenderer.h"
#include "Maths/Vector2.h"

class Enemy : public Component
{
public:
    float fireRate = 0.5f;
    float timer = 0.f;

    int bulletCount = 16;
    float bulletSpeed = 150.f;

    void Start() override;
    void Update(float dt) override;

private:
    RectangleShapeRenderer* renderer = nullptr;
};
