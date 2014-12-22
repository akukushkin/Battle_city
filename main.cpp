#include <QApplication>
#include <QGraphicsScene>
#include <math.h>
#include <QGraphicsView>
#include <QDebug>
#include "gamemanager.h"
#include <QtXml>

static const int TankCount = 1;

GameManager* game;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    game = new GameManager(":/xml/level1.xml");

    return app.exec();
}
