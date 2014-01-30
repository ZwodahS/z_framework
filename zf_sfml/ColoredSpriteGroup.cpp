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
#include "ColoredSpriteGroup.hpp"
#include "f_common.hpp"
namespace zf
{
    ColoredSpriteGroup::ColoredSpriteGroup()
        :state(_state), bound(_bound), _state(-1), _bound(0,0,0,0)
    {
    }

    ColoredSpriteGroup::ColoredSpriteGroup(const ColoredSpriteGroup& copy)
        : state(_state), bound(_bound), 
          _state(copy.state), _bound(copy.bound), _colors(copy._colors), _mainSprite(copy._mainSprite)
    {
    }

    ColoredSpriteGroup::ColoredSpriteGroup(sf::Sprite mainSprite, std::vector<sf::Color> c)
        :state(_state), bound(_bound), _state(-1), _colors(c), _mainSprite(mainSprite)
    {
        _bound = mainSprite.getGlobalBounds();
        setState(c.size() == 0 ? -1 : 0);
    }

    void ColoredSpriteGroup::setState(int s)
    {
        if(s >= _colors.size() || s < 0)
        {

        }
        else if(_state == s)
        {
            // do nothing
        }
        else
        {
            _state = s;
            setColor(_colors[s]);
        }
    }
    int ColoredSpriteGroup::getState()
    {
        return _state;
    }

    void ColoredSpriteGroup::setPosition(sf::Vector2f position) 
    {
        _mainSprite.setPosition(position);
        _bound = _mainSprite.getGlobalBounds();
    }

    void ColoredSpriteGroup::setPosition(float x, float y)
    {
        setPosition(sf::Vector2f(x, y));
    }

    void ColoredSpriteGroup::draw(sf::RenderWindow& window, const sf::Time& delta)
    {
        window.draw(_mainSprite);
    }

    void ColoredSpriteGroup::setAlpha(float alpha)
    {
        zf::setAlpha(_mainSprite, alpha);
    }

    void ColoredSpriteGroup::move(sf::Vector2f moveVec)
    {
        sf::Vector2f newPos = getPosition() + moveVec;
        setPosition(newPos);
    }
    void ColoredSpriteGroup::setColor(sf::Color color)
    {
        zf::setColor(_mainSprite, color);
    }

    sf::Vector2f ColoredSpriteGroup::getPosition()
    {
        return sf::Vector2f(_bound.left, _bound.top);
    }
    
    void ColoredSpriteGroup::setSprite(sf::Sprite sprite)
    {
        _mainSprite = sprite;
        _mainSprite.setColor(_colors[_state]);
    }
    
    void ColoredSpriteGroup::setScale(float scaleX, float scaleY)
    {
        //TODO : Do nothing for now
    }

    ColoredSpriteGroup& ColoredSpriteGroup::operator=(const ColoredSpriteGroup& rhs)
    {
        this->_colors = rhs._colors;
        this->_state = rhs._state;
        this->_bound = rhs._bound;
        this->_mainSprite = rhs._mainSprite;
        return *this;
    }

    bool ColoredSpriteGroup::contains(sf::Vector2f pos)
    {
        return _bound.contains(pos);
    }
}
