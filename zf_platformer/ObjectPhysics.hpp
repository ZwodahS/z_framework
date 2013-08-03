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
#ifndef _ZF_PLATFORMER_OBJECTPHYSICS_H_
#define _ZF_PLATFORMER_OBJECTPHYSICS_H_
#include <SFML/Graphics.hpp>


/*
 * define some basic object physics
 */
struct ObjectPhysics
{
    ObjectPhysics();
    ~ObjectPhysics();

    float maxHorizontalVelocity;
    float maxDropVelocity;
    float maxUpwardVelocity;

    ObjectPhysics& operator+=(const ObjectPhysics &rhs);
    ObjectPhysics& operator-=(const ObjectPhysics &rhs);
    // reduce the velocity using the object physics as a constraint
    sf::Vector2f reduce(sf::Vector2f velocity);
};

ObjectPhysics operator-(ObjectPhysics lhs, const ObjectPhysics& rhs);
ObjectPhysics operator+(ObjectPhysics lhs, const ObjectPhysics& rhs);

#endif
