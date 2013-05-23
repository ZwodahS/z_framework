#include "f_debug.hpp"
namespace zf
{
    void debug(std::string prefix, std::string msg)
    {
        std::cout << prefix << ":" << msg << std::endl;
    }
    void debug(std::string prefix, Grid grid)
    {
        std::cout << prefix << ": Row[" << grid.row << "] Col[ " << grid.col << "]" <<  std::endl;
    }
    void debug(std::string prefix, float f)
    {
        std::cout << prefix << ":" << f << std::endl;
    }
}
