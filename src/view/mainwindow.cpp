#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  object_factory = std::make_shared<ObjectFactory>(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}
