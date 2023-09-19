#include "../include/menu.hpp"

Menu::Menu(sf::Vector2f size, sf::Color color)
    : option("import", { 80, size.y }, { 0, 0 })
{
    bar.setSize(size);
    bar.setFillColor(color);
    bar.setPosition({ 0, 0 });
}

Menu::~Menu()
{
}

void Menu::update()
{
}

void Menu::on_hover(const sf::RenderWindow& window)
{
    option.on_hover(window);
}

std::optional<std::string> Menu::on_click(const sf::RenderWindow& window)
{
    return option.on_click(window);
}

void Menu::setColors(const std::array<sf::Color, 6>& theme)
{
    bar.setFillColor(theme[2]);
    option.setColors(theme);
}

void Menu::setBarWidth(float width)
{
    bar.setSize({ width, bar.getSize().y });
}

void Menu::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
    target.draw(bar, states);
    target.draw(option, states);
}