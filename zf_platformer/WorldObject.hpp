#ifndef _GAME_WORLDOBJECT_H_
#define _GAME_WORLDOBJECT_H_
#include "ObjectPhysics.hpp"
#include "Friction.hpp"
#include <SFML/Graphics.hpp>
class World;
class WorldObject
{
    public:
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
        bool markedForRemoval;
        sf::Vector2f oldPosition; // a temporary variable to know where this object was in the previous frame
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
