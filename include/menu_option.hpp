#ifndef MENU_OPTION_HPP
#define MENU_OPTION_HPP

#include "object.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <optional>

class MenuOption : public Object
{
    public:
        MenuOption(const std::string& name, sf::Vector2f size, sf::Vector2f position);
        ~MenuOption();
        void update() override;
        void on_hover(const sf::RenderWindow& window);
        std::optional<std::string> on_click(const sf::RenderWindow& window);
        void setColors(const std::array<sf::Color, 6>& theme);
    private:
        void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
        void fitText(sf::Vector2f size);
    private:
        sf::RectangleShape cover;
        sf::Text text;
        sf::Font font;
        sf::Color onHoverColor;
        std::string name;
};

#endif