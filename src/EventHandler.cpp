//
// Created by Colton Crapo on 4/13/2025.
//

#include <iostream>
#include "EventHandler.h"

void EventHandler::handleEvents(sf::RenderWindow &window, TetrisPiece* currentPiece, Grid &gameGrid) {
    auto dPadX = sf::Joystick::Axis::PovX;
    auto dPadY = sf::Joystick::Axis::PovY;
    while (const std::optional event = window.pollEvent()) {
        // Close window: exit
        if (event->is<sf::Event::Closed>())
             window.close();

        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                window.close();
            }
            if (keyPressed->scancode == sf::Keyboard::Scancode::S) {
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
            else if (keyPressed->scancode == sf::Keyboard::Scancode::W) {
                window.setKeyRepeatEnabled(false);
                currentPiece->hardDrop(gameGrid);
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

        if (const auto* buttonPressed = event->getIf<sf::Event::JoystickButtonPressed>()) {
            if (buttonPressed->button == 2) {
                window.setKeyRepeatEnabled(false);
                currentPiece->CWRotate(gameGrid);
            }
            else if (buttonPressed->button == 1) {
                window.setKeyRepeatEnabled(false);
                currentPiece->CCWRotate(gameGrid);
            }
        }

        if (const auto* joystickMoved = event->getIf<sf::Event::JoystickMoved>()) {
            if (sf::Joystick::getAxisPosition(0, dPadY) == -100) {
                window.setKeyRepeatEnabled(true);
                currentPiece->moveDown(gameGrid);
            }
            else if (sf::Joystick::getAxisPosition(0, dPadX) == 100) {
                window.setKeyRepeatEnabled(true);
                currentPiece->moveRight(gameGrid);
            }
            else if (sf::Joystick::getAxisPosition(0, dPadX) == -100) {
                window.setKeyRepeatEnabled(true);
                currentPiece->moveLeft(gameGrid);
            }
            else if (sf::Joystick::getAxisPosition(0, dPadY) == 100) {
                window.setKeyRepeatEnabled(false);
                currentPiece->hardDrop(gameGrid);
            }
        }
    }
}