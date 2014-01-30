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
#include "Route.hpp"

namespace zf
{
    /**
     * Create a default 1 grid route
     */
    Route::Route(const zf::Grid& s)
    {
        path.push_back(s);
    }
    
    /**
     * Creates a route following this path
     */
    Route::Route(const std::vector<zf::Grid>& p)
        : path(p)
    {
    }

    bool Route::isRouteFor(const zf::Grid& s, const zf::Grid& e) const
    {
        if(path.size() == 0)
        {
            return false;
        }
        return path[0] == s && path[path.size() - 1] == e;
    }

    bool Route::mergeRoute(const zf::Route& route1, const zf::Route& route2, zf::Route& newRoute)
    {
        if(route1.path.size() == 0 || route2.path.size() == 0 || route1.getEndPoint() != route2.getStartPoint())
        {
            return false;
        }
        newRoute.path.clear();
        newRoute.path.insert(newRoute.path.end(), route1.path.begin(), route1.path.end());
        newRoute.path.insert(newRoute.path.end(), route2.path.begin() + 1, route2.path.end());
        return true;
    }
    
    bool Route::constructRoute(const std::vector<zf::Grid>& path, zf::Route& route)
    {
        if(path.size() == 0)
        {
            return false;
        }
        route.path = path;
        return true;
    }

    zf::Grid Route::getStartPoint() const
    {
        return path.size() == 0 ? zf::Grid(0, 0) : path.front();
    }

    zf::Grid Route::getEndPoint() const
    {
        return path.size() == 0 ? zf::Grid(0, 0) : path.back();
    }
}
