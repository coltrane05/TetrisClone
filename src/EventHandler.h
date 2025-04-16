//
// Created by crapo on 4/13/2025.
//

#ifndef TETRISCLONE_EVENTHANDLER_H
#define TETRISCLONE_EVENTHANDLER_H

#include <SFML/Graphics.hpp>
#include "TetrisPiece.h"
#include "Grid.h"

class EventHandler {
private:
    sf::Event event;

public:
    void handleEvents(sf::RenderWindow &window, TetrisPiece* currentPiece, Grid gameGrid);
};


#endif //TETRISCLONE_EVENTHANDLER_H
