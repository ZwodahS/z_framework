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
#ifndef _ZF_SFML_FUNCTIONCOMMON_H_
#define _ZF_SFML_FUNCTIONCOMMON_H_
#include "iBoundable.hpp"
#include "../zf_common/Direction.hpp"
#include "../zf_common/AlignmentData.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
namespace zf
{
    void setAlpha(sf::Sprite& sprite, const sf::Int32 alpha, sf::Uint8 max = 255, sf::Uint8 min = 0);
    void setAlpha(sf::Text& text, sf::Uint8 alpha);
    void setColor(sf::Text& text, const sf::Color& color, const bool& changeAlpha = false);
    void setColor(sf::Sprite& sprite, const sf::Color& color, const bool& changeAlpha = false);
    void setColor(sf::VertexArray& array, const sf::Color& color, const bool& changeAlpha = false);
    void setString(sf::Text& text, const std::string& value);

    sf::Vector2f getTopLeftPosition(const sf::FloatRect& boundingBox, const sf::Vector2f& centerPoint);
    void setCenterPosition(iBoundable& boundable, const sf::Vector2f& position);
    sf::VertexArray toVertexArrayLinesStrip(const sf::FloatRect& bound);
    sf::VertexArray toVertexArrayQuads(const sf::FloatRect& bound);
    /**
     * Move the array to the position.
     * the position of vArray[0] is set to position 
     * and the rest of the position is set relative to the position.
     */
    sf::VertexArray calculateVertexArrayPosition(const sf::VertexArray& vArray, const sf::Vector2f& position);
    void setPosition(sf::VertexArray& array, const sf::Vector2f& position);
    /**
     * Move the array to the position.
     */
    void moveVertexArray(sf::VertexArray& vArray, const sf::Vector2f& position);
    /**
     * Get the vector modifier for this direction.
     * Similar to the one in Direction.hpp, except it return sf::Vector2i instead of grid.
     */
    sf::Vector2i getVectorModifier(const zf::Direction& direction);
};
#endif
