#include "receivethread.h"
#include <QDebug>
#include <QMessageBox>
#include "structs.h"

Receivethread::Receivethread(QObject *)
{
    setup = false;
}

Receivethread::~Receivethread()
{

}

void Receivethread::Getsocket(SOCKET ClientSocket)
{
    socket = ClientSocket;
}

void Receivethread::setservermode(bool mode)
{
    servermode = mode;
}

void Receivethread::getthing(SOCKET SS, sockaddr_in CA)
{
    SSocket = SS;
    Client = CA;
}

void Receivethread::run()
{
    bool quit = false;
    while(true){
        if (quit) break;
        if (setup || (!servermode)){
            //qDebug() << "listen";
            while(true)
            {
                char bufferr[7800];
                int Ret = recv(socket,bufferr,sizeof(bufferr),0);
                if ( Ret == 0 || Ret == SOCKET_ERROR )
                {
                    qDebug()<<"Client quits";
                    quit = true;
                    break;
                }
                qDebug() << QString::number(Ret);
                if (bufferr[0] == 'a'){
                    qDebug() << "receive a ";
                    emit(this->recinimeg(bufferr+1));
                }
                else if (bufferr[0] == 'b')
                    emit(this->Recmeg(bufferr+1)) ;
                else if (bufferr[0] == 'c')
                {
                    emit(this->shule());
                    //emit(this->Recmeg(bufferr+1));
                }
                else if (bufferr[0] == 'd')
                {
                    emit(this->tachaoshile());
                    //emit(this->Recmeg(bufferr+1));
                }
                else if (bufferr[0] == 'e')
                {
                    emit(this->yingle());
                   // emit(this->Recmeg(bufferr+1));
                }
                else if (bufferr[0] == 'f')
                {
                    emit(this->yaoqiuhe());
                }
                else if (bufferr[0] == 'g')
                {
                    emit(this->qiuhechenggong());
                }
                else if (bufferr[0] == 'h')
                {
                    emit(this->qiuheshibai());
                }
                else if (bufferr[0] == 'i')
                {
              //      qDebug() << "renshu";
                    emit(this->renshule());
                }
                else if (bufferr[0] == 'j')
                {
                    emit(this->kaishi());
                }
                else if (bufferr[0] == 'k')
                {

                    emit(this->shoudaotupian(bufferr+1));
                }
                else if (bufferr[0] == 'l')
                {
                    qDebug() << "ming zi";
                    emit(this->shoudaomingzi(bufferr+1));
                }
            }
        }
        else {
            int AddrLen = sizeof(Client);
            socket = accept(SSocket, (struct sockaddr*)&Client, &AddrLen);
            if ( socket == INVALID_SOCKET )
            {
                qDebug()<<"Accept Failed::"<<GetLastError();
                setup = false;
                return;
            }
            setup = true;
            qDebug()<<"Client is connected::"<<inet_ntoa(Client.sin_addr)<<":"<<Client.sin_port;
            emit(getSocket(socket));
        }
   }
}
