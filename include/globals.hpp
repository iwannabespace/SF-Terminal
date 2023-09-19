#include <SFML/Graphics/Color.hpp>
#include <array>

namespace Globals {
    namespace Themes {
        const std::array<sf::Color, 6> defaultTheme = {
            sf::Color { 0, 0, 0 },
            sf::Color { 255, 255, 255 },
            sf::Color { 40, 40, 40 },
            sf::Color { 255, 255, 255 },
            sf::Color { 70, 70, 70 },
            sf::Color { 0, 255, 0 },
        };
    }

    namespace Functions {
        std::vector<std::string> split(const std::string& str, const std::string& delim)
        {
            std::vector<std::string> result;
            size_t start = 0;
            size_t end = 0;

            if (str.find(delim) == std::string::npos)
                return std::vector<std::string>{};

            while ((end = str.find(delim, start)) != std::string::npos)
            {
                result.push_back(str.substr(start, end - start));
                start = end + delim.length();
            }

            std::string lastToken = str.substr(start);

            if (!lastToken.empty())
                result.push_back(lastToken);

            return result;
        }
    }
}

