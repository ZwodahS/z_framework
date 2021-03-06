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
#include "Range.hpp"
#include "f_strings.hpp"
#include "f_conversion.hpp"
#include <iostream>
namespace zf
{
    int randomRange(int rng, Range<int> range)
    {
        if(range.min == range.max)
        {
            return range.min;
        }
        return randomRange(rng, range.min, range.max, range.minInclusive, range.maxInclusive);
    }
    
    int randomRange(int rng, int min, int max, bool minInclusive, bool maxInclusive)
    {
        max = maxInclusive ? max + 1: max;
        min = minInclusive ? min : min + 1;
        int v = max <= min ? 0 : rng % (max - min);
        v += min;
        return v;
    }

    bool toRange(const std::string& line, zf::Range<int>& out) 
    {
        auto splitStrings = zf::split(line, '-');
        if(splitStrings.size() != 2)
        {
            return false;
        }
        if(!zf::toInt(splitStrings[0], out.min))
        {
            return false;
        }
        if(!zf::toInt(splitStrings[1], out.max))
        {
            return false;
        }
        return true;
    }
    
    std::string toString(const zf::Range<int>& range)
    {
        return std::to_string(range.min) + "-" + std::to_string(range.max);
    }
}
