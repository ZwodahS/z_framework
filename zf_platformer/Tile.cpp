#include "../zf_sfml/f_rect.hpp"
#include "Tile.hpp"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::setLocation(Grid grid)
{
    this->_location = grid;
    positionUpdated();
}
void Tile::positionUpdated()
{
}

