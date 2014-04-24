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
#ifndef _ZF_COMMON_FUNCTIONALIGNMENT_H_
#define _ZF_COMMON_FUNCTIONALIGNMENT_H_
namespace zf
{
    void alignSpriteCenter(sf::Sprite& sprite, const sf::Vector2f& position);
    void alignText(sf::Text& text, const sf::Vector2f& position, const AlignmentData& alignmentData);
    void alignText(sf::Text& text, const sf::FloatRect& bound, const AlignmentData& alignmentData);
    sf::FloatRect alignRect(const sf::FloatRect& outerBound, sf::FloatRect innerBound, const AlignmentData& alignmentData);
    // can't put this in the cpp
    template <typename T>
    sf::Rect<T> moveRectanglePosition(const sf::Rect<T>& rect, const sf::Vector2<T>& moveVec)
    {
        return sf::Rect<T>(rect.left + moveVec.x, rect.top + moveVec.y, rect.width, rect.height); 
    }
}
#endif
