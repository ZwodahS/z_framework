#ifndef _ZF_PLATFORMER_STATICTILE_H_
#define _ZF_PLATFORMER_STATICTILE_H_
#include "Tile.hpp"
#include "../zf_sfml/f_rect.hpp"
#include <SFML/Graphics.hpp>
class StaticTile : public Tile
{
    public:
        StaticTile();
        ~StaticTile();

        virtual void draw(sf::RenderWindow* window, sf::Time delta);
    protected:
        void setSprite(sf::Sprite sprite);
        virtual void positionUpdated();
        sf::Sprite _drawSprite;
        virtual sf::FloatRect getCollisionBound(int gridSize);
};
#endif
