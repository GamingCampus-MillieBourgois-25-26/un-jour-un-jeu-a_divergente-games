#pragma once
#include "Component.h"
#include "RectangleShapeRenderer.h"

class Ennemies : public Component
{
public:
    Ennemies(sf::Color _color, const Maths::Vector2i& _size);

    void Start() override;
    void Update(float _delta_time) override;

private:

    RectangleShapeRenderer* rectangle = nullptr;
    sf::Color color;
    Maths::Vector2i size;
    int health = 5;
    float speed = 50.0f;

};

