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
#include "f_strings.hpp"
#include "f_conversion.hpp"
namespace zf
{
    std::vector<std::string> splitString(std::string str, int maxChar)
    {
        std::vector<std::string> strings;
        std::vector<std::string> tokens = zf::tokenize(str);
        std::string curr = "";
        int token = 0 ;
        for(std::vector<std::string>::iterator it = tokens.begin() ; it != tokens.end() ; ++it)
        {
            if(curr.size() + 1 + (*it).size() > maxChar)
            {
                if(token == 0)
                {
                    token = 0;
                    strings.push_back(*it);
                }
                else
                {
                    strings.push_back(curr);
                    curr = "";
                    curr += *it;
                    token = 1;
                }
            }
            else
            {
                if(token != 0)
                {
                    curr += " ";
                }
                curr += *it;
                token++;
            }
        }
        if(token != 0)
        {
            strings.push_back(curr);
        }
        return strings;
    }
    std::vector<std::string> tokenize(std::string str)
    {
        std::vector<std::string> strings;
        std::stringstream ss(str);
        std::string token;
        while(ss >> token)
        {
            strings.push_back(token);
        }
        return strings;
    }

    std::string createBlanks(int num)
    {
        std::string s;
        for(int i = 0; i < num ; i++)
        {
            s += " ";
        }
        return s;
    }
}

