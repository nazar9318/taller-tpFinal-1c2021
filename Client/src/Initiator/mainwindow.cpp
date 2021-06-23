#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
ui(new Ui::MainWindow) { ui->setupUi(this); }

void MainWindow::on_NuevaPartida_clicked() {

}

void MainWindow::on_UnirsePartida_clicked() {

}

MainWindow::~MainWindow() { delete ui; }
