#include "Ennemies.h"
#include "Player.h"

#include "RectangleShapeRenderer.h"

Ennemies::Ennemies(const sf::Color _color, const Maths::Vector2i& _size) : color(_color), size(_size)
{

}

void Ennemies::Start()
{
    rectangle = GetOwner()->CreateComponent<RectangleShapeRenderer>();
    rectangle->SetColor(color);
    rectangle->SetSize(Maths::Vector2f(size.x, size.y));
}

void Ennemies::Update(float dt)
{

}
