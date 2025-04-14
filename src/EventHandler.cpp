//
// Created by crapo on 4/13/2025.
//

#include "EventHandler.h"

void EventHandler::handleEvents(sf::RenderWindow &window, TetrisPiece* currentPiece) {
    while (window.pollEvent(event)) {
        // Close window: exit
        if (event.type == sf::Event::Closed)
             window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::S) {
                currentPiece->moveDown();
            }
            else if (event.key.code == sf::Keyboard::D) {
                currentPiece->moveRight();
            }
            else if (event.key.code == sf::Keyboard::A) {
                currentPiece->moveLeft();
            }
            else if (event.key.code == sf::Keyboard::E) {
                currentPiece->CWRotate();
            }
            else if (event.key.code == sf::Keyboard::Q) {
                currentPiece->CCWRotate();
            }
        }

    }
}