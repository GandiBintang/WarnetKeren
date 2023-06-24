#include "appprogram.h"
#include "ui_appprogram.h"
#include "qrpopup.h"
#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QTime>
#include <QPalette>
#include "mainwindow.h"
#include <QApplication>
#include <QDialog>


static int realMinute;
static int realSeconds;
static QString realMembership;
static bool checked = false;
static QString username1;
static QString membership1;
static QString username2;
static QString membership2;
static QString username3;
static QString membership3;
static QString username4;
static QString membership4;
static QString username5;
static QString membership5;
static QString username6;
static QString membership6;
static QString username7;
static QString membership7;
static QString username8;
static QString membership8;
static QString username9;
static QString membership9;
static QString username10;
static QString membership10;
static QString username11;
static QString membership11;
static QString username12;
static QString membership12;
static bool stopTime1 = false;
static bool stopTime2 = false;
static bool stopTime3 = false;
static bool stopTime4 = false;
static bool stopTime5 = false;
static bool stopTime6 = false;
static bool stopTime7 = false;
static bool stopTime8 = false;
static bool stopTime9 = false;
static bool stopTime10 = false;
static bool stopTime11 = false;
static bool stopTime12 = false;
bool paid = false;

AppProgram::AppProgram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppProgram)
{
    ui->setupUi(this);
    setWindowTitle("warnetkeren");
    QGraphicsDropShadowEffect *shadow1 = new QGraphicsDropShadowEffect;
            shadow1->setColor(Qt::gray);
            shadow1->setOffset(1, 3);
            shadow1->setBlurRadius(10);

    ui->Computer1Button->setGraphicsEffect(shadow1);

    QGraphicsDropShadowEffect *shadow2 = new QGraphicsDropShadowEffect;
        shadow2->setColor(Qt::gray);
        shadow2->setOffset(1, 3);
        shadow2->setBlurRadius(10);

    ui->Computer2Button->setGraphicsEffect(shadow2);

    QGraphicsDropShadowEffect *shadow3 = new QGraphicsDropShadowEffect;
        shadow3->setColor(Qt::gray);
        shadow3->setOffset(1, 3);
        shadow3->setBlurRadius(10);

    ui->Computer3Button->setGraphicsEffect(shadow3);

    QGraphicsDropShadowEffect *shadow4 = new QGraphicsDropShadowEffect;
        shadow4->setColor(Qt::gray);
        shadow4->setOffset(1, 3);
        shadow4->setBlurRadius(10);

    ui->Computer4Button->setGraphicsEffect(shadow4);

    QGraphicsDropShadowEffect *shadow5 = new QGraphicsDropShadowEffect;
        shadow5->setColor(Qt::gray);
        shadow5->setOffset(1, 3);
        shadow5->setBlurRadius(10);

    ui->Computer2Button->setGraphicsEffect(shadow5);

    QGraphicsDropShadowEffect *shadow6 = new QGraphicsDropShadowEffect;
        shadow6->setColor(Qt::gray);
        shadow6->setOffset(1, 3);
        shadow6->setBlurRadius(10);

    ui->Computer6Button->setGraphicsEffect(shadow6);

    QGraphicsDropShadowEffect *shadow7 = new QGraphicsDropShadowEffect;
        shadow7->setColor(Qt::gray);
        shadow7->setOffset(1, 3);
        shadow7->setBlurRadius(10);

    ui->Computer7Button->setGraphicsEffect(shadow7);

    QGraphicsDropShadowEffect *shadow8 = new QGraphicsDropShadowEffect;
        shadow8->setColor(Qt::gray);
        shadow8->setOffset(1, 3);
        shadow8->setBlurRadius(10);

    ui->Computer8Button->setGraphicsEffect(shadow8);

    QGraphicsDropShadowEffect *shadow9 = new QGraphicsDropShadowEffect;
        shadow9->setColor(Qt::gray);
        shadow9->setOffset(1, 3);
        shadow9->setBlurRadius(10);

    ui->Computer9Button->setGraphicsEffect(shadow9);

    QGraphicsDropShadowEffect *shadow10 = new QGraphicsDropShadowEffect;
        shadow10->setColor(Qt::gray);
        shadow10->setOffset(1, 3);
        shadow10->setBlurRadius(10);

    ui->Computer10Button->setGraphicsEffect(shadow10);

    QGraphicsDropShadowEffect *shadow11 = new QGraphicsDropShadowEffect;
        shadow11->setColor(Qt::gray);
        shadow11->setOffset(1, 3);
        shadow11->setBlurRadius(10);

    ui->Computer11Button->setGraphicsEffect(shadow11);

    QGraphicsDropShadowEffect *shadow12 = new QGraphicsDropShadowEffect;
        shadow12->setColor(Qt::gray);
        shadow12->setOffset(1, 3);
        shadow12->setBlurRadius(10);

    ui->Computer12Button->setGraphicsEffect(shadow12);


    ui->regUserMembership->setEditable(true);
    ui->regUserMembership->lineEdit()->setPlaceholderText("Select Membership");
    ui->regUserMembership->lineEdit()->setReadOnly(true);
    ui->regUserMembership->lineEdit()->setAlignment(Qt::AlignCenter);
    ui->regUserMembership->addItem("Silver");
    ui->regUserMembership->addItem("Gold");
    ui->regUserMembership->addItem("Platinum");


    for(int i =0; i<ui->regUserMembership->count(); i++) {
        ui->regUserMembership->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }


}


AppProgram::~AppProgram()
{
    delete ui;
}



void AppProgram::on_ControlPage_clicked()
{
    ui->ControlPage->setStyleSheet("border-image:url(:/images/Setting_Pressed.png);");
    ui->RegisterPCPage->setStyleSheet("border-image:url(:/images/RegisterPC_Unpressed.png);");
    ui->RegisterUserPage->setStyleSheet("border-image:url(:/images/Register_Unpressed.png);");

    ui->stackedWidget->setCurrentIndex(0);

}


void AppProgram::on_RegisterPCPage_clicked()
{
    ui->ControlPage->setStyleSheet("border-image:url(:/images/Setting_Unpressed.png);");
    ui->RegisterPCPage->setStyleSheet("border-image:url(:/images/RegisterPC_Pressed.png);");
    ui->RegisterUserPage->setStyleSheet("border-image:url(:/images/Register_Unpressed.png);");

    ui->stackedWidget->setCurrentIndex(1);

}


void AppProgram::on_RegisterUserPage_clicked()
{
    ui->ControlPage->setStyleSheet("border-image:url(:/images/Setting_Unpressed.png);");
    ui->RegisterPCPage->setStyleSheet("border-image:url(:/images/RegisterPC_Unpressed.png);");
    ui->RegisterUserPage->setStyleSheet("border-image:url(:/images/Register_Pressed.png);");

    ui->stackedWidget->setCurrentIndex(2);
}


void AppProgram::on_AboutMePage_clicked()
{
    auto mm = new MainWindow();
    mm->setAttribute(Qt::WA_DeleteOnClose);
    mm->show();
    this->close();


     ui->ControlPage->setStyleSheet("border-image:url(:/images/Setting_Unpressed.png);");
     ui->RegisterPCPage->setStyleSheet("border-image:url(:/images/RegisterPC_Unpressed.png);");
     ui->RegisterUserPage->setStyleSheet("border-image:url(:/images/Register_Unpressed.png);");
     ui->AboutMePage->setStyleSheet("border-image:url(:/images/logout.png);");




}


// Register PC

void AppProgram::on_pushButton_29_clicked()
{

    if(checked == false) {
        QMessageBox::information(this, "Check Button", "Please first check your username");
    } else {
        database = QSqlDatabase::addDatabase("QMYSQL", "RegisterPC");
        database.setHostName("127.0.0.1");
        database.setUserName("root");
        database.setPassword("");
        database.setDatabaseName("qt5register");
        if(database.open()) {
            QSqlQuery qry;
            int computerID = ui->selectComputer->currentIndex()+1;
            QString username = ui->lineEdit->text();
            int duration = ui->durationBox->currentIndex()+1;
            // Setting the user's time remaining on the account

            int hour = realHour + duration;
            int minute = realMinute;
            int second = realSeconds;
            QString membership = realMembership;
            if(duration == 0 ) {
                QMessageBox::information(this, "No Duration", "Please first select the amount of hour you want");
            } else {
                qry.prepare("UPDATE `usernametime`SET hour = :hour, minute = :minute, seconds = :seconds, membership = :membership WHERE username = :username;");
                qry.bindValue(":username", username);
                qry.bindValue(":hour", hour);
                qry.bindValue(":minute", minute);
                qry.bindValue(":seconds", second);
                qry.bindValue(":membership", membership);

                if(qry.exec()) {
                    QMessageBox::information(this, "Time" , "Time Inserted Succesfully");
                } else {
                    QMessageBox::information(this, "Failed time" , "Failed time");
                }
                // Setting the user's username and computerID in the database
                qry.prepare("UPDATE `rentedcomputers` SET username = :username, hour = :hour, minute = :minute, second= :second, membership = :membership WHERE computerid = :computerid;"); // work here
                qry.bindValue(":hour", hour);
                qry.bindValue(":minute", minute);
                qry.bindValue(":second", second);
                qry.bindValue(":computerid", computerID);
                qry.bindValue(":username", username);
                qry.bindValue(":membership", membership);

                if(qry.exec()) {
                    QMessageBox::information(this, "Inserted" , "Data Inserted Sucessfully");
                    checked = false;
                    switch(computerID) {
                    // Which Computer is picked
                    case 1:
                        ui->Computer1Button->setStyleSheet("border-image:url(:/images/1.png);");
                        comp1Timer();
                        break;
                    case 2:
                        ui->Computer2Button->setStyleSheet("border-image:url(:/images/2.png);");
                        comp2Timer();
                        break;
                    case 3:
                        ui->Computer3Button->setStyleSheet("border-image:url(:/images/3.png);");
                        comp3Timer();
                        break;
                    case 4:
                        ui->Computer4Button->setStyleSheet("border-image:url(:/images/4.png);");
                        comp4Timer();
                        break;
                    case 5:
                        ui->Computer5Button->setStyleSheet("border-image:url(:/images/5.png);");
                        comp5Timer();
                        break;
                    case 6:
                        ui->Computer6Button->setStyleSheet("border-image:url(:/images/6.png);");
                        comp6Timer();
                        break;
                    case 7:
                        ui->Computer7Button->setStyleSheet("border-image:url(:/images/7.png);");
                        comp7Timer();
                        break;
                    case 8:
                        ui->Computer8Button->setStyleSheet("border-image:url(:/images/8.png);");
                        comp8Timer();
                        break;
                    case 9:
                        ui->Computer9Button->setStyleSheet("border-image:url(:/images/9.png);");
                        comp9Timer();
                        break;
                    case 10:
                        ui->Computer10Button->setStyleSheet("border-image:url(:/images/10.png);");
                        comp10Timer();
                        break;
                    case 11:
                        ui->Computer11Button->setStyleSheet("border-image:url(:/images/11.png);");
                        comp11Timer();
                        break;
                    case 12:
                        ui->Computer12Button->setStyleSheet("border-image:url(:/images/12.png);");
                        comp12Timer();
                        break;
                    }
                } else {
                     QMessageBox::information(this, "Inserted failed" , "Data Inserted  asdasdasd Sucessfully");
                }
            }
        } else {
            QMessageBox::information(this, "Connection Failed", "Connection failed to be established");
        }
    }

}

void AppProgram::accepted() {
 QMessageBox::information(this, "Database Failed", "Database connection failed"); // Change this code

}


// Register User

void AppProgram::on_RegisterButton_clicked()
{
    bool found = false;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("127.0.0.1");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("qt5register");
    if(database.open()) {
        QSqlQuery regQuery;
        QString regUsername = ui->regUserUsername->text();
        QString regMembership = ui->regUserMembership->currentText();
        int hour = 0;
        int minute = 0;
        int seconds = 0;
        if(regUsername.isEmpty()) {
            QMessageBox::information(this, "Registration Failed", "Please insert your username");
        } else {
            regQuery.prepare("SELECT * FROM usernametime");
            if(regQuery.exec()) {
                while(regQuery.next()) {
                    if(regQuery.value(0).toString() == regUsername) {
                        found = true;
                    }
                }
                if(found == true) {
                    QMessageBox::information(this, "Registration Failed", "The specified username has already exists");
                } else {

                       regQuery.prepare("INSERT INTO usernametime (username, hour, minute, seconds, membership)"
                                        "VALUES (:username, :hour, :minute, :seconds, :membership)" );
                       regQuery.bindValue(":username", regUsername );
                       regQuery.bindValue(":hour", hour);
                       regQuery.bindValue(":minute", minute);
                       regQuery.bindValue(":seconds", seconds);
                       regQuery.bindValue(":membership", regMembership);

                       if(regQuery.exec()){
                               QMessageBox::information(this, "Registration Sucessfull", "You Have been sucessfully registered");
                       } else {
                               QMessageBox::information(this, "welcome", "fail");
                       }

                }
            }
        }

    }
}

// check user's remaining time button

void AppProgram::on_checkButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::information(this, "Box Empty", "Please first fill in the username");
    } else {
        database1 = QSqlDatabase::addDatabase("QMYSQL");
        database1.setHostName("127.0.0.1");
        database1.setUserName("root");
        database1.setPassword("");
        database1.setDatabaseName("qt5register");


        // Check the Remaining time

        if(database1.open()) {

            bool found = false;
            QSqlQuery checkTime;
            QSqlQuery checkTime1;


            QString checkUsername = ui->lineEdit->text();
            QString checkUsername2 = ui->lineEdit->text();
            checkTime.prepare("SELECT * FROM `usernametime` WHERE username = :checkusername;");
            checkTime.bindValue(":checkusername", checkUsername);

            checkTime1.prepare("SELECT * FROM `usernametime`");
            if(checkTime1.exec()) {
                while(checkTime1.next()) {
                    if(checkTime1.value(0).toString() == checkUsername2) {
                       found = true;
                    }
                }
            }
            if (found == true) {
                if(checkTime.exec()) {
                    while(checkTime.next()) {
                        QString addedTime = checkTime.value(1).toString();
                        realHour = checkTime.value(1).toInt();
                        addedTime.append(":");
                        addedTime.append(checkTime.value(2).toString());
                        realMinute = checkTime.value(2).toInt();
                        addedTime.append(":");
                        addedTime.append(checkTime.value(3).toString());
                        realSeconds = checkTime.value(3).toInt();
                        realMembership = checkTime.value(4).toString();


                        ui->MembershipLabel->setText(realMembership);
                        ui->remainingTime->setText(addedTime);
                        on_durationBox_currentIndexChanged(ui->durationBox->currentIndex());
                        checked = true;

                    }

                }
            }else {
                QMessageBox::information(this, "Username not registered", "Please first register this username");
            }
        }
    }

}

// Timer to reduce each comp's time

void AppProgram::comp1Timer() {
        database2 = QSqlDatabase::addDatabase("QMYSQL", "Comp1Timer");
        database2.setHostName("127.0.0.1");
        database2.setUserName("root");
        database2.setPassword("");
        database2.setDatabaseName("qt5register");

        if(database2.open()) {
            QSqlQuery comp1;
            comp1.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = 1;");
            if(comp1.exec()) {
                while(comp1.next()) {
                    username1 = comp1.value(1).toString();
                    int hour = comp1.value(2).toInt();
                    int minute = comp1.value(3).toInt();
                    int second = comp1.value(4).toInt();
                    membership1 = comp1.value(5).toString();
                    stopTime1 = false;
                    time1 = QTime(hour,minute,second);
                    timer1 = new QTimer(this);
                    connect(timer1, SIGNAL(timeout()),this, SLOT(realTimer1()));
                    timer1->start(1000);
                }
            } else {
              QMessageBox::information(this, "exec failed", "exec failed");              
            }
        }
}

void AppProgram::comp12Timer() {
        database2 = QSqlDatabase::addDatabase("QMYSQL", "Comp12Timer");
        database2.setHostName("127.0.0.1");
        database2.setUserName("root");
        database2.setPassword("");
        database2.setDatabaseName("qt5register");

        if(database2.open()) {
            QSqlQuery comp12;
            comp12.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = 12;");
            if(comp12.exec()) {
                while(comp12.next()) {
                    username12 = comp12.value(1).toString();
                    int hour = comp12.value(2).toInt();
                    int minute = comp12.value(3).toInt();
                    int second = comp12.value(4).toInt();
                    membership12 = comp12.value(5).toString();
                    stopTime12 = false;
                    time12 = QTime(hour,minute,second);
                    timer12 = new QTimer(this);
                    connect(timer12, SIGNAL(timeout()),this, SLOT(realTimer12()));
                    timer12->start(1000);
                }
            } else {
              QMessageBox::information(this, "exec failed", "exec failed");
            }
        }
}

void AppProgram::comp11Timer() {
        database2 = QSqlDatabase::addDatabase("QMYSQL", "Comp11Timer");
        database2.setHostName("127.0.0.1");
        database2.setUserName("root");
        database2.setPassword("");
        database2.setDatabaseName("qt5register");

        if(database2.open()) {
            QSqlQuery comp11;
            comp11.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = 11;");
            if(comp11.exec()) {
                while(comp11.next()) {
                    username11 = comp11.value(1).toString();
                    int hour = comp11.value(2).toInt();
                    int minute = comp11.value(3).toInt();
                    int second = comp11.value(4).toInt();
                    membership11 = comp11.value(5).toString();
                    stopTime11 = false;
                    time11 = QTime(hour,minute,second);
                    timer11 = new QTimer(this);
                    connect(timer11, SIGNAL(timeout()),this, SLOT(realTimer11()));
                    timer11->start(1000);
                }
            } else {
              QMessageBox::information(this, "exec failed", "exec failed");
            }
        }
}

void AppProgram::comp10Timer() {
        database2 = QSqlDatabase::addDatabase("QMYSQL", "Comp10Timer");
        database2.setHostName("127.0.0.1");
        database2.setUserName("root");
        database2.setPassword("");
        database2.setDatabaseName("qt5register");

        if(database2.open()) {
            QSqlQuery comp10;
            comp10.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = 10;");
            if(comp10.exec()) {
                while(comp10.next()) {
                    username10 = comp10.value(1).toString();
                    int hour = comp10.value(2).toInt();
                    int minute = comp10.value(3).toInt();
                    int second = comp10.value(4).toInt();
                    membership10 = comp10.value(5).toString();
                    stopTime10 = false;
                    time10 = QTime(hour,minute,second);
                    timer10 = new QTimer(this);
                    connect(timer10, SIGNAL(timeout()),this, SLOT(realTimer10()));
                    timer10->start(1000);
                }
            } else {
              QMessageBox::information(this, "exec failed", "exec failed");
            }
        }
}

void AppProgram::comp9Timer() {
        database2 = QSqlDatabase::addDatabase("QMYSQL", "Comp9Timer");
        database2.setHostName("127.0.0.1");
        database2.setUserName("root");
        database2.setPassword("");
        database2.setDatabaseName("qt5register");

        if(database2.open()) {
            QSqlQuery comp9;
            comp9.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = 9;");
            if(comp9.exec()) {
                while(comp9.next()) {
                    username9 = comp9.value(1).toString();
                    int hour = comp9.value(2).toInt();
                    int minute = comp9.value(3).toInt();
                    int second = comp9.value(4).toInt();
                    membership9 = comp9.value(5).toString();
                    stopTime9 = false;
                    time9 = QTime(hour,minute,second);
                    timer9 = new QTimer(this);
                    connect(timer9, SIGNAL(timeout()),this, SLOT(realTimer9()));
                    timer9->start(1000);
                }
            } else {
              QMessageBox::information(this, "exec failed", "exec failed");
            }
        }
}

void AppProgram::comp8Timer() {
        database2 = QSqlDatabase::addDatabase("QMYSQL", "Comp8Timer");
        database2.setHostName("127.0.0.1");
        database2.setUserName("root");
        database2.setPassword("");
        database2.setDatabaseName("qt5register");

        if(database2.open()) {
            QSqlQuery comp8;
            comp8.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = 8;");
            if(comp8.exec()) {
                while(comp8.next()) {
                    username8 = comp8.value(1).toString();
                    int hour = comp8.value(2).toInt();
                    int minute = comp8.value(3).toInt();
                    int second = comp8.value(4).toInt();
                    membership8 = comp8.value(5).toString();
                    stopTime8 = false;
                    time8 = QTime(hour,minute,second);
                    timer8 = new QTimer(this);
                    connect(timer8, SIGNAL(timeout()),this, SLOT(realTimer8()));
                    timer8->start(1000);
                }
            } else {
              QMessageBox::information(this, "exec failed", "exec failed");
            }
        }
}

void AppProgram::comp7Timer() {
        database2 = QSqlDatabase::addDatabase("QMYSQL", "Comp7Timer");
        database2.setHostName("127.0.0.1");
        database2.setUserName("root");
        database2.setPassword("");
        database2.setDatabaseName("qt5register");

        if(database2.open()) {
            QSqlQuery comp7;
            comp7.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = 7;");
            if(comp7.exec()) {
                while(comp7.next()) {
                    username7 = comp7.value(1).toString();
                    int hour = comp7.value(2).toInt();
                    int minute = comp7.value(3).toInt();
                    int second = comp7.value(4).toInt();
                    membership7 = comp7.value(5).toString();
                    stopTime7 = false;
                    time7 = QTime(hour,minute,second);
                    timer7 = new QTimer(this);
                    connect(timer7, SIGNAL(timeout()),this, SLOT(realTimer7()));
                    timer7->start(1000);
                }
            } else {
              QMessageBox::information(this, "exec failed", "exec failed");
            }
        }
}

void AppProgram::comp6Timer() {
        database2 = QSqlDatabase::addDatabase("QMYSQL", "Comp6Timer");
        database2.setHostName("127.0.0.1");
        database2.setUserName("root");
        database2.setPassword("");
        database2.setDatabaseName("qt5register");

        if(database2.open()) {
            QSqlQuery comp6;
            comp6.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = 6;");
            if(comp6.exec()) {
                while(comp6.next()) {
                    username6 = comp6.value(1).toString();
                    int hour = comp6.value(2).toInt();
                    int minute = comp6.value(3).toInt();
                    int second = comp6.value(4).toInt();
                    membership6 = comp6.value(5).toString();
                    stopTime6 = false;
                    time6 = QTime(hour,minute,second);
                    timer6 = new QTimer(this);
                    connect(timer6, SIGNAL(timeout()),this, SLOT(realTimer6()));
                    timer6->start(1000);
                }
            } else {
              QMessageBox::information(this, "exec failed", "exec failed");
            }
        }
}

void AppProgram::comp3Timer() {
        database2 = QSqlDatabase::addDatabase("QMYSQL", "Comp3Timer");
        database2.setHostName("127.0.0.1");
        database2.setUserName("root");
        database2.setPassword("");
        database2.setDatabaseName("qt5register");

        if(database2.open()) {
            QSqlQuery comp3;
            comp3.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = 3;");
            if(comp3.exec()) {
                while(comp3.next()) {
                    username3 = comp3.value(1).toString();
                    int hour = comp3.value(2).toInt();
                    int minute = comp3.value(3).toInt();
                    int second = comp3.value(4).toInt();
                    membership3 = comp3.value(5).toString();
                    stopTime3 = false;
                    time3 = QTime(hour,minute,second);
                    timer3 = new QTimer(this);
                    connect(timer3, SIGNAL(timeout()),this, SLOT(realTimer3()));
                    timer3->start(1000);
                }
            } else {
              QMessageBox::information(this, "exec failed", "exec failed");
            }
        }
}

void AppProgram::comp4Timer() {
        database2 = QSqlDatabase::addDatabase("QMYSQL", "Comp4Timer");
        database2.setHostName("127.0.0.1");
        database2.setUserName("root");
        database2.setPassword("");
        database2.setDatabaseName("qt5register");

        if(database2.open()) {
            QSqlQuery comp4;
            comp4.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = 4;");
            if(comp4.exec()) {
                while(comp4.next()) {
                    username4 = comp4.value(1).toString();
                    int hour = comp4.value(2).toInt();
                    int minute = comp4.value(3).toInt();
                    int second = comp4.value(4).toInt();
                    membership4 = comp4.value(5).toString();
                    stopTime4 = false;
                    time4 = QTime(hour,minute,second);
                    timer4 = new QTimer(this);
                    connect(timer4, SIGNAL(timeout()),this, SLOT(realTimer4()));
                    timer4->start(1000);
                }
            } else {
              QMessageBox::information(this, "exec failed", "exec failed");
            }
        }
}

void AppProgram::comp5Timer() {
        database2 = QSqlDatabase::addDatabase("QMYSQL", "Comp5Timer");
        database2.setHostName("127.0.0.1");
        database2.setUserName("root");
        database2.setPassword("");
        database2.setDatabaseName("qt5register");

        if(database2.open()) {
            QSqlQuery comp5;
            comp5.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = 5;");
            if(comp5.exec()) {
                while(comp5.next()) {
                    username5 = comp5.value(1).toString();
                    int hour = comp5.value(2).toInt();
                    int minute = comp5.value(3).toInt();
                    int second = comp5.value(4).toInt();
                    membership5 = comp5.value(5).toString();
                    stopTime5 = false;
                    time5 = QTime(hour,minute,second);
                    timer5 = new QTimer(this);
                    connect(timer5, SIGNAL(timeout()),this, SLOT(realTimer5()));
                    timer5->start(1000);
                }
            } else {
              QMessageBox::information(this, "exec failed", "exec failed");
            }
        }
}



void AppProgram::realTimer1() {
    if(stopTime1 == false) {
        QTime time1Added = time1.addSecs(-1);
        time1 = time1Added;
        ui->Computer1Label->setText(QString::number(time1.hour()) + ":" + QString::number(time1.minute()) + ":" + QString::number(time1.second()));
        qDebug() << time1.hour() << time1.minute() << time1.second();
    } else { // Time Stop Initiated
        QSqlQuery comp1;
        qInfo() << "This is the last record" << Qt::endl;
        timer1->stop();
        qInfo() << time1.hour() << time1.minute() << time1.second();
        comp1.prepare("UPDATE `usernametime` SET hour = :hour, minute = :minute, seconds = :second WHERE username = :username;");
        comp1.bindValue(":hour", time1.hour());
        comp1.bindValue(":minute", time1.minute());
        comp1.bindValue(":second", time1.second());
        comp1.bindValue(":username", username1);
        if (comp1.exec()) {

            ui->Computer1Button->setStyleSheet("border-image:url(:/images/closed.png);");
        } else {
            QMessageBox::information(this, "storing failed 1", "storing failed");
        }
    }
}

void AppProgram::realTimer12() {
    if(stopTime12 == false) {
        QTime time12Added = time12.addSecs(-1);
        time12 = time12Added;
        ui->Computer12Label->setText(QString::number(time12.hour()) + ":" + QString::number(time12.minute()) + ":" + QString::number(time12.second()));
        qDebug() << time12.hour() << time12.minute() << time12.second();
    } else { // Time Stop Initiated
        QSqlQuery comp12;
        qInfo() << "This is the last record" << Qt::endl;
        timer12->stop();
        qInfo() << time12.hour() << time12.minute() << time12.second();
        comp12.prepare("UPDATE `usernametime` SET hour = :hour, minute = :minute, seconds = :second WHERE username = :username;");
        comp12.bindValue(":hour", time12.hour());
        comp12.bindValue(":minute", time12.minute());
        comp12.bindValue(":second", time12.second());
        comp12.bindValue(":username", username1);
        if (comp12.exec()) {
            ui->Computer12Button->setStyleSheet("border-image:url(:/images/closed.png);");
        } else {
            QMessageBox::information(this, "storing failed", "storing failed");
        }
    }
}

void AppProgram::realTimer11() {
    if(stopTime11 == false) {
        QTime time11Added = time11.addSecs(-1);
        time11 = time11Added;
        ui->Computer11Label->setText(QString::number(time11.hour()) + ":" + QString::number(time11.minute()) + ":" + QString::number(time11.second()));
        qDebug() << time11.hour() << time11.minute() << time11.second();
    } else { // Time Stop Initiated
        QSqlQuery comp11;
        qInfo() << "This is the last record" << Qt::endl;
        timer11->stop();
        qInfo() << time11.hour() << time11.minute() << time11.second();
        comp11.prepare("UPDATE `usernametime` SET hour = :hour, minute = :minute, seconds = :second WHERE username = :username;");
        comp11.bindValue(":hour", time11.hour());
        comp11.bindValue(":minute", time11.minute());
        comp11.bindValue(":second", time11.second());
        comp11.bindValue(":username", username11);
        if (comp11.exec()) {

            ui->Computer11Button->setStyleSheet("border-image:url(:/images/closed.png);");
        } else {
            QMessageBox::information(this, "storing failed", "storing failed");
        }
    }
}


void AppProgram::realTimer10() {
    if(stopTime10 == false) {
        QTime time10Added = time10.addSecs(-1);
        time10 = time10Added;
        ui->Computer10Label->setText(QString::number(time10.hour()) + ":" + QString::number(time10.minute()) + ":" + QString::number(time10.second()));
        qDebug() << time10.hour() << time10.minute() << time10.second();
    } else { // Time Stop Initiated
        QSqlQuery comp10;
        qInfo() << "This is the last record" << Qt::endl;
        timer10->stop();
        qInfo() << time10.hour() << time10.minute() << time10.second();
        comp10.prepare("UPDATE `usernametime` SET hour = :hour, minute = :minute, seconds = :second WHERE username = :username;");
        comp10.bindValue(":hour", time10.hour());
        comp10.bindValue(":minute", time10.minute());
        comp10.bindValue(":second", time10.second());
        comp10.bindValue(":username", username10);
        if (comp10.exec()) {

            ui->Computer10Button->setStyleSheet("border-image:url(:/images/closed.png);");
        } else {
            QMessageBox::information(this, "storing failed 1", "storing failed");
        }
    }
}

void AppProgram::realTimer9() {
    if(stopTime9 == false) {
        QTime time9Added = time9.addSecs(-1);
        time9 = time9Added;
        ui->Computer9Label->setText(QString::number(time9.hour()) + ":" + QString::number(time9.minute()) + ":" + QString::number(time9.second()));
        qDebug() << time9.hour() << time9.minute() << time9.second();
    } else { // Time Stop Initiated
        QSqlQuery comp9;
        qInfo() << "This is the last record" << Qt::endl;
        timer9->stop();
        qInfo() << time9.hour() << time9.minute() << time9.second();
        comp9.prepare("UPDATE `usernametime` SET hour = :hour, minute = :minute, seconds = :second WHERE username = :username;");
        comp9.bindValue(":hour", time9.hour());
        comp9.bindValue(":minute", time9.minute());
        comp9.bindValue(":second", time9.second());
        comp9.bindValue(":username", username1);
        if (comp9.exec()) {

            ui->Computer9Button->setStyleSheet("border-image:url(:/images/closed.png);");
        } else {
            QMessageBox::information(this, "storing failed 1", "storing failed");
        }
    }
}

void AppProgram::realTimer8() {
    if(stopTime8 == false) {
        QTime time8Added = time8.addSecs(-1);
        time8 = time8Added;
        ui->Computer8Label->setText(QString::number(time8.hour()) + ":" + QString::number(time8.minute()) + ":" + QString::number(time8.second()));
        qDebug() << time8.hour() << time8.minute() << time8.second();
    } else { // Time Stop Initiated
        QSqlQuery comp8;
        qInfo() << "This is the last record" << Qt::endl;
        timer8->stop();
        qInfo() << time8.hour() << time8.minute() << time8.second();
        comp8.prepare("UPDATE `usernametime` SET hour = :hour, minute = :minute, seconds = :second WHERE username = :username;");
        comp8.bindValue(":hour", time8.hour());
        comp8.bindValue(":minute", time8.minute());
        comp8.bindValue(":second", time8.second());
        comp8.bindValue(":username", username8);
        if (comp8.exec()) {

            ui->Computer8Button->setStyleSheet("border-image:url(:/images/closed.png);");
        } else {
            QMessageBox::information(this, "storing failed", "storing failed");
        }
    }
}

void AppProgram::realTimer7() {
    if(stopTime7 == false) {
        QTime time7Added = time7.addSecs(-1);
        time7 = time7Added;
        ui->Computer7Label->setText(QString::number(time7.hour()) + ":" + QString::number(time7.minute()) + ":" + QString::number(time7.second()));
        qDebug() << time7.hour() << time7.minute() << time7.second();
    } else { // Time Stop Initiated
        QSqlQuery comp7;
        qInfo() << "This is the last record" << Qt::endl;
        timer7->stop();
        qInfo() << time7.hour() << time7.minute() << time7.second();
        comp7.prepare("UPDATE `usernametime` SET hour = :hour, minute = :minute, seconds = :second WHERE username = :username;");
        comp7.bindValue(":hour", time7.hour());
        comp7.bindValue(":minute", time7.minute());
        comp7.bindValue(":second", time7.second());
        comp7.bindValue(":username", username7);
        if (comp7.exec()) {

            ui->Computer7Button->setStyleSheet("border-image:url(:/images/closed.png);");

        } else {
            QMessageBox::information(this, "storing failed 1", "storing failed");
        }
    }
}

void AppProgram::realTimer6() {
    if(stopTime6 == false) {
        QTime time6Added = time6.addSecs(-1);
        time6 = time6Added;
        ui->Computer6Label->setText(QString::number(time6.hour()) + ":" + QString::number(time6.minute()) + ":" + QString::number(time6.second()));
        qDebug() << time6.hour() << time6.minute() << time6.second();
    } else { // Time Stop Initiated
        QSqlQuery comp6;
        qInfo() << "This is the last record" << Qt::endl;
        timer6->stop();
        qInfo() << time6.hour() << time6.minute() << time6.second();
        comp6.prepare("UPDATE `usernametime` SET hour = :hour, minute = :minute, seconds = :second WHERE username = :username;");
        comp6.bindValue(":hour", time6.hour());
        comp6.bindValue(":minute", time6.minute());
        comp6.bindValue(":second", time6.second());
        comp6.bindValue(":username", username6);
        if (comp6.exec()) {

            ui->Computer6Button->setStyleSheet("border-image:url(:/images/closed.png);");
        } else {
            QMessageBox::information(this, "storing failed 1", "storing failed");
        }
    }
}

void AppProgram::realTimer5() {
    if(stopTime5 == false) {
        QTime time5Added = time5.addSecs(-1);
        time5 = time5Added;
        ui->Computer5Label->setText(QString::number(time5.hour()) + ":" + QString::number(time5.minute()) + ":" + QString::number(time5.second()));
        qDebug() << time1.hour() << time1.minute() << time1.second();
    } else { // Time Stop Initiated
        QSqlQuery comp5;
        qInfo() << "This is the last record" << Qt::endl;
        timer5->stop();
        qInfo() << time5.hour() << time5.minute() << time5.second();
        comp5.prepare("UPDATE `usernametime` SET hour = :hour, minute = :minute, seconds = :second WHERE username = :username;");
        comp5.bindValue(":hour", time5.hour());
        comp5.bindValue(":minute", time5.minute());
        comp5.bindValue(":second", time5.second());
        comp5.bindValue(":username", username5);
        if (comp5.exec()) {

            ui->Computer5Button->setStyleSheet("border-image:url(:/images/closed.png);");
        } else {
            QMessageBox::information(this, "storing failed 1", "storing failed");
        }
    }
}

void AppProgram::realTimer3() {
    if(stopTime3 == false) {
        QTime time3Added = time3.addSecs(-1);
        time3 = time3Added;
        ui->Computer3Label->setText(QString::number(time3.hour()) + ":" + QString::number(time3.minute()) + ":" + QString::number(time3.second()));
        qDebug() << time3.hour() << time3.minute() << time3.second();
    } else { // Time Stop Initiated
        QSqlQuery comp3;
        qInfo() << "This is the last record" << Qt::endl;
        timer3->stop();
        qInfo() << time3.hour() << time3.minute() << time3.second();
        comp3.prepare("UPDATE `usernametime` SET hour = :hour, minute = :minute, seconds = :second WHERE username = :username;");
        comp3.bindValue(":hour", time3.hour());
        comp3.bindValue(":minute", time3.minute());
        comp3.bindValue(":second", time3.second());
        comp3.bindValue(":username", username3);
        if (comp3.exec()) {

            ui->Computer3Button->setStyleSheet("border-image:url(:/images/closed.png);");
        } else {
            QMessageBox::information(this, "storing failed 1", "storing failed");
        }
    }
}

void AppProgram::realTimer4() {
    if(stopTime4 == false) {
        QTime time4Added = time4.addSecs(-1);
        time4 = time4Added;
        ui->Computer4Label->setText(QString::number(time4.hour()) + ":" + QString::number(time4.minute()) + ":" + QString::number(time4.second()));
        qDebug() << time4.hour() << time4.minute() << time4.second();
    } else { // Time Stop Initiated
        QSqlQuery comp4;
        qInfo() << "This is the last record" << Qt::endl;
        timer4->stop();
        qInfo() << time4.hour() << time4.minute() << time4.second();
        comp4.prepare("UPDATE `usernametime` SET hour = :hour, minute = :minute, seconds = :second WHERE username = :username;");
        comp4.bindValue(":hour", time4.hour());
        comp4.bindValue(":minute", time4.minute());
        comp4.bindValue(":second", time4.second());
        comp4.bindValue(":username", username4);
        if (comp4.exec()) {

            ui->Computer4Button->setStyleSheet("border-image:url(:/images/closed.png);");
        } else {
            QMessageBox::information(this, "storing failed 1", "storing failed");
        }
    }
}

void AppProgram::on_stopTime1_clicked()
{
    stopTime1 = true;
    database2 = QSqlDatabase::addDatabase("QMYSQL", "stopTime1");
    database2.setHostName("127.0.0.1");
    database2.setUserName("root");
    database2.setPassword("");
    database2.setDatabaseName("qt5register");

    if(database2.open()) {
        bool occupied = true;

        QSqlQuery setCancel;

        setCancel.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = :computerid;");
        setCancel.bindValue(":computerid", 1);
        if(setCancel.exec()) {
            while(setCancel.next()) {
                if (setCancel.value(1).toString() == "NULL") {
                    occupied = false;
                }
            }
        }

        if (occupied == true) {
            QSqlQuery set1;
            set1.prepare("UPDATE `rentedcomputers` SET username = :username , hour = :hour, minute = :minute, second= :second, membership= :membership WHERE computerid = :computerid;");
            set1.bindValue(":computerid", 1);
            set1.bindValue(":username", "NULL");
            set1.bindValue(":hour", 0);
            set1.bindValue(":minute", 0);
            set1.bindValue(":second", 0);
            set1.bindValue(":membership", "NULL");

            if(set1.exec()) {
                ui->Computer1Label->setText(QString::number(0) + ":" + QString::number(0) + ":" + QString::number(0));
                QMessageBox::information(this, " Sucessfully Stopped Time ", "Computer 1 has been stopped");
            }
        } else {
            QMessageBox::information(this, " Failed To Stop Time", "Computer 1 isn't occupied and can't be stopped");
        }

    }
}

void AppProgram::on_stopTime12_clicked()
{
    stopTime12 = true;
    database2 = QSqlDatabase::addDatabase("QMYSQL", "stopTime12");
    database2.setHostName("127.0.0.1");
    database2.setUserName("root");
    database2.setPassword("");
    database2.setDatabaseName("qt5register");

    if(database2.open()) {
        bool occupied = true;

        QSqlQuery setCancel;

        setCancel.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = :computerid;");
        setCancel.bindValue(":computerid", 12);
        if(setCancel.exec()) {
            while(setCancel.next()) {
                if (setCancel.value(1).toString() == "NULL") {
                    occupied = false;
                }
            }
        }

        if (occupied == true) {
            QSqlQuery set12;
            set12.prepare("UPDATE `rentedcomputers` SET username = :username , hour = :hour, minute = :minute, second= :second, membership= :membership WHERE computerid = :computerid;");
            set12.bindValue(":computerid", 12);
            set12.bindValue(":username", "NULL");
            set12.bindValue(":hour", 0);
            set12.bindValue(":minute", 0);
            set12.bindValue(":second", 0);
            set12.bindValue(":membership", "NULL");

            if(set12.exec()) {
                ui->Computer12Label->setText(QString::number(0) + ":" + QString::number(0) + ":" + QString::number(0));
                QMessageBox::information(this, " Sucessfully Stopped Time ", "Computer 12 has been stopped");
            }
        } else {
            QMessageBox::information(this, " Failed To Stop Time", "Computer 12 isn't occupied and can't be stopped");
        }

    }
}

void AppProgram::on_stopTime11_clicked()
{
    stopTime11 = true;
    database2 = QSqlDatabase::addDatabase("QMYSQL", "stopTime11");
    database2.setHostName("127.0.0.1");
    database2.setUserName("root");
    database2.setPassword("");
    database2.setDatabaseName("qt5register");

    if(database2.open()) {
        bool occupied = true;

        QSqlQuery setCancel;

        setCancel.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = :computerid;");
        setCancel.bindValue(":computerid", 11);
        if(setCancel.exec()) {
            while(setCancel.next()) {
                if (setCancel.value(1).toString() == "NULL") {
                    occupied = false;
                }
            }
        }

        if (occupied == true) {
            QSqlQuery set11;
            set11.prepare("UPDATE `rentedcomputers` SET username = :username , hour = :hour, minute = :minute, second= :second, membership= :membership WHERE computerid = :computerid;");
            set11.bindValue(":computerid", 11);
            set11.bindValue(":username", "NULL");
            set11.bindValue(":hour", 0);
            set11.bindValue(":minute", 0);
            set11.bindValue(":second", 0);
            set11.bindValue(":membership", "NULL");

            if(set11.exec()) {
                ui->Computer11Label->setText(QString::number(0) + ":" + QString::number(0) + ":" + QString::number(0));
                QMessageBox::information(this, " Sucessfully Stopped Time ", "Computer 11 has been stopped");
            }
        } else {
            QMessageBox::information(this, " Failed To Stop Time", "Computer 11 isn't occupied and can't be stopped");
        }

    }
}

void AppProgram::on_stopTime10_clicked()
{
    stopTime10 = true;
    database2 = QSqlDatabase::addDatabase("QMYSQL", "stopTime10");
    database2.setHostName("127.0.0.1");
    database2.setUserName("root");
    database2.setPassword("");
    database2.setDatabaseName("qt5register");

    if(database2.open()) {
        bool occupied = true;

        QSqlQuery setCancel;

        setCancel.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = :computerid;");
        setCancel.bindValue(":computerid", 10);
        if(setCancel.exec()) {
            while(setCancel.next()) {
                if (setCancel.value(1).toString() == "NULL") {
                    occupied = false;
                }
            }
        }

        if (occupied == true) {
            QSqlQuery set10;
            set10.prepare("UPDATE `rentedcomputers` SET username = :username , hour = :hour, minute = :minute, second= :second, membership= :membership WHERE computerid = :computerid;");
            set10.bindValue(":computerid", 10);
            set10.bindValue(":username", "NULL");
            set10.bindValue(":hour", 0);
            set10.bindValue(":minute", 0);
            set10.bindValue(":second", 0);
            set10.bindValue(":membership", "NULL");

            if(set10.exec()) {
                ui->Computer10Label->setText(QString::number(0) + ":" + QString::number(0) + ":" + QString::number(0));
                QMessageBox::information(this, " Sucessfully Stopped Time ", "Computer 10 has been stopped");
            }
        } else {
            QMessageBox::information(this, " Failed To Stop Time", "Computer 10 isn't occupied and can't be stopped");
        }

    }
}

void AppProgram::on_stopTime9_clicked()
{
    stopTime9 = true;
    database2 = QSqlDatabase::addDatabase("QMYSQL", "stopTime9");
    database2.setHostName("127.0.0.1");
    database2.setUserName("root");
    database2.setPassword("");
    database2.setDatabaseName("qt5register");

    if(database2.open()) {
        bool occupied = true;

        QSqlQuery setCancel;

        setCancel.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = :computerid;");
        setCancel.bindValue(":computerid", 9);
        if(setCancel.exec()) {
            while(setCancel.next()) {
                if (setCancel.value(1).toString() == "NULL") {
                    occupied = false;
                }
            }
        }

        if (occupied == true) {
            QSqlQuery set9;
            set9.prepare("UPDATE `rentedcomputers` SET username = :username , hour = :hour, minute = :minute, second= :second, membership= :membership WHERE computerid = :computerid;");
            set9.bindValue(":computerid", 9);
            set9.bindValue(":username", "NULL");
            set9.bindValue(":hour", 0);
            set9.bindValue(":minute", 0);
            set9.bindValue(":second", 0);
            set9.bindValue(":membership", "NULL");

            if(set9.exec()) {
                ui->Computer9Label->setText(QString::number(0) + ":" + QString::number(0) + ":" + QString::number(0));
                QMessageBox::information(this, " Sucessfully Stopped Time ", "Computer 9 has been stopped");
            }
        } else {
            QMessageBox::information(this, " Failed To Stop Time", "Computer 9 isn't occupied and can't be stopped");
        }

    }
}

void AppProgram::on_stopTime8_clicked()
{
    stopTime8 = true;
    database2 = QSqlDatabase::addDatabase("QMYSQL", "stopTime8");
    database2.setHostName("127.0.0.1");
    database2.setUserName("root");
    database2.setPassword("");
    database2.setDatabaseName("qt5register");

    if(database2.open()) {
        bool occupied = true;

        QSqlQuery setCancel;

        setCancel.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = :computerid;");
        setCancel.bindValue(":computerid", 8);
        if(setCancel.exec()) {
            while(setCancel.next()) {
                if (setCancel.value(1).toString() == "NULL") {
                    occupied = false;
                }
            }
        }

        if (occupied == true) {
            QSqlQuery set8;
            set8.prepare("UPDATE `rentedcomputers` SET username = :username , hour = :hour, minute = :minute, second= :second, membership= :membership WHERE computerid = :computerid;");
            set8.bindValue(":computerid", 8);
            set8.bindValue(":username", "NULL");
            set8.bindValue(":hour", 0);
            set8.bindValue(":minute", 0);
            set8.bindValue(":second", 0);
            set8.bindValue(":membership", "NULL");

            if(set8.exec()) {
                ui->Computer8Label->setText(QString::number(0) + ":" + QString::number(0) + ":" + QString::number(0));
                QMessageBox::information(this, " Sucessfully Stopped Time ", "Computer 8 has been stopped");
            }
        } else {
            QMessageBox::information(this, " Failed To Stop Time", "Computer 8 isn't occupied and can't be stopped");
        }

    }
}

void AppProgram::on_stopTime7_clicked()
{
    stopTime7 = true;
    database2 = QSqlDatabase::addDatabase("QMYSQL", "stopTime7");
    database2.setHostName("127.0.0.1");
    database2.setUserName("root");
    database2.setPassword("");
    database2.setDatabaseName("qt5register");

    if(database2.open()) {
        bool occupied = true;

        QSqlQuery setCancel;

        setCancel.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = :computerid;");
        setCancel.bindValue(":computerid", 7);
        if(setCancel.exec()) {
            while(setCancel.next()) {
                if (setCancel.value(1).toString() == "NULL") {
                    occupied = false;
                }
            }
        }

        if (occupied == true) {
            QSqlQuery set7;
            set7.prepare("UPDATE `rentedcomputers` SET username = :username , hour = :hour, minute = :minute, second= :second, membership= :membership WHERE computerid = :computerid;");
            set7.bindValue(":computerid", 7);
            set7.bindValue(":username", "NULL");
            set7.bindValue(":hour", 0);
            set7.bindValue(":minute", 0);
            set7.bindValue(":second", 0);
            set7.bindValue(":membership", "NULL");

            if(set7.exec()) {
                ui->Computer7Label->setText(QString::number(0) + ":" + QString::number(0) + ":" + QString::number(0));
                QMessageBox::information(this, " Sucessfully Stopped Time ", "Computer 7 has been stopped");
            }
        } else {
            QMessageBox::information(this, " Failed To Stop Time", "Computer 7 isn't occupied and can't be stopped");
        }

    }
}

void AppProgram::on_stopTime6_clicked()
{
    stopTime6 = true;
    database2 = QSqlDatabase::addDatabase("QMYSQL", "stopTime6");
    database2.setHostName("127.0.0.1");
    database2.setUserName("root");
    database2.setPassword("");
    database2.setDatabaseName("qt5register");

    if(database2.open()) {
        bool occupied = true;

        QSqlQuery setCancel;

        setCancel.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = :computerid;");
        setCancel.bindValue(":computerid", 6);
        if(setCancel.exec()) {
            while(setCancel.next()) {
                if (setCancel.value(1).toString() == "NULL") {
                    occupied = false;
                }
            }
        }

        if (occupied == true) {
            QSqlQuery set6;
            set6.prepare("UPDATE `rentedcomputers` SET username = :username , hour = :hour, minute = :minute, second= :second, membership= :membership WHERE computerid = :computerid;");
            set6.bindValue(":computerid", 6);
            set6.bindValue(":username", "NULL");
            set6.bindValue(":hour", 0);
            set6.bindValue(":minute", 0);
            set6.bindValue(":second", 0);
            set6.bindValue(":membership", "NULL");

            if(set6.exec()) {
                ui->Computer6Label->setText(QString::number(0) + ":" + QString::number(0) + ":" + QString::number(0));
                QMessageBox::information(this, " Sucessfully Stopped Time ", "Computer 6 has been stopped");
            }
        } else {
            QMessageBox::information(this, " Failed To Stop Time", "Computer 6 isn't occupied and can't be stopped");
        }

    }
}

void AppProgram::on_stopTime5_clicked()
{
    stopTime5 = true;
    database2 = QSqlDatabase::addDatabase("QMYSQL", "stopTime5");
    database2.setHostName("127.0.0.1");
    database2.setUserName("root");
    database2.setPassword("");
    database2.setDatabaseName("qt5register");

    if(database2.open()) {
        bool occupied = true;

        QSqlQuery setCancel;

        setCancel.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = :computerid;");
        setCancel.bindValue(":computerid", 5);
        if(setCancel.exec()) {
            while(setCancel.next()) {
                if (setCancel.value(1).toString() == "NULL") {
                    occupied = false;
                }
            }
        }

        if (occupied == true) {
            QSqlQuery set5;
            set5.prepare("UPDATE `rentedcomputers` SET username = :username , hour = :hour, minute = :minute, second= :second, membership= :membership WHERE computerid = :computerid;");
            set5.bindValue(":computerid", 5);
            set5.bindValue(":username", "NULL");
            set5.bindValue(":hour", 0);
            set5.bindValue(":minute", 0);
            set5.bindValue(":second", 0);
            set5.bindValue(":membership", "NULL");

            if(set5.exec()) {
                ui->Computer5Label->setText(QString::number(0) + ":" + QString::number(0) + ":" + QString::number(0));
                QMessageBox::information(this, " Sucessfully Stopped Time ", "Computer 5 has been stopped");
            }
        } else {
            QMessageBox::information(this, " Failed To Stop Time", "Computer 5 isn't occupied and can't be stopped");
        }

    }
}


void AppProgram::on_stopTime3_clicked()
{
    stopTime3 = true;
    database2 = QSqlDatabase::addDatabase("QMYSQL", "stopTime3");
    database2.setHostName("127.0.0.1");
    database2.setUserName("root");
    database2.setPassword("");
    database2.setDatabaseName("qt5register");

    if(database2.open()) {
        bool occupied = true;

        QSqlQuery setCancel;

        setCancel.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = :computerid;");
        setCancel.bindValue(":computerid", 3);
        if(setCancel.exec()) {
            while(setCancel.next()) {
                if (setCancel.value(1).toString() == "NULL") {
                    occupied = false;
                }
            }
        }

        if (occupied == true) {
            QSqlQuery set3;
            set3.prepare("UPDATE `rentedcomputers` SET username = :username , hour = :hour, minute = :minute, second= :second, membership= :membership WHERE computerid = :computerid;");
            set3.bindValue(":computerid", 3);
            set3.bindValue(":username", "NULL");
            set3.bindValue(":hour", 0);
            set3.bindValue(":minute", 0);
            set3.bindValue(":second", 0);
            set3.bindValue(":membership", "NULL");

            if(set3.exec()) {
                ui->Computer3Label->setText(QString::number(0) + ":" + QString::number(0) + ":" + QString::number(0));
                QMessageBox::information(this, " Sucessfully Stopped Time ", "Computer 3 has been stopped");
            }
        } else {
            QMessageBox::information(this, " Failed To Stop Time", "Computer 3 isn't occupied and can't be stopped");
        }

    }
}

void AppProgram::on_stopTime4_clicked()
{
    stopTime4 = true;
    database2 = QSqlDatabase::addDatabase("QMYSQL", "stopTime4");
    database2.setHostName("127.0.0.1");
    database2.setUserName("root");
    database2.setPassword("");
    database2.setDatabaseName("qt5register");

    if(database2.open()) {
        bool occupied = true;

        QSqlQuery setCancel;

        setCancel.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = :computerid;");
        setCancel.bindValue(":computerid", 4);
        if(setCancel.exec()) {
            while(setCancel.next()) {
                if (setCancel.value(1).toString() == "NULL") {
                    occupied = false;
                }
            }
        }

        if (occupied == true) {
            QSqlQuery set4;
            set4.prepare("UPDATE `rentedcomputers` SET username = :username , hour = :hour, minute = :minute, second= :second, membership= :membership WHERE computerid = :computerid;");
            set4.bindValue(":computerid", 4);
            set4.bindValue(":username", "NULL");
            set4.bindValue(":hour", 0);
            set4.bindValue(":minute", 0);
            set4.bindValue(":second", 0);
            set4.bindValue(":membership", "NULL");

            if(set4.exec()) {
                ui->Computer4Label->setText(QString::number(0) + ":" + QString::number(0) + ":" + QString::number(0));
                QMessageBox::information(this, " Sucessfully Stopped Time ", "Computer 4 has been stopped");
            }
        } else {
            QMessageBox::information(this, " Failed To Stop Time", "Computer 4 isn't occupied and can't be stopped");
        }

    }
}

void AppProgram::comp2Timer() {
        database3 = QSqlDatabase::addDatabase("QMYSQL", "Comp1Timer");
        database3.setHostName("127.0.0.1");
        database3.setUserName("root");
        database3.setPassword("");
        database3.setDatabaseName("qt5register");

        if(database3.open()) {
            QSqlQuery comp2;
            comp2.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = 2;");
            if(comp2.exec()) {
                while(comp2.next()) {
                    username2 = comp2.value(1).toString();
                    int hour = comp2.value(2).toInt();
                    int minute = comp2.value(3).toInt();
                    int second = comp2.value(4).toInt();
                    membership2 = comp2.value(5).toString();
                    stopTime2 = false;
                    time2 = QTime(hour,minute,second);
                    timer2 = new QTimer(this);
                    connect(timer2, SIGNAL(timeout()),this, SLOT(realTimer2()));
                    timer2->start(1000);
                }
            } else {
              QMessageBox::information(this, "exec failed", "exec failed");
            }
        }
}

void AppProgram::realTimer2() {
    if(stopTime2 == false) {
        QTime time2Added = time2.addSecs(-1);
        time2 = time2Added;
        qDebug() << time2.hour() << time2.minute() << time2.second();
        ui->Computer2Label->setText(QString::number(time2.hour()) + ":" + QString::number(time2.minute()) + ":" + QString::number(time2.second()));
    } else {
        QSqlQuery comp2;
        qInfo() << "This is the last record" << Qt::endl;
        timer2->stop();
        qInfo() << time2.hour() << time2.minute() << time2.second();
        comp2.prepare("UPDATE `usernametime` SET hour = :hour, minute = :minute, seconds = :second WHERE username = :username;");
        comp2.bindValue(":hour", time2.hour());
        comp2.bindValue(":minute", time2.minute());
        comp2.bindValue(":second", time2.second());
        comp2.bindValue(":username", username2);
        if (comp2.exec()) {

            ui->Computer2Button->setStyleSheet("border-image:url(:/images/closed.png);");
        } else {
            QMessageBox::information(this, "storing failed", "storing failed");
        }
    }
}

void AppProgram::on_stopTime2_clicked()
{
    stopTime2 = true;
    database2 = QSqlDatabase::addDatabase("QMYSQL", "stopTime2");
    database2.setHostName("127.0.0.1");
    database2.setUserName("root");
    database2.setPassword("");
    database2.setDatabaseName("qt5register");

    if(database2.open()) {
        bool occupied = true;

        QSqlQuery setCancel;

        setCancel.prepare("SELECT * FROM `rentedcomputers` WHERE computerid = :computerid;");
        setCancel.bindValue(":computerid", 2);
        if(setCancel.exec()) {
            while(setCancel.next()) {
                if (setCancel.value(1).toString() == "NULL") {
                    occupied = false;
                }
            }
        }

        if (occupied == true) {
            QSqlQuery set2;
            set2.prepare("UPDATE `rentedcomputers` SET username = :username , hour = :hour, minute = :minute, second= :second, membership= :membership WHERE computerid = :computerid;");
            set2.bindValue(":computerid", 2);
            set2.bindValue(":username", "NULL");
            set2.bindValue(":hour", 0);
            set2.bindValue(":minute", 0);
            set2.bindValue(":second", 0);
            set2.bindValue(":membership", "NULL");

            if(set2.exec()) {
                ui->Computer2Label->setText(QString::number(0) + ":" + QString::number(0) + ":" + QString::number(0));
                QMessageBox::information(this, " Sucessfully Stopped Time ", "Computer 2 has been stopped");
            }
        } else {
            QMessageBox::information(this, " Failed To Stop Time", "Computer 2 isn't occupied and can't be stopped");
        }

    }
}



void AppProgram::on_durationBox_currentIndexChanged(int index)
{
      int indexPlus1 = index +1;
      double totalPrice = 0;
      int oneHour = 5;
      int twoHour = 10;
      int threeHour = 15;
      int fourHour = 20;
      int fiveHour = 25;
      int sixHour = 30;
      double silverDiscount = 0.95;
      double goldDiscount = 0.85;
      double platinumDiscount = 0.7;

      if(realMembership == "Silver") {
          switch(indexPlus1) {
           case 1:
              totalPrice = oneHour * silverDiscount;
              break;
           case 2:
              totalPrice = twoHour * silverDiscount;
              break;
           case 3:
             totalPrice = threeHour * silverDiscount;
             break;
           case 4:
              totalPrice = fourHour * silverDiscount;
              break;
           case 5:
              totalPrice = fiveHour * silverDiscount;
              break;
           case 6:
              totalPrice = sixHour * silverDiscount;
              break;
          }
      } else if (realMembership == "Gold") {
          switch(indexPlus1) {
           case 1:
              totalPrice = oneHour * goldDiscount;
              break;
           case 2:
              totalPrice = twoHour * goldDiscount;
              break;
           case 3:
             totalPrice = threeHour * goldDiscount;
             break;
           case 4:
              totalPrice = fourHour * goldDiscount;
              break;
           case 5:
              totalPrice = fiveHour * goldDiscount;
              break;
           case 6:
              totalPrice = sixHour * goldDiscount;
              break;
          }
      } else if (realMembership == "Platinum") {
          switch(indexPlus1) {
           case 1:
              totalPrice = oneHour * platinumDiscount;
              break;
           case 2:
              totalPrice = twoHour * platinumDiscount;
              break;
           case 3:
             totalPrice = threeHour * platinumDiscount;
             break;
           case 4:
              totalPrice = fourHour * platinumDiscount;
              break;
           case 5:
              totalPrice = fiveHour * platinumDiscount;
              break;
           case 6:
              totalPrice = sixHour * platinumDiscount;
              break;
          }

      } else {
          // Do Nothing
      }

       if(totalPrice == 0) {
           // Do Nothing
       } else {
           ui->priceLabel->setText("$" + QString::number(totalPrice));
       }
}


void AppProgram::on_regUserMembership_currentIndexChanged(int index)
{
    index = index + 1;
    switch(index) {
    case 1: ui->regPriceLabel->setText("FREE");
            break;
    case 2: ui->regPriceLabel->setText("$" + QString::number(25));
            break;
    case 3: ui->regPriceLabel->setText("$" + QString::number(50));
            break;
    }
}


void AppProgram::on_playButton1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->selectComputer->setCurrentIndex(0);
}

void AppProgram::on_playButton2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->selectComputer->setCurrentIndex(1);
}

void AppProgram::on_playButton3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->selectComputer->setCurrentIndex(2);
}

void AppProgram::on_playButton4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->selectComputer->setCurrentIndex(3);
}

void AppProgram::on_playButton5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->selectComputer->setCurrentIndex(4);
}

void AppProgram::on_playButton6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->selectComputer->setCurrentIndex(5);
}

void AppProgram::on_playButton7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->selectComputer->setCurrentIndex(6);
}

void AppProgram::on_playButton8_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->selectComputer->setCurrentIndex(7);
}

void AppProgram::on_playButton9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->selectComputer->setCurrentIndex(8);
}

void AppProgram::on_playButton10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->selectComputer->setCurrentIndex(9);
}

void AppProgram::on_playButton11_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->selectComputer->setCurrentIndex(10);
}

void AppProgram::on_playButton12_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->selectComputer->setCurrentIndex(11);
}
