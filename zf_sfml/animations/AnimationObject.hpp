/*
 *           DO WHAT THE **** YOU WANT TO PUBLIC LICENSE
 *                   Version 2, December 2004
 * 
 * Copyright (C) 2013 ZwodahS(ericnjf@gmail.com) 
 * zwodahs.wordpress.com
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
#ifndef _ZF_SFML_ANIMATIONS_ANIMATIONOBJECT_H_
#define _ZF_SFML_ANIMATIONS_ANIMATIONOBJECT_H_

#include <SFML/Graphics.hpp>
class AnimationInstruction;
class AnimationObject
{
    public:
        AnimationObject();
        ~AnimationObject();
        
        // return if this object is done animating
        bool done();
        // return done().
        bool update(sf::RenderWindow& window, sf::Time delta);
        void setInstruction(AnimationInstruction* _instruction);
        /**
         * Use this to pass a boolean pointer to check if this animation is complete.
         * This is probably the worst way to do it, but I have to stop working on framework and focus on the actual product for now.
         * I will find another better method for this in the future.
         * TODO
         */
        void setDoneVariable(bool* done);
        virtual void draw(sf::RenderWindow& window, sf::Time delta) = 0;
        virtual void setAlpha(float alpha) = 0;
        virtual void setPosition(sf::Vector2f position) = 0;
        virtual void movePosition(sf::Vector2f move) = 0;
        virtual void setColor(sf::Color color) = 0;
    private:
        bool* _done;
        AnimationInstruction* _instruction;
};
#endif
