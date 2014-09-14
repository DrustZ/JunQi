#ifndef WEB_H
#define WEB_H
#include "structs.h"
#include "windows.h"
#include <QVector>
#include <QObject>

class Web : public QObject
{
    Q_OBJECT
public:
    Web(QObject* parent = 0);
    ~Web();
    void startserver();
    void startclient();
    void getinfo(QVector<qizi> fangkuai);
    void sendthing();
    QVector<qizi> gezi;
    DWORD WINAPI ClientThread(LPVOID lpParameter);
   // DWORD WINAPI SendThread(LPVOID lpParameter);

signals:
    void sendinfo(QVector<qizi> fangkuai);

private:
    bool server;
    SOCKET CSocket;
};

#endif // WEB_H
