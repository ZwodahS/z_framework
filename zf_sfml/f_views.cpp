#include "f_views.hpp"

namespace zfviews
{
    sf::Vector2f topLeft(sf::View view)
    {
        sf::Vector2f center = view.getCenter();
        sf::Vector2f size = view.getSize();
        return sf::Vector2f(center - (size/2.0f));
    }

    sf::Vector2f bottomRight(sf::View view)
    {
        sf::Vector2f center = view.getCenter();
        sf::Vector2f size = view.getSize();
        return sf::Vector2f(center + (size/2.0f));
    }
    sf::IntRect viewToTileBounds(sf::View view, int rowSize, int colSize, int maxRow, int maxCol)
    {
        sf::Vector2f topLeft = zfviews::topLeft(view);
        sf::Vector2f bottomRight = zfviews::bottomRight(view);
        sf::IntRect rect = sf::IntRect(0,0,0,0);
        rect.left = (int)(topLeft.x / colSize);
        rect.top = (int)(topLeft.y / rowSize);
        rect.width = (int)(bottomRight.x / colSize);
        rect.height = (int)(bottomRight.y / rowSize);
        rect.left = rect.left <= 0 ? 0 : rect.left - 1;
        rect.top = rect.top <= 0 ? 0 : rect.top - 1;
        rect.width = rect.width >= maxCol ? maxCol : rect.width + 1;
        rect.height = rect.height >= maxRow ? maxRow : rect.height + 1;
        return rect;
    }
}
