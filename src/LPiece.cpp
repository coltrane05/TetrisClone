//
// Created by crapo on 4/6/2025.
//

#include "LPiece.h"

LPiece::LPiece(float posX, float posY, sf::Texture &blockTexture) {
    x = posX;
    y = posY;
    rotationState = 0;
    for (int i = 0; i < 4; i++) {
        sprites.push_back(sf::Sprite(blockTexture));
        sprites[i].scale(0.02f, 0.02f);
        sprites[i].setColor(sf::Color::Cyan);
    }

    sprites[0].setPosition(x, y);
    blockHeight = sprites[0].getGlobalBounds().height;
    blockWidth = sprites[0].getGlobalBounds().width;
    sprites[1].setPosition(x, y + blockHeight);
    sprites[2].setPosition(x, y + blockHeight * 2);
    sprites[3].setPosition(x + blockWidth, y + blockHeight * 2);
}

void LPiece::CWRotate() {
    if (rotationState == 0) {
        rotationState++;
        sprites[0].move(blockWidth, blockHeight);
        sprites[2].move(-blockWidth, -blockHeight);
        sprites[3].move(-blockWidth * 2, 0);
        x = sprites[2].getPosition().x;
        y = sprites[2].getPosition().y;
    }
    else if (rotationState == 1) {
        rotationState++;
        sprites[0].move(-blockWidth, blockHeight);
        sprites[2].move(blockWidth, -blockHeight);
        sprites[3].move(0, -blockHeight * 2);
        x = sprites[3].getPosition().x;
        y = sprites[3].getPosition().y;
    }
    else if (rotationState == 2) {
        rotationState++;
        sprites[0].move(-blockWidth, -blockHeight);
        sprites[2].move(blockWidth, blockHeight);
        sprites[3].move(blockWidth * 2, 0);
        x = sprites[0].getPosition().x;
        y = sprites[0].getPosition().y;
    }
    else {
        rotationState = 0;
        sprites[0].move(blockWidth, -blockHeight);
        sprites[2].move(-blockWidth, blockHeight);
        sprites[3].move(0, blockHeight * 2);
        // not sure if this is necessary, but I will put it here just in case.
        x = sprites[0].getPosition().x;
        y = sprites[0].getPosition().y + blockHeight;
    }
}

void LPiece::CCWRotate() {
    if (rotationState == 0) {
        rotationState = 3;
        sprites[0].move(-blockWidth, blockHeight);
        sprites[2].move(blockWidth, -blockHeight);
        sprites[3].move(0, -blockHeight * 2);
        x = sprites[0].getPosition().x;
        y = sprites[0].getPosition().y + blockHeight;
    }
    else if (rotationState == 3) {
        rotationState--;
        sprites[0].move(blockWidth, blockHeight);
        sprites[2].move(-blockWidth, -blockHeight);
        sprites[3].move(-blockWidth * 2, 0);
        x = sprites[3].getPosition().x;
        y = sprites[3].getPosition().y;
    }
    else if (rotationState == 2) {
        rotationState--;
        sprites[0].move(blockWidth, -blockHeight);
        sprites[2].move(-blockWidth, blockHeight);
        sprites[3].move(0, blockHeight * 2);
        x = sprites[2].getPosition().x;
        y = sprites[2].getPosition().y;
    }
    else {
        rotationState--;
        sprites[0].move(-blockWidth, -blockHeight);
        sprites[2].move(blockWidth, blockHeight);
        sprites[3].move(blockWidth * 2, 0);
        x = sprites[0].getPosition().x;
        y = sprites[0].getPosition().y;
    }
}