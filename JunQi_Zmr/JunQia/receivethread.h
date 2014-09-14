#ifndef RECEIVETHREAD_H
#define RECEIVETHREAD_H
#include <QThread>
#include <windows.h>

class Receivethread : public QThread
{
    Q_OBJECT
public:
    Receivethread(QObject *parent=0);
    ~Receivethread();
    void Getsocket(SOCKET ClientSocket);
    void setservermode(bool);
    void getthing(SOCKET SS,struct sockaddr_in CA);

protected:
    void run();
signals:
    void Recmeg(char*);
    void recinimeg(char*);
    void shule();
    void tachaoshile();
    void yingle();
    void yaoqiuhe();
    void qiuhechenggong();
    void qiuheshibai();
    void renshule();
    void getSocket(SOCKET);
    void kaishi();
    void shoudaotupian(char*);
    void shoudaomingzi(char*);

private:
    SOCKET socket,SSocket;
    bool servermode,setup;
    struct sockaddr_in Client;
};

#endif // RECEIVETHREAD_H
