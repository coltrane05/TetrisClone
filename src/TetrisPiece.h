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
    std::vector<sf::Sprite> sprites;
    std::vector<std::pair<int, int>> spriteCoordinates;
    static std::map<int, std::vector<std::pair<int, int>>> cwWallKickData;
    static std::map<int, std::vector<std::pair<int, int>>> ccwWallKickData;


public:

    void draw(sf::RenderWindow &window);
    void moveLeft(Grid gameGrid);
    void moveRight(Grid gameGrid);
    void moveDown(Grid gameGrid);
    bool isBlockVisibleHelper();
    bool canMoveLeftHelper(Grid gameGrid);
    bool canMoveRightHelper(Grid gameGrid);
    bool canMoveDownHelper(Grid gameGrid);
    bool isBlockInBoundsHelper(int spriteIndex, std::pair<int, int> wallKickPair);
    bool isCellUnoccupiedHelper(int spriteIndex, std::pair<int, int> wallKickPair, Grid gameGrid);
    float getBlockHeight() const;
    float getBlockWidth() const;
    virtual void CWRotate(Grid gameGrid) = 0;
    virtual void CCWRotate(Grid gameGrid) = 0;
    virtual void CWReverse() = 0;
    virtual void CCWReverse() = 0;
    bool CWWallKick(Grid gameGrid);
    bool CCWWallKick(Grid gameGrid);
//    void slam();

};


#endif //TETRISCLONE_TETRISPIECE_H
