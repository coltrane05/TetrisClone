#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "LPiece.h"
#include "Grid.h"
#include "EventHandler.h"

TetrisPiece *generateTetrisPiece(float gridPosX, float gridPosY, sf::Texture &blockTexture);

int main() {
    // Create the main window
    sf::VideoMode mode({2000,1200});
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes().at(0), "SFML window", sf::State::Fullscreen);

    // Create the texture that will be mapped to all block sprites
    sf::Texture texture;
    if (!texture.loadFromFile("assets/block_shadow.jpg")) {
        std::cout << "Did not work bruh..." << std::endl;
    }

    sf::Sprite sampleBrick(texture);
    sampleBrick.scale({0.04f, 0.04f});

    unsigned int windowWidth =  window.getSize().x;
    unsigned int windowHeight = window.getSize().y;

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/background1.jpg")) {
        std::cout << "Could not load background image..." << std::endl;
    }
    sf::Vector2u backgroundSize = backgroundTexture.getSize();
    sf::Sprite background(backgroundTexture);
    background.scale({static_cast<float>(windowWidth) / backgroundSize.x, static_cast<float>(windowHeight) / backgroundSize.y});

    texture.setSmooth(true);
    float blockHeight = sampleBrick.getGlobalBounds().size.y;
    float blockWidth = sampleBrick.getGlobalBounds().size.x;
    float gridPosX = windowWidth / 2.0 - (blockWidth * 10) / 2;
    float gridPosY = 100;
    auto* currentPiece = generateTetrisPiece(gridPosX + blockWidth * 3, gridPosY - blockHeight * 1, texture);
    Grid tetrisGrid(gridPosX, gridPosY, blockWidth, blockHeight, texture);
    EventHandler eventHandler;

    window.setJoystickThreshold(20.0f);

    while (window.isOpen()) {
        if (currentPiece->isFrozen()) {
            delete currentPiece;
            currentPiece = generateTetrisPiece(gridPosX + blockWidth * 3, gridPosY - blockHeight * 1, texture);
        }

        eventHandler.handleEvents(window, currentPiece, tetrisGrid);

        window.clear();
        window.draw(background);
        tetrisGrid.draw(window);
        currentPiece->draw(window);
        window.display();

    }
    delete currentPiece;

    return 0;
}

TetrisPiece *generateTetrisPiece(float gridPosX, float gridPosY, sf::Texture &blockTexture) {
    return new LPiece(gridPosX, gridPosY, blockTexture);
}

