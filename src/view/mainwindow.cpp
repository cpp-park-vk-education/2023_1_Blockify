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
