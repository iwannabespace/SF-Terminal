#include "../include/menu_option.hpp"
#include "../ext/portable-file-dialogs/portable-file-dialogs.h"
#include <SFML/Window/Mouse.hpp>
#include <iostream>

MenuOption::MenuOption(const std::string& name, sf::Vector2f size, sf::Vector2f position)
    : name(name)
{
    if (!font.loadFromFile("fonts/Monaco.ttf"))
        std::cerr << "Could not load the font." << std::endl;

    cover.setSize(size);
    cover.setPosition(position);
    cover.setFillColor(sf::Color::Transparent);

    text.setFont(font);
    text.setString(name);
    text.setCharacterSize(21);
    text.setFillColor(sf::Color::White);

    fitText(size);
    text.setPosition({ 
        std::round((position.x + ((size.x - text.getGlobalBounds().width) / 2))),
        std::round((position.y + ((size.y - text.getGlobalBounds().height) / 2) - text.getGlobalBounds().top)),
    });
}

MenuOption::~MenuOption()
{
}

void MenuOption::update()
{
}

void MenuOption::on_hover(const sf::RenderWindow& window)
{
    if (cover.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
        cover.setFillColor(onHoverColor);
    
    else
        cover.setFillColor(sf::Color::Transparent);
}

std::optional<std::string> MenuOption::on_click(const sf::RenderWindow& window)
{
    if (cover.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
    {    
        auto result = pfd::open_file("Choose a Theme", ".", { "Theme Files, ", "*.theme" }).result();
        
        if (result.size())
            return result[0];
        
        return std::nullopt;
    }

    return std::nullopt;
}   

void MenuOption::setColors(const std::array<sf::Color, 6>& theme)
{
    text.setFillColor(theme[3]);
    onHoverColor = theme[4];
}

void MenuOption::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
    target.draw(cover, states);
    target.draw(text, states);
}

void MenuOption::fitText(sf::Vector2f size)
{
    for (uint8_t i = 1; true; i++)
    {
        text.setCharacterSize(i);
        
        auto tSize = text.getGlobalBounds().getSize();
        
        if (tSize.x >= size.x || tSize.y >= size.y)
        {
            text.setCharacterSize(i - 9);
            return;
        }
    }
}