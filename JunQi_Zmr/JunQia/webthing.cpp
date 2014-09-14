#include "webthing.h"
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <ipdialog.h>
#include <QMetaType>
#include <fstream>
#include <QFile>
#include <cstring>
#include <stdlib.h>
using namespace std;

Webthing::Webthing(QObject *)
{
    qRegisterMetaType<SOCKET>("SOCKET");
    rthread = NULL;
}

Webthing::~Webthing()
{

}

void Webthing::startserver(QWidget *wid)
{\
    QString ip;
    if (rthread != NULL){
        rthread->terminate();
        closed();
    }
    qipanwidget = wid;
    IPDialog *da = new IPDialog;
    da->settitle("请输入本机IP");
    da->show();
    if (da->exec() == QDialog::Accepted)
    {
        ip = da->ip;
    }
    server = true;
    WSADATA  Ws;
    struct sockaddr_in LocalAddr, ClientAddr;
    SOCKET ServerSocket, CientSocket;
    int Ret = 0;
    int AddrLen = 0;
    //Init Windows Socket
    if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        qDebug()<<"Init Windows Socket Failed::"<<GetLastError();
        return ;
    }

    //Create Socket
    ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( ServerSocket == INVALID_SOCKET )
    {
        qDebug()<<"Create Socket Failed::"<<GetLastError() ;
        return ;
    }
    LocalAddr.sin_family = AF_INET;
    LocalAddr.sin_addr.s_addr = inet_addr(ip.toStdString().c_str());
    LocalAddr.sin_port = htons(4000);
    memset(LocalAddr.sin_zero, 0x00, 8);

    //Bind Socket
    Ret = bind(ServerSocket, (struct sockaddr*)&LocalAddr, sizeof(LocalAddr));
    if ( Ret != 0 )
    {
        qDebug()<<"Bind Socket Failed::"<<GetLastError() ;
        return ;
    }

    Ret = listen(ServerSocket, 10);
    if ( Ret != 0 )
    {
        qDebug()<<"listen Socket Failed::"<<GetLastError() ;
        return ;
    }
    qDebug() << "successed in setup";
    Ssocket = ServerSocket;

    rthread = new Receivethread;
    rthread->setservermode(true);
    rthread->getthing(ServerSocket,ClientAddr);
    connect(rthread,SIGNAL(getSocket(SOCKET)),this,SLOT(setSocket(SOCKET)));
    connect(rthread,SIGNAL(Recmeg(char*)),this,SLOT(getinfo(char*)));
    connect(rthread,SIGNAL(recinimeg(char*)),this,SLOT(getinitinfo(char*)));
    connect(rthread,SIGNAL(shule()),this,SLOT(shula()));
    connect(rthread,SIGNAL(tachaoshile()),this,SLOT(ye()));
    connect(rthread,SIGNAL(yingle()),this,SLOT(yinglehaha()));
    connect(rthread,SIGNAL(yaoqiuhe()),this,SLOT(renjiaqiuhele()));
    connect(rthread,SIGNAL(qiuhechenggong()),this,SLOT(renjiatongyile()));
    connect(rthread,SIGNAL(qiuheshibai()),this,SLOT(renjiabutongyi()));
    connect(rthread,SIGNAL(renshule()),this,SLOT(renshulea()));
    connect(rthread,SIGNAL(destroyed()),this,SLOT(closed()));
    connect(rthread,SIGNAL(kaishi()),this,SLOT(started()));
    connect(rthread,SIGNAL(shoudaotupian(char*)),this,SLOT(getupian(char*)));
    connect(rthread,SIGNAL(shoudaomingzi(char*)),this,SLOT(getname(char*)));

    rthread->start();
    /*{
        AddrLen = sizeof(ClientAddr);
        CientSocket = accept(ServerSocket, (struct sockaddr*)&ClientAddr, &AddrLen);
        if ( CientSocket == INVALID_SOCKET )
        {
            qDebug()<<"Accept Failed::"<<GetLastError();
        }

        qDebug()<<"Client is connected::"<<inet_ntoa(ClientAddr.sin_addr)<<":"<<ClientAddr.sin_port;

        rthread->getthing();
        connect(rthread,SIGNAL(Recmeg(char*)),this,SLOT(getinfo(char*)));
        connect(rthread,SIGNAL(recinimeg(char*)),this,SLOT(getinitinfo(char*)));
        connect(rthread,SIGNAL(shule()),this,SLOT(shula()));
        connect(rthread,SIGNAL(tachaoshile()),this,SLOT(ye()));
        connect(rthread,SIGNAL(yingle()),this,SLOT(yinglehaha()));
        connect(rthread,SIGNAL(yaoqiuhe()),this,SLOT(renjiaqiuhele()));
        connect(rthread,SIGNAL(qiuhechenggong()),this,SLOT(renjiatongyile()));
        connect(rthread,SIGNAL(qiuheshibai()),this,SLOT(renjiabutongyi()));
        connect(rthread,SIGNAL(renshule()),this,SLOT(renshulea()));*/

}

void Webthing::startclient(QWidget *wid)
{
    QString ip;
    if (rthread != NULL){
        rthread->terminate();
        closed();
    }
    IPDialog *da = new IPDialog;
    da->settitle("请输入对方IP");

    da->show();
    if (da->exec() == QDialog::Accepted)
    {
        ip = da->ip;
    }
    qipanwidget = wid;
    int Ret = 0;
   // int AddrLen = 0;
    server = false;
    WSADATA  Ws;
    struct sockaddr_in ServerAddr;

    //Init Windows Socket
    if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        //cout<<"Init Windows Socket Failed::"<<GetLastError()<<endl;
        return;
    }

    //Create Socket
    CSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( CSocket == INVALID_SOCKET )
    {
        //cout<<"Create Socket Failed::"<<GetLastError()<<endl;
        return;
    }


    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = inet_addr(ip.toStdString().c_str());
    ServerAddr.sin_port = htons(4000);
    memset(ServerAddr.sin_zero, 0x00, 8);
    Ret = ::connect(CSocket,(struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
    if ( Ret == SOCKET_ERROR )
    {
        qDebug()<<"Connect Error::"<<GetLastError();
    }
    else
    {
        qDebug()<<"Connection succeeds!";
    }
    emit(connect_succeeded());
  //  Ret = send(CSocket, "SendBuffer", (int)strlen("SendBuffer"), 0);
    rthread = new Receivethread;
    connect(rthread,SIGNAL(Recmeg(char*)),this,SLOT(getinfo(char*)));
    connect(rthread,SIGNAL(recinimeg(char*)),this,SLOT(getinitinfo(char*)));
    connect(rthread,SIGNAL(shule()),this,SLOT(shula()));
    connect(rthread,SIGNAL(yingle()),this,SLOT(yinglehaha()));
    connect(rthread,SIGNAL(tachaoshile()),this,SLOT(ye()));
    connect(rthread,SIGNAL(yaoqiuhe()),this,SLOT(renjiaqiuhele()));
    connect(rthread,SIGNAL(qiuhechenggong()),this,SLOT(renjiatongyile()));
    connect(rthread,SIGNAL(qiuheshibai()),this,SLOT(renjiabutongyi()));
    connect(rthread,SIGNAL(renshule()),this,SLOT(renshulea()));
    connect(rthread,SIGNAL(destroyed()),this,SLOT(closed()));
    connect(rthread,SIGNAL(kaishi()),this,SLOT(started()));
    connect(rthread,SIGNAL(shoudaotupian(char*)),this,SLOT(getupian(char*)));
    connect(rthread,SIGNAL(shoudaomingzi(char*)),this,SLOT(getname(char*)));
    rthread->setservermode(false);
    rthread->Getsocket(CSocket);
    rthread->start();

}

void Webthing::vtos()
{
    for (int i = 0; i < gezi.size(); ++i)
        gezizu[i] = gezi[i];
}

void Webthing::stov()
{
    gezi.clear();
    for (int i = 0; i <= 59; ++i)
        gezi.push_back(gezizu[i]);
}

void Webthing::closed()
{
    closesocket(CSocket);
    if (server)
        closesocket(Ssocket);
    WSACleanup();
}

void Webthing::started()
{
    emit(this->kaishi());
}

void Webthing::shezhitouxiang(QString filename)
{
    myphotofiledir = filename;
    sendprofile(1);
}

void Webthing::shezhinicheng(QString name)
{
    myName = name;
    //qDebug() << myName;
    sendprofile(2);
}

void Webthing::getupian(char *tupian)
{
    qDebug() << "shou dao tou xiang";
     ofstream file("touxiang.jpg",std::ios::binary);
     char lo[10] = {0};
     memcpy(lo,tupian,4);
     tupian += 4;
     int length = *((int*)lo);
     file.write(tupian,length);
     file.close();
     emit(this->displayName((duifangname)));
}

void Webthing::getname(char *name)
{
    qDebug() << "shou dao ming zi";
    std::string s = name;
    duifangname = QString::fromStdString(s);
    qDebug() << duifangname;
    emit(this->displayName(duifangname));
}

void Webthing::swapnum(int &a, int &b)
{
    int pp = a;
    a = b;
    b = pp;
}

bool Webthing::sendprofile(int mode)
{
    //qDebug() << "fasong";
    char e[7800] = {0};
    char a[2]  = {0};
    int length = 0;
     if (mode == 1){
        //传头像
        a[0] = 'k';
        ifstream fin(myphotofiledir.toStdString().c_str(),std::ios::binary);
        QFile photo(myphotofiledir);
        length = photo.size();
        memcpy(e,a,1);
        memcpy(e+1,&length,4);
        fin.read(e+5,length);
        fin.close();
        int Ret = ::send(CSocket, e, sizeof(e), 0);
        if ( Ret == SOCKET_ERROR )
        {
            qDebug()<<"Send Info Error::"<<GetLastError();
        }
    }
    else {
        //传昵称
        a[0] = 'l';
        memcpy(e,a,1);
        memcpy(e+1,myName.toStdString().c_str(),strlen(myName.toStdString().c_str()));
        int Ret = ::send(CSocket, e, sizeof(e), 0);
        if ( Ret == SOCKET_ERROR )
        {
            qDebug()<<"Send Info Error::"<<GetLastError();
        }
     }
     return true;
}

void Webthing::sendinfo(int mode,QVector<qizi> fangkuai)
{
    this->gezi.clear();
    for (int i = 0; i < fangkuai.size(); ++i)
        gezi.push_back(fangkuai[i]);
    for (int i = 0; i < fangkuai.size()/2; ++i)
    {
        swapnum(gezi[i].state, gezi[59-i].state);
        swapnum(gezi[i].grade, gezi[59-i].grade);
        swapnum(gezi[i].team, gezi[59-i].team);
    }
    vtos();

    char e[7800] = {0};

    //if (mode == 0) strcat(e,"a");
    //else strcat(e,"b");
    char a[1];
    if (mode == 0)
    {
        a[0] = 'a';
    }
    else if (mode == 1){
        a[0] = 'b';
    }
    else if (mode == 2){
        a[0] = 'c';
    }
    else if (mode == 3){
        a[0] = 'd';
    }
    else if (mode == 4){
        a[0] = 'e';
    }
    else if (mode == 5){
        a[0] = 'f';
    }
    else if (mode == 6){
        a[0] = 'g';
    }
    else if (mode == 7){
        a[0] = 'h';
    }
    else if (mode == 8){
        a[0] = 'i';
    }
    else if (mode == 9){
        a[0] = 'j';
    }

    memcpy(e,a,1);
    memcpy(e+1,gezizu,sizeof(qizi)*60);
    int Ret = ::send(CSocket, e, sizeof(qizi)*61, 0);
    if ( Ret == SOCKET_ERROR )
    {
        qDebug()<<"Send Info Error::"<<GetLastError();
    }
}

void Webthing::getinfo(char* mbuffer)
{
    qizi *temp = new qizi[60];
    temp = (qizi*)mbuffer;
    for (int i = 0; i < 60; ++i)
        gezizu[i] = temp[i];
    delete(temp);
    stov();
    emit(this->updateinfo(this->gezi));
}

void Webthing::getinitinfo(char *mbuffer)
{
    qizi *temp = new qizi[60];
    temp = (qizi*)mbuffer;
    for (int i = 0; i < 60; ++i)
        gezizu[i] = temp[i];
    delete(temp);
    stov();
    emit(this->updateinitinfo(this->gezi));
}

void Webthing::shula()
{
    QMessageBox *box = new QMessageBox(QMessageBox::NoIcon,"哇擦!","你输了！");
    box->show();
    emit(shouldrestart());
    //closed();
}

void Webthing::ye()
{
    QMessageBox *box = new QMessageBox(QMessageBox::NoIcon,"哦也!","对方超时五次所以你赢了哈哈高兴吧！");
    box->show();
    emit(shouldrestart());
    //closed();
}

void Webthing::yinglehaha()
{
    QMessageBox *box = new QMessageBox(QMessageBox::NoIcon,"哦也!","对方已经无棋可走了，你赢了！");
    box->show();
    emit(shouldrestart());
    //closed();
}

void Webthing::renjiaqiuhele()
{
   int say = QMessageBox::question(qipanwidget,tr("报告报告"),tr("对方求和，是否同意？"),QMessageBox::Yes,QMessageBox::No);

   if (say == QMessageBox::Yes){
       QMessageBox *box = new QMessageBox(qipanwidget);
       box->setWindowTitle("和棋");
       box->setText("和棋成功，游戏结束");
       box->show();
       sendinfo(6,gezi);
       emit(shouldrestart());
       //closed();
   }
   else {
        sendinfo(7,gezi);
   }

}

void Webthing::renjiatongyile()
{
    QMessageBox *box = new QMessageBox(qipanwidget);
    box->setWindowTitle("和棋");
    box->setText("和棋成功，游戏结束");
    box->show();
    emit(shouldrestart());
    //closed();
}

void Webthing::renjiabutongyi(){
    QMessageBox *box = new QMessageBox(qipanwidget);
    box->setWindowTitle("和棋");
    box->setText("人家不同意和棋，乖乖继续下吧");
    box->show();
}

void Webthing::renshulea()
{
    QMessageBox *box = new QMessageBox(qipanwidget);
    box->setWindowTitle("游戏结束");
    box->setText("对方认输");
    box->show();
    emit(shouldrestart());
    //closed();
}

void Webthing::setSocket(SOCKET so)
{
    CSocket = so;
    emit(connect_succeeded());
 //   Sleep(1);
}
