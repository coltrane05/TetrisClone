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

    sf::Texture texture;
    if (!texture.loadFromFile("Assets/block_shadow.jpg")) {
        std::cout << "Did not work bruh..." << std::endl;
    }

    texture.setSmooth(true);
//    sf::Sprite L1;
//    sf::Sprite L2;
//    sf::Sprite L3;
//    sf::Sprite L4;
//
//    L1.setTexture(texture);
//    L2.setTexture(texture);
//    L3.setTexture(texture);
//    L4.setTexture(texture);
//
//    L1.scale(0.02f, 0.02f);
//    L2.scale(0.02f, 0.02f);
//    L3.scale(0.02f, 0.02f);
//    L4.scale(0.02f, 0.02f);
//
//    float verticalOffset = L1.getGlobalBounds().height;
//    float horizontalOffset = L1.getGlobalBounds().width;
//    L1.setPosition(200, 200);
//    L2.setPosition(200, 200 + verticalOffset);
//    L3.setPosition(200, 200 + verticalOffset * 2);
//    L4.setPosition(200 + horizontalOffset, 200 + verticalOffset * 2);
//
//    sf::FloatRect floatTextureRect = sprite.getLocalBounds();
//    sf::IntRect  intTextureRect(floatTextureRect.left, floatTextureRect.top, floatTextureRect.width, floatTextureRect.height);
//    sprite.setTextureRect(intTextureRect)
//    L1.setColor(sf::Color::Cyan);
//    L2.setColor(sf::Color::Cyan);
//    L3.setColor(sf::Color::Cyan);
//    L4.setColor(sf::Color::Cyan);

    LPiece newLPiece(200, 200, texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.resetGLStates();
        newLPiece.draw(window);
        window.display();

    }



    return 0;
}
