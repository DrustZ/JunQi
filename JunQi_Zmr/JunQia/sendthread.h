#ifndef SENDTHREAD_H
#define SENDTHREAD_H
#include <QThread>
#include <windows.h>


class SendThread : public QThread
{
    Q_OBJECT
public:
    SendThread(QObject *parent=0);
    ~SendThread();
    void getSocket(SOCKET ClientSocket);

protected:
    void run();

public slots:
    void getmessage(QString mstring);

signals:
    void getData(QString mstring);

private:
    SOCKET Clinetsocket;
    QString message;
    bool msgGet;

};

#endif // SENDTHREAD_H
