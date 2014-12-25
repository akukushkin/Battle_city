#include <QApplication>
#include <QGraphicsScene>
#include <math.h>
#include <QGraphicsView>
#include <QDebug>
#include "gamemanager.h"
#include <QtXml>
#include <QTimer>

static const int TankCount = 1;

GameManager* game;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    app.setOverrideCursor(Qt::BlankCursor);
    game = new GameManager((char*)":/xml/level1.xml");

    return app.exec();
}
