#include "Player.h"

Player::Player()
    :health(20),damage(5),speed(200.f)
{

}

void Player::Update(float dt)
{
   
    Move(dt);
    applyRotation(dt);
    if (InputModule::GetKeyDown(sf::Keyboard::Key::Escape))
    {
        Engine::GetInstance()->RequestQuit();
    }
}

void Player::Move(float dt)
{
    Maths::Vector2<float> position = GetOwner()->GetPosition();

    if (InputModule::GetKey(sf::Keyboard::Key::D))
    {
        position.x += speed * dt;
    }
    if (InputModule::GetKey(sf::Keyboard::Key::Q))
    {
        position.x -= speed * dt;
    }

    if (InputModule::GetKey(sf::Keyboard::Key::Z))
    {
        position.y -= speed * dt;
    }
    if (InputModule::GetKey(sf::Keyboard::Key::S))
    {
        position.y += speed * dt;
    }

    GetOwner()->SetPosition(position);
}

void Player::applyRotation(float dt)
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

void Player::shoot() 
{


}

sf::Vector2f Player::GetPosition()
{
    return position;
}