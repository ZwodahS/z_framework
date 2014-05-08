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
#include "NumberDie.hpp"
#include <stdlib.h>
namespace zf
{
    NumberDie::NumberDie()
        : faces(_faces), _currentFace(0)
    {
    }
    
    NumberDie::NumberDie(int X, bool zeroIndex)
        : faces(_faces), _currentFace(0)
    {
        for(int i = zeroIndex ? 0 : 1; i < zeroIndex ? X : X + 1; i++)
        {
            _faces.push_back(i);
        }
    }

    NumberDie::NumberDie(const NumberDie& copy)
        : faces(_faces), _currentFace(copy._currentFace), _faces(copy._faces)
    {
    }
    
    NumberDie& NumberDie::operator= (const NumberDie& copy)
    {
        _faces = copy._faces;
        _currentFace = copy._currentFace;
        return *this;
    }
    
    int NumberDie::getCurrentValue() const
    {
        return (_currentFace >= 0 && _currentFace < _faces.size()) ? _faces[_currentFace] : 0;
    }

    int NumberDie::getCurrentFaceIndex() const
    {
        return _currentFace;
    }

    int NumberDie::roll()
    {
        return roll(rand());
    }

    int NumberDie::roll(long r)
    {
        _currentFace = _faces.size() == 0 ? 0 : r % _faces.size() ;
        return getCurrentValue();
    }
}

