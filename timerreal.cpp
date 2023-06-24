#include "timerreal.h"
#include <QTime>
#include <QTimer>

timerReal::timerReal()
{
    QTimer timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(realTimer()));
    timer.start(1000);
}
