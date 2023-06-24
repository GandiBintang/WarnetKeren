#ifndef QRPOPUP_H
#define QRPOPUP_H

#include <QDialog>

namespace Ui {
class QRPopUp;
}

class QRPopUp : public QDialog
{
    Q_OBJECT

public:
    explicit QRPopUp(QWidget *parent = nullptr);
    ~QRPopUp();

signals:
    void buttonBox();

private:
    Ui::QRPopUp *ui;
};

#endif // QRPOPUP_H
