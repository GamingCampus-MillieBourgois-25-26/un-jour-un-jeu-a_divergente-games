#include "PlayerController.h"
#include "Core/GameObject.h"
#include "Core/Scene.h"
#include "Maths/Vector2.h"
#include "WindowModule.h"
#include "BulletController.h"
#include "Modules/InputModule.h"
#include "Components/ARenderedComponent.h"
#include "Components/RectangleShapeRenderer.h"

#include <SFML/System/Angle.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cmath>
#include <iostream>

void PlayerController::Update(float dt)
{
    if (!layoutDetected)
    {
        DetectKeyboardLayout();
        return; 
    }

    ApplyMovement(dt);
    ApplyRotation();
}

void PlayerController::DetectKeyboardLayout()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
    {
        std::cout << "Layout detecte : AZERTY\n";
        keyUp = sf::Keyboard::Key::Z;
        keyDown = sf::Keyboard::Key::S;
        keyLeft = sf::Keyboard::Key::Q;
        keyRight = sf::Keyboard::Key::D;
        layoutDetected = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        std::cout << "Layout detecte : QWERTY\n";
        keyUp = sf::Keyboard::Key::W;
        keyDown = sf::Keyboard::Key::S;
        keyLeft = sf::Keyboard::Key::A;
        keyRight = sf::Keyboard::Key::D;
        layoutDetected = true;
    }
}

void PlayerController::ApplyMovement(float dt)
{
    auto* owner = GetOwner();

    float x = 0.f;
    float y = 0.f;

    if (sf::Keyboard::isKeyPressed(keyUp))    y -= 1.f;
    if (sf::Keyboard::isKeyPressed(keyDown))  y += 1.f;
    if (sf::Keyboard::isKeyPressed(keyLeft))  x -= 1.f;
    if (sf::Keyboard::isKeyPressed(keyRight)) x += 1.f;

    float len = std::sqrt(x * x + y * y);
    if (len > 0.f)
    {
        x /= len;
        y /= len;
    }

    float speed = config->playerSpeed;
    Maths::Vector2f pos = owner->GetPosition();
    pos.x += x * speed * dt;
    pos.y += y * speed * dt;

    owner->SetPosition(pos);
}

void PlayerController::ApplyRotation()
{
    auto* owner = GetOwner();

   
    Maths::Vector2f pos = owner->GetPosition();

    auto* windowModule = Component::GetModule<WindowModule>();
    sf::RenderWindow* window = windowModule->GetWindow();

    sf::Vector2i mouse = sf::Mouse::getPosition(*window);

    float dx = mouse.x - pos.x;
    float dy = mouse.y - pos.y;

    float angleRad = std::atan2(dy, dx);
    float angleDeg = angleRad * 180.f / 3.14159265f;

    owner->SetRotation(sf::degrees(angleDeg));
}

void PlayerController::Shoot()
{
    Scene* scene = GetOwner()->GetScene();

    GameObject* bullet = scene->CreateGameObject("Bullet");
    bullet->SetPosition(GetOwner()->GetPosition());

    
    Maths::Vector2f pos = GetOwner()->GetPosition();

   
    Maths::Vector2i mouse = InputModule::GetMousePosition();
    Maths::Vector2f mouseF(mouse.x, mouse.y);

    
    Maths::Vector2f dir(mouseF.x - pos.x, mouseF.y - pos.y);
    float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    dir.x /= len;
    dir.y /= len;

    
    auto* renderer = bullet->CreateComponent<RectangleShapeRenderer>();
    renderer->SetColor(sf::Color::Red);
    renderer->SetSize({ 8.f, 8.f });

    
    bullet->CreateComponent<BulletController>(dir, 600.f);
}