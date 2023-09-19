#include "../include/cursor.hpp"

Cursor::Cursor()
{
}

Cursor::~Cursor()
{
}

void Cursor::update()
{
    int32_t elapsedTime = timer.getElapsedTime().asMilliseconds();

    if (elapsedTime >= 500)
    {    
        _visible = !_visible;
        timer.restart();
    }
}

void Cursor::setColor(sf::Color color)
{
    cursor.setFillColor(color);
}

void Cursor::setSize(sf::Vector2f size)
{
    cursor.setSize(size);
}

void Cursor::setPosition(sf::Vector2f position)
{
    cursor.setPosition(position);
}

sf::Vector2f Cursor::getSize() const
{
    return cursor.getSize();
}

sf::Vector2f Cursor::getPosition() const
{
    return cursor.getPosition();
}

bool Cursor::visible() const
{
    return _visible;
}

void Cursor::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
    _visible ? target.draw(cursor, states) : void();
}