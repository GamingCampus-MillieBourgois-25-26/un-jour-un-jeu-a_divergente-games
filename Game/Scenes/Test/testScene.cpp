#include "testScene.h"

#include <chrono>
#include <cstdint>
#include <random>
#include "AssetsModule.h"
#include "RectangleShapeRenderer.h"
#include "SpriteRenderer.h"

#include "SquareCollider.h"
#include "Texture.h"
#include "WindowModule.h"
#include "Demo/Tile.h"
#include "Test/Ennemies.h"

int RandomInt(const int _min, const int _max)
{
    thread_local std::mt19937_64 gen(static_cast<uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count()));

    std::uniform_real_distribution dist(static_cast<float>(_min), static_cast<float>(_max));
    return dist(gen);
}

Test::TestScene::TestScene() :Scene("TestScene")
{
    // CHARGEMENT SPRITES
    AssetsModule * assets_module = Engine::GetInstance()->GetModuleManager()->GetModule<AssetsModule>();
    Texture* logo_texture = assets_module->LoadAsset<Texture>("logo.png");
    AssetsModule* asset = Engine::GetInstance()->GetModuleManager()->GetModule<AssetsModule>();
    Texture* player_tex = asset->LoadAsset<Texture>("player.png");

    GameObject* const& logo = CreateGameObject("SFML Logo");
    logo->CreateComponent<SpriteRenderer>(logo_texture);
    //---------------------------------------

   GameObject* player = CreateGameObject("Player");
    auto* sprite_player = player->CreateComponent<SpriteRenderer>(player_tex);
    sprite_player->SetSize({ 64.f,64.f });
    player->SetPosition({ 200.f, 100.f });
    player->CreateComponent<Player>();

    /*for (int i = 0; i < 10; ++i)
    {
        CreateBots();
    }*/
}

void Test::TestScene::CreateBots()
{
    GameObject* bots = CreateGameObject("bots");
    sf::Color color = sf::Color::Red;

    const Maths::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetSize();

    const int random_position_x = RandomInt(0, window_size.x);
    const int random_position_y = RandomInt(0, window_size.y);
    bots->SetPosition(Maths::Vector2f(random_position_x, random_position_y));
   // bots->CreateComponent<Tile>(color);
    //const int random_size = RandomInt(minSize, maxSize);
    //bots->CreateComponent<Tile>(color, Maths::Vector2i(random_size, random_size));
}