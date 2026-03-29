//
// Created by Wontai Ki on 3/28/26.
//

#ifndef QFILETRANSFER_NETWORKSERVICE_H
#define QFILETRANSFER_NETWORKSERVICE_H

#include <QHostAddress>
#include <QList>
#include <QTcpServer>

enum NetworkServiceError {
    NoAddress = -1,
    FailedToStart = -2,
};


class NetworkService: public QObject {
    Q_OBJECT

private:
    QList<QHostAddress> mAddressList;
    std::optional<QHostAddress> selectedAddress = std::nullopt;
    int mPort = 8989;

    QList<QHostAddress> scanIPAddresses() const;
    QTcpServer* mServer = nullptr;

public:
    NetworkService();
    ~NetworkService();

    const QList<QHostAddress>& getAddressList() const;
    const int getPort() const;
    void setPort(const int port);

    int startToListen();
    void clear();

private slots:
    void newConnection();
};


#endif //QFILETRANSFER_NETWORKSERVICE_H