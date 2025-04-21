//
// Created by Colton Crapo on 4/9/2025.
//

#ifndef TETRISCLONE_TETRISPIECE_H
#define TETRISCLONE_TETRISPIECE_H

#include <SFML/Graphics.hpp>
#include "Grid.h"
#include <vector>
#include <map>
#include <utility>
#include <tuple>

class TetrisPiece {
protected:
    float x;
    float y;
    float blockHeight;
    float blockWidth;
    int rotationState;
    bool frozen = false;
    sf::Color pieceColor;
    std::vector<sf::Sprite> sprites;
    std::vector<std::pair<int, int>> spriteCoordinates;
    static std::map<int, std::vector<std::pair<int, int>>> cwWallKickData;
    static std::map<int, std::vector<std::pair<int, int>>> ccwWallKickData;

    bool isBlockVisibleHelper() const;
    bool canMoveLeftHelper(Grid &gameGrid) const;
    bool canMoveRightHelper(Grid &gameGrid) const;
    bool canMoveDownHelper(Grid &gameGrid) const;
    bool isBlockInBoundsHelper(int spriteIndex, const std::pair<int, int> &wallKickPair) const;
    bool isCellUnoccupiedHelper(int spriteIndex, const std::pair<int, int> &wallKickPair, Grid &gameGrid) const;


public:

    virtual ~TetrisPiece() = 0;
    void draw(sf::RenderWindow &window) const;
    void moveLeft(Grid &gameGrid);
    void moveRight(Grid &gameGrid);
    void moveDown(Grid &gameGrid);
    float getBlockHeight() const;
    float getBlockWidth() const;
    virtual void CWRotate(Grid &gameGrid) = 0;
    virtual void CCWRotate(Grid &gameGrid) = 0;
    virtual void CWReverse() = 0;
    virtual void CCWReverse() = 0;
    bool CWWallKick(Grid &gameGrid);
    bool CCWWallKick(Grid &gameGrid);
    void hardDrop(Grid &gameGrid);
    void freezePiece(Grid &gameGrid);
    bool isFrozen() const;

};


#endif //TETRISCLONE_TETRISPIECE_H
