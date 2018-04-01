#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    //valuex = value;
}

void MainWindow::on_selectFile_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"/","Obj File (*.obj)") ;
    QMessageBox::information(this,"...",filename) ;

}
