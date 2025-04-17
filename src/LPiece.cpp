//
// Created by Colton Crapo on 4/6/2025.
//

#include <iostream>
#include "LPiece.h"

LPiece::LPiece(float posX, float posY, sf::Texture &blockTexture) {
    x = posX;
    y = posY;
    rotationState = 0;
    transitionStates0[0] = {1.0, -1.0}; // {1.0, 1.0}
    transitionStates0[1] = {1.0, 1.0};  // {-1.0, 1.0}
    transitionStates0[2] = {-1.0, 1.0}; // {-1.0, -1.0}
    transitionStates0[3] = {-1.0, -1.0};// {1.0, -1.0}

    transitionStates2[0] = {-1.0, 1.0};
    transitionStates2[1] = {-1.0, -1.0};
    transitionStates2[2] = {1.0, -1.0};
    transitionStates2[3] = {1.0, 1.0};

    transitionStates3[0] = {0.0, 2.0};
    transitionStates3[1] = {-2.0, 0.0};
    transitionStates3[2] = {0.0, -2.0};
    transitionStates3[3] = {2.0, 0.0};


    for (int i = 0; i < 4; i++) {
        sprites.push_back(sf::Sprite(blockTexture));
        sprites[i].scale(0.04f, 0.04f);
        sprites[i].setColor(sf::Color::Cyan);
    }


    sprites[0].setPosition(x, y);
    spriteCoordinates.emplace_back(3, -1);
    blockHeight = sprites[0].getGlobalBounds().height;
    blockWidth = sprites[0].getGlobalBounds().width;

    sprites[1].setPosition(x + blockWidth, y);
    spriteCoordinates.emplace_back(4, -1);

    sprites[2].setPosition(x + blockWidth * 2, y);
    spriteCoordinates.emplace_back(5, -1);

    sprites[3].setPosition(x + blockWidth * 2, y - blockHeight);
    spriteCoordinates.emplace_back(5, -2);

}

void LPiece::CWRotate(Grid gameGrid) {
    std::vector<float> movements0 = transitionStates0[rotationState];
    std::vector<float> movements2 = transitionStates2[rotationState];
    std::vector<float> movements3 = transitionStates3[rotationState];

    sprites[0].move(blockWidth * movements0[0], blockHeight * movements0[1]);
    spriteCoordinates[0].first += movements0[0];
    spriteCoordinates[0].second += movements0[1];

    sprites[2].move(blockWidth * movements2[0], blockHeight * movements2[1]);
    spriteCoordinates[2].first += movements2[0];
    spriteCoordinates[2].second += movements2[1];

    sprites[3].move(blockWidth * movements3[0], blockHeight * movements3[1]);
    spriteCoordinates[3].first += movements3[0];
    spriteCoordinates[3].second += movements3[1];


    if (CWWallKick(gameGrid)) {
        rotationState = (rotationState + 1) % 4;
    }
    else {
        CWReverse();
    }
}

void LPiece::CWReverse() {
    std::vector<float> movements0 = transitionStates0[(rotationState + 2) % 4];
    std::vector<float> movements2 = transitionStates2[(rotationState + 2) % 4];
    std::vector<float> movements3 = transitionStates3[(rotationState + 2) % 4];

    sprites[0].move(blockWidth * movements0[0], blockHeight * movements0[1]);
    spriteCoordinates[0].first += movements0[0];
    spriteCoordinates[0].second += movements0[1];

    sprites[2].move(blockWidth * movements2[0], blockHeight * movements2[1]);
    spriteCoordinates[2].first += movements2[0];
    spriteCoordinates[2].second += movements2[1];

    sprites[3].move(blockWidth * movements3[0], blockHeight * movements3[1]);
    spriteCoordinates[3].first += movements3[0];
    spriteCoordinates[3].second += movements3[1];
}

void LPiece::CCWRotate(Grid gameGrid) {
    std::vector<float> movements0 = transitionStates0[(rotationState + 1) % 4];
    std::vector<float> movements2 = transitionStates2[(rotationState + 1) % 4];
    std::vector<float> movements3 = transitionStates3[(rotationState + 1) % 4];

    sprites[0].move(blockWidth * movements0[0], blockHeight * movements0[1]);
    spriteCoordinates[0].first += movements0[0];
    spriteCoordinates[0].second += movements0[1];

    sprites[2].move(blockWidth * movements2[0], blockHeight * movements2[1]);
    spriteCoordinates[2].first += movements2[0];
    spriteCoordinates[2].second += movements2[1];

    sprites[3].move(blockWidth * movements3[0], blockHeight * movements3[1]);
    spriteCoordinates[3].first += movements3[0];
    spriteCoordinates[3].second += movements3[1];

    if (CCWWallKick(gameGrid)) {
        rotationState--;
        if (rotationState == -1) {
            rotationState = 3;
        }
    }
    else {
        CCWReverse();
    }
}

void LPiece::CCWReverse() {
    std::vector<float> movements0 = transitionStates0[(rotationState + 3) % 4];
    std::vector<float> movements2 = transitionStates2[(rotationState + 3) % 4];
    std::vector<float> movements3 = transitionStates3[(rotationState + 3) % 4];

    sprites[0].move(blockWidth * movements0[0], blockHeight * movements0[1]);
    spriteCoordinates[0].first += movements0[0];
    spriteCoordinates[0].second += movements0[1];

    sprites[2].move(blockWidth * movements2[0], blockHeight * movements2[1]);
    spriteCoordinates[2].first += movements2[0];
    spriteCoordinates[2].second += movements2[1];

    sprites[3].move(blockWidth * movements3[0], blockHeight * movements3[1]);
    spriteCoordinates[3].first += movements3[0];
    spriteCoordinates[3].second += movements3[1];
}