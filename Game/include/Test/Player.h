#pragma once
#include "Component.h"
#include "InputModule.h"
#include "RectangleShapeRenderer.h"

namespace Test
{
    class Player : public Component
    {
    public:
        Player(sf::Color _color, const Maths::Vector2i& _size);
        void Start();

        void Update(const float _delta_time) override
        {
            Maths::Vector2<float> position = GetOwner()->GetPosition();

            if (InputModule::GetKey(sf::Keyboard::Key::D))
            {
                position.x += speed * _delta_time;
            }
            if (InputModule::GetKey(sf::Keyboard::Key::Q))
            {
                position.x -= speed * _delta_time;
            }

            if (InputModule::GetKey(sf::Keyboard::Key::Z))
            {
                position.y -= speed * _delta_time;
            }
            if (InputModule::GetKey(sf::Keyboard::Key::S))
            {
                position.y += speed * _delta_time;
            }

            GetOwner()->SetPosition(position);

            if (InputModule::GetKeyDown(sf::Keyboard::Key::Escape))
            {
                Engine::GetInstance()->RequestQuit();
            }
        }

        float speed = 100.0f;
        int health = 10;

    private:
        RectangleShapeRenderer* rectangle = nullptr;
        sf::Color color;
        Maths::Vector2i size;


     
    };
}

