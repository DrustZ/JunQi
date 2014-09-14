/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qipan.h>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QAction *actionNew;
    QAction *actionAdd_to_existing;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralWidget;
    qipan *widget;
    QFrame *frame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_4;
    QLCDNumber *lcdNumber;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *countlabel;
    QLabel *statusLabel;
    QLabel *state2;
    QLabel *remoteName;
    QLabel *myName;
    QFrame *line;
    QLabel *RemotePhoto;
    QLabel *myPhoto;
    QLabel *backgroundlabel;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QStringLiteral("Game"));
        Game->resize(710, 701);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Game->sizePolicy().hasHeightForWidth());
        Game->setSizePolicy(sizePolicy);
        Game->setMinimumSize(QSize(710, 701));
        Game->setMaximumSize(QSize(710, 701));
        actionNew = new QAction(Game);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionAdd_to_existing = new QAction(Game);
        actionAdd_to_existing->setObjectName(QStringLiteral("actionAdd_to_existing"));
        action_2 = new QAction(Game);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(Game);
        action_3->setObjectName(QStringLiteral("action_3"));
        centralWidget = new QWidget(Game);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new qipan(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 0, 450, 640));
        widget->setMinimumSize(QSize(450, 640));
        widget->setMaximumSize(QSize(450, 640));
        widget->setAutoFillBackground(true);
        widget->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(480, 460, 221, 191));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        pushButton_5->setFont(font);

        horizontalLayout_3->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setFont(font);

        horizontalLayout_3->addWidget(pushButton_6);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lcdNumber = new QLCDNumber(frame);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout_4->addWidget(lcdNumber);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        countlabel = new QLabel(frame);
        countlabel->setObjectName(QStringLiteral("countlabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(15);
        countlabel->setFont(font1);
        countlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(countlabel);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(490, 430, 201, 21));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        statusLabel->setFont(font2);
        state2 = new QLabel(centralWidget);
        state2->setObjectName(QStringLiteral("state2"));
        state2->setGeometry(QRect(490, 400, 161, 21));
        state2->setFont(font);
        remoteName = new QLabel(centralWidget);
        remoteName->setObjectName(QStringLiteral("remoteName"));
        remoteName->setGeometry(QRect(480, 170, 171, 21));
        remoteName->setFont(font);
        remoteName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        myName = new QLabel(centralWidget);
        myName->setObjectName(QStringLiteral("myName"));
        myName->setGeometry(QRect(470, 370, 181, 21));
        QFont font3;
        font3.setPointSize(10);
        myName->setFont(font3);
        myName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(470, 180, 231, 20));
        line->setFont(font3);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        RemotePhoto = new QLabel(centralWidget);
        RemotePhoto->setObjectName(QStringLiteral("RemotePhoto"));
        RemotePhoto->setGeometry(QRect(540, 0, 161, 161));
        RemotePhoto->setStyleSheet(QStringLiteral("border : 1px solid white"));
        myPhoto = new QLabel(centralWidget);
        myPhoto->setObjectName(QStringLiteral("myPhoto"));
        myPhoto->setGeometry(QRect(540, 200, 161, 161));
        myPhoto->setStyleSheet(QStringLiteral("border : 1px solid white"));
        backgroundlabel = new QLabel(centralWidget);
        backgroundlabel->setObjectName(QStringLiteral("backgroundlabel"));
        backgroundlabel->setGeometry(QRect(0, 0, 711, 671));
        backgroundlabel->setStyleSheet(QStringLiteral("background-image: url(:/beijing1.jpg);"));
        Game->setCentralWidget(centralWidget);
        backgroundlabel->raise();
        widget->raise();
        frame->raise();
        statusLabel->raise();
        state2->raise();
        remoteName->raise();
        myName->raise();
        line->raise();
        RemotePhoto->raise();
        myPhoto->raise();
        menuBar = new QMenuBar(Game);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 710, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        Game->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Game);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Game->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Game);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Game->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addSeparator();
        menu->addAction(actionNew);
        menu->addAction(actionAdd_to_existing);
        menu_2->addSeparator();
        menu_2->addAction(action_2);
        menu_2->addAction(action_3);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QMainWindow *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "Game", 0));
        actionNew->setText(QApplication::translate("Game", "\346\226\260\345\273\272\346\234\215\345\212\241\345\231\250", 0));
        actionAdd_to_existing->setText(QApplication::translate("Game", "\350\277\236\346\216\245\345\267\262\346\234\211\346\234\215\345\212\241\345\231\250", 0));
        action_2->setText(QApplication::translate("Game", "\345\244\264\345\203\217", 0));
        action_3->setText(QApplication::translate("Game", "\346\230\265\347\247\260", 0));
        pushButton_5->setText(QApplication::translate("Game", "\346\261\202\345\222\214", 0));
        pushButton_6->setText(QApplication::translate("Game", "\350\256\244\350\276\223", 0));
        pushButton_2->setText(QApplication::translate("Game", "\345\274\200\345\247\213", 0));
        pushButton->setText(QApplication::translate("Game", "\346\221\206\345\245\275\344\272\206", 0));
        label->setText(QApplication::translate("Game", "\345\205\261\350\266\205\346\227\266\357\274\232", 0));
        countlabel->setText(QApplication::translate("Game", "0  \346\254\241", 0));
        statusLabel->setText(QApplication::translate("Game", "\346\270\270\346\210\217\347\212\266\346\200\201\357\274\232", 0));
        state2->setText(QString());
        remoteName->setText(QString());
        myName->setText(QString());
        RemotePhoto->setText(QString());
        myPhoto->setText(QString());
        backgroundlabel->setText(QString());
        menu->setTitle(QApplication::translate("Game", "\350\277\236\346\216\245", 0));
        menu_2->setTitle(QApplication::translate("Game", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
