#include "comm_class.h"

Comm_class::Comm_class(QObject *parent)
    : QObject{parent}
{
//    socket->connectToHost("127.0.0.1",8903);
//    if(socket->waitForConnected(10000)){
//        qDebug()<<"Connection successful";
//        return;
//    }
    start_Server();

}

void Comm_class::data_from_qml(QString val)
{
    qDebug()<<Q_FUNC_INFO<<val;
    if(socket->isOpen()){
    socket->write(val.toUtf8());
    socket->flush();
    }

}
void Comm_class::connect_to_unity(){
//    socket->connectToHost("127.0.0.1",8903);
//    if(socket->waitForConnected(10000)){S
//        socket->write("hello");
//        qDebug()<<"Connection successful";
//        return;
//    }
    socket=server->nextPendingConnection();
    qDebug()<<Q_FUNC_INFO;
    socket->write("Hello from qt ");
    socket->flush();

}

void Comm_class::start_Server(){

//    server->listen("127.0.0.1",6359);
    connect(server,&QTcpServer::newConnection,this,&Comm_class::connect_to_unity);
    if (!server->listen(QHostAddress("127.0.0.1"), 6359)) {
         qDebug() << "Failed to start the server:" << server->errorString();
//         return 1;
     }

}

