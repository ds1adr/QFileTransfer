//
// Created by Wontai Ki on 3/27/26.
//

#ifndef QFILETRANSFER_MAINWINDOW_H
#define QFILETRANSFER_MAINWINDOW_H

#include <QMainWindow>
#include "mainwidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    MainWidget *mMainWidget;
};


#endif //QFILETRANSFER_MAINWINDOW_H