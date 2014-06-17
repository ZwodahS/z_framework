#ifndef _ZF_COMMON_F_SHORTCUT_H_
#define _ZF_COMMON_F_SHORTCUT_H_
namespace zf
{
    /**
     * short cut function to check if a value is within a range
     * min inclusive, max exclusive
     */
    template<class T>
    bool inRange(const T& value, const T& min, const T& max)
    {
        return value >= min && value < max;
    }

    /**
     * short cut function to bound a value within 2 values
     * min inclusive, max inclusive
     */
    int bound(const int& value, const int& min, const int& max);
};
#endif
