#ifndef _ZF_SFML_FUNCTIONS_RECT_H_
#define _ZF_SFML_FUNCTIONS_RECT_H_
#include "../zf_common/Grid.hpp"
namespace zf
{
    class Rect
    {
        public:
            static float right(sf::FloatRect rect)
            {
                return rect.left + rect.width - 1;
            }
            static float bottom(sf::FloatRect rect)
            {
                return rect.top + rect.height - 1;
            }
            static sf::Vector2f topLeft(sf::FloatRect rect)
            {
                return sf::Vector2f(rect.left,rect.top);
            }
            static sf::Vector2f bottomRight(sf::FloatRect rect)
            {
                return sf::Vector2f(right(rect), bottom(rect));
            }
            static sf::FloatRect toFloatRect(Grid grid, float gridsize, float gridspacing)
            {
                return sf::FloatRect(grid.col * (gridsize + gridspacing) , grid.row * (gridsize + gridspacing),gridsize,gridsize);
            }
    };
}
#endif
