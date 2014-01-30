/*
 *           DO WHAT THE **** YOU WANT TO PUBLIC LICENSE
 *                   Version 2, December 2004
 * 
 * Copyright (C) 2013 ZwodahS(ericnjf@gmail.com) 
 * zwodahs.github.io
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
#include "SelectionBox.hpp"
namespace zf
{
    SelectionBox::SelectionBox(int width, int height, int maxOffset, int minOffset, float movementPerSec = 2)
    {
        this->_width = width;
        this->_height = height;
        this->_maxOffset = maxOffset;
        this->_minOffset = minOffset;
        this->_offset = 0;
        this->_multiplier = 1;
        this->_movement = movementPerSec;
    }

    void SelectionBox::setSprites(sf::Sprite topLeft, sf::Sprite topRight, sf::Sprite bottomRight, sf::Sprite bottomLeft)
    {
        this->_topLeft = topLeft;
        this->_topRight = topRight;
        this->_bottomRight = bottomRight;
        this->_bottomLeft = bottomLeft;
        _position = sf::Vector2f(0,0);
    }

    void SelectionBox::setPosition(sf::Vector2f newPosition)
    {
        _position = newPosition;
    }

    void SelectionBox::update(sf::RenderWindow& window, const sf::Time& delta)
    {
        _offset += _multiplier * (delta.asSeconds() * _movement);
        if(_multiplier == -1 && _offset <= _minOffset )
        {
            _multiplier = 1;
        }
        else if(_multiplier == 1 && _offset >= _maxOffset)
        {
            _multiplier = -1;
        }
        _topLeft.setPosition(_position.x-_offset, _position.y-_offset);
        _topRight.setPosition(_position.x+_offset+_width-_topRight.getGlobalBounds().width, _position.y-_offset);
        _bottomLeft.setPosition(_position.x-_offset,_position.y+_offset+_height-_bottomLeft.getGlobalBounds().height);
        _bottomRight.setPosition(_position.x+_offset+_width-_bottomRight.getGlobalBounds().width, _position.y+_offset+_height-_bottomRight.getGlobalBounds().height);
    }
    void SelectionBox::draw(sf::RenderWindow& window, const sf::Time& delta)
    {
        window.draw(_topLeft);
        window.draw(_topRight);
        window.draw(_bottomLeft);
        window.draw(_bottomRight);
    }
}
