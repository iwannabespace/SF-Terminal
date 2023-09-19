#ifndef MENU_HPP
#define MENU_HPP

#include "object.hpp"
#include "menu_option.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class Menu : public Object
{
    public:
        Menu(sf::Vector2f size, sf::Color color);
        ~Menu();
        void update() override;
        void on_hover(const sf::RenderWindow& window);
        std::optional<std::string> on_click(const sf::RenderWindow& window);
        void setColors(const std::array<sf::Color, 6>& theme);
        void setBarWidth(float width);
    private:
        void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
    private:
        sf::RectangleShape bar;
        MenuOption option;
};  

#endif