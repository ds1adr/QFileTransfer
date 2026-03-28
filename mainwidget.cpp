//
// Created by Wontai Ki on 3/28/26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWidget.h" resolved

#include "mainwidget.h"
#include <QHostInfo>

MainWidget::MainWidget(const NetworkService& networkService, QWidget *parent) : QWidget(parent) {
    mNetworkService = networkService;

    mIPPortHLayout = new QHBoxLayout();

    mIPPortVLayout = new QVBoxLayout();

    mIPHLayout = new QHBoxLayout();
    mIPLabel = new QLabel("IP:");
    mIPAddressComboBox = new QComboBox();

    mIPHLayout->addWidget(mIPLabel);
    mIPHLayout->addWidget(mIPAddressComboBox);

    mPortHLayout = new QHBoxLayout();
    mPortLabel = new QLabel("Port:");
    mPortLineEdit = new QLineEdit();
    mPortHLayout->addWidget(mPortLabel);
    mPortHLayout->addWidget(mPortLineEdit);

    mIPPortVLayout->addLayout(mIPHLayout);
    mIPPortVLayout->addLayout(mPortHLayout);

    mIPPortHLayout->addLayout(mIPPortVLayout);

    mStartStopButton = new QPushButton("Start");
    mIPPortHLayout->addWidget(mStartStopButton);

    mMainLayout =new QVBoxLayout(this);
    mMainLayout->addLayout(mIPPortHLayout);

    updateIPAddresses();
}

MainWidget::~MainWidget() {
    delete mIPLabel;
    delete mIPAddressComboBox;
    delete mStartStopButton;
    delete mIPHLayout;
    delete mPortLabel;
    delete mPortLineEdit;
    delete mPortHLayout;
    delete mIPPortHLayout;
    delete mIPPortVLayout;
    delete mMainLayout;
}

void MainWidget::updateIPAddresses() const {
    QList<QHostAddress> addresses = mNetworkService.getIPAddresses();
    for (const auto& address : addresses) {
        mIPAddressComboBox->addItem(address.toString());
    }
}