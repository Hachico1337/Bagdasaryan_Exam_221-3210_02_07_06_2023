#include "singletonclient.h"

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
SingletonClient::SingletonClient(QObject *parent) : QObject(parent){
    mTcpSocket = new QTcpSocket(this);
    mTcpSocket -> connectToHost("127.0.0.1" , 33333);

  //  connect(mTcpSocket, &QTcpSocket::readyRead,
          //  this, &SingletonClient::slotServerRead);
    if(!mTcpSocket->isOpen())
        flag = false;


}
SingletonClient* SingletonClient::getInstance(){
    if (!p_instance)
        {
            p_instance = new SingletonClient();
            destroyer.initialize(p_instance);
        }
    return p_instance;
}

void SingletonClient::send_msg_to_server(QString query){
    ResultMessage.clear();
   
    mTcpSocket->write(query.toUtf8());
    
}

void SingletonClient::slotServerRead(){

    ResultMessage.clear();
    while(mTcpSocket->bytesAvailable()>0)
    {
        ResultMessage.append(mTcpSocket->readAll());
    }

    emit message_from_server(ResultMessage);
}

SingletonClient::~SingletonClient(){
    mTcpSocket->close();
};



SingletonClient* SingletonClient::p_instance;
SingletonDestroyer SingletonClient::destroyer;
