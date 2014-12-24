#include "enemytank.h"
#include "simplemove.h"
#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"
#include <ctime>
#include <QDebug>
#include <QTimer>
//extern QTimer* enemyTimer;
using namespace boost;
EnemyTank::EnemyTank() : BaseTank()
{
    qDebug() << "CreateEnemy";
    enemyTimer = new QTimer();
    connect(enemyTimer, SIGNAL(timeout()), this, SLOT(randomMove()));
    moveable = new SimpleMove(this);
    enemyTimer->start(500);
}

EnemyTank::EnemyTank(size_t x, size_t y) : BaseTank(x, y)
{
    moveable = new SimpleMove(this);
}

EnemyTank::~EnemyTank()
{
}
void EnemyTank::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Body
    painter->drawPixmap(0,0,50,50,QPixmap(":/images/enemytank.png"));
}

void EnemyTank::randomMove()
{
      static int i = 0;
      const int rangeMin = 0;
      const int rangeMax = 3;
      typedef boost::uniform_int<> NumberDistribution;
      typedef boost::mt19937 RandomNumberGenerator;
      typedef boost::variate_generator<RandomNumberGenerator&,
                                       NumberDistribution> Generator;

      NumberDistribution distribution(rangeMin, rangeMax);
      RandomNumberGenerator generator;
      Generator numberGenerator(generator, distribution);
      generator.seed(std::time(0)+i++);
      int direct = numberGenerator();
      if (this->direction != direct)
        move(direct);
      move(direct);
}
