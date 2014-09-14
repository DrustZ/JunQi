/********************************************************************************
** Form generated from reading UI file 'qipan.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIPAN_H
#define UI_QIPAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qipan
{
public:

    void setupUi(QWidget *qipan)
    {
        if (qipan->objectName().isEmpty())
            qipan->setObjectName(QStringLiteral("qipan"));
        qipan->resize(450, 643);
        qipan->setAutoFillBackground(true);
        qipan->setStyleSheet(QStringLiteral(""));

        retranslateUi(qipan);

        QMetaObject::connectSlotsByName(qipan);
    } // setupUi

    void retranslateUi(QWidget *qipan)
    {
        qipan->setWindowTitle(QApplication::translate("qipan", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class qipan: public Ui_qipan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIPAN_H
