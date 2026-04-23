#pragma once
#include "Component.h"
#include "InputModule.h"
#include <cmath>
#include "SFML/Window/Mouse.hpp"
#include "SFML/System/Angle.hpp"
#include "WindowModule.h"
#include <iostream>



class Player : public Component
{
public:
    Player();
    void Update(const float dt) override;
    void Move(float dt);
    void applyRotation(float dt);
    void shoot();



private:

    
    float speed;
    int health;
    int damage;
    sf::Vector2f position;


};

