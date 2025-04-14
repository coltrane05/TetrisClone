//
// Created by Colton Crapo on 4/9/2025.
//

#ifndef TETRISCLONE_TETRISPIECE_H
#define TETRISCLONE_TETRISPIECE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <tuple>

class TetrisPiece {
protected:
    float x;
    float y;
    float blockHeight;
    float blockWidth;
    std::vector<sf::Sprite> sprites;
    std::vector<std::tuple<int, int>> spriteCoordinates;

public:

    void draw(sf::RenderWindow &window);
    void moveLeft();
    void moveRight();
    void moveDown();
    bool allBlocksVisibleHelper();
    bool canMoveLeftHelper();
    bool canMoveRightHelper();
    bool canMoveDownHelper();
    float getBlockHeight() const;
    float getBlockWidth() const;
    virtual void CWRotate() = 0;
    virtual void CCWRotate() = 0;
//    void slam();

};


#endif //TETRISCLONE_TETRISPIECE_H
