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
#include "ManagedText.hpp"
#include "f_common.hpp"
namespace zf
{
    ManagedText::ManagedText()
    {
    }
    ManagedText::ManagedText(const sf::Text& t)
        : text(t)
    {
    }

    ManagedText::ManagedText(const sf::String& string, const sf::Font& font, unsigned int characterSize, const sf::Color& color)
        : text(string, font, characterSize)
    {
        text.setColor(color);
    }

    ManagedText::~ManagedText()
    {
        text.setString(" ");
    }

    void ManagedText::setText(const sf::Text& t)
    {
        text = t;
        updatePosition();
    }

    void ManagedText::setAlignment(const zf::AlignmentData& data, const sf::FloatRect& bBox)
    {
        alignmentData = data;
        boundingBox = bBox;
        updatePosition();
    }
    
    void ManagedText::setString(const sf::String& string)
    {
        text.setString(string);
        updatePosition();
    }

    void ManagedText::setPosition(sf::Vector2f position)
    {
        boundingBox.left = position.x;
        boundingBox.top = position.y;
        updatePosition();
    }

    void ManagedText::setPosition(float x, float y)
    {
        boundingBox.left = x;
        boundingBox.top = y;
        updatePosition();
    }

    void ManagedText::setColor(const sf::Color& color)
    {
        text.setColor(color);
    }

    void ManagedText::setAlpha(const sf::Uint8& alpha)
    {
        zf::setAlpha(text, alpha);
    }

    void ManagedText::updatePosition()
    {
        zf::alignText(text, boundingBox, alignmentData);
    }

    void ManagedText::draw(sf::RenderWindow& window)
    {
        window.draw(text);
    }
    void ManagedText::draw(sf::RenderWindow& window, const sf::Time& delta)
    {
        window.draw(text);
    }

    void ManagedText::update(sf::RenderWindow& window, const sf::Time& delta)
    {
    }
}
