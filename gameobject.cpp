#include "gameobject.h"

GameObject::GameObject()
{
    this->currentFrame = 0;
    this->timeSinceCurrentFrame = 0;
}

float GameObject::getX()
{
    return this->x;
}

float GameObject::getY()
{
    return this->y;
}

QImage *GameObject::getImage()
{
    return this->image;
}

int GameObject::getWidth()
{
    return this->frameSize.width();
}

int GameObject::getHeight()
{
    return this->frameSize.height();
}

size_t GameObject::getCurrentFrame()
{
    return this->currentFrame;
}

void GameObject::nextFrame()
{
    ++timeSinceCurrentFrame;

    if (frames.contains(currentFrame) && timeSinceCurrentFrame == frames[currentFrame])
    {
        if (frames.contains(currentFrame + 1))
        {
            ++currentFrame;
            timeSinceCurrentFrame = 0;
        }
        else
        {
            currentFrame = frames.keys().first();
            timeSinceCurrentFrame = 0;
        }
    }
}
