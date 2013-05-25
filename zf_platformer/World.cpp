#include "World.hpp"
#include "Tile.hpp"
#include "WorldObject.hpp"
#include "../zf_sfml/f_views.hpp"
#include "../zf_sfml/f_rect.hpp"
World::World(TwoDSpace<Tile*>* space)
{
    this->_space = space;
    this->_defaultFriction = Friction(0,0,0,0);
}

World::~World()
{
    for(TwoDSpace<Tile*>::Iterator it ; !it.end() ; ++it)
    {
        if(it.get() != 0)
        {
            delete it.get();
        }
    }
}

void World::setTileSize(int width, int height)
{
    _tileSize.width = width;
    _tileSize.height = height;
}


void World::update(sf::RenderWindow* window, sf::Time delta)
{
    for(int i = 0 ; i < _freeObjects.size() ; i++)
    {
        // update all free objects actions.
        _freeObjects[i]->updateAction(window,delta);
        // apply gravity
        _freeObjects[i]->applyMomentum(sf::Vector2f(0,1300) * delta.asSeconds());
    }
    // update all free objects position (collision check with the world's static object(impassable) )
    for(int i = 0 ; i < _freeObjects.size() ; i++)
    {
        _freeObjects[i]->updatePosition(delta,_defaultFriction); 
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
            _freeObjects.erase(_freeObjects.begin() + i);
        }
    }
}

void World::addFreeObject(WorldObject* object)
{
    _freeObjects.push_back(object);
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
