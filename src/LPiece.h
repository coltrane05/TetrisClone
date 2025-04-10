//
// Created by Colton Crapo on 4/6/2025.
//

#ifndef TETRISCLONE_LPIECE_H
#define TETRISCLONE_LPIECE_H

#include "TetrisPiece.h"
#include <SFML/Graphics.hpp>
#include <vector>


class LPiece : public TetrisPiece {
private:
    int rotationState;
public:
    LPiece(float posX, float posY, sf::Texture &blockTexture);

    void CWRotate();
    void CCWRotate();
};


#endif //TETRISCLONE_LPIECE_H
