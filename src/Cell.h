//
// Created by Colton Crapo on 4/10/2025.
//

#ifndef TETRISCLONE_CELL_H
#define TETRISCLONE_CELL_H

#include <SFML/Graphics.hpp>

class Cell {
private:
    int gridX;
    int gridY;
    sf::RectangleShape box;
    sf::Sprite cellSprite;
    bool occupied;
    bool fixed;

public:
    Cell(float x, float y, int coordinateX, int coordinateY, sf::Vector2f size, float thickness, sf::Color fill, sf::Color outline, sf::Texture &spriteTexture);
    bool isOccupied();
    void setOccupied();
    void setUnoccupied();
    bool isFixed();
    void setFixed();
    void setUnfixed();
    sf::RectangleShape getBox();
    void drawSprite(sf::RenderWindow &window);
    void setSpriteColor(sf::Color color);
};


#endif //TETRISCLONE_CELL_H
