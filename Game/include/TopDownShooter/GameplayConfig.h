#pragma once
#include <string>
#include <vector>

namespace TopDownShooter
{
    struct GameplayConfig
    {
        float playerSpeed = 500.0f;
        float rotationSpeed = 10.0f;
    };

    extern GameplayConfig config;
}