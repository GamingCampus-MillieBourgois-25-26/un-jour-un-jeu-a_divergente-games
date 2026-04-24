#include "Player.h"
#include "InputModule.h"
#include "Bullet.h"
#include "GameObject.h"
#include "Scene.h"
#include <cmath>

inline Maths::Vector2f Normalize(const Maths::Vector2f& v)
{
    float len = std::sqrt(v.x * v.x + v.y * v.y);
    if (len == 0) return Maths::Vector2f(0, 0);
    return Maths::Vector2f(v.x / len, v.y / len);
}


void Player::Start()
{
    renderer = GetOwner()->CreateComponent<RectangleShapeRenderer>();
    renderer->SetColor(sf::Color::Cyan);
    renderer->SetSize(Maths::Vector2f(radius * 2, radius * 2));
}

void Player::Update(float dt)
{
    Maths::Vector2f pos = GetOwner()->GetPosition();
    Maths::Vector2f move(0, 0);

    if (InputModule::GetKey(sf::Keyboard::Key::Z)) move.y -= 1;
    if (InputModule::GetKey(sf::Keyboard::Key::S)) move.y += 1;
    if (InputModule::GetKey(sf::Keyboard::Key::Q)) move.x -= 1;
    if (InputModule::GetKey(sf::Keyboard::Key::D)) move.x += 1;

    if (move.x != 0 || move.y != 0)
        move = Normalize(move) * speed * dt;

    pos += move;
    GetOwner()->SetPosition(pos);

    // Tir
    if (InputModule::GetMouseButtonDown(sf::Mouse::Button::Left))
    {
        Maths::Vector2i mouse = InputModule::GetMousePosition();
        Maths::Vector2f dir = Normalize(Maths::Vector2f(mouse.x, mouse.y) - pos);

        GameObject* bullet = GetOwner()->GetScene()->CreateGameObject("PlayerBullet");
        bullet->SetPosition(pos);
        bullet->CreateComponent<Bullet>(dir, 400.f, 4.f);
    }
}

