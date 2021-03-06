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
#include "Button.hpp"
#include "../zf_sfml/f_sfml.hpp"
#include "../zf_common/f_alignment.hpp"
#include <iostream>
namespace zf
{
    Button::Button()
        :_buttonType(None)
    {
    }

    Button::Button(sf::Sprite selectedSprite, sf::Sprite unselectedSprite)
        :_buttonType(TSB), _state(0), _internalStateManaged(true)
    {
        _sprites.push_back(unselectedSprite);
        _sprites.push_back(selectedSprite);
        _clickBound = unselectedSprite.getGlobalBounds();
        updatePosition();
    }

    Button::Button(sf::Sprite selectedSprite, sf::Sprite unselectedSprite, sf::Text text)
        :_buttonType(TSTB), _state(0), _internalStateManaged(true)
    {
        _textPositionData.alignmentX = zf::X_Center;
        _textPositionData.alignmentY = zf::Y_Center;
        _textPositionData.offset = sf::Vector2f(0,0);
        _sprites.push_back(unselectedSprite);
        _sprites.push_back(selectedSprite);
        _texts.push_back(text);
        _clickBound = unselectedSprite.getGlobalBounds();
        updatePosition();
    }
    Button::Button(sf::Sprite selectedSprite, sf::Sprite unselectedSprite, sf::Text text, AlignmentData pData)
        :_buttonType(TSTB), _textPositionData(pData), _state(0), _internalStateManaged(true)
    {
        _sprites.push_back(unselectedSprite);
        _sprites.push_back(selectedSprite);
        _texts.push_back(text);
        _clickBound = unselectedSprite.getGlobalBounds();
        updatePosition();
    }

    Button::Button(std::vector<sf::Sprite> sprites, sf::Text text, bool managed)
        :_buttonType(MSTB), _sprites(sprites), _state(0), _internalStateManaged(managed)
    {
        _textPositionData.alignmentX = zf::X_Center;
        _textPositionData.alignmentY = zf::Y_Center;
        _textPositionData.offset = sf::Vector2f(0,0);
        _clickBound = _sprites[0].getGlobalBounds();
        _texts.push_back(text);
        updatePosition();
    }
    Button::Button(std::vector<sf::Sprite> sprites, sf::Text text, AlignmentData position, bool managed)
        :_buttonType(MSTB), _textPositionData(position), _sprites(sprites), _state(0), _internalStateManaged(managed)
    {
        _texts.push_back(text);
        updatePosition();
    }

    void Button::setState(int state)
    {
        // dafaq did I just wrote ?
        // check that the state value is between 0(inclusive) and _sprites.size(exclusive).
        // If the value is out of bound, then do nothing.
        // Else we change the value.
        // So Simple !? :D
        _state = _sprites.size() <= state ? _state : state < 0 ? _state : state;
    }

    int Button::getState() const 
    {
        return _state;
    }

    bool Button::contains(sf::Vector2f mousePosition) const
    {
        return _clickBound.contains(mousePosition);
    }

    void Button::update(sf::RenderWindow& window, const sf::Time& delta, const zf::Mouse& mouse)
    {
        if(_internalStateManaged)
        {
            if(_buttonType == TSB || _buttonType == TSTB)
            {
                _state = _clickBound.contains(mouse.getWorldPosition(window)) ? 1 : 0;
            }
            else if(_buttonType == MSTB)
            {
                _state = _state > 1 ? _state : _clickBound.contains(mouse.getWorldPosition(window)) ? 1 : 0;
            }
        }
    }

    void Button::draw(sf::RenderWindow& window)
    {
        if(_buttonType == TSB || _buttonType == TSTB || _buttonType == MSTB)
        {
            window.draw(_sprites[_state]);
        }
        if(_buttonType == TSTB || _buttonType == MSTB)
        {
            window.draw(_texts[0]);
        }
    }

    void Button::setPosition(sf::Vector2f position)
    {
        _clickBound.left = position.x;
        _clickBound.top = position.y;
        updatePosition();
    }

    void Button::setPosition(float x, float y)
    {
        _clickBound.left = x;
        _clickBound.top = y;
        updatePosition();
    }

    void Button::setString(std::string displayString)
    {
        // this is all i have now but in case i add a new type , i shall do a check.
        if(_buttonType == TSTB || _buttonType == MSTB)
        {
            zf::setString(_texts[0], displayString);
            updatePosition();
        }
    }

    Button& Button::setTextColor(const sf::Color& color)
    {
        // this is all i have now but in case i add a new type , i shall do a check.
        if(_buttonType == TSTB || _buttonType == MSTB)
        {
            _texts[0].setColor(color);
        }
        return *this;
    }

    void Button::updatePosition()
    {
        if(_buttonType == TSB || _buttonType == TSTB || _buttonType == MSTB)
        {
            // update all sprite position
            for(std::vector<sf::Sprite>::iterator it = _sprites.begin() ; it != _sprites.end() ; ++it)
            {
                (*it).setPosition(_clickBound.left, _clickBound.top);
            }
        }
        if(_buttonType == TSTB || _buttonType == MSTB)
        {
            sf::FloatRect p = _texts[0].getGlobalBounds();
            alignText(_texts[0], _clickBound, _textPositionData);
            p = _texts[0].getGlobalBounds();
        }
    }
}
