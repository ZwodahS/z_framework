#include "f_shortcut.hpp"

namespace zf
{
    int bound(const int& value, const int& min, const int& max)
    {
        return value < min ? min : value > max ? max : value;
    }
};
