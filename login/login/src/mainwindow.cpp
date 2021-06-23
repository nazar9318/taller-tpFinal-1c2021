#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
ui(new Ui::MainWindow) {

    ui->setupUi(this);

    // CODIGO SI QUEREMOS AGREGAR UNA IMAGEN DE FONDO
    /*
    QPixmap bkgnd("/home/user/Pictures/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
*/
}

void MainWindow::on_NuevaPartida_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_UnirsePartida_clicked() {

}

MainWindow::~MainWindow() { delete ui; }
