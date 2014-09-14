#ifndef WEBTHING_H
#define WEBTHING_H
#include <QObject>
#include <QVector>
#include "structs.h"
#include "windows.h"
#include "receivethread.h"
#include "sendthread.h"

class Webthing:public QObject
{
    Q_OBJECT
public:
    Webthing(QObject *parent = 0);
    ~Webthing();
    void startserver(QWidget*);
    void startclient(QWidget*);
    void vtos();
    void stov();
    void swapnum(int&a, int&b);
    bool sendprofile(int mode);

    Receivethread *rthread;

signals:
    void updateinfo(QVector<qizi>);//更新信息
    void updateinitinfo(QVector<qizi>);
    void kaishi();
    void displayPhoto();
    void displayName(QString );
    void shouldrestart();
    void connect_succeeded();

public slots:
    void sendinfo(int mode, QVector<qizi> fangkuai);//发送信息
    void getinfo(char*);
    void getinitinfo(char*);
    void shula();
    void ye();
    void yinglehaha();
    void renjiaqiuhele();
    void renjiatongyile();
    void renjiabutongyi();
    void renshulea();
    void setSocket(SOCKET so);
    void closed();
    void started();
    void shezhitouxiang(QString);
    void shezhinicheng(QString);
    void getupian(char* tupian);
    void getname(char* name);

private:
    QVector<qizi> gezi;
    qizi gezizu[60];
    SOCKET CSocket,Ssocket;
    bool server,QH;
    QWidget *qipanwidget;
    QString myphotofiledir,myName,duifangname;

};

#endif // WEBTHING_H
