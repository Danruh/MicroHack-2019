#include "unlockbutton.h"

UnlockButton::UnlockButton(QWidget *parent) : QWidget(parent), unlocked(false)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::red);

    setAutoFillBackground(true);
    setPalette(pal);

    /* Set layout */
    grid = new QGridLayout;

    connect(&receive_thread, &SlaveThread::request, this, &UnlockButton::showRequest);
}

void UnlockButton::showRequest(const QString &s)
{
    qDebug() << "showRequest() s = " << s;

    QPalette pal = palette();

    if ( s==QString("1234\r\nUnlocked\n\r\n") )
    {
        unlocked = true;
        pal.setColor(QPalette::Background, Qt::green);
        setAutoFillBackground(true);
        setPalette(pal); 

        emit sig_correctPassword();
        //setStyleSheet("background-image: url(C:/Users/danru/OneDrive/Documents/Cpp_files/Qt_stuff/SerialRW/Capture.png)");
    }

    else
    {
        pal.setColor(QPalette::Background, Qt::red);
        setAutoFillBackground(true);
        setPalette(pal);
    }
}

void UnlockButton::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "UnlockButton::mousePressEvent";
    startSlave();
}

void UnlockButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QFont font;

    font.setPixelSize(height()/8 - 2);

    painter.setFont(font);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    if ( unlocked )
    {
        painter.drawText(rect(), Qt::AlignTop, QString("Identity Confirmed"));
        painter.drawText(rect(), Qt::AlignBottom, QString("Welcome home Elon"));
    }
}

void UnlockButton::startSlave()
{
    receive_thread.startSlave("COM3", 10000, "");
}
