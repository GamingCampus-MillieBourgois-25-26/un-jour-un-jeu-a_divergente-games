#pragma once
#include "Logic.h"
#include "SFML/Graphics.hpp"

#include <iostream>

class Render
{
public:
	void draw(sf::RenderWindow& window, const Logic& logic);
};

