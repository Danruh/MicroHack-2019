#ifndef BACKGROUNDWIDGET_H
#define BACKGROUNDWIDGET_H

#include "SerialRW.h"
#include "unlockbutton.h"

class BackgroundWidget : public QFrame
{
    Q_OBJECT
public:
    BackgroundWidget(QFrame *parent = nullptr);
    UnlockButton *unlock_button = nullptr;

private:
    QGridLayout *grid = nullptr;

    QPushButton *lock_button = nullptr;
};

#endif // BACKGROUNDWIDGET_H
