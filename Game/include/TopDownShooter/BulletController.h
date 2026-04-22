#pragma once
#include "Core/Component.h"
#include "Maths/Vector2.h"

class BulletController : public Component
{
public:
    BulletController(const Maths::Vector2f& dir, float speed)
        : direction(dir), speed(speed) {
    }

    void Update(float dt) override
    {
        lifetime -= dt;
        if (lifetime <= 0.f)
        {
            GetOwner()->MarkForDeletion();
            return;
        }

        auto pos = GetOwner()->GetPosition();
        pos.x += direction.x * speed * dt;
        pos.y += direction.y * speed * dt;
        GetOwner()->SetPosition(pos);
    }

private:
    Maths::Vector2f direction;
    float speed;
    float lifetime = 2.f;
};
