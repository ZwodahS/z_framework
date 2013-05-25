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
