#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
class Graphical_object : public sf::Sprite
{
    sf::Texture texture;

public:
    Graphical_object(string tex_filename, bool set_repeated)
    {
        texture.loadFromFile(tex_filename);
        if (!texture.loadFromFile(tex_filename)) {
            std::cerr << "Could not load texture" << std::endl;
        }

        else {
            texture.setRepeated(set_repeated);
            this->setTexture(texture);
        }
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    Graphical_object grass("grass.png", true);
    Graphical_object guy("guy.png", false);
    guy.setTextureRect(sf::IntRect(10, 10, 800, 600));

    Graphical_object wall("wall.png", true);
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
        window.draw(grass);
        window.draw(wall);
        window.draw(guy);

        // end the current frame
        window.display();
    }
    return 0;
}
