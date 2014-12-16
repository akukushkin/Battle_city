#include <QApplication>
#include <QGraphicsScene>
#include <math.h>
#include <QGraphicsView>
#include "tank.h"
#include "field.h"

#define WIDHT_SCENE 600
#define HEIGHT_SCENE 600

static const int TankCount = 1;
QGraphicsScene *scene;
Field* field;
//! [0]
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QPixmap(":/images/1.jpg"));
    field = new Field();
    Tank *tank = new Tank();
    tank->setRect(0, 0, 50, 50);
    scene->addItem(tank);


    tank->setFlag(QGraphicsItem::ItemIsFocusable);
    tank->setFocus();

    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(WIDHT_SCENE, HEIGHT_SCENE);
    scene->setSceneRect(0, 0, WIDHT_SCENE, HEIGHT_SCENE);

    tank->setPos(175, view->height() - tank->rect().height()/2);

    return app.exec();
}
//! [6]
