/*
 *           DO WHAT THE **** YOU WANT TO PUBLIC LICENSE
 *                   Version 2, December 2004
 * 
 * Copyright (C) 2013 ZwodahS(ericnjf@gmail.com) 
 * zwodahs.wordpress.com
 * 
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 * 
 *           DO WHAT THE **** YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 * 
 *  0. You just DO WHAT THE **** YOU WANT TO.
 * 
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. 
 */
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
