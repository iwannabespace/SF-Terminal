#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics/Drawable.hpp>

class Object : public sf::Drawable
{
    protected:
        virtual void update() = 0;
};  

#endif