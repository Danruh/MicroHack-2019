#include "backgroundwidget.h"

BackgroundWidget::BackgroundWidget(QFrame *parent)
{
    grid = new QGridLayout(this);

    unlock_button = new UnlockButton;
    lock_button = new QPushButton;

    grid->addWidget(unlock_button, 0, 0);
    grid->addWidget(lock_button, 1, 0);
}
