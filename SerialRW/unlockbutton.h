#ifndef UNLOCKBUTTON_H
#define UNLOCKBUTTON_H

#include <QWidget>

#include "SerialRW.h"
#include "slavethread.h"

class UnlockButton : public QWidget
{
    Q_OBJECT
public:
    explicit UnlockButton(QWidget *parent = nullptr);

signals:
    void sig_correctPassword();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

public slots:
    void showRequest(const QString &s);
    void startSlave();

private:
    SlaveThread receive_thread;

    QGridLayout *grid = nullptr;
    bool unlocked;
};

#endif // UNLOCKBUTTON_H
