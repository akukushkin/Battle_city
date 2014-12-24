#include "gamemanager.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtXml>
#include <vector>
#include "tankfactory.h"

QGraphicsScene* scene;
QGraphicsView* view;
int ElementSize;

GameManager::GameManager(char* str){
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QPixmap(":/images/1.jpg"));
    view = new QGraphicsView(scene);
    std::vector<int> matrixField;
    QFile* file = new QFile(str);
    int h;
    int w;
    EnemyTank* ePlayer = NULL;
    if(file->open(QIODevice::ReadOnly | QIODevice::Text)){
        QXmlStreamReader xml(file);
        while(!xml.atEnd() && !xml.hasError()){
            qDebug() << xml.name().toString();
            QXmlStreamReader::TokenType token = xml.readNext();
            if (token == QXmlStreamReader::StartDocument)
                continue;
            if (token == QXmlStreamReader::StartElement){
                if (xml.name() == "width"){
                    xml.readNext();
                   // qDebug() << "!!! "<<  xml.text().toInt();
                    w = xml.text().toInt();
                }
                if (xml.name() == "height"){
                    xml.readNext();
                   // qDebug() << "!!! "<<  xml.text().toInt();
                    h = xml.text().toInt();
                }
                if (xml.name() == "fieldSize"){
                    xml.readNext();
                   // qDebug() << "!!! "<<  xml.text().toInt();
                    view->setFixedSize(xml.text().toInt(), xml.text().toInt());
                    scene->setSceneRect(0, 0, xml.text().toInt(), xml.text().toInt());
                }
                if (xml.name() == "fieldElement"){
                    xml.readNext();
                   // qDebug() << "!!! "<<  xml.text().toInt();
                    ElementSize = xml.text().toInt();
                }
                if (xml.name() == "string"){
                xml.readNext();
                QString s = xml.text().toString();

                for(int i = 0; i < w; i++)
                   matrixField.push_back(s[i].digitValue());
                }
            }
        }
    }
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    field = new Field(w,h,matrixField);
    playerTank = (Tank*)TankFactory::createTank(hPl);
    playerTank->setRect(0, 0, 50, 50);
    scene->addItem(playerTank);
    playerTank->setFlag(QGraphicsItem::ItemIsFocusable);
    playerTank->setFocus();
    for(int i=0; i < h;i++)
         for (int j = 0; j < w;j++){
             if ( matrixField[i+j*w] == 7)
                 playerTank->setPos(i*ElementSize-2*ElementSize,j*ElementSize);

             if ( matrixField[i+j*w] == 9)
             {
                 matrixField[i+j*w] = 0;
                 ePlayer = (EnemyTank*)TankFactory::createTank(ePl);
                 ePlayer->setRect(0, 0, 50, 50);
                 enemyPlayers.push_back(ePlayer);
                 scene->addItem(ePlayer);
                 ePlayer->setPos(i*ElementSize,j*ElementSize);
             }
         }
}

GameManager::~GameManager() {
    EnemyTank* player = NULL;
    scene->removeItem(playerTank);
    delete playerTank;
    delete field;
    scene->setBackgroundBrush(QPixmap(":/images/white.jpg"));
    scene->addText("GAME OVER!");
    while(enemyPlayers.size())
    {
        player = enemyPlayers.back();
        scene->removeItem(player);
        delete player;
        enemyPlayers.pop_back();
    }
}

void GameManager::destroyEnemyTank(BaseTank *)
{
    return;
}
