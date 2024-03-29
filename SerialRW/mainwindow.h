#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "unlockbutton.h"
#include "backgroundwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void password_correct();

private:
    Ui::MainWindow *ui;

    BackgroundWidget *background = nullptr;
};
#endif // MAINWINDOW_H
