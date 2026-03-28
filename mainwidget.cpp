//
// Created by Wontai Ki on 3/28/26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWidget.h" resolved

#include "mainwidget.h"
#include <QHostInfo>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent) {
    mIPHBoxlayout = new QHBoxLayout();
    mIPLabel = new QLabel("IP:");
    mIPAddressComboBox = new QComboBox();
    mIPAddressComboBox->setFixedWidth(250);

    mStartStopButton = new QPushButton("Start");
    mIPHBoxlayout->addWidget(mIPLabel);
    mIPHBoxlayout->addWidget(mIPAddressComboBox);
    mIPHBoxlayout->addWidget(mStartStopButton);

    mMainLayout =new QVBoxLayout(this);
    mMainLayout->addLayout(mIPHBoxlayout);

    updateIPAddresses();
}

MainWidget::~MainWidget() {
    delete mIPLabel;
    delete mIPAddressComboBox;
    delete mStartStopButton;
    delete mIPHBoxlayout;
    delete mMainLayout;
}

void MainWidget::updateIPAddresses() const {
    QList<QHostAddress> addresses = getIPAddresses();
    for (const auto& address : addresses) {
        mIPAddressComboBox->addItem(address.toString());
    }
}

QList<QHostAddress> MainWidget::getIPAddresses() const {
    QList<QHostAddress> addresses = QHostInfo::fromName(QHostInfo::localHostName()).addresses();
    QList<QHostAddress> filtered = QList<QHostAddress>();
    for (const auto& address : addresses) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && (address.toString() != "127.0.0.1")) {
            filtered.append(address);
        }
    }
    return filtered;
}