//
// Created by Colton Crapo on 4/6/2025.
//

#ifndef TETRISCLONE_LPIECE_H
#define TETRISCLONE_LPIECE_H

#include "TetrisPiece.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>


class LPiece : public TetrisPiece {
private:
    std::map<int, std::vector<float>> transitionStates0;
    std::map<int, std::vector<float>> transitionStates2;
    std::map<int, std::vector<float>> transitionStates3;
public:
    LPiece(float posX, float posY, sf::Texture &blockTexture);

    void CWRotate(Grid &gameGrid) override;
    void CCWRotate(Grid &gameGrid) override;
    void CWReverse() override;
    void CCWReverse() override;
};


#endif //TETRISCLONE_LPIECE_H
