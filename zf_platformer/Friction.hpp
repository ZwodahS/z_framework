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
#ifndef _ZF_PLATFORMER_FRICTION_H_
#define _ZF_PLATFORMER_FRICTION_H_
struct Friction
{
    float left; // friction when you moving left (-x)
    float right; // friction when you moving right(-x)
    float up; // friction when you moving up (-y)
    float down; // friction when you moving down (+y);
    
    Friction()
    {
        this->left = 0;
        this->right = 0;
        this->up = 0;
        this->down = 0;
    }
    Friction(float left , float right, float up , float down)
    {
        this->left = left;
        this->right = right;
        this->up = up;
        this->down = down;
    };
};
#endif
