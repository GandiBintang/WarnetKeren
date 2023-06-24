#include "qrpopup.h"
#include "ui_qrpopup.h"
#include "appprogram.h"

#include <QWidget>

#include <QDialogButtonBox>

QRPopUp::QRPopUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QRPopUp)
{
    ui->setupUi(this);

    AppProgram *appprogram = new AppProgram();
    connect(ui->buttonBox, &QDialogButtonBox::accepted, appprogram, &AppProgram::accepted);
}

QRPopUp::~QRPopUp()
{
    delete ui;
}



