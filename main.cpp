#include <iostream>
#include <SFML/Graphics.hpp>
#include <typeinfo>
#include <string>
int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

    sf::Font font;
    if(!font.loadFromFile("arial.ttf")) {
        return EXIT_FAILURE;
    }

    sf::CircleShape circle;
    circle.setRadius(200);
    circle.setOutlineColor(sf::Color::Red);
    circle.setOutlineThickness(5);
    circle.setPosition(30, 50);
    circle.setFillColor(sf::Color::Blue);
    circle.setPointCount(100);
    std::cout << (circle.getPointCount()) << std::endl;



    sf::Text text("Do you love me???", font);

    sf::Texture texture;
    if (!texture.loadFromFile("Assets/block_shadow.jpg")) {
        std::cout << "Did not work bruh..." << std::endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sprite.setPosition(200, 200);
    sprite.scale(0.1f, 0.1f);
    std::cout << sprite.getLocalBounds().top + sprite.getLocalBounds().left << std::endl;
    sf::FloatRect floatTextureRect = sprite.getLocalBounds();
    sf::IntRect  intTextureRect(floatTextureRect.left, floatTextureRect.top, floatTextureRect.width, floatTextureRect.height);
    sprite.setTextureRect(intTextureRect);
    sprite.setColor(sf::Color::Cyan);

    int circleOffsetX;
    int circleOffsetY;
    bool beingDragged = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i position = sf::Mouse::getPosition(window);
            if (!beingDragged) {
                beingDragged = true;
                circleOffsetX = position.x - circle.getPosition().x;
                circleOffsetY = position.y - circle.getPosition().y;
           }
            std::string positionString = std::to_string(position.x) + ", " + std::to_string(position.y);
            text.setString(positionString);
            circle.setPosition(position.x - circleOffsetX, position.y - circleOffsetY);
        }
        else {
            beingDragged = false;
        }
        window.clear();
        window.resetGLStates();
        window.draw(text);
        window.draw(circle);
        window.draw(sprite);
        window.display();

    }



    return 0;
}
