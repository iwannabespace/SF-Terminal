#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "menu.hpp"
#include "cursor.hpp"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <memory>
#include <array>

class Application
{
    public:
        Application(const std::string& title);
        ~Application();
        void run();
        void loadTheme(const std::filesystem::path& path);
    private:
        std::string handleConfigFiles() const;
    private:
        std::unique_ptr<sf::RenderWindow> window;
        Menu menu;
        Cursor cursor;
        sf::ContextSettings settings;
        sf::View view;
        std::array<sf::Color, 6> theme;
};

#endif