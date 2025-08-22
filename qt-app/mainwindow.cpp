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

void MainWindow::setPage(int page)
{
    // обработка изменения страницы
    switch (page) {
    case 1: // страница аккаунта
        // тут просто меняю стиль шапки
        ui->pageHeaderName->setText("ACCOUNT");
        ui->frame->setStyleSheet("background-color: rgb(112,112,191)");
        // отправка запроса на сервер для получения данных о пользователе ...
        break;
    case 3: // страница авторизации
        // тут тоже просто меняю стиль шапки
        ui->pageHeaderName->setText("SIGN IN");
        ui->frame->setStyleSheet("background-color: #3F9E54");
        break;
    }

    ui->stackedWidget->setCurrentIndex(page);
}

void MainWindow::on_stackedWidget_currentChanged(int page)
{}

void MainWindow::on_signInBtn_clicked()
{
    if (ui->username->toPlainText().isEmpty() ||
            ui->password->toPlainText().isEmpty()) {
        // введите текст ...
        return;
    }

    // отправка введенных данных на сервер


    // перенаправление на страницу аккаунта
    setPage(1);
}

