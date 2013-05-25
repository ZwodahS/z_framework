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
#include "SpriteSheet.hpp"
#include <iostream>
SpriteSheet::SpriteSheet()
{
    managed = false;
    currRow = 0;
    currCol = 0;
    maxrow = 0;
    maxcol = 0;
}

SpriteSheet::SpriteSheet(sf::IntRect spriteSize, int row, int col)
{
    this->spriteSize = spriteSize;
    this->size = sf::IntRect(0,0,spriteSize.width*col,spriteSize.height*row);
    this->texture.create(size.width,size.height);
    currRow = 0;
    currCol = 0;
    maxrow = row;
    maxcol = col;
    bool managed = true;
}

TextureRegion SpriteSheet::createRegion(sf::Image image)
{
    sf::Vector2u imgSize = image.getSize();
    if(imgSize.x != this->spriteSize.width || imgSize.y != this->spriteSize.height)
    {
        return TextureRegion(); 
    }
    texture.update(image,currCol*spriteSize.width, currRow*spriteSize.height);
    TextureRegion returnRegion = TextureRegion(&texture,sf::IntRect(currCol*spriteSize.width,currRow*spriteSize.height,spriteSize.width,spriteSize.height));
    currCol++;
    if(currCol >= maxcol)
    {
        currCol = 0;
        currRow++;
        if(currRow >= maxrow)
        {
            currRow = 0; //just wrap it back. graphics error is better than runtime.
        }
    }
    return returnRegion;
}
