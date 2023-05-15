#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ObjectFactory.h"
#include "IObjectFactory.h"
#include <memory>
#include <QColorDialog>
#include <QObject>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  QColor getColor();

public slots:
  void setColor();

private:
  Ui::MainWindow *ui;
  std::shared_ptr<IObjectFactory> object_factory_;
  std::shared_ptr<QColorDialog> color_dialog_;
};
#endif // MAINWINDOW_H
