//
// Created by lpsandaruwan on 3/13/17.
//

#include "Asteroid.h"


Asteroid::Asteroid(SDL_Rect* clip): Object(clip)
{
    velocityX = 0;
    velocityY = 0;
}

Asteroid::~Asteroid() {}

void Asteroid::move(const int *SCR_WIDTH, const int *SCR_HEIGHT)
{
    // move asteroid
    X += velocityX;
    Y += velocityY;

    // stop if ship meets frame edges
    if((X + spriteClip->w * 2 < 0) || (X - spriteClip->w) > *SCR_WIDTH)
    {
        X -= velocityX;
        destroyFlag = true;
    }

    if((Y + spriteClip->x * 2 < 0) || (Y - spriteClip->x) > *SCR_HEIGHT)
    {
        Y -= velocityY;
        destroyFlag = true;
    }
}

void Asteroid::setAutoMove(int identifier)
{
    // identifier 0 -set X axis velocity, 1 -set Y axis velocity, 2 -set both
    switch(identifier)
    {
        case 0:
            velocityX += axis_velocity;
            break;
        case 1:
            velocityY += axis_velocity;
            break;
        case 2:
            velocityX += axis_velocity;
            velocityY += axis_velocity;
            break;
        default:
            velocityX -= axis_velocity;
            velocityY -= axis_velocity;
            break;
    }
}