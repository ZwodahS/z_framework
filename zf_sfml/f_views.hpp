#ifndef _ZF_SFML_FUNCTIONS_VIEWS_H_
#define _ZF_SFML_FUNCTIONS_VIEWS_H_
#include <SFML/Graphics.hpp>
#include <vector>

namespace zfviews
{
    sf::Vector2f topLeft(sf::View view);
    sf::Vector2f bottomRight(sf::View view);
    // return the start row / col and the number of tiles in this view.
    sf::IntRect viewToTileBounds(sf::View view, int rowSize, int colSize, int maxRow, int maxCol);
}
#endif
