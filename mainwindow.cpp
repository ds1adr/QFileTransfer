//
// Created by Wontai Ki on 3/27/26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QHBoxLayout>
#include "mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    mMainWidget = new MainWidget(this);
    this->setCentralWidget(mMainWidget);

}

MainWindow::~MainWindow() {
    delete mMainWidget;
}