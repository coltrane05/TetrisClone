//
// Created by crapo on 4/13/2025.
//

#include "EventHandler.h"

void EventHandler::handleEvents(sf::RenderWindow &window, TetrisPiece* currentPiece, Grid gameGrid) {
    while (window.pollEvent(event)) {
        // Close window: exit
        if (event.type == sf::Event::Closed)
             window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::S) {
                window.setKeyRepeatEnabled(true);
                currentPiece->moveDown(gameGrid);
            }
            else if (event.key.code == sf::Keyboard::D) {
                window.setKeyRepeatEnabled(true);
                currentPiece->moveRight(gameGrid);
            }
            else if (event.key.code == sf::Keyboard::A) {
                window.setKeyRepeatEnabled(true);
                currentPiece->moveLeft(gameGrid);
            }
            else if (event.key.code == sf::Keyboard::E) {
                window.setKeyRepeatEnabled(false);
                currentPiece->CWRotate(gameGrid);
            }
            else if (event.key.code == sf::Keyboard::Q) {
                window.setKeyRepeatEnabled(false);
                currentPiece->CCWRotate(gameGrid);
            }
        }
    }
}