#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
using namespace std;
class UICommand
{
public:
    virtual void execute() = 0;
};
class UICommanSetColor : public UICommand
{
    sf::Color color_;
    sf::Shape *object_;

public:
    void set_object(sf::Shape *object) { object_ = object; }

public:
    UICommanSetColor(sf::Color color, sf::Shape *obj) : color_(color), object_(obj) {}
    void execute() { object_->setFillColor(color_); }
};

class Button : public sf::RectangleShape
{
    UICommand *command_;

public:
    Button(const sf::Vector2f &pos, const sf::Vector2f size, UICommand *cmd)
        : sf::RectangleShape(size), command_(cmd)
    {
        this->setPosition(pos);
    }
    bool is_clicked(const sf::Vector2i &pos)
    {
        if (this->getGlobalBounds().contains(pos.x, pos.y)) {
            command_->execute();
            return true;
        } else
            return false;
    }
};

class Graphical_object : public sf::Sprite
{
    sf::Texture texture;

public:
    Graphical_object() {}
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
    Player() {}
    Player(string tex_filename, bool set_repeated)
        : Graphical_object(tex_filename, set_repeated), score_(0)
    {}
};

class Player_decorator : public Player
{
protected:
    unique_ptr<Player> player_;
    sf::RectangleShape rect_;

public:
    Player_decorator(Player *player) : player_(std::move(player))
    {
        rect_.setSize(sf::Vector2f(20, 10));
    }
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(*player_, states);
        target.draw(rect_, states);
    }
    virtual void set_color(const sf::Color &color) { rect_.setFillColor(color); }
};

class Decorator_blue : public Player_decorator
{
public:
    Decorator_blue(Player *player) : Player_decorator(player)
    {
        set_color((sf::Color::Blue));
        rect_.setPosition(0, -10);
    }
};

class Decorator_red : public Player_decorator
{
public:
    Decorator_red(Player *player) : Player_decorator(player)
    {
        set_color((sf::Color::Red));
        rect_.setPosition(0, 60);
    }
};

class Game_engine
{
    sf::RenderWindow window_;
    vector<unique_ptr<Graphical_object>> objects_;
    vector<Button *> buttons_;

public:
    Game_engine() : window_(sf::VideoMode(800, 600), "My window")
    {
        unique_ptr<Graphical_object> grass = make_unique<Graphical_object>("grass.png", true);

        grass->setTextureRect(sf::IntRect(10, 10, 800, 600));
        objects_.push_back(std::move(grass));

        Player *player = new Player("guy.png", false);

        Decorator_red *player_red = new Decorator_red(std::move(player));
        //        player_blue->setPosition(100, 100);

        unique_ptr<Decorator_blue> player_blue = make_unique<Decorator_blue>(player_red);
        player_blue->setPosition(100, 100);
        objects_.emplace_back(std::move(player_blue));

        unique_ptr<Graphical_object> wall = make_unique<Graphical_object>("wall.png", true);
        wall->setScale(0.3, 0.3);
        wall->setTextureRect(sf::IntRect(0, 0, 30, 100));

        unique_ptr<Graphical_object> wall2 = make_unique<Graphical_object>("wall.png", true);
        wall2->setScale(0.3, 0.3);
        wall2->setTextureRect(sf::IntRect(0, 0, 100, 30));

        objects_.push_back(std::move(wall));
        objects_.push_back(std::move(wall2));

        UICommanSetColor *cmd_red = new UICommanSetColor(sf::Color::Red, nullptr);
        UICommanSetColor *cmd_blue = new UICommanSetColor(sf::Color::Blue, nullptr);
        Button *button1 = new Button(sf::Vector2f(10, 100), sf::Vector2f(30, 30), cmd_red);
        Button *button2 = new Button(sf::Vector2f(50, 100), sf::Vector2f(30, 30), cmd_blue);
        cmd_blue->set_object(button1);
        cmd_red->set_object(button1);

        buttons_.emplace_back(button1);
        buttons_.emplace_back(button2);
    }
    void draw()
    {
        window_.clear(sf::Color::Black);

        for (auto &el : objects_) {
            window_.draw(*el);
        }
        for (auto &el : buttons_) {
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

                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Left) {
                        std::cout << "Space released" << std::endl;
                        //                        objects_[1]
                    }
                }

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window_);
                        std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y
                                  << std::endl;
                        for (auto &el : buttons_) {
                            el->is_clicked(mouse_pos);
                        }
                    }
                }
            }
            draw();
        }
    }
};

int main()
{
    //    auto res = S::getInstance();
    Game_engine maze;
    maze.loop();
    return 0;
}
