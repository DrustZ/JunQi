#include "sendthread.h"
#include "QDebug"
SendThread::SendThread(QObject *parent)
{
    msgGet = false;
}

SendThread::~SendThread()
{

}

void SendThread::getSocket(SOCKET ClientSocket)
{
    Clinetsocket = ClientSocket;
}

void SendThread::run()
{
    while(true)
    {
        if (msgGet){
           // emit(this->getData(message));
            msgGet = false;
            std::string a = message.toStdString();

            int Ret = ::send(Clinetsocket, (char*)(a.c_str()), sizeof(message), 0);
            if ( Ret == SOCKET_ERROR )
            {
                qDebug()<<"Send Info Error::"<<GetLastError();
                break;
            }
        }
    }
}

void SendThread::getmessage(QString mstring)
{
    msgGet = true;
    message = mstring;
}
