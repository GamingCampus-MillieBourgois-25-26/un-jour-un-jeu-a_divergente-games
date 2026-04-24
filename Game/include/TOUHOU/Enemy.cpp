#include "Enemy.h"
#include "Bullet.h"
#include "GameObject.h"
#include "Scene.h"
#include <cmath>

void Enemy::Start()
{
    renderer = GetOwner()->CreateComponent<RectangleShapeRenderer>();
    renderer->SetColor(sf::Color::Red);
    renderer->SetSize(Maths::Vector2f(20.f, 20.f));
}

void Enemy::Update(float dt)
{
    timer += dt;
    if (timer < fireRate)
        return;

    timer -= fireRate;

    const float twoPi = 6.28318530718f;
    Maths::Vector2f origin = GetOwner()->GetPosition();

    for (int i = 0; i < bulletCount; ++i)
    {
        float angle = twoPi * (float(i) / bulletCount);
        Maths::Vector2f dir(std::cos(angle), std::sin(angle));

        GameObject* bullet = GetOwner()->GetScene()->CreateGameObject("EnemyBullet");
        bullet->SetPosition(origin);
        bullet->CreateComponent<Bullet>(dir, bulletSpeed, 4.f);
    }
}
