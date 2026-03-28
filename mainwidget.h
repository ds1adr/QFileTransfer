//
// Created by Wontai Ki on 3/28/26.
//

#ifndef QFILETRANSFER_MAINWIDGET_H
#define QFILETRANSFER_MAINWIDGET_H

#include <QComboBox>
#include <QHBoxLayout>
#include <QHostAddress>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);

    ~MainWidget() override;

private:
    QHBoxLayout* mIPHBoxlayout;
    QLabel* mIPLabel;
    QVBoxLayout* mMainLayout;
    QComboBox* mIPAddressComboBox;
    QPushButton* mStartStopButton;

    void updateIPAddresses() const;
    QList<QHostAddress> getIPAddresses() const;
};


#endif //QFILETRANSFER_MAINWIDGET_H