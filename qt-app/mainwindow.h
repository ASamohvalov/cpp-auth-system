#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setPage(int number);

private slots:
    void on_stackedWidget_currentChanged(int arg1);

    void on_signInBtn_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
