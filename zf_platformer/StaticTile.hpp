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
