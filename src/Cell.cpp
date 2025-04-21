//
// Created by Colton Crapo on 4/10/2025.
//

#include "Cell.h"
#include <iostream>

Cell::Cell(float x, float y, int coordinateX, int coordinateY, sf::Vector2f size, float thickness, sf::Color fill, sf::Color outline, sf::Texture &spriteTexture): cellSprite(spriteTexture) {
    gridX = coordinateX;
    gridY = coordinateY;
    box.setSize(size);
    box.setPosition({x, y});
    box.setFillColor(fill);
    box.setOutlineColor(outline);
    box.setOutlineThickness(thickness);
    occupied = false;
    fixed = true;
    cellSprite.setPosition({x - 1, y - 1});
    cellSprite.scale({0.04f, 0.04f});
}

bool Cell::isOccupied() {
    return occupied;
}

void Cell::setOccupied() {
    occupied = true;
}

void Cell::setUnoccupied() {
    occupied = false;
}

bool Cell::isFixed() {
    return fixed;
}

void Cell::setFixed() {
    fixed = true;
}

void Cell::setUnfixed() {
    fixed = false;
}

sf::RectangleShape Cell::getBox() {
    return box;
}

void Cell::drawSprite(sf::RenderWindow &window) {
    window.draw(cellSprite);
}

void Cell::setSpriteColor(sf::Color color) {
    cellSprite.setColor(color);
}