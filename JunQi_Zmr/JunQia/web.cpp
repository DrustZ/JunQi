#include "web.h"
#include <QDebug>

Web::Web(QObject *parent)
{

}

Web::~Web()
{

    closesocket(CSocket);
    WSACleanup();
}

void Web::getinfo(QVector<qizi> fangkuai)
{
    this->gezi = fangkuai;
    sendthing();
}

DWORD WINAPI Web::ClientThread(LPVOID lpParameter)
{
    SOCKET CientSocket = (SOCKET)lpParameter;
    int Ret = 0;
    char RecvBuffer[20000];

    while ( true )
    {
        memset(RecvBuffer, 0x00, sizeof(RecvBuffer));
        Ret = ::recv(CientSocket, RecvBuffer, 20000, 0);
        gezi = (QVector<qizi>)RecvBuffer;
        if ( Ret == 0 || Ret == SOCKET_ERROR )
        {
            qDebug()<<"Client quits";
            break;
        }
     emit(this->getinfo(gezi));

    }
    return 0;
}

void Web::sendthing()
{
    int Ret = 0;
    char SendBuffer[20000];

    SendBuffer = (char*)gezi;
    Ret = send(CSocket, SendBuffer, (int)strlen(SendBuffer), 0);
    if ( Ret == SOCKET_ERROR )
        {
           qDebug()<<"Send Info Error::"<<GetLastError()<<endl;
        }
    return;
}



void Web::startserver()
{
    server = true;
    WSADATA  Ws;
    SOCKET CientSocket;
    struct sockaddr_in ServerAddr;
    int Ret = 0;
    int AddrLen = 0;
    char SendBuffer[20000];

    //Init Windows Socket
    if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        qDebug()<<"Init Windows Socket Failed::"<<GetLastError();
        return;
    }

    //Create Socket
    CientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( CientSocket == INVALID_SOCKET )
    {
        qDebug()<<"Create Socket Failed::"<<GetLastError();
        return ;
    }

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    ServerAddr.sin_port = htons(4000);
    memset(ServerAddr.sin_zero, 0x00, 8);
    Ret = ::connect(CientSocket,(struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
    if ( Ret == SOCKET_ERROR )
    {
        qDebug()<<"Connect Error::"<<GetLastError();
        return ;
    }
    else
    {
        qDebug()<<"Connection succeeds!";
    }

    {
        AddrLen = sizeof(ClientAddr);
        CientSocket = accept(ServerSocket, (struct sockaddr*)&ClientAddr, &AddrLen);
        if ( CientSocket == INVALID_SOCKET )
        {
            qDebug()<<"Accept Failed::"<<GetLastError();
            return;
        }

        qDebug()<<"Client is connected::"<<inet_ntoa(ClientAddr.sin_addr)<<":"<<ClientAddr.sin_port;

        hThread = CreateThread(NULL, 0, ClientThread, (LPVOID)CientSocket, 0, NULL);

        if ( hThread == NULL )
        {
            qDebug()<<"Create Thread Failed!";
            return;
        }

        CloseHandle(hThread);
    }

    closesocket(ServerSocket);
    closesocket(CientSocket);
    WSACleanup();
}

void Web::startclient()
{
    server = false;
    WSADATA  Ws;
    SOCKET CientSocket;
    struct sockaddr_in ServerAddr;
    int Ret = 0;
    int AddrLen = 0;
    char SendBuffer[20000];

    //Init Windows Socket
    if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        qDebug()<<"Init Windows Socket Failed::"<<GetLastError();
        return;
    }

    //Create Socket
    CientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( CientSocket == INVALID_SOCKET )
    {
        qDebug()<<"Create Socket Failed::"<<GetLastError();
        return;
    }

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    ServerAddr.sin_port = htons(4000);
    memset(ServerAddr.sin_zero, 0x00, 8);
    Ret = connect(CientSocket,(struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
    if ( Ret == SOCKET_ERROR )
    {
        qDebug()<<"Connect Error::"<<GetLastError();
        return ;
    }
    else
    {
        qDebug()<<"Connection succeeds!"<<endl;
    }
    CSocket = CientSocket;
}
