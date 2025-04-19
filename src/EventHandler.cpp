//
// Created by crapo on 4/13/2025.
//

#include "EventHandler.h"

void EventHandler::handleEvents(sf::RenderWindow &window, TetrisPiece* currentPiece, Grid &gameGrid) {
    while (const std::optional event = window.pollEvent()) {
        // Close window: exit
        if (event->is<sf::Event::Closed>())
             window.close();

        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scancode::S ) {
                window.setKeyRepeatEnabled(true);
                currentPiece->moveDown(gameGrid);
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
                window.setKeyRepeatEnabled(true);
                currentPiece->moveRight(gameGrid);
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::A) {
                window.setKeyRepeatEnabled(true);
                currentPiece->moveLeft(gameGrid);
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::E) {
                window.setKeyRepeatEnabled(false);
                currentPiece->CWRotate(gameGrid);
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::Q) {
                window.setKeyRepeatEnabled(false);
                currentPiece->CCWRotate(gameGrid);
            }
        }
    }
}