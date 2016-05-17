#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QImage>
#include <QMap>

class GameObject
{
public:
    GameObject();
    float getX();
    float getY();
    QImage * getImage();
    int getWidth();
    int getHeight();
    size_t getCurrentFrame();
    virtual void nextFrame();
protected:
    float x, y;
    QImage *image;
    QSize frameSize;
    //size_t frames;
    QMap<size_t, size_t> frames;
    //size_t timePerFrame;
    size_t timeSinceCurrentFrame;
    size_t currentFrame;
};

#endif // GAMEOBJECT_H
