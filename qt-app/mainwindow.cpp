#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPage(int number)
{
    ui->stackedWidget->setCurrentIndex(number);
}

void MainWindow::on_stackedWidget_currentChanged(int arg1)
{

}

