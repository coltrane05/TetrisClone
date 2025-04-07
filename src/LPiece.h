//
// Created by Colton Crapo on 4/6/2025.
//

#ifndef TETRISCLONE_LPIECE_H
#define TETRISCLONE_LPIECE_H
#include <SFML/Graphics.hpp>
#include <vector>


class LPiece {
private:
    float x;
    float y;
    std::vector<sf::Sprite> sprites;

public:
    LPiece(float posX, float posY, sf::Texture &blockTexture);

    void draw(sf::RenderWindow &window);
//    void moveUp();
//    void moveDown();
//    void moveLeft();
//    void moveRight();
//    void rotate();
};


#endif //TETRISCLONE_LPIECE_H
