//
// Created by Colton Crapo on 4/10/2025.
//

#ifndef TETRISCLONE_GRID_H
#define TETRISCLONE_GRID_H

#include <vector>
#include <map>
#include <tuple>
#include "Cell.h"


class Grid {
private:
    float x;
    float y;
    float cellWidth;
    float cellHeight;
    std::vector<std::vector<Cell>> TetrisGrid;
public:
    std::map<std::tuple<float, float>, std::tuple<int, int>> positionMap;
    Grid(float posX, float posY, float cellWidth, float cellHeight);

    void draw(sf::RenderWindow &window);

};


#endif //TETRISCLONE_GRID_H
