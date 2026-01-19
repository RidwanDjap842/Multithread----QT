#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar_a->setRange(0, 100);
    ui->progressBar_b->setRange(0, 100);
    ui->progressBar_c->setRange(0, 100);

    ui->progressBar_a->setValue(0);
    ui->progressBar_b->setValue(0);
    ui->progressBar_c->setValue(0);

    connect(&threadA, &QMyThread::progressUpdated, this, &MainWindow::updateProgressBar_a);
    connect(&threadB, &QMyThread::progressUpdated, this, &MainWindow::updateProgressBar_b);
    connect(&threadC, &QMyThread::progressUpdated, this, &MainWindow::updateProgressBar_c);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_a_clicked()
{
    if (!threadA.isRunning())
        threadA.start();
}


void MainWindow::on_stopButton_a_clicked()
{
    threadA.stop();
}


void MainWindow::on_resetButton_a_clicked()
{
    threadA.reset();
}

void MainWindow::on_startButton_b_clicked()
{
    if (!threadB.isRunning())
        threadB.start();
}


void MainWindow::on_stopButton_b_clicked()
{
    threadB.stop();
}


void MainWindow::on_resetButton_b_clicked()
{
    threadB.reset();
}

void MainWindow::on_startButton_c_clicked()
{
    if (!threadC.isRunning())
        threadC.start();
}


void MainWindow::on_stopButton_c_clicked()
{
    threadC.stop();
}


void MainWindow::on_resetButton_c_clicked()
{
    threadC.reset();
}


void MainWindow::updateProgressBar_a(int value)
{
    ui->progressBar_a->setValue(value);
}

void MainWindow::updateProgressBar_b(int value)
{
    ui->progressBar_b->setValue(value);
}

void MainWindow::updateProgressBar_c(int value)
{
    ui->progressBar_c->setValue(value);
}

