//
// Created by Wontai Ki on 3/28/26.
//

#ifndef QFILETRANSFER_NETWORKSERVICE_H
#define QFILETRANSFER_NETWORKSERVICE_H

#include <QHostAddress>
#include <QList>

class NetworkService {


    public:
    NetworkService();
    ~NetworkService();
    QList<QHostAddress> getIPAddresses() const;
};


#endif //QFILETRANSFER_NETWORKSERVICE_H