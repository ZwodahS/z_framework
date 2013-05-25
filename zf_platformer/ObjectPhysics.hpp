#ifndef _ZF_PLATFORMER_OBJECTPHYSICS_H_
#define _ZF_PLATFORMER_OBJECTPHYSICS_H_
#include <SFML/Graphics.hpp>

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
