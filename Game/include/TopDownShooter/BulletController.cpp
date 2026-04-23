#include "BulletController.h"
#include "Core/GameObject.h"
#include "WindowModule.h"

BulletController::BulletController(const Maths::Vector2f& dir, float speed)
	: direction(dir), speed(speed)
{

}

void BulletController::Update(float dt)
{
    if (!GetOwner()->IsEnabled())
        return;

 
    auto* windowModule = Component::GetModule<WindowModule>();
    sf::RenderWindow* window = windowModule->GetWindow();
    sf::Vector2u size = window->getSize();

    auto pos = GetOwner()->GetPosition();
    if (pos.x < 0 || pos.x > size.x ||
        pos.y < 0 || pos.y > size.y)
    {
        GetOwner()->Destroy();
        return;
    }

    pos.x += direction.x * speed * dt;
    pos.y += direction.y * speed * dt;

    GetOwner()->SetPosition(pos);
}