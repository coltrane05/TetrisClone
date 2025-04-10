//
// Created by crapo on 4/9/2025.
//

#include "TetrisPiece.h"

void TetrisPiece::draw(sf::RenderWindow &window) {
    for (const auto & sprite : sprites) {
        window.draw(sprite);
    }
}

void TetrisPiece::moveDown() {
    x = x + blockHeight;
    for (auto & sprite : sprites) {
        sprite.move(0, blockHeight);
    }
}

void TetrisPiece::moveRight() {
    y = y + blockWidth;
    for (auto & sprite : sprites) {
        sprite.move(blockWidth, 0);
    }
}

void TetrisPiece::moveLeft() {
    y = y - blockWidth;
    for (auto & sprite : sprites) {
        sprite.move(-blockWidth, 0);
    }
}
