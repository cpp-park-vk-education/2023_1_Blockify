#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QMessageBox>

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
  QObject::connect(this->findChild<QPushButton *>("pushButton"), &QPushButton::clicked,
  this, &MainWindow::addObject);
  QObject::connect(this->findChild<QPushButton *>("pushButton_7"), &QPushButton::clicked,
  this, &MainWindow::deleteObject);
  QObject::connect(this->findChild<QPushButton *>("pushButton_3"), &QPushButton::clicked,
  this, &MainWindow::createLandscape);
  QObject::connect(this->findChild<QPushButton *>("pushButton_6"), &QPushButton::clicked,
  this, &MainWindow::Undo);

  object_drawer_ = std::make_shared<ObjectDrawer>(this->findChild<QOpenGLWidget *>("openGLWidget"));
  object_table_ = std::make_shared<ObjectTable>(this->findChild<QTableWidget *>("tableWidget"));
  state_manager_ = std::make_shared<StateManager>(object_table_);
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

std::shared_ptr<IObjectFactory> MainWindow::getFactory()
{
  return object_factory_;
}

QColor MainWindow::getColor()
{
  return color_dialog_->selectedColor();
}

void MainWindow::addObject()
{
  auto object = object_factory_->createObject();
  state_manager_->addObject(object);
}

void MainWindow::deleteObject()
{
  int row;
  try
  {
    row = object_table_->getCurrentRow();
  }
  catch(const std::exception& e)
  {
      QMessageBox error;
      error.setText(e.what());
      error.exec();
      return;
  }
  auto object = object_table_->getItem(row);
  state_manager_->deleteObject(row, object);
}

void MainWindow::createLandscape()
{
  return;
}

void MainWindow::Undo()
{
  state_manager_->Undo();
}
