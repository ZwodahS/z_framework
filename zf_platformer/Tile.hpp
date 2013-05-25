#ifndef _GAME_TILES_TILE_H_
#define _GAME_TILES_TILE_H_
#include "../zf_common/Grid.hpp"
#include <SFML/Graphics.hpp>
class Tile
{
    public:
        Tile();
        ~Tile();

        virtual std::string getTileType() = 0;
        virtual void draw(sf::RenderWindow* window, sf::Time delta) = 0;
        virtual void update(sf::RenderWindow* window, sf::Time delta) = 0;
        virtual void setLocation(Grid grid);
        virtual sf::FloatRect getCollisionBound() = 0;
        Grid getLocation();
    protected:
        Grid _location;
        virtual void positionUpdated();
};
#endif
