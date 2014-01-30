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
#ifndef _Z_FRAMEWORK_ZF_COMMON_ROUTE_H_
#define _Z_FRAMEWORK_ZF_COMMON_ROUTE_H_
#include "Grid.hpp"
#include <vector>
namespace zf
{
    /**
     * Defines a route to take from a start point to end point.
     * I know I can store this as a vector but I kind of feel that abstracting this can allow me to 
     * provide a common implementation for path finding later, like using TwoDSpace.
     */
    struct Route
    {
        /**
         * This route include the start and end.
         * This route can be use in both direction.
         */
        std::vector<zf::Grid> path;

        /**
         * Create a 1-grid route, that start from a grid and ends at that grid.
         */
        Route(const zf::Grid& start = zf::Grid(0, 0));

        /**
         * Create a route following this path.
         */
        Route(const std::vector<zf::Grid>& path);

        /**
         * Return true if this route is for this start and end
         */
        bool isRouteFor(const zf::Grid& start, const zf::Grid& end) const;

        /**
         * if path is empty, zf::Grid(0, 0) is returned.
         */
        zf::Grid getStartPoint() const;

        /**
         * if path is empty, zf::Grid(0, 0) is returned.
         */
        zf::Grid getEndPoint() const;

        /**
         * Merge 2 route to form a new route.
         * This only works if route1.end = route2.start.
         * The new route will be stored in newRoute.
         * If the route cannot be merge, then false will be returned.
         * THIS DO NOT take care of repeating routes.
         * The pathfinding for that should be done elsewhere.
         * This only works IF and ONLY IF route1.start != route2.start, route1.end == route2.start, route2.end != route1.end
         * and route1 and route2 size > 1
         */
        static bool mergeRoute(const zf::Route& route1, const zf::Route& route2, zf::Route& newRoute);
        /**
         * Construct a route from path, and put it in the route object
         */
        static bool constructRoute(const std::vector<zf::Grid>& path, zf::Route& route);
    };
}

#endif
