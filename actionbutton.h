#ifndef ACTIONBUTTON_H
#define ACTIONBUTTON_H


#include <QWidget>
#include <QImage>
#include <QPainter>

class ActionButton : public QWidget
{
    Q_OBJECT
public:
    ActionButton(QString type, QImage iconImage, QSize iconImageSize);
    QString getType();
    QImage *getBackgroundImage();
    static QSize getBackgroundImageSize();
    int getFrame();
    void setHover(bool value);
    void redraw();
private:
    QString type;
    QImage *backgroundImage;
    int frame;
    QImage iconImage;
    QSize iconImageSize;
    void repaint();
signals:
    void pressed();
};



#endif // ACTIONBUTTON_H
