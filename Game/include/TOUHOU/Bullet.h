#pragma once
#include "Component.h"
#include "RectangleShapeRenderer.h"
#include "Maths/Vector2.h"

class Bullet : public Component
{
public:
    Bullet(const Maths::Vector2f& direction, float speed, float radius);

    void Start() override;
    void Update(float dt) override;

private:
    Maths::Vector2f dir;
    float speed;
    float radius;

    RectangleShapeRenderer* renderer = nullptr;
};
