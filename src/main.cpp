#include <iostream>
#include <SFML/Graphics.hpp>
#include <typeinfo>
#include <string>
#include <vector>
#include "LPiece.h"

int main() {
    // Create the main window
    std::vector<sf::VideoMode> videoModes = sf::VideoMode::getFullscreenModes();
    sf::VideoMode mode = videoModes[1];
    sf::RenderWindow window(mode, "SFML window");

    // Create the texture that will be mapped to all block sprites
    sf::Texture texture;
    if (!texture.loadFromFile("assets/block_shadow.jpg")) {
        std::cout << "Did not work bruh..." << std::endl;
    }

    texture.setSmooth(true);

    LPiece newLPiece(200, 200, texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::S) {
                    newLPiece.moveDown();
                }
                else if (event.key.code == sf::Keyboard::D) {
                    newLPiece.moveRight();
                }
                else if (event.key.code == sf::Keyboard::A) {
                    newLPiece.moveLeft();
                }
                else if (event.key.code == sf::Keyboard::E) {
                    newLPiece.CWRotate();
                }
                else if (event.key.code == sf::Keyboard::Q) {
                    newLPiece.CCWRotate();
                }
            }

        }
        window.clear();
        window.resetGLStates();
        newLPiece.draw(window);
        window.display();

    }



    return 0;
}
