#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>


class Elevator : public QObject
{
    Q_OBJECT
public:
    explicit Elevator(QObject *parent = nullptr);

signals:

private:
    int * floorQueue;
};

#endif // ELEVATOR_H
