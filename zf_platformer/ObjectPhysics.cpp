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
}

ObjectPhysics& ObjectPhysics::operator-=(const ObjectPhysics& rhs)
{
    this->maxHorizontalVelocity -= rhs.maxHorizontalVelocity;
    this->maxDropVelocity -= rhs.maxDropVelocity;
    this->maxUpwardVelocity -= rhs.maxUpwardVelocity;
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
