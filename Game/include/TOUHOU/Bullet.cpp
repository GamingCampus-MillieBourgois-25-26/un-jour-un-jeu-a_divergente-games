#include "Bullet.h"
#include "GameObject.h"
#include <cmath>

Bullet::Bullet(const Maths::Vector2f& direction, float speed, float radius)
    : dir(direction), speed(speed), radius(radius)
{
}

void Bullet::Start()
{
    renderer = GetOwner()->CreateComponent<RectangleShapeRenderer>();
    renderer->SetColor(sf::Color::Yellow);
    renderer->SetSize(Maths::Vector2f(radius * 2, radius * 2));
}

void Bullet::Update(float dt)
{
    Maths::Vector2f pos = GetOwner()->GetPosition();
    pos += dir * speed * dt;
    GetOwner()->SetPosition(pos);

    if (pos.x < -50 || pos.x > 900 || pos.y < -50 || pos.y > 700)
    {
        GetOwner()->MarkForDeletion();
    }
}
