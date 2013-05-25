#include "StaticTile.hpp"

StaticTile::StaticTile()
{
}
StaticTile::~StaticTile()
{
}


void StaticTile::draw(sf::RenderWindow* window, sf::Time delta)
{
    window->draw(_drawSprite);
}

void StaticTile::positionUpdated()
{
}

sf::FloatRect StaticTile::getCollisionBound(int gridSize)
{
    return zf::Rect::toFloatRect(_location,gridSize,0);
}

void StaticTile::setSprite(sf::Sprite sprite)
{
    this->_drawSprite = sprite;
}
