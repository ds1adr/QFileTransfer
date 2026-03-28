//
// Created by Wontai Ki on 3/28/26.
//

#ifndef QFILETRANSFER_MAINWIDGET_H
#define QFILETRANSFER_MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);

    ~MainWidget() override;

private:
    QHBoxLayout* mIPHBoxlayout;
    QLabel* mIPLabel;
    QVBoxLayout* mMainLayout;
    QLineEdit* mIPAddressEdit;
    QPushButton* mStartStopButton;
};


#endif //QFILETRANSFER_MAINWIDGET_H