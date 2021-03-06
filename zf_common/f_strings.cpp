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
    std::vector<std::string> splitString(const std::string& str, const int& maxChar)
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

    std::vector<std::string> splitString(const std::string& originalString, const std::string& searchString)
    {
        std::vector<std::string> ss; 
        size_t lastFound = 0;
        size_t index = originalString.find(searchString);
        while(index != std::string::npos)
        {
            // if something is found, there 2 possibility
            // originalString = [Found][Rest]
            // originalString = [Rest][Found][Rest]
            if(lastFound == index) // this is the first case.
            {
                // add the search string
                ss.push_back(searchString);
            }
            else
            {
                // add the string before the search string.
                // // if index == lastFound , this will be 0, so it will pointless.
                ss.push_back(originalString.substr(lastFound, index - lastFound));
                // add the search string
                ss.push_back(searchString);
            }
            lastFound = index + searchString.size();
            // start searching from the end of the replaceString, such that the replaceString will never be part of the search
            index = originalString.find(searchString, lastFound);
        }

        if(lastFound != originalString.size()) // to add the rest of the string to the list
        {
            ss.push_back(originalString.substr(lastFound, originalString.size() - lastFound));
        }
        return ss;
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

    std::string& replaceString(std::string& newString, const std::string& searchString, const std::string& replaceString, const bool& multipleReplace)
    {
        size_t index = newString.find(searchString);
        if(multipleReplace)
        {
            while(index != std::string::npos)
            {
                // replace
                newString.replace(index, searchString.size(), replaceString);
                // start searching from the end of the replaceString, such that the replaceString will never be part of the search
                index = newString.find(searchString, index + replaceString.size());
            }
        }
        else
        {
            if(index != std::string::npos)
            {
                newString.replace(index, searchString.size(), replaceString);
            }
        }
        return newString;
    }

    std::string& replaceString(std::string& original, const std::string& searchString, const int& replaceInt, const bool& multipleReplace)
    {
        return replaceString(original, searchString, std::to_string(replaceInt), multipleReplace);
    }

    inline bool startsWith(const std::string& longStrings, const std::string& startString)
    {
        std::size_t index = longStrings.find(startString);
        return index == 0;
    }

    /**
     * These 2 functions are taken from
     * http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c
     */
    std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems) 
    {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) 
        {
            elems.push_back(item);
        }
        return elems;
    }


    std::vector<std::string> split(const std::string &s, char delim) 
    {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }

    int maxLength(const std::vector<std::string>& strings)
    {
        int l = 0;
        for(auto s : strings)
        {
            l = s.size() >= l ? s.size() : l;
        }
        return l;
    }
}


