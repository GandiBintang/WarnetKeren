#include "timereal1.h"
#include <QTimer>
#include <QMainWindow>

timereal1::timereal1()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(realTimer()));
    timer->start(1000);
}
