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
//QTimer* enemyTimer;
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    //enemyTimer = new QTimer();
    game = new GameManager(":/xml/level1.xml");

    return app.exec();
}
