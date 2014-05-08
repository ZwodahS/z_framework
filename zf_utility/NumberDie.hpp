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
/**
 * Number Die defines a die that faces are numbers.
 */
#ifndef _ZF_UTILITY_NUMBERDIE_H_
#define _ZF_UTILITY_NUMBERDIE_H_
#include <vector>
namespace zf
{
    class NumberDie
    {
    public:
        /**
         * Create a die with 0 faces.
         */
        NumberDie();
        /**
         * Create a die with X faces, and the faces' have value from 1 to X
         * if zeroIndex is true, then the faces have value from 0 to (X-1)
         */
        NumberDie(int X, bool zeroIndex = false);
    
        /**
         * Make a copy of this die.
         */
        NumberDie(const NumberDie& copy);
  
        NumberDie& operator= (const NumberDie& copy);

        /**
         * Get the value at the rolled face.
         * If the current face is out of range(_faces.size == 0 ), then 0 is returned.
         */
        int getCurrentValue() const;
        /**
         * Get the rolled faced value.
         */
        int getCurrentFaceIndex() const;
        
        /**
         * The const reference to all the faces.
         */
        const std::vector<int>& faces;
        /**
         * roll the die and return the VALUE at the rolled face.
         */
        int roll();
        /**
         * roll the die with a long value and return the value at the rolled face.
         */
        int roll(long rolled); 

    private:
        std::vector<int> _faces;
        int _currentFace;
    };
}
#endif
