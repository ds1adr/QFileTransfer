//
// Created by Wontai Ki on 3/28/26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWidget.h" resolved

#include "mainwidget.h"
#include <QHostInfo>
#include <QMessageBox>

MainWidget::MainWidget(NetworkService* networkService, QWidget *parent) : QWidget(parent) {
    mNetworkService = networkService;

    mIPPortHLayout = new QHBoxLayout();

    mIPPortVLayout = new QVBoxLayout();

    mIPHLayout = new QHBoxLayout();
    mIPLabel = new QLabel("IP:");
    mIPAddressComboBox = new QComboBox();

    mIPHLayout->addWidget(mIPLabel);
    mIPHLayout->addWidget(mIPAddressComboBox);
    connect(mIPAddressComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateIPComboBox(int)));

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
    connect(mStartStopButton, SIGNAL(clicked(bool)), this, SLOT(startStopButtonClicked()));

    mTreeView = new QTreeView();
    mFileSystemModel = new QFileSystemModel();
    mFileSystemModel->setRootPath(QDir::currentPath());
    mTreeView->setModel(mFileSystemModel);

    mMainLayout =new QVBoxLayout(this);
    mMainLayout->addLayout(mIPPortHLayout);
    mMainLayout->addWidget(mTreeView);

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
    QList<QHostAddress> addresses = mNetworkService->getAddressList();
    for (const auto& address : addresses) {
        mIPAddressComboBox->addItem(address.toString());
    }
    mPortLineEdit->setText(QString::number(mNetworkService->getPort()));
}

void MainWidget::updateIPComboBox(int index) {

}

void MainWidget::startStopButtonClicked() {
    int result = mNetworkService->startToListen();
    if (result == NetworkServiceError::NoAddress) {
        displayError("No Selected IP address");
    } else if (result == FailedToStart) {
        displayError("Can't open network. Can you try later or different IP/Port?");
    }
}

void MainWidget::displayError(char* message) {
    QMessageBox::critical(this, "Error", message);
}