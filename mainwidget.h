//
// Created by Wontai Ki on 3/28/26.
//

#ifndef QFILETRANSFER_MAINWIDGET_H
#define QFILETRANSFER_MAINWIDGET_H

#include <QComboBox>
#include <QHBoxLayout>
#include <QFileSystemModel>
#include <QHostAddress>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeView>
#include <QVBoxLayout>
#include <QWidget>

#include "Network/NetworkService.h"

class MainWidget : public QWidget {
    Q_OBJECT

public:
    MainWidget(NetworkService* networkService, QWidget* parent = nullptr);
    ~MainWidget() override;

private:
    NetworkService* mNetworkService;

    // For IP/Port and Start Stop Button
    QHBoxLayout* mIPPortHLayout;

    // For IP and Port
    QVBoxLayout* mIPPortVLayout;

    QHBoxLayout* mIPHLayout;
    QLabel* mIPLabel;
    QComboBox* mIPAddressComboBox;

    QHBoxLayout* mPortHLayout;
    QLabel* mPortLabel;
    QLineEdit* mPortLineEdit;

    QPushButton* mStartStopButton;

    QVBoxLayout* mMainLayout;

    QFileSystemModel* mFileSystemModel;
    QTreeView* mTreeView;

    void updateIPAddresses() const;

    void displayError(char* message);

private slots:
    void startStopButtonClicked();
    void updateIPComboBox(int index);
};


#endif //QFILETRANSFER_MAINWIDGET_H