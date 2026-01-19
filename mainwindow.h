#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qmythread.h"

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

private slots:
    void on_startButton_a_clicked();
    void on_stopButton_a_clicked();
    void on_resetButton_a_clicked();
    void on_startButton_b_clicked();
    void on_stopButton_b_clicked();
    void on_resetButton_b_clicked();
    void on_startButton_c_clicked();
    void on_stopButton_c_clicked();
    void on_resetButton_c_clicked();
    void updateProgressBar_a(int value);
    void updateProgressBar_b(int value);
    void updateProgressBar_c(int value);
private:
    Ui::MainWindow *ui;
    QMyThread threadA, threadB, threadC;
};
#endif // MAINWINDOW_H
