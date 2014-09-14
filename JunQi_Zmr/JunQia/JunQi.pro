#-------------------------------------------------
#
# Project created by QtCreator 2014-09-10T16:10:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JunQi
TEMPLATE = app
LIBS += -lwsock32

SOURCES += main.cpp\
        game.cpp \
    qipan.cpp \
    receivethread.cpp \
    webthing.cpp \
    ipdialog.cpp

HEADERS  += game.h \
    qipan.h \
    structs.h \
    receivethread.h \
    webthing.h \
    ipdialog.h

FORMS    += game.ui \
    qipan.ui \
    ipdialog.ui

RESOURCES += \
    cs.qrc
