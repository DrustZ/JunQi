#ifndef QIPAN_H
#define QIPAN_H

#include <QWidget>
#include <QFile>
#include <QVector>
#include <QRect>
#include <QTimer>
#include "structs.h"
#include "webthing.h"

namespace Ui {
class qipan;
}

class qipan : public QWidget
{
    Q_OBJECT

public:
    explicit qipan(QWidget *parent = 0);
    ~qipan();
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent*p);
    void init();
    QVector<qizi> fangkuai;
//    QVector<QRect> fangkuai;
//    QVector<QRect> dabenying;
    void panduan(int from,int goal);
    void panding(int a,int b);
    bool tielu(int a, int b);
    bool baifangok();
    void dfs(int a,int b);
    void initdfs();

public slots:
    void start();
    void putok();
    void getinfo(QVector<qizi> gezi);
    void getinitinfo(QVector<qizi> gezi);
    void serverstart();
    void clientstart();
    void chaoshi();
    void fangqi();//超时了，自动放弃
    bool wuqikezou();
    void settrue();
    void qiuhe();
    void renshu();
    void chuantouxiang(QString filename);
    void chuannicheng(QString filename);
    void begin();
    void xianshiname(QString name);//接收收到名字图片的信号
    void over();
    void informParent();

signals:
    void baihaole(int i);
    void kaishile();//计时开始
    void jieshule();//计时结束
    void restart();
    void renjiakaishila(int state);
    void wanle();
    void display(QString);//收到名字头像，发送信号
    void successful_connection();

private:
    Ui::qipan *ui;
    int selecteRect;
    bool selected,zhaodao,putted,finished,CAN,chizi;
    int mode,order,bushu;
    bool dabenying(int b);
    int linjie[60][60];
    bool visited[60];
    int hangHeLie[6][10];//前四组为行，后两组为列
    Webthing *lianjie;
    QTimer *timer;
};

#endif // QIPAN_H
