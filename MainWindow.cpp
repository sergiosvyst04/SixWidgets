#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QVariant>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->spinBox, &QSpinBox::editingFinished, this, &MainWindow::spinandnumber);
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MainWindow::horizontalelements);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::set75);
    connect(ui->verticalSlider, &QSlider::valueChanged, this, &MainWindow::verticalelements);

}

void MainWindow::spinandnumber()
{
   ui->lcdNumber->display(ui->spinBox->value());
}

void MainWindow::horizontalelements()
{
  ui->horizontalScrollBar->setValue(ui->horizontalSlider->value());
}

void MainWindow::verticalelements()
{
    ui->verticalScrollBar->setValue(ui->verticalSlider->value());
    ui->textEdit->setText(QString("%1 percents").arg(QVariant(ui->verticalSlider->value()).toString()));
}

void MainWindow::set75()
{
    ui->lcdNumber->display(75);
    ui->horizontalScrollBar->setValue(75);
    ui->horizontalSlider->setValue(75);
    ui->verticalScrollBar->setValue(75);
    ui->verticalSlider->setValue(75);
    ui->textEdit->setText("It worksssss");
    ui->spinBox->setValue(75);
}


MainWindow::~MainWindow()
{
    delete ui;
}
