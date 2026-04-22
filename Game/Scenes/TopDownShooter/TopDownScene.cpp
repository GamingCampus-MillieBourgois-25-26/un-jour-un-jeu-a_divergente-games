#include "TopDownScene.h"
#include "Core/GameObject.h"
#include "TopDownShooter/PlayerController.h"
#include "Components/SpriteRenderer.h"
#include "Modules/AssetsModule.h"
#include "Assets/Texture.h"


TopDownScene::TopDownScene() : Scene("TopDownScene")
{
    
    auto* assets = Engine::GetInstance()->GetModuleManager()->GetModule<AssetsModule>();
    Texture* tex = assets->LoadAsset<Texture>("robot1_gun.png");

    
    GameObject* player = CreateGameObject("Player");
    player->SetPosition({ 400.f, 300.f });

    auto* sprite = player->CreateComponent<SpriteRenderer>(tex);
    sprite->SetSize({ 64.f, 64.f });

    player->CreateComponent<PlayerController>(&TopDownShooter::config);
}