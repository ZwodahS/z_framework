#ifndef _ZF_PLATFORMER_FRICTION_H_
#define _ZF_PLATFORMER_FRICTION_H_
struct Friction
{
    float left; // friction when you moving left (-x)
    float right; // friction when you moving right(-x)
    float up; // friction when you moving up (-y)
    float down; // friction when you moving down (+y);
    
    Friction()
    {
        this->left = 0;
        this->right = 0;
        this->up = 0;
        this->down = 0;
    }
    Friction(float left , float right, float up , float down)
    {
        this->left = left;
        this->right = right;
        this->up = up;
        this->down = down;
    };
};
#endif
