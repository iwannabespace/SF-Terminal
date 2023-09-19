#ifndef CURSOR_HPP
#define CURSOR_HPP

#include "object.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class Cursor : public Object
{
    public:
        Cursor();
        ~Cursor();
        void update() override;
        void setColor(sf::Color color);
        void setSize(sf::Vector2f size);
        void setPosition(sf::Vector2f position);
        sf::Vector2f getSize() const;
        sf::Vector2f getPosition() const;
        bool visible() const;
    private:
        void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
    private:
        sf::RectangleShape cursor;
        sf::Clock timer;
        bool _visible = false;
};

#endif