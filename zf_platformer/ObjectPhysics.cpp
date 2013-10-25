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
#include "ObjectPhysics.hpp"

ObjectPhysics::ObjectPhysics()
{
    this->maxHorizontalVelocity = 0;
    this->maxDropVelocity = 0;
    this->maxUpwardVelocity = 0;
}
ObjectPhysics::~ObjectPhysics()
{
}

ObjectPhysics& ObjectPhysics::operator+=(const ObjectPhysics& rhs)
{
    this->maxHorizontalVelocity += rhs.maxHorizontalVelocity;
    this->maxDropVelocity += rhs.maxDropVelocity;
    this->maxUpwardVelocity += rhs.maxUpwardVelocity;
    return *this;
}

ObjectPhysics& ObjectPhysics::operator-=(const ObjectPhysics& rhs)
{
    this->maxHorizontalVelocity -= rhs.maxHorizontalVelocity;
    this->maxDropVelocity -= rhs.maxDropVelocity;
    this->maxUpwardVelocity -= rhs.maxUpwardVelocity;
    return *this;
}

sf::Vector2f ObjectPhysics::reduce(sf::Vector2f velocity)
{
    // check horizontal velocity
    if(velocity.x > 0)
    {
        velocity.x = velocity.x > maxHorizontalVelocity ? maxHorizontalVelocity : velocity.x;
    }
    else if(velocity.x < 0)
    {
        velocity.x = velocity.x < -(maxHorizontalVelocity) ? -maxHorizontalVelocity : velocity.x;
    }
    // check vertical velocity
    if(velocity.y > 0) // downwards
    {
        velocity.y = velocity.y > maxDropVelocity ? maxDropVelocity : velocity.y;
    }
    else if(velocity.y < 0)
    {
        velocity.y = velocity.y < -(maxUpwardVelocity) ? -maxUpwardVelocity : velocity.y;
    }
    return velocity;
}

ObjectPhysics operator+(ObjectPhysics lhs, const ObjectPhysics rhs)
{
    return lhs += rhs;
}

ObjectPhysics operator-(ObjectPhysics lhs, const ObjectPhysics rhs)
{
    return lhs -= rhs;
}
