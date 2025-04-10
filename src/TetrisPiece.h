//
// Created by Colton Crapo on 4/9/2025.
//

#ifndef TETRISCLONE_TETRISPIECE_H
#define TETRISCLONE_TETRISPIECE_H

#include <SFML/Graphics.hpp>
#include <vector>

class TetrisPiece {
protected:
    float x;
    float y;
    float blockHeight;
    float blockWidth;
    std::vector<sf::Sprite> sprites;

public:

    void draw(sf::RenderWindow &window);
    void moveLeft();
    void moveRight();
    void moveDown();
//    void slam();

};


#endif //TETRISCLONE_TETRISPIECE_H
