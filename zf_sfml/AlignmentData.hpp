#ifndef _ZF_SFML_ALIGNMENTDATA_H_
#define _ZF_SFML_ALIGNMENTDATA_H_
#include "../zf_common/Alignment.hpp"
#include <SFML/System.hpp>
namespace zf
{
    struct AlignmentData
    {
        AlignmentX alignmentX;
        AlignmentY alignmentY;
        sf::Vector2f offset;
    };
}
#endif
