#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QWidget>
#include<QtSql>
#include<QSqlDatabase>
#include <QMessageBox>
#include<QTime>
#include <regex>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();    

private slots:
    void on_LoginButton_clicked();

    void on_pushButton_clicked();

    void on_LoginButton_pressed();

    void on_RegisterButton_clicked();

    void on_RegRegButton_clicked();    

    void delay( int millisecondsToWait )
    {
        QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
        while( QTime::currentTime() < dieTime )
        {
            QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
        }
    }

    void on_BackButton_clicked();

    bool isChar(QChar);

    bool isDigit(const QChar);

    bool isTelephoneNumber(QString);

    bool emailCheck(QString email);

private:
    Ui::MainWindow *ui;

    QSqlDatabase database;
};
#endif // MAINWINDOW_H
