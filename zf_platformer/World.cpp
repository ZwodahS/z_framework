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
#include "World.hpp"
#include "Tile.hpp"
#include "WorldObject.hpp"
#include "../zf_sfml/f_views.hpp"
#include "../zf_sfml/f_rect.hpp"
World::World()
{
    this->_space = 0;
}
World::World(TwoDSpace<Tile*>* space)
{
    this->_space = space;
}
World::~World()
{
    if(_space != 0 )
    {
        for(TwoDSpace<Tile*>::Iterator it = _space->iteratesColRow() ; !it.end() ; ++it)
        {
            if(it.get() != 0)
            {
                delete it.get();
            }
        }
    }
    for(int i = 0 ; i < _freeObjects.size() ; i++)
    {
        if(_freeObjects[i]->managedByWorld)
        {
            delete _freeObjects[i];
        }
    }
}
// set the size of each tile
void World::setTileSize(int size)
{
    _tileSize.width = size;
    _tileSize.height = size;
}
// update
void World::update(sf::RenderWindow* window, sf::Time delta)
{
    for(int i = 0 ; i < _freeObjects.size() ; i++)
    {
        // update all free objects actions.
        _freeObjects[i]->updateAction(window,delta);
        // apply gravity 
        _freeObjects[i]->applyMomentum(getMomentum(_freeObjects[i]) * delta.asSeconds());
    }
    // update all free objects position (collision check with the world's static object(impassable) )
    for(int i = 0 ; i < _freeObjects.size() ; i++)
    {
        _freeObjects[i]->updatePosition(delta,getFriction(_freeObjects[i])); 
    }
    // for each object, check collision with each other objects
    for(int i = 0 ; i < _freeObjects.size() ; i++)
    {
        for(int j = i+1 ; j < _freeObjects.size() ; i++)
        {
            // test for collision
            // if collide then call a collide method for both side.
            sf::FloatRect intersect;
            if(_freeObjects[i]->getCollisionBound().intersects(_freeObjects[i]->getCollisionBound(),intersect))
            {
                _freeObjects[i]->applyCollision(_freeObjects[j],delta,intersect);
                _freeObjects[j]->applyCollision(_freeObjects[i],delta,intersect);
            } 
        }
    }
    // for each object , if they are marked for removal, then remove it from list)
    for(int i = _freeObjects.size() - 1; i >= 0 ; i--)
    {
        if(_freeObjects[i]->markedForRemoval)
        {
            if(_freeObjects[i]->managedByWorld)
            {
                delete _freeObjects[i];
            }
            _freeObjects.erase(_freeObjects.begin() + i);
        }
    }
}
// add a free object to this world.
void World::addFreeObject(WorldObject* object)
{
    _freeObjects.push_back(object);
    object->setCurrentWorld(this);
}

void World::draw(sf::RenderWindow* window, sf::Time delta)
{
    sf::IntRect rect = zf::View::viewToTileBounds(window->getView(),_tileSize.height, _tileSize.width, _space->row, _space->col);
    Grid start = Grid(rect.top,rect.left);
    Grid end = Grid(rect.height,rect.width);
    for(TwoDSpace<Tile*>::Iterator it = _space->iteratesColRow(start,end) ; !(it.end()) ; ++it)
    {
        Tile* tile = it.get();
        if(tile != 0)
        {
            tile->draw(window,delta);
        }
    }
    
    for(int i = 0 ; i < _freeObjects.size() ; i++)
    {
        _freeObjects[i]->draw(window,delta);
    }
}

TwoDSpace<Tile*> World::getTiles(sf::FloatRect range)
{
    sf::Vector2f topLeft = zf::Rect::topLeft(range);
    sf::Vector2f bottomRight = zf::Rect::bottomRight(range);
    Grid topLeftGrid = Grid::toGrid(topLeft.x,topLeft.y,_tileSize.width,0);
    Grid bottomRightGrid = Grid::toGrid(bottomRight.x,bottomRight.y,_tileSize.width,0);
    return _space->subspace(topLeftGrid, bottomRightGrid);    
}

Friction World::getFriction(WorldObject* object)
{
    return Friction(0,0,0,0);
}

sf::Vector2f World::getMomentum(WorldObject* object)
{
    return sf::Vector2f(0,1000);
}
