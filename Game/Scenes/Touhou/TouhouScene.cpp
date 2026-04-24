#include "TouhouScene.h"
#include "Engine.h"
#include "ModuleManager.h"
#include "AssetsModule.h"
#include "WindowModule.h"
#include "SpriteRenderer.h"
#include "RectangleShapeRenderer.h"

#include "Touhou/Player.h"
#include "Touhou/Enemy.h"
#include "Touhou/Bullet.h"

#include "Touhou/QueueGlobal.h"   

TouhouScene::TouhouScene()
    : Scene("TouhouScene")
{
   
    GCreateQueue = &createQueue;

    auto* assets = Engine::GetInstance()
        ->GetModuleManager()
        ->GetModule<AssetsModule>();

    Texture* playerTex = assets->LoadAsset<Texture>("playerShip2_red.png");
    Texture* enemyTex = assets->LoadAsset<Texture>("enemyBlack3.png");

    
    GameObject* player = CreateGameObject("Player");
    player->SetPosition({ 400.f, 500.f });

    auto* pSprite = player->CreateComponent<SpriteRenderer>(playerTex);
    pSprite->SetSize({ 48.f, 48.f });

    player->CreateComponent<Player>();

    
    GameObject* enemy = CreateGameObject("Enemy");
    enemy->SetPosition({ 400.f, 150.f });

    auto* eSprite = enemy->CreateComponent<SpriteRenderer>(enemyTex);
    eSprite->SetSize({ 48.f, 48.f });

    enemy->CreateComponent<Enemy>();
}

GameObject* TouhouScene::CreateObjectSafe(const std::string& name)
{
    GameObject* newObj = nullptr;

    createQueue.Enqueue([&, name]()
        {
            newObj = Scene::CreateGameObject(name);
        });

    return newObj;
}

void TouhouScene::FlushCreateQueue()
{
    createQueue.Flush();
}
