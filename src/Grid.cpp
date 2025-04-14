//
// Created by Colton Crapo on 4/10/2025.
//

#include "Grid.h"

Grid::Grid(float posX, float posY, float cellWidth, float cellHeight) {
    x = posX + 1;
    y = posY + 1;
    this->cellWidth = cellWidth;
    this->cellHeight = cellHeight;
    sf::Vector2f size(cellWidth - 2, cellHeight - 2);
    sf::Color fillColor(40, 40, 40, 200);
    sf::Color outlineColor(130, 130, 130, 200);
    for (int i = 0; i < 20; i++) {
        std::vector<Cell> row;
        for (int j = 0; j < 10; j++) {
            std::tuple<float, float> currentPosition(posX + j * cellWidth, posY + i * cellHeight);
            std::tuple<int, int> currentCoordinates(j, i);
            positionMap[currentPosition] = currentCoordinates;
            row.emplace_back(x + j * cellWidth, y + i * cellHeight, j, i, size, 1, fillColor, outlineColor);

        }
        TetrisGrid.push_back(row);
    }

}

void Grid::draw(sf::RenderWindow &window) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            window.draw(TetrisGrid[i][j].getBox());
        }
    }
    sf::RectangleShape gridOutline;
    sf::RectangleShape gridOutline2;
    sf::RectangleShape gridOutline3;

    sf::Vector2f gridSize(cellWidth * 10, cellHeight * 20);
    sf::Vector2f gridSize2(gridSize.x + 5 * 2, gridSize.y + 5 * 2);
    sf::Vector2f gridSize3(gridSize2.x + 4 * 2, gridSize2.y + 4 * 2);

    gridOutline.setSize(gridSize);
    gridOutline2.setSize(gridSize2);
    gridOutline3.setSize(gridSize3);

    gridOutline.setPosition(x - 1, y - 1);
    gridOutline2.setPosition(gridOutline.getPosition().x - 5, gridOutline.getPosition().y - 5);
    gridOutline3.setPosition(gridOutline2.getPosition().x - 4, gridOutline2.getPosition().y - 4);

    sf::Color outlineColor(255, 255, 255, 255);
    sf::Color outlineColor2(175, 175, 175, 255);
    sf::Color outlineColor3(100, 100, 100, 255);

    gridOutline.setOutlineColor(outlineColor);
    gridOutline2.setOutlineColor(outlineColor2);
    gridOutline3.setOutlineColor(outlineColor3);

    gridOutline.setOutlineThickness(5);
    gridOutline2.setOutlineThickness(4);
    gridOutline3.setOutlineThickness(3);

    gridOutline.setFillColor(sf::Color::Transparent);
    gridOutline2.setFillColor(sf::Color::Transparent);
    gridOutline3.setFillColor(sf::Color::Transparent);

    window.draw(gridOutline);
    window.draw(gridOutline2);
    window.draw(gridOutline3);

}