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
#ifndef _GAME_TILES_TILE_H_
#define _GAME_TILES_TILE_H_
#include "../zf_common/Grid.hpp"
#include <SFML/Graphics.hpp>
class Tile
{
    public:
        Tile();
        ~Tile();
        
        // set the location of this tile. 
        virtual void setLocation(Grid grid);
        // useful to identify the type of tile.
        // requires if there is a need to do type casting.
        virtual std::string getTileType() = 0;
        // abstract draw.
        virtual void draw(sf::RenderWindow* window, sf::Time delta) = 0;
        // update tile. 
        virtual void update(sf::RenderWindow* window, sf::Time delta) = 0;
        // collision bound, requires for collision bound
        virtual sf::FloatRect getCollisionBound() = 0;
        // get location of this object
        const Grid &location;
    protected:
        Grid _location;
        virtual void positionUpdated();
};
#endif
