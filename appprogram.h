#ifndef APPPROGRAM_H
#define APPPROGRAM_H

#include <QDialog>
#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QWidget>
#include<QtSql>
#include<QSqlDatabase>
#include <QMessageBox>
#include<QTime>
#include <QTimer>
#include <QGraphicsDropShadowEffect>
#include "timereal1.h"
#include "mainwindow.h"

namespace Ui {
class AppProgram;
}

class AppProgram : public QDialog
{
    Q_OBJECT

public:
    explicit AppProgram(QWidget *parent = nullptr);

    ~AppProgram();

private slots:
    void on_ControlPage_clicked();

    void on_RegisterPCPage_clicked();

    void on_RegisterUserPage_clicked();

    void on_AboutMePage_clicked();

    void on_pushButton_29_clicked();

    void on_RegisterButton_clicked();

    void on_checkButton_clicked();

    void delay( int millisecondsToWait )
    {
        QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
        while( QTime::currentTime() < dieTime )
        {
            QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
        }
    }


    void on_stopTime1_clicked();

    void on_stopTime2_clicked();

    void on_stopTime3_clicked();

    void on_stopTime4_clicked();

    void on_stopTime5_clicked();

    void on_stopTime6_clicked();

    void on_stopTime7_clicked();

    void on_stopTime8_clicked();

    void on_stopTime9_clicked();

    void on_stopTime10_clicked();

    void on_stopTime11_clicked();

    void on_stopTime12_clicked();



    void on_durationBox_currentIndexChanged(int index);

    void on_regUserMembership_currentIndexChanged(int index);

    void on_playButton1_clicked();
    void on_playButton2_clicked();
    void on_playButton3_clicked();
    void on_playButton4_clicked();
    void on_playButton5_clicked();
    void on_playButton6_clicked();
    void on_playButton7_clicked();
    void on_playButton8_clicked();
    void on_playButton9_clicked();
    void on_playButton10_clicked();
    void on_playButton11_clicked();
    void on_playButton12_clicked();


public slots:
    void accepted();

    void comp1Timer();
    void comp2Timer();
    void comp3Timer();
    void comp4Timer();
    void comp5Timer();
    void comp6Timer();
    void comp7Timer();
    void comp8Timer();
    void comp9Timer();
    void comp10Timer();
    void comp11Timer();
    void comp12Timer();



    void realTimer1();
    void realTimer2();
    void realTimer3();
    void realTimer4();
    void realTimer5();
    void realTimer6();
    void realTimer7();
    void realTimer8();
    void realTimer9();
    void realTimer10();
    void realTimer11();
    void realTimer12();






private:
    Ui::AppProgram *ui;
    int realHour;
    QSqlDatabase database;
    QSqlDatabase database1;
    QSqlDatabase database2;
    QSqlDatabase database3;
    QTimer *timer1;
    QTime time1;
    QTimer *timer2;
    QTime time2;
    QTimer *timer3;
    QTime time3;
    QTimer *timer4;
    QTime time4;
    QTimer *timer5;
    QTime time5;
    QTimer *timer6;
    QTime time6;
    QTimer *timer7;
    QTime time7;
    QTimer *timer8;
    QTime time8;
    QTimer *timer9;
    QTime time9;
    QTimer *timer10;
    QTime time10;
    QTimer *timer11;
    QTime time11;
    QTimer *timer12;
    QTime time12;
};

#endif // APPPROGRAM_H
