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
#include "WorldObject.hpp"
#include "World.hpp"
#include "Tile.hpp"
#include "../zf_sfml/f_rect.hpp"
WorldObject::WorldObject()
    :position(_position)
{
    setCurrentWorld(0);
    setPosition(sf::Vector2f(0,0), true);
    markedForRemoval = false;
    managedByWorld = false;
}
WorldObject::WorldObject(World* world)
    :position(_position)
{
    setCurrentWorld(world);
    setPosition(sf::Vector2f(0,0), true);
    markedForRemoval = false;
    managedByWorld = true;
}

WorldObject::~WorldObject()
{
}

void WorldObject::setCurrentWorld(World* world)
{
    this->_world = world;
}

void WorldObject::setPosition(sf::Vector2f position, bool hardmove) // if hardmove is set, then move the old position to this position as well.
{
    _position.x = position.x;
    _position.y = position.y;
    if(hardmove)
    {
        oldPosition = position;
    }
}

void WorldObject::setObjectPhysics(ObjectPhysics objectPhys)
{
    this->_physics = objectPhys;
}


void WorldObject::applyForce(sf::Vector2f force)
{
    this->_force += force;
}

void WorldObject::applyMomentum(sf::Vector2f force)
{
    this->_momentum += force;
    this->_momentum = _physics.reduce(_momentum);   
}

void WorldObject::removeMomentum(bool horizontal , bool vertical)
{
    if(horizontal)
    {
        _momentum.x = 0;
    }
    if(vertical)
    {
        _momentum.y = 0;
    }
}

void WorldObject::updatePosition(sf::Time delta, Friction friction)
{
    // save the old position.
    oldPosition = _position;
    //depend on the direction of moving, iterates them in the correct order.
    sf::Vector2f applyMove = _force + _momentum;
    applyMove *= delta.asSeconds();
    // not sure if I need to restrict here or not.
    _physics.reduce(_momentum);
    bool reversedRow = false;
    bool reversedCol = false;
    if(applyMove.x < 0)
    {
        reversedCol = true;
    }
    if(applyMove.y < 0)
    {
       reversedRow = true;
    }
    // calculate the movement for this frame
    // apply the x first.
    //
    sf::Vector2f newPosition = oldPosition + sf::Vector2f(applyMove.x,0);
    sf::FloatRect selfCollisionBound = getCollisionBound(newPosition);
    sf::FloatRect expandedBound = expandRect(selfCollisionBound,8);
    // check for collision
    TwoDSpace<Tile*> tiles = _world->getTiles(expandedBound);
    for(TwoDSpace<Tile*>::Iterator it = tiles.iteratesRowCol(reversedCol,reversedRow); !it.end() ; ++it)
    {
        if(it.get() != 0)
        {
            sf::FloatRect tileCollisionBound = it.get()->getCollisionBound();
            if(applyMove.x > 0) // moving right
            {
                if(tileCollisionBound.intersects(selfCollisionBound))
                {
                    newPosition.x = tileCollisionBound.left - selfCollisionBound.width ;
                    if(_momentum.x > 0)
                    {
                        //TOOD hit wall , with a certain momentum.
                        _momentum.x = 0;
                    }
                    break;
                }
            }
            else if(applyMove.x < 0) // moving left
            {
                if(tileCollisionBound.intersects(selfCollisionBound))
                {
                    newPosition.x = zf::Rect::right(tileCollisionBound) + 1 ;
                    if(_momentum.x < 0)
                    {
                        _momentum.x = 0;
                    }
                    break;
                }
            }
        }
    }
    newPosition = newPosition + sf::Vector2f(0,applyMove.y);
    selfCollisionBound = getCollisionBound(newPosition);
    expandedBound = expandRect(selfCollisionBound,8);
    TwoDSpace<Tile*> tiles2 = _world->getTiles(expandedBound);
    for(TwoDSpace<Tile*>::Iterator it = tiles2.iteratesRowCol(reversedCol,reversedRow); !it.end() ; ++it)
    {
        if(it.get()!=0)
        {
            sf::FloatRect tileCollisionBound = it.get()->getCollisionBound();
            if(applyMove.y > 0) // moving down
            {
                if(tileCollisionBound.intersects(selfCollisionBound))
                {
                    newPosition.y = tileCollisionBound.top - selfCollisionBound.height;
                    if(_momentum.y > 0)
                    {
                        _momentum.y = 0;
                    }
                    break;
                }
            }
            else if(applyMove.y < 0) // moving up
            {
                if(tileCollisionBound.intersects(selfCollisionBound))
                {
                    newPosition.y = zf::Rect::bottom(tileCollisionBound) + 1;
                    if(_momentum.y < 0)
                    {
                        _momentum.y = 0;
                    }
                    break;
                }
            }
        }
    }
    setPosition(newPosition);
    // reduce the force to 0 for next frame
    _force = sf::Vector2f(0,0);
    // reduce the momentum
    if(_momentum.x > 0)
    {
        _momentum.x -= friction.right;
        _momentum.x = _momentum.x <= 0 ? 0 : _momentum.x;
    }
    else if(_momentum.x < 0)
    {
        _momentum.x += friction.left;
        _momentum.x = _momentum.x >= 0 ? 0 : _momentum.x;
    } 
    if(_momentum.y > 0)
    {
        _momentum.y -= friction.down;
        _momentum.y = _momentum.y <= 0 ? 0 : _momentum.y;
    }
    else if(_momentum.y < 0)
    {
        _momentum.y += friction.up;
        _momentum.y = _momentum.y >= 0 ? 0 : _momentum.y;
    }
}

sf::FloatRect WorldObject::expandRect(sf::FloatRect rect, float amount)
{
    rect.left -= amount/2;
    rect.top -= amount/2;
    rect.width += amount;
    rect.height += amount;
    return rect;
}
