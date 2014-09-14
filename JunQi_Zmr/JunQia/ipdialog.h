#ifndef IPDIALOG_H
#define IPDIALOG_H

#include <QDialog>

namespace Ui {
class IPDialog;
}

class IPDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IPDialog(QWidget *parent = 0);
    ~IPDialog();
    QString ip;
    void settitle(QString title);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::IPDialog *ui;
};

#endif // IPDIALOG_H
