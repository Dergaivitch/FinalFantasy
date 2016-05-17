#include "actionbutton.h"


ActionButton::ActionButton(QString type, QImage iconImage, QSize iconImageSize)
{
    this->type = type;
    this->backgroundImage = new QImage(getBackgroundImageSize().width() * 2, getBackgroundImageSize().height(), QImage::Format_ARGB32);
    this->frame = 0;
    this->iconImage = iconImage;
    this->iconImageSize = iconImageSize;

    repaint();
}

QString ActionButton::getType()
{
    return type;
}

QImage *ActionButton::getBackgroundImage()
{
    return backgroundImage;
}

QSize ActionButton::getBackgroundImageSize()
{
    return QSize(42, 50);
}

int ActionButton::getFrame()
{
    return frame;
}

void ActionButton::setHover(bool value)
{
    frame = (value) ? 1 : 0;
}

void ActionButton::redraw()
{
    repaint();
}

void ActionButton::repaint()
{
    QPainter painter(backgroundImage);

    painter.drawImage(0, 0, QImage(":/graphics/order-button.png"), 0, 0, -1, -1);

}

