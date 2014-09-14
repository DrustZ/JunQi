#include "game.h"
#include "ui_game.h"
#include <QPalette>
#include <QFile>
#include <QFileDialog>
#include <QInputDialog>

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    QPalette palette;
    timer = new QTimer;
    second = 30;
    count = 0;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/map.jpg")));
    ui->widget->setPalette(palette);

    ui->pushButton->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);

    connect(ui->widget,SIGNAL(baihaole(int)),this,SLOT(updateLabel(int)));
    connect(timer,SIGNAL(timeout()),this,SLOT(updatetime()));
    connect(ui->widget,SIGNAL(kaishile()),this,SLOT(starttime()));
    connect(ui->widget,SIGNAL(jieshule()),this,SLOT(stoptime()));
    connect(ui->widget,SIGNAL(restart()),this,SLOT(playagain()));
    connect(ui->widget,SIGNAL(renjiakaishila(int)),this,SLOT(kaishile(int)));
    connect(ui->widget,SIGNAL(display(QString)),this,SLOT(xianshi(QString)));
    connect(ui->widget,SIGNAL(successful_connection()),this,SLOT(setconnected()));
}

Game::~Game()
{
    delete ui;
}

void Game::on_pushButton_2_clicked()
{
    ui->widget->start();
    ui->pushButton->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
}

void Game::updateLabel(int i)
{
    if (i == 1)
    ui->statusLabel->setText("游戏状态：开始游戏");
    else
        ui->statusLabel->setText("游戏状态：结束游戏");
}

void Game::on_pushButton_clicked()
{
    ui->widget->putok();
    ui->pushButton_2->setEnabled(false);
}

void Game::timeOUT()
{
    count++;
    ui->countlabel->setText(QString::number(count)+"  次");
    if(count == 5)
        ui->widget->chaoshi();
    ui->widget->fangqi();
}

void Game::on_actionNew_triggered()
{
    ui->widget->serverstart();
}

void Game::starttime()
{
    timer->start(1000);
    ui->state2->setText("");
}

void Game::stoptime()
{
    second = 30;
    ui->lcdNumber->display(30);
    timer->stop();
}

void Game::updatetime()
{
    ui->lcdNumber->display(--second);
    if (second == 0)
    {
        second = 30;
        timer->stop();
        ui->state2->setText("你超时了！");
        timeOUT();
    }
}

void Game::on_actionAdd_to_existing_triggered()
{
    ui->widget->clientstart();
}

void Game::playagain()
{
    timer->stop();
    ui->pushButton_2->setEnabled(true);
    ui->pushButton->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
}

void Game::on_pushButton_5_clicked()
{
    ui->widget->qiuhe();
}

void Game::kaishile(int state)
{
    if (state == 1)
        ui->state2->setText("对方已经开始");
    else ui->state2->setText("对方已经摆好棋子");
}


void Game::on_pushButton_6_clicked()
{
    ui->widget->renshu();
}

void Game::xianshi(QString remotename)
{
    ui->remoteName->setText(remotename);
    QImage *image = new QImage;
    image->load("touxiang.jpg");
    ui->RemotePhoto->setPixmap(QPixmap::fromImage(image->scaled(161, 161, Qt::KeepAspectRatio)));
}

void Game::on_action_2_triggered()
{
    QString filename;
    filename=QFileDialog::getOpenFileName(this,
                                             tr("选择图像"),
                                             "",
                                             tr("Images (*.jpg)"));
    QImage *image = new QImage;
    image->load(filename);
    ui->myPhoto->setPixmap(QPixmap::fromImage(image->scaled(161, 161, Qt::KeepAspectRatio)));
    ui->widget->chuantouxiang(filename);

}

void Game::setconnected()
{
    ui->statusLabel->setText("游戏状态：连接成功");
}

void Game::on_action_3_triggered()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("设置"),
                                         tr("User name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty()){
        ui->myName->setText(text);
    }
    ui->widget->chuannicheng(text);
}
