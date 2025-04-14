#include <iostream>
#include <SFML/Graphics.hpp>
#include <typeinfo>
#include <string>
#include <vector>
#include "LPiece.h"
#include "Grid.h"
#include "EventHandler.h"

int main() {
    // Create the main window
//    std::vector<sf::VideoMode> videoModes = sf::VideoMode::getFullscreenModes();
    sf::VideoMode mode(2000,1200);
    sf::RenderWindow window(mode, "SFML window");

    // Create the texture that will be mapped to all block sprites
    sf::Texture texture;
    if (!texture.loadFromFile("assets/block_shadow.jpg")) {
        std::cout << "Did not work bruh..." << std::endl;
    }

    sf::Sprite sampleBrick(texture);
    sampleBrick.scale(0.04f, 0.04f);

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/background1.jpg")) {
        std::cout << "Could not load background image..." << std::endl;
    }
    backgroundTexture.setSmooth(true);
    sf::Sprite background(backgroundTexture);
    background.scale(0.4f, 0.4f);

    texture.setSmooth(true);


    float blockHeight = sampleBrick.getGlobalBounds().height;
    float blockWidth = sampleBrick.getGlobalBounds().width;
    float gridPosX = 2000 / 2.0 - (blockWidth * 10) / 2;
    float gridPosY = 100;
    auto* newLPiece = new LPiece(gridPosX + blockWidth * 3, gridPosY - blockHeight * 1, texture);
    Grid tetrisGrid(gridPosX, gridPosY, blockWidth, blockHeight);
    EventHandler eventHandler;

    while (window.isOpen()) {
        eventHandler.handleEvents(window, newLPiece);

        window.clear();
        window.draw(background);
        tetrisGrid.draw(window);
        newLPiece->draw(window);
        window.display();

    }
    delete newLPiece;



    return 0;
}
