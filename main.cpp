#include <QApplication>
#include <QGraphicsScene>
#include <math.h>
#include <QGraphicsView>
#include "tank.h"

#define WIDHT_SCENE 800
#define HEIGHT_SCENE 600

static const int TankCount = 1;

//! [0]
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene();
    Tank *tank = new Tank();
    tank->setRect(0, 0, 100, 100);
    scene->addItem(tank);

    tank->setFlag(QGraphicsItem::ItemIsFocusable);
    tank->setFocus();

    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(WIDHT_SCENE, HEIGHT_SCENE);
    scene->setSceneRect(0, 0, WIDHT_SCENE, HEIGHT_SCENE);

    tank->setPos(view->width()/2, view->height() - tank->rect().height());

    return app.exec();
}
//! [6]
