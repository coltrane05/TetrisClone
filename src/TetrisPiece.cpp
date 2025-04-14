//
// Created by Colton Crapo on 4/9/2025.
//

#include "TetrisPiece.h"

void TetrisPiece::draw(sf::RenderWindow &window) {
    for (int i = 0; i < sprites.size(); i++) {
        if (std::get<1>(spriteCoordinates[i]) >= 0) {
            window.draw(sprites[i]);
        }
    }
}

void TetrisPiece::moveDown() {
    if (this->canMoveDownHelper()) {
        x = x + blockHeight;
        for (int i = 0; i < sprites.size(); i++) {
            sprites[i].move(0, blockHeight);
            std::get<1>(spriteCoordinates[i])++;
        }
    }
}

void TetrisPiece::moveRight() {
    if (this->allBlocksVisibleHelper() && this->canMoveRightHelper()) {
        y = y + blockWidth;
        for (int i = 0; i < sprites.size(); i++) {
            sprites[i].move(blockWidth, 0);
            std::get<0>(spriteCoordinates[i])++;
        }
    }
}

void TetrisPiece::moveLeft() {
    if (this->allBlocksVisibleHelper() && this->canMoveLeftHelper()) {
        y = y - blockWidth;
        for (int i = 0; i < sprites.size(); i++) {
            sprites[i].move(-blockWidth, 0);
            std::get<0>(spriteCoordinates[i])--;
        }
    }
}

bool TetrisPiece::allBlocksVisibleHelper() {
    bool allBlocksVisible = true;
    for (auto & spriteCoordinate : spriteCoordinates) {
        if (std::get<1>(spriteCoordinate) < 0) {
            allBlocksVisible = false;
        }
    }
    return allBlocksVisible;
}

bool TetrisPiece::canMoveLeftHelper() {
    bool canMoveLeft = true;
    for (auto & spriteCoordinate : spriteCoordinates) {
        if (std::get<0>(spriteCoordinate) - 1 < 0) {
            canMoveLeft = false;
            break;
        }
    }
    return canMoveLeft;
}

bool TetrisPiece::canMoveRightHelper() {
    bool canMoveRight = true;
    for (auto & spriteCoordinate : spriteCoordinates) {
        if (std::get<0>(spriteCoordinate) + 1 > 9) {
            canMoveRight = false;
            break;
        }
    }
    return canMoveRight;
}

bool TetrisPiece::canMoveDownHelper() {
    bool canMoveDown = true;
    for (auto & spriteCoordinate : spriteCoordinates) {
        if (std::get<1>(spriteCoordinate) + 1 > 19) {
            canMoveDown = false;
        }
    }
    return canMoveDown;
}

float TetrisPiece::getBlockHeight() const {
    return blockHeight;
}

float TetrisPiece::getBlockWidth() const {
    return blockWidth;
}

