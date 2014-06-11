#ifndef _ZF_COMMON_F_SHORTCUT_H_
#define _ZF_COMMON_F_SHORTCUT_H_
namespace zf
{
    /**
     * short cut function to check if a value is within a range
     * min inclusive, max exclusive
     */
    template<class T>
    bool inRange(T value, T min, T max)
    {
        return value >= min && value < max;
    }
};
#endif
