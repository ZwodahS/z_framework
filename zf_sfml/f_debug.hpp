#ifndef _ZF_SFML_FUNCTIONS_DEBUG_H_
#define _ZF_SFML_FUNCTIONS_DEBUG_H_
#include <SFML/Graphics.hpp>
#include <iostream>
namespace zf
{
    void debug(std::string prefix, sf::FloatRect rect);

    void debug(std::string prefix, sf::Vector2f vect);

}
#endif
