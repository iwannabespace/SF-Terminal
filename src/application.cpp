#include "../include/application.hpp"
#include "../include/globals.hpp"
#include <fstream>
#include <iostream>

Application::Application(const std::string& title)
    : menu({ 700, 35 }, { 40, 40, 40 })
{
    settings.antialiasingLevel = 8;

    theme = Globals::Themes::defaultTheme;
    view.setSize({ 700, 600 });
    view.setCenter({ 350, 300 });

    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(700, 600), title, sf::Style::Default, settings);
    window->setFramerateLimit(60);

    cursor.setSize({ 5, 30 });
    cursor.setPosition({ 10, 10 });
    cursor.setColor(sf::Color::White);

    loadTheme(handleConfigFiles());
}

Application::~Application()
{
}

void Application::run()
{
    while (window->isOpen())
    {
        sf::Event event;

        while (window->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::MouseButtonReleased:
                {
                    auto result = menu.on_click(*window.get());

                    if (result.has_value())
                        loadTheme(result.value());

                    break;
                }
                case sf::Event::Resized:
                {
                    uint32_t width = event.size.width;
                    uint32_t height = event.size.height;

                    // if (width < 200)
                    //     window->setSize({ 200, height });
                    
                    // if (height < 100)
                    //     window->setSize({ width, 100 });

                    view.setSize({ (float)width, (float)height });
                    view.setCenter({ width / 2.f, height / 2.f });

                    menu.setBarWidth((float)width);
                    window->setView(view);

                    break;
                }
                default:
                    break;
            }
        }

        menu.on_hover(*window.get());

        cursor.update();

        window->setView(view);
        window->clear(theme[0]);
        //window->draw(cursor);
        window->draw(menu);
        window->display();
    }
}

void Application::loadTheme(const std::filesystem::path& path)
{
    if (!std::filesystem::exists(path))
        std::cerr << "Config file is empty thus will use the default theme!" << std::endl;

    else 
    {
        using namespace Globals;

        std::fstream file(path.string(), std::ios::in);
        std::string line;

        for (int8_t i = 0; i < 6; i++)
        { 
            std::getline(file, line);
            std::string rhs = line.substr(line.find("=") + 1);

            auto rgbs = Functions::split(rhs, ",");

            try {
                std::uint8_t red = std::stoi(rgbs[0]);
                std::uint8_t green = std::stoi(rgbs[1]);
                std::uint8_t blue = std::stoi(rgbs[2]);
                theme[i] = { red, green, blue };
            } catch (...) {
                theme = Themes::defaultTheme;
                break;
            }
        }

        file.close();
        file.open("config.cfg", std::ios::out);
        file << path.string() << std::endl;
        file.close();
    }

    menu.setColors(theme);
}

std::string Application::handleConfigFiles() const
{
    if (!std::filesystem::exists("config.cfg"))
    {
        std::fstream file("config.cfg", std::ios::out);
        file.close();
    }

    std::fstream file("config.cfg", std::ios::in);
    std::string filename;

    std::getline(file, filename);

    if (!std::filesystem::exists(filename))
    {   
        file.close();
        file.open("config.cfg", std::ios::out);
        file.close();

        filename = "";
    }

    return filename;
}