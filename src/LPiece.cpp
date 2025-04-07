//
// Created by crapo on 4/6/2025.
//

#include "LPiece.h"

LPiece::LPiece(float posX, float posY, sf::Texture &blockTexture) {
    x = posX;
    y = posY;
    for (int i = 0; i < 4; i++) {
        sprites.push_back(sf::Sprite(blockTexture));
        sprites[i].scale(0.02f, 0.02f);
        sprites[i].setColor(sf::Color::Cyan);
    }

    sprites[0].setPosition(x, y);
    float verticalOffset = sprites[0].getGlobalBounds().height;
    float horizontalOffset = sprites[0].getGlobalBounds().width;
    sprites[1].setPosition(x, y + verticalOffset);
    sprites[2].setPosition(x, y + verticalOffset * 2);
    sprites[3].setPosition(x + horizontalOffset, y +verticalOffset * 2);
}

void LPiece::draw(sf::RenderWindow &window) {
    for (int i = 0; i < 4; i++) {
        window.draw(sprites[i]);
    }
}