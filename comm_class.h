#ifndef COMM_CLASS_H
#define COMM_CLASS_H

#include <QObject>
#include<QTcpSocket>
#include<QTcpServer>
#include <QDebug>

class Comm_class : public QObject
{
    Q_OBJECT
public:
    explicit Comm_class(QObject *parent = nullptr);

    QTcpSocket *socket=new QTcpSocket();
    QTcpServer *server=new QTcpServer();

 public slots:
    void data_from_qml(QString val);
    void connect_to_unity();
    void start_Server();
signals:

};

#endif // COMM_CLASS_H
