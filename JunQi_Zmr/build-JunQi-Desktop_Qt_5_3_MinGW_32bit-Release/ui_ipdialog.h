/********************************************************************************
** Form generated from reading UI file 'ipdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IPDIALOG_H
#define UI_IPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IPDialog
{
public:
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_10;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_11;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *IPDialog)
    {
        if (IPDialog->objectName().isEmpty())
            IPDialog->setObjectName(QStringLiteral("IPDialog"));
        IPDialog->resize(184, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IPDialog->sizePolicy().hasHeightForWidth());
        IPDialog->setSizePolicy(sizePolicy);
        IPDialog->setMinimumSize(QSize(184, 250));
        IPDialog->setMaximumSize(QSize(184, 250));
        label = new QLabel(IPDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 161, 31));
        widget = new QWidget(IPDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 40, 161, 201));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_2->addWidget(pushButton_6);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout_3->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        horizontalLayout_3->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        horizontalLayout_3->addWidget(pushButton_9);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        pushButton_12 = new QPushButton(widget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        horizontalLayout_4->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(widget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        horizontalLayout_4->addWidget(pushButton_13);

        pushButton_10 = new QPushButton(widget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        pushButton_10->setMinimumSize(QSize(48, 23));
        pushButton_10->setMaximumSize(QSize(48, 23));

        horizontalLayout_4->addWidget(pushButton_10);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        horizontalLayout_5->addWidget(pushButton_11);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(IPDialog);

        QMetaObject::connectSlotsByName(IPDialog);
    } // setupUi

    void retranslateUi(QDialog *IPDialog)
    {
        IPDialog->setWindowTitle(QApplication::translate("IPDialog", "Dialog", 0));
        label->setText(QString());
        pushButton->setText(QApplication::translate("IPDialog", "1", 0));
        pushButton_2->setText(QApplication::translate("IPDialog", "2", 0));
        pushButton_3->setText(QApplication::translate("IPDialog", "3", 0));
        pushButton_4->setText(QApplication::translate("IPDialog", "4", 0));
        pushButton_5->setText(QApplication::translate("IPDialog", "5", 0));
        pushButton_6->setText(QApplication::translate("IPDialog", "6", 0));
        pushButton_7->setText(QApplication::translate("IPDialog", "7", 0));
        pushButton_8->setText(QApplication::translate("IPDialog", "8", 0));
        pushButton_9->setText(QApplication::translate("IPDialog", "9", 0));
        pushButton_12->setText(QApplication::translate("IPDialog", ".", 0));
        pushButton_13->setText(QApplication::translate("IPDialog", "0", 0));
        pushButton_10->setText(QApplication::translate("IPDialog", "Del", 0));
        pushButton_11->setText(QApplication::translate("IPDialog", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class IPDialog: public Ui_IPDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPDIALOG_H
