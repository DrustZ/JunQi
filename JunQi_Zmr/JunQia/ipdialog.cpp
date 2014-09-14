#include "ipdialog.h"
#include "ui_ipdialog.h"

IPDialog::IPDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IPDialog)
{
    ui->setupUi(this);
    ip.clear();
    this->setWindowTitle("连接游戏");
}

IPDialog::~IPDialog()
{
    delete ui;
}

void IPDialog::settitle(QString title)
{
    ui->label->setText(title);
}

void IPDialog::on_pushButton_clicked()
{
    ip += "1";
    ui->lineEdit->setText(ip);
}

void IPDialog::on_pushButton_11_clicked()
{
    this->done(QDialog::Accepted);
}

void IPDialog::on_pushButton_2_clicked()
{
    ip += "2";
    ui->lineEdit->setText(ip);
}

void IPDialog::on_pushButton_3_clicked()
{
    ip += "3";
    ui->lineEdit->setText(ip);
}

void IPDialog::on_pushButton_4_clicked()
{
    ip += "4";
    ui->lineEdit->setText(ip);
}

void IPDialog::on_pushButton_5_clicked()
{
    ip += "5";
    ui->lineEdit->setText(ip);
}

void IPDialog::on_pushButton_6_clicked()
{
    ip += "6";
    ui->lineEdit->setText(ip);
}

void IPDialog::on_pushButton_7_clicked()
{
    ip += "7";
    ui->lineEdit->setText(ip);
}

void IPDialog::on_pushButton_8_clicked()
{
    ip += "8";
    ui->lineEdit->setText(ip);
}

void IPDialog::on_pushButton_9_clicked()
{
    ip += "9";
    ui->lineEdit->setText(ip);
}

void IPDialog::on_pushButton_12_clicked()
{
    ip += ".";
    ui->lineEdit->setText(ip);
}

void IPDialog::on_pushButton_10_clicked()
{
    ip = ip.left(ip.length() - 1);
    ui->lineEdit->setText(ip);
}

void IPDialog::on_pushButton_13_clicked()
{
    ip += "0";
    ui->lineEdit->setText(ip);
}

void IPDialog::on_lineEdit_textChanged(const QString &arg1)
{
    ip = arg1;
}
