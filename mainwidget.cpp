//
// Created by Wontai Ki on 3/28/26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWidget.h" resolved

#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent) {
    mIPHBoxlayout = new QHBoxLayout();
    mIPLabel = new QLabel("IP:");
    mIPAddressEdit = new QLineEdit();
    mIPAddressEdit->setFixedWidth(250);
    mIPAddressEdit->setReadOnly(true);

    mStartStopButton = new QPushButton("Start");
    mIPHBoxlayout->addWidget(mIPLabel);
    mIPHBoxlayout->addWidget(mIPAddressEdit);
    mIPHBoxlayout->addWidget(mStartStopButton);

    mMainLayout =new QVBoxLayout(this);
    mMainLayout->addLayout(mIPHBoxlayout);
}

MainWidget::~MainWidget() {
    delete mIPLabel;
    delete mIPAddressEdit;
    delete mStartStopButton;
    delete mIPHBoxlayout;
    delete mMainLayout;
}