#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ObjectFactory.h"
#include "IObjectFactory.h"
#include "IObjectDrawer.h"
#include "IStateManager.h"
#include "IObjectTable.h"
#include "ObjectDrawer.h"
#include "StateManager.h"
#include "ObjectTable.h"
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
  std::shared_ptr<IObjectFactory> getFactory();

public slots:
  void setColor();
  void addObject();
  void deleteObject();
  void Undo();
  void createLandscape();
  void about();

private:
  Ui::MainWindow *ui;
  std::shared_ptr<IObjectFactory> object_factory_;
  std::shared_ptr<QColorDialog> color_dialog_;
  std::shared_ptr<IObjectDrawer> object_drawer_;
  std::shared_ptr<IObjectTable> object_table_;
  std::shared_ptr<IStateManager> state_manager_;
};
#endif // MAINWINDOW_H
