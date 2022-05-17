#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
using namespace std;

class S
{
public:
    static S &getInstance(){};
} int foo()
{
    int i = 0;
    return i++;
}
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

class Player : public Graphical_object
{
    int score_;

public:
    Player(string tex_filename, bool set_repeated)
        : Graphical_object(tex_filename, set_repeated), score_(0)
    {}
};

class Game_engine
{
    sf::RenderWindow window_;
    vector<unique_ptr<Graphical_object>> objects_;

public:
    Game_engine() : window_(sf::VideoMode(800, 600), "My window")
    {
        unique_ptr<Graphical_object> grass = make_unique<Graphical_object>("grass.png", true);

        grass->setTextureRect(sf::IntRect(10, 10, 800, 600));
        objects_.push_back(std::move(grass));

        objects_.emplace_back(make_unique<Player>("guy.png", false));

        unique_ptr<Graphical_object> wall = make_unique<Graphical_object>("wall.png", true);
        wall->setScale(0.3, 0.3);
        wall->setTextureRect(sf::IntRect(0, 0, 30, 100));

        unique_ptr<Graphical_object> wall2 = make_unique<Graphical_object>("wall.png", true);
        wall2->setScale(0.3, 0.3);
        wall2->setTextureRect(sf::IntRect(0, 0, 100, 30));

        objects_.push_back(std::move(wall));
        objects_.push_back(std::move(wall2));
    }
    void draw()
    {
        window_.clear(sf::Color::Black);

        for (auto &el : objects_) {
            window_.draw(*el);
        }
        window_.display();
    }

    void loop()
    {
        sf::Clock clock;
        while (window_.isOpen()) {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window_.pollEvent(event)) {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window_.close();
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Space) {
                        std::cout << "Space released" << std::endl;
                    }
                }

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window_);
                        std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y
                                  << std::endl;
                    }
                }
            }
            draw();
        }
    }
};

int main()
{
    Game_engine maze;
    maze.loop();
    return 0;
}
