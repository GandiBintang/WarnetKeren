#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include"appprogram.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->widget->setVisible(0);
    QGraphicsDropShadowEffect *shadow1 = new QGraphicsDropShadowEffect;
            shadow1->setColor(Qt::gray);
            shadow1->setOffset(1, 1);
            shadow1->setBlurRadius(10);
    ui->EmailEdit->setGraphicsEffect(shadow1);

    QGraphicsDropShadowEffect *shadow2 = new QGraphicsDropShadowEffect;
            shadow2->setColor(Qt::gray);
            shadow2->setOffset(1, 1);
            shadow2->setBlurRadius(10);
    ui->PasswordEdit->setGraphicsEffect(shadow2);

    QGraphicsDropShadowEffect *shadow3 = new QGraphicsDropShadowEffect;
            shadow3->setColor(Qt::gray);
            shadow3->setOffset(1, 1);
            shadow3->setBlurRadius(10);

    ui->PasswordInput->setGraphicsEffect(shadow3);

    QGraphicsDropShadowEffect *shadow4 = new QGraphicsDropShadowEffect;
            shadow4->setColor(Qt::gray);
            shadow4->setOffset(1, 1);
            shadow4->setBlurRadius(10);
    ui->EmailInput->setGraphicsEffect(shadow4);

    QGraphicsDropShadowEffect *shadow5 = new QGraphicsDropShadowEffect;
            shadow5->setColor(Qt::gray);
            shadow5->setOffset(1, 1);
            shadow5->setBlurRadius(10);

    ui->PhoneInput->setGraphicsEffect(shadow5);

    QGraphicsDropShadowEffect *shadow6 = new QGraphicsDropShadowEffect;
            shadow6->setColor(Qt::gray);
            shadow6->setOffset(1, 1);
            shadow6->setBlurRadius(10);

    ui->UsernameInput->setGraphicsEffect(shadow6);


    QGraphicsDropShadowEffect *shadow8 = new QGraphicsDropShadowEffect;
            shadow8->setColor(Qt::gray);
            shadow8->setOffset(1, 1);
            shadow8->setBlurRadius(100);

    ui->widget->setGraphicsEffect(shadow8);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Login

void MainWindow::on_LoginButton_clicked()
{


    // Connect to database
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("qt5register");

    QString username = ui->EmailEdit->text();
    QString password = ui->PasswordEdit->text();

    if (db.open()) {

        //creating query



      QSqlQuery query(QSqlDatabase::database("MyConnect"));

      query.prepare(QString("SELECT * FROM users WHERE email = :username AND password = :password "));
      query.bindValue(":username", username);
      query.bindValue(":password", password);

      if(!query.exec()) {
          QMessageBox::information(this, "Failed" , "Query Failed To Execute");
      } else {
          // kalau berhasil execute
          bool found = false;
          while(query.next()) {
              QString usernameFromDB = query.value(3).toString();
              QString passwordFromDB = query.value(2).toString();

              if(usernameFromDB == username && passwordFromDB == password) {
                  ui->widget->setVisible(1);
                  delay(3000);
                  this->close();
                  AppProgram program;
                  program.setModal(true);
                  program.exec();

                  found = true;
              }
          } if(!found) {
              QMessageBox::information(this, "Login Failed", "Login Unsucesfull, please try again");
          }
      }


    } else {
        QMessageBox::information(this, "Database Failed", "Database connection failed");


    }

}

void MainWindow::on_LoginButton_pressed()
{
    QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
    bodyShadow->setBlurRadius(9.0);
    bodyShadow->setColor(QColor(0, 0, 0, 160));
    bodyShadow->setOffset(0);
    ui->LoginButton->setGraphicsEffect(bodyShadow);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_RegisterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_RegRegButton_clicked() // Register Button On Register Page
{

    // Connect to database

    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("127.0.0.1");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("qt5register");

    if(database.open()) {
        bool found = false;
        // Get data from input fields
        QString username = ui->UsernameInput->text();
        QString password = ui->PasswordInput->text();
        QString email = ui->EmailInput->text();
        QString phone = ui->PhoneInput->text();

        // Check If email is present Query
        if (password.isEmpty() || username.isEmpty() || email.isEmpty() || phone.isEmpty()) {
            QMessageBox::information(this, "Registration Failed", "There is a missing field");
        } else  {
            if (isTelephoneNumber(phone)) {
                if (emailCheck(email) == true) {
                    QSqlQuery qry1;
                    qry1.prepare("SELECT * FROM `users`");
                    if(qry1.exec()) {
                        while(qry1.next()) {
                            QString checkEmail = qry1.value(3).toString();
                            if(checkEmail == email) {
                                found = true;
                            }
                        }
                    }

                    if (found == true) {
                        QMessageBox::information(this, "Registration Failed", "Email has already been taken");
                    } else {
                        // Run Insert Query

                        QSqlQuery qry;
                        qry.prepare("INSERT INTO users (username, password, email, phone)"
                                    "VALUES (:username, :password, :email, :phone)" );
                        qry.bindValue(":username", username);
                        qry.bindValue(":password", password);
                        qry.bindValue(":email", email);
                        qry.bindValue(":phone", phone);

                        if(qry.exec()) {
                            QMessageBox::information(this, "Inserted" , "Data Inserted Sucessfully");
                        } else {
                            QMessageBox::information(this, "Not Inserted", "Data Is Not Inserted");
                        }
                    }
                } else {
                    QMessageBox::information(this, "Failed to register" , "Email in email field is not of email format");
                }
            } else {
                QMessageBox::information(this, "Failed to register" , "Telephone number is not in the right format");
            }


        }

    } else {
        QMessageBox::information(this, "Not Connected", "Database is not connected");
    }

}

bool MainWindow::isChar(QChar c) {
    return ((c >= 'a' && c <= 'z')
                || (c >= 'A' && c <= 'Z'));
}

bool MainWindow::isDigit(const QChar c) {
    return (c >= '0' && c <= '9');
}

bool MainWindow::emailCheck(QString email) {
    if (!isChar(email[0])) {

            // If it's not an alphabet
            // email id is not valid
            return 0;
        }
        // Variable to store position
        // of At and Dot
        int At = -1, Dot = -1;

        // Traverse over the email id
        // string to find position of
        // Dot and At
        for (int i = 0;
             i < email.length(); i++) {

            // If the character is '@'
            if (email[i] == '@') {

                At = i;
            }

            // If character is '.'
            else if (email[i] == '.') {

                Dot = i;
            }
        }

        // If At or Dot is not present
        if (At == -1 || Dot == -1)
            return 0;

        // If Dot is present before At
        if (At > Dot)
            return 0;

        // If Dot is present at the end
        return !(Dot >= (email.length() - 1));
}

void MainWindow::on_BackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

bool MainWindow::isTelephoneNumber(QString number) {
    bool state = true;

    for(int i = 0; i<number.length(); i++) {
        if(!isDigit(number[i])) {
            state = false;
        }
    }

    if(number.length() < 8) {
        state = false;
    }
    return state;
}
