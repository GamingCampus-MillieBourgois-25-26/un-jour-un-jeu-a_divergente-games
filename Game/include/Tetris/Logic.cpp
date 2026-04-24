#include "Logic.h"
#include <SFML/Graphics.hpp>



void Logic::rotate() {
   
    Block backup[4];
    for (int i = 0; i < 4; i++)
        backup[i] = active[i];

   
    Block pivot = active[0];

    for (int i = 1; i < 4; i++) {
        int dx = active[i].x - pivot.x;
        int dy = active[i].y - pivot.y;

        int newX = pivot.x + dy;
        int newY = pivot.y - dx;

        active[i].x = newX;
        active[i].y = newY;
    }

   
    bool valid = true;

    for (int i = 0; i < 4; i++) {
        int x = active[i].x;
        int y = active[i].y;

        
        if (x < 0 || x >= GridWidth || y < 0 || y >= GridHeight) {
            valid = false;
            break;
        }

        
        if (grid[y][x] != 0) {
            valid = false;
            break;
        }
    }

    
    if (!valid) {
        for (int i = 0; i < 4; i++)
            active[i] = backup[i];
    }
}

void Logic::drawGrid(sf::RenderWindow& window) {
    sf::RectangleShape cell;
    cell.setSize(sf::Vector2f(20, 20));

    for (int y = 0; y < GridHeight; y++) {
        for (int x = 0; x < GridWidth; x++) {

            int id = grid[y][x];
            if (id == 0)
                continue;

            sf::Color color;

            switch (id) {
            case 1: color = sf::Color::Cyan; break;      // I
            case 2: color = sf::Color::Yellow; break;    // O
            case 3: color = sf::Color(128, 0, 128); break; // T
            case 4: color = sf::Color(255, 165, 0); break; // L
            case 5: color = sf::Color::Blue; break;      // J
            case 6: color = sf::Color::Green; break;     // S
            case 7: color = sf::Color::Red; break;       // Z
            }

            cell.setFillColor(color);
            cell.setPosition({ x * 20, y * 20 });
            window.draw(cell);
        }
    }

    
    sf::RectangleShape border;
    border.setSize(sf::Vector2f(GridWidth * 20, GridHeight * 20));
    border.setPosition({ 0, 0 });
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineThickness(2);
    border.setOutlineColor(sf::Color::White);

    window.draw(border);
}

