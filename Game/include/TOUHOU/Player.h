#pragma once
#include "Component.h"
#include "RectangleShapeRenderer.h"
#include "Maths/Vector2.h"

class Player : public Component
{
public:
    float speed = 250.f;
    float radius = 8.f;

    void Start() override;
    void Update(float dt) override;

private:
    RectangleShapeRenderer* renderer = nullptr;
};
