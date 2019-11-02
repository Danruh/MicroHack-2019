#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    background = new BackgroundWidget;

    setCentralWidget(background);
    resize(1000, 1000);

    connect( background->unlock_button, &UnlockButton::sig_correctPassword, this, &MainWindow::password_correct );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::password_correct()
{
    qDebug() << "password_correct";
    QLabel *elonMusk = new QLabel(0);
    elonMusk->setAlignment(Qt::AlignCenter);

    QPixmap pix;
    if ( pix.load("C:/Users/danru/OneDrive/Documents/Cpp_files/Qt_stuff/SerialRW/Capture.png") )
    {
        pix = pix.scaled(elonMusk->size(),Qt::KeepAspectRatio);
        elonMusk->setPixmap(pix);
        elonMusk->show();
    }
}
