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
#ifndef _ZF_SFML_ANIMATIONS_SINGLEANIMATOR_H_
#define _ZF_SFML_ANIMATIONS_SINGLEANIMATOR_H_
#include <SFML/Graphics.hpp>
#include "AnimatableObject.hpp"
/**
 * This class is used to animate one single iAnimatable
 * Note that this is a very basic animator, only one instruction at one time.
 */
namespace zf
{
    class CompositeInstruction;
    class AnimationInstruction;
    class iAnimatable;
    class SingleAnimator
    {
    public:
        SingleAnimator(iAnimatable& iAnimatable);

        bool update(sf::RenderWindow& window, const sf::Time& delta);
        bool fade(int startingAlpha, int targetAlpha, float time);
        bool moveTo(sf::Vector2f target, float time);
        bool move(sf::Vector2f moveVec, float duration);
        CompositeInstruction* composite(bool ordered = false); // use this to construct the instructionn for the method below.
        bool composite(CompositeInstruction* instruction);
        AnimatableObject object;

        bool isAnimating() const;
    private:
        // instead of leting AnimationObject handles the instruction, i going to do
        // it myself here instead.
        AnimationInstruction* _instruction;
    };
}
#endif
