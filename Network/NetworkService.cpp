//
// Created by Wontai Ki on 3/28/26.
//

#include "NetworkService.h"
#include <QDebug>
#include <QHostInfo>

NetworkService::NetworkService() {
    mAddressList = scanIPAddresses();
    if (!mAddressList.isEmpty()) {
        mSelectedAddress = mAddressList.first();
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
    if (!mSelectedAddress.has_value()) {
        return NoAddress;
    }
    if (mServer != nullptr) {
        mServer->close();
        mServer = nullptr;
    }
    mServer = new QTcpServer(this);
    if (!mServer->listen(mSelectedAddress.value(), mPort)) {
        return FailedToStart; // Could not start
    }
    connect(mServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    return 0;
}

void NetworkService::newConnection() {
    mSocket = mServer->nextPendingConnection();
    if (!mSocket) {
        return;
    }

    qDebug() << "Client connected";
}

void NetworkService::clear() {
    if (mServer != nullptr) {
        mServer->close();
    }
}

void NetworkService::updateSelectedAddress(int index) {
    mSelectedAddress = mAddressList[index];
}

void NetworkService::onDisconnected() {

}