#ifndef _ZF_COMMON_ZFINPUTS_H_
#define _ZF_COMMON_ZFINPUTS_H_

#include "InputState.hpp"
namespace zf
{
    class Input
    {
        public:
            static void processKey(InputState &inputState, bool newState)
            {
                inputState.lastDown = inputState.thisDown;
                inputState.thisDown = newState;
                inputState.thisPressed = inputState.thisDown && !(inputState.lastDown);
                inputState.thisHeld = inputState.thisDown && inputState.lastDown;
                inputState.thisReleased = !inputState.thisDown && inputState.lastDown;
            }
    };
}
#endif
