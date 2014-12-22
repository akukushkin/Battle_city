#ifndef OBJECTS_H
#define OBJECTS_H

#include <QObject>

class ObjectS : public QObject
{
    Q_OBJECT
public:
    explicit ObjectS(QObject *parent = 0);

signals:

public slots:

};

#endif // OBJECTS_H
