//
// Created by Wontai Ki on 3/28/26.
//

#include "NetworkService.h"
#include <QHostInfo>

NetworkService::NetworkService() {

}

NetworkService::~NetworkService() {

}

QList<QHostAddress> NetworkService::getIPAddresses() const {
    QList<QHostAddress> addresses = QHostInfo::fromName(QHostInfo::localHostName()).addresses();
    QList<QHostAddress> filtered = QList<QHostAddress>();
    for (const auto& address : addresses) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && (address.toString() != "127.0.0.1")) {
            filtered.append(address);
        }
    }
    return filtered;
}