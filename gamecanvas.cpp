#include "gamecanvas.h"
#include <QDebug>
GameCanvas::GameCanvas(QWidget *parent) :
    QWidget(parent)
{
    ROAD_Y = 195;

    setMouseTracking(true);
}

void GameCanvas::setGameLogic(GameLogic *gameLogic)
{
    this->gameLogic = gameLogic;
}

void GameCanvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawImage(0, 0, QImage(":/graphics/background.png"), 0, -90, -1, -1, 0);

    drawGameObjects(painter);

    drawButtons(painter);

}


int GameCanvas::getButtonX(size_t index)
{
    return 10 + (ActionButton::getBackgroundImageSize().width() + 4) * index;
}

int GameCanvas::getButtonY(size_t)
{
    return 10;
}

void GameCanvas::mousePressEvent(QMouseEvent *mouseEvent)
{
    mousePressedX = mouseEvent->x();
    mousePressedY = mouseEvent->y();
}

void GameCanvas::mouseReleaseEvent(QMouseEvent *mouseEvent)
{
    size_t i = 0;

    foreach (ActionButton *key, gameLogic->getButtons())
    {
        int keyX = getButtonX(i);
        int keyY = getButtonY(i);

        if (isPointInArea(mouseEvent->x(), mouseEvent->y(), keyX, keyY, key->getBackgroundImageSize()))
        {
            if (isPointInArea(mousePressedX, mousePressedY, keyX, keyY, key->getBackgroundImageSize()) )
            {
                emit key->pressed();

                break;
            }
        }

        ++i;
    }
   /*тут блок
    i = 0;

    foreach (GameUnit *gunit, gameLogic->getGameObjects())
    {
        int keyX = get;
        int keyY = getButtonY(i);

        if (isPointInArea(mouseEvent->x(), mouseEvent->y(), keyX, keyY, gunit->frameSize()))
        {
            if (isPointInArea(mousePressedX, mousePressedY, keyX, keyY, gunit->frameSize()) )

            {
                GameLogic::enemy = gunit;
            }

    }*/
}

void GameCanvas::mouseMoveEvent(QMouseEvent *mouseEvent)
{
    size_t i = 0;

    foreach (ActionButton *key, gameLogic->getButtons())
    {
        int keyX = getButtonX(i);
        int keyY = getButtonY(i);

        if (isPointInArea(mouseEvent->x(), mouseEvent->y(), keyX, keyY, key->getBackgroundImageSize()))
        {
            key->setHover(true);
        }
        else
        {
            key->setHover(false);
        }

        ++i;
    }
}

bool GameCanvas::isPointInArea(int x, int y, int rect_x, int rect_y, QSize rect_size)
{
    return (x >= rect_x && y >= rect_y && x < rect_x + rect_size.width() && y < rect_y + rect_size.height());
}



void GameCanvas::drawButtons(QPainter &painter)
{
    size_t i = 0;

    foreach (ActionButton *key, gameLogic->getButtons())
    {
        painter.drawImage(getButtonX(i), getButtonY(i), *key->getBackgroundImage(), key->getFrame() * key->getBackgroundImageSize().width(), 0, key->getBackgroundImageSize().width(), key->getBackgroundImageSize().height());
        ++i;
    }
}



void GameCanvas::drawGameObjects(QPainter &painter)
{
    foreach (GameObject *object, gameLogic->getGameObjects())
    {
        painter.drawImage((int)object->getX(), ROAD_Y - object->getHeight() - (int)object->getY(), *object->getImage(), object->getCurrentFrame() * object->getWidth(), 0, object->getWidth(), object->getHeight());

        GameUnit *gameUnit = dynamic_cast<GameUnit *>(object);

        if (gameUnit)
        {
            drawHealthBar(painter, gameUnit);
        }


    }
}

void GameCanvas::drawHealthBar(QPainter &painter, GameUnit *unit)
{
    int padding_left = 1;
    int padding_right = 1;
    int bottom_margin = 10;
    int border_width = 1;
    int bar_height = 5;

    painter.fillRect((int)unit->getX() + padding_left, ROAD_Y - unit->getHeight() - (int)unit->getY() - bottom_margin, unit->getWidth() - padding_left - padding_right, bar_height, QBrush(Qt::black));
    painter.fillRect((int)unit->getX() + padding_left + border_width, ROAD_Y - unit->getHeight() - (int)unit->getY() - bottom_margin + border_width, (unit->getWidth() - border_width * 2 - padding_left - padding_right) * ((float)unit->getHealthPoints() / unit->getMaxHealthPoints()), bar_height - border_width * 2, QBrush(QColor(102, 204, 102, 255)));
}



void GameCanvas::onGameUpdated()
{
    repaint();
}
