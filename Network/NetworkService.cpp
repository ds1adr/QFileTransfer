//
// Created by Wontai Ki on 3/28/26.
//

#include "NetworkService.h"
#include <QHostInfo>

NetworkService::NetworkService() {
    mAddressList = scanIPAddresses();
    if (!mAddressList.isEmpty()) {
        selectedAddress = mAddressList.first();
    }
}

NetworkService::~NetworkService() {

}

const int NetworkService::getPort() const {
    return mPort;
}

void NetworkService::setPort(const int port) {
    mPort = port;
}

const QList<QHostAddress>& NetworkService::getAddressList() const {
    return mAddressList;
}

QList<QHostAddress> NetworkService::scanIPAddresses() const {
    QList<QHostAddress> addresses = QHostInfo::fromName(QHostInfo::localHostName()).addresses();
    QList<QHostAddress> filtered = QList<QHostAddress>();
    for (const auto& address : addresses) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && (address.toString() != "127.0.0.1")) {
            filtered.append(address);
        }
    }
    return filtered;
}

int NetworkService::startToListen() {
    if (!selectedAddress.has_value()) {
        return -1;
    }
    if (mServer != nullptr) {
        mServer->close();
        mServer = nullptr;
    }
    mServer = new QTcpServer(this);
    if (!mServer->listen(selectedAddress.value(), mPort)) {
        return -2; // Could not start
    }
    connect(mServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    return 0;
}

void NetworkService::newConnection() {

}

void NetworkService::clear() {

}