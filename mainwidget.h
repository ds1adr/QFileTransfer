//
// Created by Wontai Ki on 3/28/26.
//

#ifndef QFILETRANSFER_MAINWIDGET_H
#define QFILETRANSFER_MAINWIDGET_H

#include <QComboBox>
#include <QHBoxLayout>
#include <QHostAddress>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);

    ~MainWidget() override;

private:
    // For IP Address
    QHBoxLayout* mIPPortHLayout;

    QVBoxLayout* mIPPortVLayout;

    QHBoxLayout* mIPHLayout;
    QLabel* mIPLabel;
    QComboBox* mIPAddressComboBox;

    QHBoxLayout* mPortHLayout;
    QLabel* mPortLabel;
    QLineEdit* mPortLineEdit;

    QPushButton* mStartStopButton;

    QVBoxLayout* mMainLayout;


    void updateIPAddresses() const;
    QList<QHostAddress> getIPAddresses() const;
};


#endif //QFILETRANSFER_MAINWIDGET_H