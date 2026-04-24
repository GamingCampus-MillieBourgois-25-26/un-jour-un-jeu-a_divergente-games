#pragma once
#include <SFML/Graphics.hpp>

const int GridWidth = 10;
const int GridHeight = 20;

struct Block {
    int x;
    int y;
};

class Logic {
public:
    Logic();

    void rotate();
    void drawGrid(sf::RenderWindow& window);

private:
    int grid[GridHeight][GridWidth] = { 0 };
    Block active[4];
};
