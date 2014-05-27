#ifndef _ZF_COMMON_F_VECTOR_H_
#define _ZF_COMMON_F_VECTOR_H_
#include <vector>
namespace zf
{
    template <class T>
    T randomItem(std::vector<T> list, const T& defaultValue, long r)
    {
        return list.size() == 0 ? defaultValue : list[r % list.size()];
    }
}
#endif
