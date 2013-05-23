#include "f_debug.hpp"
namespace zf
{
    void debug(std::string prefix, sf::FloatRect rect)
    {
        std::cout << prefix << ":" << rect.left << " " << rect.top << " " << rect.width << " " << rect.height << std::endl;
    }

    void debug(std::string prefix, sf::Vector2f vect)
    {
        std::cout << prefix << ":" << vect.x << " " << vect.y << std::endl;
    }
}
