
#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H
#include<QDebug>
#include<QObject>
#include<QtNetwork>
#include<QTcpSocket>
#include<QByteArray>
#include<QString>

class SingletonClient;

class SingletonDestroyer
{
    private:
        SingletonClient * p_instance;
    public:
        ~SingletonDestroyer() { delete p_instance; }
        void initialize(SingletonClient * p){p_instance = p;};
};
inline QString ResultMessage = "";

class SingletonClient : public QObject
{
    Q_OBJECT
    private:
        static SingletonClient * p_instance;
        static SingletonDestroyer destroyer;
        QTcpSocket * mTcpSocket;
        bool flag=true;
    protected:
        explicit SingletonClient(QObject *parent = nullptr);
        SingletonClient(const SingletonClient& ) = delete;
        SingletonClient& operator = (SingletonClient &) = delete;

        friend class SingletonDestroyer;
    public:

        static SingletonClient* getInstance();
          ~SingletonClient();
       void send_msg_to_server(QString query);
       void slotServerRead();
    signals:
       void message_from_server(QString msg);



};


#endif // SINGLETONCLIENT_H
