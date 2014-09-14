#include "qipan.h"
#include "ui_qipan.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QRect>
#include <QFile>
#include <QMessageBox>

qipan::qipan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qipan)
{
    ui->setupUi(this);

    init();
    initdfs();
    lianjie = new Webthing;
    timer = new QTimer;
    connect(lianjie,SIGNAL(updateinfo(QVector<qizi>)),this,SLOT(getinfo(QVector<qizi>)));
    connect(lianjie,SIGNAL(updateinitinfo(QVector<qizi>)),this,SLOT(getinitinfo(QVector<qizi>)));
    connect(timer,SIGNAL(timeout()),this,SLOT(settrue()));
    connect(lianjie,SIGNAL(kaishi()),this,SLOT(begin()));
    connect(lianjie,SIGNAL(displayName(QString)),this,SLOT(xianshiname(QString )));
    connect(lianjie,SIGNAL(shouldrestart()),this,SLOT(over()));
    connect(lianjie,SIGNAL(connect_succeeded()),this,SLOT(informParent()));
}

qipan::~qipan()
{
    delete ui;
}

void qipan::mousePressEvent(QMouseEvent *e)
{
    bool xuanzhong = false; finished = false;
    for (int i = 0; i < fangkuai.size(); ++i)
    {
        QRect temp(QPoint(fangkuai[i].x1,fangkuai[i].y1),QPoint(fangkuai[i].x2,fangkuai[i].y2));
        if (temp.contains(e->pos())){
            xuanzhong = true;
            if (!selected){
                if (fangkuai[i].team == 0) break;
                if (fangkuai[i].state == 0) break;
                selected = true;
                selecteRect = i;
                break;
            }
            else {

                if (mode == 1){
                   // if (fangkuai[i].grade == 11) selected = false;
                    if (fangkuai[i].team == fangkuai[selecteRect].team)
                        {
                        /*//不能放地雷在中间
                            if ((fangkuai[selecteRect].grade == 0)||((i > 9)&&(i < 40)))
                            {
                                selected = false;
                                break;
                            }
                        //大本营限制
                            if ((i == 1)||(i == 3)||(i == 56)||(i == 58)){
                                qDebug() << "dabenying";
                                if ((fangkuai[selecteRect].grade != 0)||(fangkuai[selecteRect].grade != 11))
                                        selected = false;
                                        break;
                            }
                        //炸弹限制
                            if (fangkuai[selecteRect].grade == 1)
                                if ((i >= 50)||(i <= 69)){
                                    selected = false;
                                    break;
                                }
                          */
                            int pp;
                            pp = fangkuai[i].grade;
                            fangkuai[i].grade = fangkuai[selecteRect].grade;
                            fangkuai[selecteRect].grade = pp;
                            pp = fangkuai[i].state;
                            fangkuai[i].state = fangkuai[selecteRect].state;
                            fangkuai[selecteRect].state = pp;
                            selected = false;
                            break;
                        }
                }
                else if (order == 2){ xuanzhong = false; break;}
                else if (mode == 2){//开始进行走棋判断
                    //qDebug() << QString::number(i) << QString::number(fangkuai[i].state);
                    panduan(selecteRect,i);
                //    qDebug() << "zoule";
                }
            }
        }
    }
    if (!xuanzhong){ selected = false;}
    //mode = 2;
    update();
    //wuqikezou();
    if (order == 1 && finished)
        if (putted){
            order = 2;
            emit(jieshule());
            if(!wuqikezou()){
                bushu+=2;
                lianjie->sendinfo(1,fangkuai);
            }
        }
}

void qipan::paintEvent(QPaintEvent*)
{
    QFont font("Helvetica");
    font.setFamily("Arial");
    font.setBold(true);
    font.setPixelSize(14);
    QPainter painter(this);
    painter.setFont(font);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    bool xianqi = false;
    int kongge = 0;
    if (mode){
    for(int i = 0; i < fangkuai.size(); ++i)
    {
        if (fangkuai[i].state == 1){

            if (fangkuai[i].team == 0){
                brush.setColor(Qt::darkBlue);
                painter.setBrush(brush);
            }
            else {
                brush.setColor(Qt::green);
                painter.setBrush(brush);
            }
                QRect temprect = QRect(QPoint(fangkuai[i].x1,fangkuai[i].y1),QPoint(fangkuai[i].x2,fangkuai[i].y2));
                painter.drawRect(temprect);
                painter.setBrush(QBrush(Qt::black));
                //painter.drawText(fangkuai[i].x1,fangkuai[i].y1,QString::number(fangkuai[i].bianshu));
                if (fangkuai[i].team == 1){
                    switch (fangkuai[i].grade) {
                    case 0:
                        painter.drawText(temprect,Qt::AlignCenter, tr("地雷"));
                        break;
                    case 1:
                        painter.drawText(temprect,Qt::AlignCenter,tr("炸弹"));
                        break;
                    case 2:
                        painter.drawText(temprect,Qt::AlignCenter,tr("工兵"));
                        break;
                    case 3:
                        painter.drawText(temprect,Qt::AlignCenter,tr("排长"));
                        break;
                    case 4:
                        painter.drawText(temprect,Qt::AlignCenter,tr("连长"));
                        break;
                    case 5:
                        painter.drawText(temprect,Qt::AlignCenter,tr("营长"));
                        break;
                    case 6:
                        painter.drawText(temprect,Qt::AlignCenter,tr("团长"));
                        break;
                    case 7:
                        painter.drawText(temprect,Qt::AlignCenter,tr("旅长"));
                        break;
                    case 8:
                        painter.drawText(temprect,Qt::AlignCenter,tr("师长"));
                        break;
                    case 9:
                        painter.drawText(temprect,Qt::AlignCenter,tr("军长"));
                        break;
                    case 10:
                        painter.drawText(temprect,Qt::AlignCenter,tr("司令"));
                        break;
                    case 11:
                        painter.drawText(temprect,Qt::AlignCenter,tr("军旗"));
                        break;
                    default:
                        break;
                    }
                }
        }
        else if (fangkuai[i].grade == 10 && fangkuai[i].team == 0){
            xianqi = true;
        }
        else kongge++;
   }
    if (kongge == 10)
        if (bushu >= 50)
        {
            if (!chizi)
            {
                QMessageBox *box = new QMessageBox(QMessageBox::NoIcon,"和棋！","你们真牛，50步没吃一个子");
                box->show();
                emit(restart());
            }
        }
    if (xianqi)
        for (int i = 0; i < fangkuai.size(); ++i){
        if (fangkuai[i].grade == 11 && fangkuai[i].team == 0){
            painter.drawText(fangkuai[i].x1,fangkuai[i].y1,tr("军旗"));
        }
    }
    if (selected){
        brush.setColor(Qt::yellow);
        painter.setBrush(brush);
        QRect temprect = QRect(QPoint(fangkuai[selecteRect].x1,fangkuai[selecteRect].y1),QPoint(fangkuai[selecteRect].x2,fangkuai[selecteRect].y2));
        painter.drawRect(temprect);
        painter.setBrush(QBrush(Qt::black));
        switch (fangkuai[selecteRect].grade) {
        case 0:
            painter.drawText(temprect,Qt::AlignCenter,tr("地雷"));
            break;
        case 1:
            painter.drawText(temprect,Qt::AlignCenter,tr("炸弹"));
            break;
        case 2:
            painter.drawText(temprect,Qt::AlignCenter,tr("工兵"));
            break;
        case 3:
            painter.drawText(temprect,Qt::AlignCenter,tr("排长"));
            break;
        case 4:
            painter.drawText(temprect,Qt::AlignCenter,tr("连长"));
            break;
        case 5:
            painter.drawText(temprect,Qt::AlignCenter,tr("营长"));
            break;
        case 6:
            painter.drawText(temprect,Qt::AlignCenter,tr("团长"));
            break;
        case 7:
            painter.drawText(temprect,Qt::AlignCenter,tr("旅长"));
            break;
        case 8:
            painter.drawText(temprect,Qt::AlignCenter,tr("师长"));
            break;
        case 9:
            painter.drawText(temprect,Qt::AlignCenter,tr("军长"));
            break;
        case 10:
            painter.drawText(temprect,Qt::AlignCenter,tr("司令"));
            break;
        case 11:
            painter.drawText(temprect,Qt::AlignCenter,tr("军旗"));
            break;
        }
        }
    }
}

void qipan::init()
{
    fangkuai.clear();
    finished = false;
    selected = false;
    CAN = false;
    putted = false;
    order = 0;
    bushu = 0;
    chizi = false;
    mode = 0;
    QFile file("info.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    for (int i = 0; i <= 59; ++i){
        qizi temp;
        temp.x1 = in.readLine().toInt();
        temp.y1 = in.readLine().toInt();
        temp.x2 = in.readLine().toInt();
        temp.y2 = in.readLine().toInt();
        //qDebug() << QString::number(temp.x1);
        temp.grade = -1;
        temp.state = 1;
        if (i < 30)
            temp.team = 0;
        else temp.team = 1;
        temp.bianshu = 0;
        temp.kangqi = 0;
        temp.leixing = 1;
        if (dabenying(i)){
            temp.leixing = 0;
        }
        fangkuai.push_back(temp);
    }
    //qDebug() << fangkuai.size();
   for (int i = 0; i <= 59; ++i){
       if (i+5 <= 59){
           if ((i == 26)||(i == 28));
           else {
              fangkuai[i].bian[fangkuai[i].bianshu] = i + 5;
              fangkuai[i].bianshu++;
              fangkuai[i+5].bian[fangkuai[i+5].bianshu] = i;
              fangkuai[i+5].bianshu++;
           }
       }
       if ((i % 5 != 4)&&(i + 1 <= 59)){
           fangkuai[i].bian[fangkuai[i].bianshu] = i + 1;
           fangkuai[i].bianshu++;
           fangkuai[i+1].bian[fangkuai[i+1].bianshu] = i;
           fangkuai[i+1].bianshu++;
       }
       if ((i == 11)||(i == 13)||(i == 21)||(i == 23)||(i == 36)||(i == 38)||(i == 46)||(i == 48)){
           fangkuai[i].state = 0;
           fangkuai[i].grade = -1;
           fangkuai[i].leixing = -1;//xing ying
           fangkuai[i].bian[fangkuai[i].bianshu] = i - 6;
           fangkuai[i].bianshu++;
           fangkuai[i-6].bian[fangkuai[i-6].bianshu] = i;
           fangkuai[i-6].bianshu++;
           fangkuai[i].bian[fangkuai[i].bianshu] = i + 6;
           fangkuai[i].bianshu++;
           fangkuai[i+6].bian[fangkuai[i+6].bianshu] = i;
           fangkuai[i+6].bianshu++;
           fangkuai[i].bian[fangkuai[i].bianshu] = i - 4;
           fangkuai[i].bianshu++;
           fangkuai[i-4].bian[fangkuai[i-4].bianshu] = i;
           fangkuai[i-4].bianshu++;
           fangkuai[i].bian[fangkuai[i].bianshu] = i + 4;
           fangkuai[i].bianshu++;
           fangkuai[i+4].bian[fangkuai[i+4].bianshu] = i;
           fangkuai[i+4].bianshu++;
        }
   }
   fangkuai[17].state = fangkuai[42].state = 0;
   fangkuai[17].leixing = fangkuai[42].leixing = -1;//xingying

    {
   //init the type
   //junqi --- 11
   fangkuai[1].grade = 11; fangkuai[58].grade = 11;
   //dilei --- 0
   fangkuai[0].grade = fangkuai[2].grade = fangkuai[3].grade = 0;
   fangkuai[59].grade = fangkuai[57].grade = fangkuai[56].grade = 0;
   //zhadan 1
   fangkuai[4].grade = fangkuai[5].grade = 1;
   fangkuai[55].grade = fangkuai[54].grade = 1;
   //gongbing 2
   fangkuai[6].grade = fangkuai[7].grade = fangkuai[8].grade = 2;
   fangkuai[53].grade = fangkuai[52].grade = fangkuai[51].grade = 2;
   //paizhang 3
   fangkuai[9].grade = fangkuai[10].grade = fangkuai[12].grade = 3;
   fangkuai[50].grade = fangkuai[49].grade = fangkuai[47].grade = 3;
   //lianzhang 4
   fangkuai[14].grade = fangkuai[15].grade = fangkuai[16].grade = 4;
   fangkuai[45].grade = fangkuai[44].grade = fangkuai[43].grade = 4;
   //yingzhang 5
   fangkuai[18].grade = fangkuai[19].grade = 5;
   fangkuai[41].grade = fangkuai[40].grade = 5;
   //tuanzhang 6
   fangkuai[20].grade = fangkuai[22].grade = 6;
   fangkuai[39].grade = fangkuai[37].grade = 6;
   //lvzhang 7
   fangkuai[24].grade = fangkuai[25].grade = 7;
   fangkuai[35].grade = fangkuai[34].grade = 7;
   //shizhang 8
   fangkuai[26].grade = fangkuai[33].grade = 8;
   fangkuai[27].grade = fangkuai[32].grade = 8;
   //junzhang 9
   fangkuai[28].grade = fangkuai[31].grade = 9;
   //siling 10
   fangkuai[29].grade = fangkuai[30].grade = 10;
   }

    //邻接矩阵建立铁路
   {
    memset(linjie,0,sizeof(int));
    for(int i = 5; i < 9; ++i){
        linjie[i+1][i] = 1;
        linjie[i][i+1] = 1;
    }
    for(int i = 25; i < 29; ++i){
        linjie[i+1][i] = 1;
        linjie[i][i+1] = 1;
    }
    for(int i = 30; i < 34; ++i){
        linjie[i+1][i] = 1;
        linjie[i][i+1] = 1;
    }
    for(int i = 50; i < 54; ++i){
        linjie[i+1][i] = 1;
        linjie[i][i+1] = 1;
    }
    for (int i = 5; i < 50; i+=5){
        linjie[i][i+5] = 1;
        linjie[i+5][i] = 1;
    }
    for (int i = 9; i < 54; i+=5){
        linjie[i][i+5] = 1;
        linjie[i+5][i] = 1;
    }
    linjie[27][32] = linjie[32][27] = 1;
    for (int i = 0; i <= 3; ++i)
        for (int j = 0; j <= 4; ++j){
            if (i == 0)
                hangHeLie[i][j] = j+5;
            if (i == 1)
                hangHeLie[i][j] = 25+j;
            if (i == 2)
                hangHeLie[i][j] = 30+j;
            if (i == 3)
                hangHeLie[i][j] = 50+j;
        }
    for (int i = 4; i < 6; ++i)
        for(int j = 0; j < 10; ++j){
            if (i == 4)
                hangHeLie[i][j] = 5+5*j;
            if (i == 5)
                hangHeLie[i][j] = 9+5*j;
        }
   }
}

void qipan::panduan(int from, int goal)
{
   // qDebug() << QString::number(from) << QString::number(fangkuai[from].grade);
    selected = false;

    //军旗不动地雷不动
    if (fangkuai[from].grade == 11) return;
    if (fangkuai[from].grade == 0) return;
    //大本营不动
    if (fangkuai[from].leixing == 0) return;

    //首先判断目标有没有同伴点
    if (fangkuai[goal].state == 1){

        if (fangkuai[goal].team == fangkuai[from].team) return;
        //是敌方，进行判定（在不在走的范围内，怎么吃）
        for (int i = 0; i < fangkuai[from].bianshu; ++i)
        {
            if (fangkuai[from].bian[i] == goal){
                //可以走，进行判定
                panding(from,goal);
                update();
                finished = true;
                break;
            }
            else
                //检查是否在铁路上
            {
                if (tielu(from,goal))
                {
                    finished = true;
                    //都在铁路上，怎么吃
                    panding(from,goal);
                    update();
                    break;
                }
            }
        }
    }
    else {
        //目标点没有人，直接判断走
      //  qDebug() << "wonengzou";
        for (int i = 0; i < fangkuai[from].bianshu; ++i)
        {
                if (fangkuai[from].bian[i] == goal){
                   // qDebug() << "wokeyi";
                    finished = true;
                    fangkuai[from].state = 0;
                    fangkuai[goal].state = 1;
                    fangkuai[goal].team = fangkuai[from].team;
                    int pp;
                    pp = fangkuai[from].grade;
                    fangkuai[from].grade = fangkuai[goal].grade;
                    fangkuai[goal].grade = pp;
                    break;
                    update();
                }
            else //检查是否在铁路上
            {
                if (tielu(from,goal)){
                    finished = true;
                    fangkuai[from].state = 0;
                    fangkuai[goal].state = 1;
                    fangkuai[goal].team = fangkuai[from].team;
                    int pp;
                    pp = fangkuai[from].grade;
                    fangkuai[from].grade = fangkuai[goal].grade;
                    fangkuai[goal].grade = pp;
                    break;
                    update();
                }
            }
        }
    }
}

void qipan::start()
{
    init();
    mode = 1;
    update();
    lianjie->sendinfo(9,fangkuai);
}

void qipan::putok()
{
    if (baifangok()){
        mode = 2;
        putted = true;
        //发送摆好命令
        if (order == 2){
            timer->start(1000*180);
            lianjie->sendinfo(1,fangkuai);
        }
        else{
            lianjie->sendinfo(0,fangkuai);
        }
        emit(baihaole(1));
    }
}

void qipan::getinfo(QVector<qizi> gezi)
{
    for (int i = 0; i < gezi.size(); ++i){
        fangkuai[i].grade = gezi[i].grade;
        fangkuai[i].state = gezi[i].state;
        fangkuai[i].team = 1 - gezi[i].team;
    }
    if (order == 2) order = 1;
    if (order == 0){
        timer->start(1000*180);
        order = 1;
    }
   // qDebug() << QString::number(order);
    emit(this->kaishile());
    update();
}

void qipan::getinitinfo(QVector<qizi> gezi)
{
   // qDebug() << "get";
    for(int i = 0; i < 30; ++i){
        fangkuai[i].grade = gezi[i].grade;
        fangkuai[i].state = gezi[i].state;
    }
    if (order == 0) order = 2;
    emit(this->renjiakaishila(2));
    update();
}

void qipan::serverstart()
{
    lianjie->startserver(this);
}

void qipan::clientstart()
{
    lianjie->startclient(this);
}

void qipan::chaoshi()
{
    QMessageBox *box = new QMessageBox(QMessageBox::NoIcon,"...","超时五次就输了哥们别这样虽然我知道你在思考但是你输了");
    box->show();
    lianjie->sendinfo(3,fangkuai);
    init();
    emit(restart());
}

void qipan::fangqi()
{
    lianjie->sendinfo(1,fangkuai);
    order = 2;
}

bool qipan::wuqikezou()
{
    bool wofang = false, difang = false;
    for (int i = 0; i < fangkuai.size(); ++i)
    {
        if (fangkuai[i].state != 0)//还活着
            if (fangkuai[i].grade != 11 && fangkuai[i].grade != 0)//不是地雷或者军旗
                if (i != 1 && i != 3 && i != 56 && i != 58)//不在大本营
                {
                    if (fangkuai[i].team == 0) difang = true;
                    else wofang = true;
                }
        if (wofang && difang) return false;
    }
    if (wofang == false){
        QMessageBox *box = new QMessageBox(QMessageBox::NoIcon,"无棋可走","你输了。");
        box->show();
        lianjie->sendinfo(4,fangkuai);
        emit(restart());
    }
    else{
        QMessageBox *box = new QMessageBox(QMessageBox::NoIcon,"对方已经无棋可走","你赢了！");
        box->show();
        lianjie->sendinfo(2,fangkuai);
        emit(restart());
    }
    return true;
}

void qipan::settrue()
{
    CAN = true;
}

void qipan::qiuhe()
{
    if (CAN)
    lianjie->sendinfo(5,fangkuai);
}

void qipan::renshu()
{
    if (CAN){
        lianjie->sendinfo(8,fangkuai);
        init();
        emit(this->restart());
    }
}

void qipan::chuantouxiang(QString filename)
{
    lianjie->shezhitouxiang(filename);
}

void qipan::chuannicheng(QString name)
{
    lianjie->shezhinicheng(name);
}


void qipan::begin()
{
    emit(this->renjiakaishila(1));
}

void qipan::xianshiname(QString name)
{
    emit(this->display(name));
}

void qipan::over()
{
    emit(restart());
}

void qipan::informParent()
{
    emit(successful_connection());
}

bool qipan::dabenying(int b)
{
    if ((b == 1) || (b == 3) || (b == 58) || (b == 56)){
        return true;
    }
    return false;
}

void qipan::panding(int a, int b)
{
    if (fangkuai[b].leixing == -1) return;
    //判断地雷
    if (fangkuai[b].grade == 0){
        if (fangkuai[a].grade != 2){
            fangkuai[a].state = 0;
        }
        else {
            fangkuai[b].grade = 2;
            fangkuai[a].state = 0;
            fangkuai[b].team = fangkuai[a].team;
        }
        return;
    }
    //判断炸弹
    if ((fangkuai[a].grade == 1)||(fangkuai[b].grade == 1)){
        fangkuai[a].state = 0;
        fangkuai[b].state = 0;

        return;
    }
    //判断军旗
    if (fangkuai[b].grade == 11)
    {
        fangkuai[a].state = 0;
        fangkuai[b].grade = fangkuai[a].grade;
       // QString name = (fangkuai[b].team == 1) ? "蓝方" : "绿方";
        QMessageBox *box = new QMessageBox(QMessageBox::NoIcon,"哇哦!","你赢了！");
        box->show();
        lianjie->sendinfo(2,fangkuai);
        emit(this->restart());
        return;
    }
    //普遍判断
    if (fangkuai[a].grade < fangkuai[b].grade)
    {
        fangkuai[a].state = 0;
        //如果扛旗，则被抢走
       /* if (fangkuai[a].kangqi == 1){
            fangkuai[a].kangqi = 0;
            fangkuai[b].kangqi = 2;
        }
        else if (fangkuai[a].kangqi == 2){
            fangkuai[a].kangqi = 0;
            fangkuai[b].kangqi = 1;
        }
        */
    }
    else if (fangkuai[a].grade > fangkuai[b].grade)
    {

        fangkuai[a].state = 0;
        fangkuai[b].grade = fangkuai[a].grade;
        fangkuai[a].grade = -1;
        fangkuai[b].team = fangkuai[a].team;
        //如果扛旗，则被抢走
        /*if (fangkuai[b].kangqi == 1){
            fangkuai[b].kangqi = 2;
        }
        else if (fangkuai[b].kangqi == 2){
            fangkuai[b].kangqi = 1;
        }
        */
    }
    else {
        fangkuai[a].state = 0;
        fangkuai[b].state = 0;
        return;
    }
}

bool qipan::tielu(int a, int b)
{
    //判断是否在铁路上
    if (fangkuai[a].grade != 2){
        int dian1 = -1,dian2 = -2,qidian = 0,zhongdian = 0;
        for (int i = 0; i <= 3; ++i)
            for (int j = 0; j <= 4; ++j){
                if (a == hangHeLie[i][j]){
                    dian1 = i;
                    qidian = j;
                }
                if (b == hangHeLie[i][j]){
                    zhongdian = j;
                    dian2 = i;
                }
            }
        if (dian1 == dian2){
            if (qidian > zhongdian){
                int pp = qidian;
                qidian = zhongdian;
                zhongdian = pp;
            }
            for (int i = qidian+1; i < zhongdian; ++i)
                if (fangkuai[hangHeLie[dian1][i]].state == 1)
                    return false;
            //qDebug() << QString::number(dian1)
            return true;
        }
        for (int i = 4; i <= 5; ++i)
            for (int j = 0; j <= 9; ++j)
              {
                if (a == hangHeLie[i][j]){
                    dian1 = i;
                    qidian = j;
                }
                if (b == hangHeLie[i][j]){
                    dian2 = i;
                    zhongdian = j;
                }
            }
        if (dian1 == dian2){
            if (qidian > zhongdian){
                int pp = qidian;
                qidian = zhongdian;
                zhongdian = pp;
            }
            for (int i = qidian+1; i < zhongdian; ++i)
                if (fangkuai[hangHeLie[dian1][i]].state == 1)
                    return false;
            return true;
        }
    }
    else {
        initdfs();
        dfs(a,b);
        return zhaodao;
    }
    return false;
}

bool qipan::baifangok()
{
    for (int i = 0; i <= 59; ++i)
    {
        //不能放地雷在中间
            if (fangkuai[i].grade == 0)
               if (((i > 9)&&(i < 50)))
            {
                QMessageBox *box = new QMessageBox(QMessageBox::NoIcon,"Putting mistake!","地雷只能放后两排，挫！");
                box->show();
                qDebug() << "dilei~";
                return false;
            }

        //炸弹限制
            if (fangkuai[i].grade == 1)
                if ((i >= 25)&&(i <= 34)){
                    QMessageBox *box = new QMessageBox(QMessageBox::NoIcon,"Putting mistake!","炸弹不能放第一排，挫！");
                    box->show();
                    selected = false;

                    qDebug() << "zhadan~" ;
                    return false;
                }
        if ((i == 11)||(i == 13)||(i == 21)||(i == 23)||(i == 36)||(i == 38)||(i == 46)||(i == 48)){
            if (fangkuai[i].state == 1){
                QMessageBox *box = new QMessageBox(QMessageBox::NoIcon,"Putting mistake!","行营不能放子啊，你会下棋？");
                box->show();
                qDebug() << "xingying~";
                return false;
            }
        }
    }
    if (!((fangkuai[1].grade == 11)||(fangkuai[3].grade == 11))){
        QMessageBox *box = new QMessageBox(QMessageBox::NoIcon,"Putting mistake!","军旗不在大本营，别这样");
        box->show();
        return false;
        }
    if (!((fangkuai[58].grade == 11)||(fangkuai[56].grade == 11))){
        QMessageBox *box = new QMessageBox(QMessageBox::NoIcon,"Putting mistake!","军旗不在大本营，别这样");
        box->show();
        return false;
      }
    return true;
}

void qipan::dfs(int a, int b)
{
    visited[a]=true;//标记顶点a被访问
    for(int j=0;j<60;j++)
    {
        if (linjie[a][j] != 0)
            if (j == b)
            {
                zhaodao = true;
                return;
            }
        if(linjie[a][j]!=0&&visited[j]==0&&fangkuai[j].state!=1)
            dfs(j,b);
    }
}

void qipan::initdfs()
{
    zhaodao = false;
    for (int i = 0; i < 60; ++i)
        visited[i] = false;
}



