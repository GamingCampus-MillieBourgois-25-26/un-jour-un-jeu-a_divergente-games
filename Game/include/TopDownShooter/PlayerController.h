#pragma once
#include <SFML/Window/Keyboard.hpp>
#include "GameplayConfig.h"
#include "Core/Component.h"

class PlayerController : public Component
{
public:
    PlayerController(TopDownShooter::GameplayConfig* cfg)
        : config(cfg)
    {
    }

    void Update(float dt);

private:
    TopDownShooter::GameplayConfig* config;

    bool layoutDetected = false;

    sf::Keyboard::Key keyUp;
    sf::Keyboard::Key keyDown;
    sf::Keyboard::Key keyLeft;
    sf::Keyboard::Key keyRight;

    void DetectKeyboardLayout();
    void ApplyMovement(float dt);
    void ApplyRotation();
    void Shoot();
};
