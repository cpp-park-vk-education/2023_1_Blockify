#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  object_factory_ = std::make_shared<ObjectFactory>(this);
  color_dialog_ = std::make_shared<QColorDialog>(this);
  QColor black_color;
  color_dialog_->setCurrentColor(black_color.black());
  QObject::connect(this->findChild<QPushButton *>("pushButton_2"), &QPushButton::clicked,
  this, &MainWindow::setColor);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::setColor()
{
  auto color = color_dialog_->getColor();
  QLabel *color_label = this->findChild<QLabel *>("label_4");
  QPalette palette = color_label->palette();
  palette.setColor(QPalette::Window, color);
  color_label->setPalette(palette);
}
