#include "gun.h"
#include "GameObject.h"
#include "Bullet.h"
#include "QueueGlobal.h"
#include "Scene.h"
#include <cmath>

void BulletEmitter::Update(float dt)
{
    timer += dt;
    if (timer < fireRate)
        return;

    timer -= fireRate;

    const float twoPi = 6.28318530718f;

    GameObject* owner = GetOwner();
    Scene* scene = owner->GetScene();
    Maths::Vector2f origin = owner->GetPosition();

    if (!GCreateQueue)
        return;

    for (int i = 0; i < bulletCount; ++i)
    {
        float angle = twoPi * (float(i) / bulletCount);
        Maths::Vector2f dir(std::cos(angle), std::sin(angle));
        float speed = bulletSpeed;

        
        GCreateQueue->Enqueue([scene, origin, dir, speed]()
            {
                GameObject* bullet = scene->CreateGameObject("Bullet");
                bullet->SetPosition(origin);
                bullet->CreateComponent<Bullet>(dir, speed, 4.f);
            });
    }
}
