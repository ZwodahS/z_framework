#ifndef _GAME_WORLD_WORLD_H_
#define _GAME_WORLD_WORLD_H_

#include "../zf_common/TwoDSpace.hpp"
#include "Friction.hpp"
#include <SFML/Graphics.hpp>

#include <vector>
class Tile;
class WorldObject;
class World
{
    public:
        World(TwoDSpace<Tile*>* space);
        ~World();
        void setTileSize(int width, int height);
        void draw(sf::RenderWindow* window, sf::Time delta);
        void update(sf::RenderWindow* window, sf::Time delta);

        TwoDSpace<Tile*> getTiles(sf::FloatRect range);
        void addFreeObject(WorldObject* object);
    protected:
        TwoDSpace<Tile*>* _space;
        Friction _defaultFriction;
        std::vector<WorldObject*> _freeObjects; 
    

        sf::IntRect _tileSize;
};
#endif
