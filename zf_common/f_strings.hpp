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
#ifndef _ZF_COMMON_F_STRINGS_H_
#define _ZF_COMMON_F_STRINGS_H_
#include <vector>
#include <string>
namespace zf
{
    std::vector<std::string> tokenize(std::string);
    std::string createBlanks(int num);

    /**
     * search the original search for "searchString", and replace all instances with "replaceString"
     * set multiple replace to false if you only want to replace the first instances.
     */
    std::string& replaceString(std::string& original, const std::string& searchString, const std::string& replaceString, const bool& multipleReplace = true);
    std::string& replaceString(std::string& original, const std::string& searchString, const int& replaceInt, const bool& multipleReplace = true);

    /**
     * Split a single strings into multiple strings, 
     * each string in the return list have a maximum characters of "maxChar"
     */
    std::vector<std::string> splitString(const std::string& str, const int& maxChar);
    /**
     * Search the searchString from the originalString, and split them from the originalString.
     * the list of strings are in proper order.
     * No "space" are required.
     */
    std::vector<std::string> splitString(const std::string& originalString, const std::string& searchString);

    inline bool startsWith(const std::string& longStrings, const std::string& startString);

    std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems) ;
    std::vector<std::string> split(const std::string &s, char delim);
}
#endif
