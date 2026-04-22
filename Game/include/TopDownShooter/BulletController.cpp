#include "BulletController.h"
#include "Core/GameObject.h"

BulletController::BulletController(const Maths::Vector2f& dir, float speed)
	: direction(dir), speed(speed)
{

}

void BulletController::Update(float dt)
{
	lifetime -= dt;
	if (lifetime <= 0.f)
	{
		GetOwner()->MarkForDeletion();
		return;
	}

	auto* owner = GetOwner();
	auto pos = owner->GetPosition();

	pos.x += direction.x * speed * dt;
	pos.y += direction.y * speed * dt;

	owner->GetPosition();
}