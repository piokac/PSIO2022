#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Texture texture;
    if (!texture.loadFromFile("grass.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    texture.setRepeated(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Texture texture_guy;
    if (!texture_guy.loadFromFile("guy.png")) {
        return 1;
    }

    sf::Sprite guy;

    guy.setTexture(texture_guy);
    guy.setTextureRect(sf::IntRect(10, 10, 800, 600)); //left, top, width, height

    sf::Texture texture_wall;
    if (!texture_wall.loadFromFile("wall.png")) {
        return 1;
    }
    texture_wall.setRepeated(true);

    sf::Sprite wall;
    wall.setTexture(texture_wall);
    wall.setScale(0.3, 0.3);
    wall.setTextureRect(sf::IntRect(0, 0, 500, 500));

    sf::Clock clock;
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Space) {
                    std::cout << "Space released" << std::endl;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y
                              << std::endl;
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.draw(wall);
        window.draw(guy);

        // end the current frame
        window.display();
    }
    return 0;
}
