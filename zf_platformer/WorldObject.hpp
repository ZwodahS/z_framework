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
#ifndef _GAME_WORLDOBJECT_H_
#define _GAME_WORLDOBJECT_H_
#include "ObjectPhysics.hpp"
#include "Friction.hpp"
#include <SFML/Graphics.hpp>
class World;
class WorldObject
{
    public:
        // default position is (0,0), a null world and managedByWorld defaulted to false
        WorldObject();
        // default position is (0,0), world = world and managedByWorld = true.
        WorldObject(World* world);
        ~WorldObject();

        // apply a force to this object. force only exist for one frame
        // This is used to do movement most of time.
        // the force vector is the raw value before delta is calculated
        virtual void applyForce(sf::Vector2f force); 
        // apply a momentum to this object.
        virtual void applyMomentum(sf::Vector2f momentum);
        virtual void removeMomentum(bool horizontal = true, bool vertical = true);
        // set the position of the world object.
        // if hardmove is true, then the old position is also set to the position.
        // if hardmove is false, then the old position is unchanged.
        virtual void setPosition(sf::Vector2f position, bool hardmove = false);
        
        // set the object physics
        virtual void setObjectPhysics(ObjectPhysics objectPhys);
        virtual void draw(sf::RenderWindow* window, sf::Time delta) = 0; 
        // update functions
        virtual void updateAction(sf::RenderWindow* window, sf::Time delta) = 0;
        virtual void updatePosition(sf::Time delta, Friction friction);
        virtual void applyCollision(WorldObject* object, sf::Time delta,sf::FloatRect intersect) = 0;
        // get the current collision bound of the unit.
        virtual sf::FloatRect getCollisionBound() = 0;
        // get the current collision bound if the unit is in a specific position
        virtual sf::FloatRect getCollisionBound(sf::Vector2f position) = 0;
        const sf::Vector2f &position;
        // a variable used to determine if this object is to be removed in this frame.
        bool markedForRemoval; 
        // a variable to determine if this object is tied to the world. if true, whenever the world is destroyed, this object is also freed
        bool managedByWorld;
        // a temporary variable to know where this object was in the previous frame
        sf::Vector2f oldPosition; 
        virtual void setCurrentWorld(World* world);
    protected:
        World* _world;        
        sf::Vector2f _position;
        ObjectPhysics _physics;
        sf::Vector2f _momentum; // momentum is applied every frame.
        sf::Vector2f _force; // force is only applied once, and then it will be reset.

    private:
        sf::FloatRect expandRect(sf::FloatRect rect, float amount);
};
#endif
