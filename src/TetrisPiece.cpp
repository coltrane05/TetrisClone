//
// Created by Colton Crapo on 4/9/2025.
//

#include "TetrisPiece.h"
#include <iostream>
#include <map>
#include <utility>

using std::make_pair;

std::map<int, std::vector<std::pair<int, int>>> TetrisPiece::cwWallKickData = {
        {0, {make_pair(0, 0), make_pair(-1, 0), make_pair(-1, -1), make_pair(0, 2), make_pair(-1, 2)}},
        {1, {make_pair(0, 0), make_pair(1, 0), make_pair(1, 1), make_pair(0, -2), make_pair(1, -2)}},
        {2, {make_pair(0, 0), make_pair(1, 0), make_pair(1, -1), make_pair(0, 2), make_pair(1, 2)}},
        {3, {make_pair(0, 0), make_pair(-1, 0), make_pair(-1, 1), make_pair(0, -2), make_pair(-1, -2)}}
};

std::map<int, std::vector<std::pair<int, int>>> TetrisPiece::ccwWallKickData = {
        {0, {make_pair(0, 0), make_pair(1, 0), make_pair(1, -1), make_pair(0, 2), make_pair(1, 2)}},
        {1, {make_pair(0, 0), make_pair(1, 0), make_pair(1, 1), make_pair(0, -2), make_pair(1, -2)}},
        {2, {make_pair(0, 0), make_pair(-1, 0), make_pair(-1, -1), make_pair(0, 2), make_pair(-1, 2)}},
        {3, {make_pair(0, 0), make_pair(-1, 0), make_pair(-1, 1), make_pair(0, -2), make_pair(-1, -2)}}
};

TetrisPiece::~TetrisPiece() = default;

void TetrisPiece::draw(sf::RenderWindow &window) const {
    for (int i = 0; i < sprites.size(); i++) {
        if (std::get<1>(spriteCoordinates[i]) >= 0) {
            window.draw(sprites[i]);
        }
    }
}

void TetrisPiece::moveDown(Grid &gameGrid) {
    if (this->canMoveDownHelper(gameGrid)) {
        x = x + blockHeight;
        for (int i = 0; i < sprites.size(); i++) {
            sprites[i].move({0, blockHeight});
            spriteCoordinates[i].second++;
        }
    }
    else {
        freezePiece(gameGrid);
    }
}

void TetrisPiece::moveRight(Grid &gameGrid) {
    if (this->isBlockVisibleHelper() && this->canMoveRightHelper(gameGrid)) {
        y = y + blockWidth;
        for (int i = 0; i < sprites.size(); i++) {
            sprites[i].move({blockWidth, 0});
            std::get<0>(spriteCoordinates[i])++;
        }
    }
}

void TetrisPiece::moveLeft(Grid &gameGrid) {
    if (this->isBlockVisibleHelper() && this->canMoveLeftHelper(gameGrid)) {
        y = y - blockWidth;
        for (int i = 0; i < sprites.size(); i++) {
            sprites[i].move({-blockWidth, 0});
            std::get<0>(spriteCoordinates[i])--;
        }
    }
}

void TetrisPiece::hardDrop(Grid &gameGrid) {
    while(canMoveDownHelper(gameGrid)) {
        moveDown(gameGrid);
    }
    freezePiece(gameGrid);
}

bool TetrisPiece::isBlockVisibleHelper() const {
    bool isBlockVisible = false;
    for (auto & spriteCoordinate : spriteCoordinates) {
        if (spriteCoordinate.second >= 0) {
            isBlockVisible = true;
        }
    }
    return isBlockVisible;
}

bool TetrisPiece::canMoveLeftHelper(Grid &gameGrid) const {
    bool canMoveLeft = true;
    for (auto & spriteCoordinate : spriteCoordinates) {
        const int xCoord = spriteCoordinate.first - 1;
        const int yCoord = spriteCoordinate.second;
        if (spriteCoordinate.second >= 0) {
            if (spriteCoordinate.first - 1 < 0 || gameGrid.tetrisGrid.at(yCoord).at(xCoord).isOccupied()) {
                canMoveLeft = false;
                break;
            }
        }
        else {
            if (spriteCoordinate.first - 1 < 0) {
                canMoveLeft = false;
                break;
            }
        }
    }
    return canMoveLeft;
}

bool TetrisPiece::canMoveRightHelper(Grid &gameGrid) const {
    bool canMoveRight = true;
    for (auto & spriteCoordinate : spriteCoordinates) {
        const int xCoord = spriteCoordinate.first + 1;
        const int yCoord = spriteCoordinate.second;
        if (spriteCoordinate.second >= 0) {
            if (spriteCoordinate.first + 1 > 9 || gameGrid.tetrisGrid.at(yCoord).at(xCoord).isOccupied()) {
                canMoveRight = false;
                break;
            }
        }
        else {
            if (spriteCoordinate.first + 1 > 9) {
                canMoveRight = false;
                break;
            }
        }
    }
    return canMoveRight;
}

bool TetrisPiece::canMoveDownHelper(Grid &gameGrid) const {
    bool canMoveDown = true;
    for (auto & spriteCoordinate : spriteCoordinates) {
        const int xCoord = spriteCoordinate.first;
        const int yCoord = spriteCoordinate.second + 1;
        if (spriteCoordinate.second >= 0) {
            if (spriteCoordinate.second + 1 > 19 || gameGrid.tetrisGrid.at(yCoord).at(xCoord).isOccupied()) {
                canMoveDown = false;
                break;
            }
        }
    }

    return canMoveDown;
}

bool TetrisPiece::CWWallKick(Grid &gameGrid) {
    bool successful = false;
    for (auto pair : cwWallKickData[rotationState]) {
        bool allBlocksAreValid = true;
        for (int i = 0; i < sprites.size(); i++) {
            if (!isBlockInBoundsHelper(i, pair) || !isCellUnoccupiedHelper(i, pair, gameGrid)) {
                allBlocksAreValid = false;
                break;
            }
        }
        if (allBlocksAreValid) {
            for (int i = 0; i < sprites.size(); i++) {
                sprites[i].move({blockWidth * pair.first, blockHeight * pair.second});
                spriteCoordinates[i].first += pair.first;
                spriteCoordinates[i].second += pair.second;
            }
            successful = true;
            break;
        }
    }
    return successful;
}

bool TetrisPiece::CCWWallKick(Grid &gameGrid) {
    bool successful = false;
    for (auto pair : ccwWallKickData[rotationState]) {
        bool allBlocksAreValid = true;
        for (int i = 0; i < sprites.size(); i++) {
            if (!isBlockInBoundsHelper(i, pair) || !isCellUnoccupiedHelper(i, pair, gameGrid)) {
                allBlocksAreValid = false;
                break;
            }
        }
        if (allBlocksAreValid) {
            for (int i = 0; i < sprites.size(); i++) {
                sprites[i].move({blockWidth * pair.first, blockHeight * pair.second});
                spriteCoordinates[i].first += pair.first;
                spriteCoordinates[i].second += pair.second;
            }
            successful = true;
            break;
        }
    }
    return successful;
}

bool TetrisPiece::isBlockInBoundsHelper(int spriteIndex, const std::pair<int, int> &wallKickPair) const {
    int xCoord = spriteCoordinates[spriteIndex].first + wallKickPair.first;
    int yCoord = spriteCoordinates[spriteIndex].second + wallKickPair.second;
    if (xCoord < 0 || xCoord > 9) {
        return false;
    }
    if (yCoord > 19) {
        return false;
    }

    return true;
}

bool TetrisPiece::isCellUnoccupiedHelper(int spriteIndex, const std::pair<int, int> &wallKickPair, Grid &gameGrid) const {
    int xCoord = spriteCoordinates[spriteIndex].first + wallKickPair.first;
    int yCoord= spriteCoordinates[spriteIndex].second + wallKickPair.second;
    if (yCoord < 0) {
        return true;
    }
    if (gameGrid.tetrisGrid.at(yCoord).at(xCoord).isOccupied()) {
        return false;
    }
    return true;
}

void TetrisPiece::freezePiece(Grid &gameGrid) {
    int newColorR = pieceColor.r - 50 * (pieceColor.r / 255);
    int newColorG = pieceColor.g - 50 * (pieceColor.g / 255);
    int newColorB = pieceColor.b - 50 * (pieceColor.b / 255);

    for (auto & spriteCoordinate : spriteCoordinates) {
        const int xCoord = spriteCoordinate.first;
        const int yCoord = spriteCoordinate.second;
        gameGrid.tetrisGrid.at(yCoord).at(xCoord).setOccupied();
        gameGrid.tetrisGrid.at(yCoord).at(xCoord).setSpriteColor(sf::Color(newColorR, newColorG, newColorB));
    }

    frozen = true;
}

bool TetrisPiece::isFrozen() const {
    return frozen;
}

