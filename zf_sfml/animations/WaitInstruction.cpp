#include "WaitInstruction.hpp"
namespace zf
{
    WaitInstruction::WaitInstruction(float waitTime)
        :waitTimeLeft(waitTime)
    {
    }
    WaitInstruction::~WaitInstruction()
    {
    }

    bool WaitInstruction::update(sf::RenderWindow& window, sf::Time delta, AnimationObject& object)
    {
        if(waitTimeLeft < 0)
        {
            return true;
        }
        waitTimeLeft -= delta.asSeconds();
        return false;
    }

    bool WaitInstruction::isDone(AnimationObject& object)
    {
        return waitTimeLeft < 0;
    }
}
