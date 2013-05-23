#ifndef _ZF_COMMON_F_DEBUG_H
#define _ZF_COMMON_F_DEBUG_H
#include "Grid.hpp"
#include <iostream>
#include <string>
namespace zf
{
    void debug(std::string prefix, std::string msg);
    void debug(std::string prefix, Grid grid);
    void debug(std::string prefix, float f);
}
#endif
