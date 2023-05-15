#include "ObjectFactory.h"
#include <iostream>
#include <QLabel>
#include <QLineEdit>
#include <string>
#include <QVector3D>
using std::string;

std::shared_ptr<IObject> ObjectFactory::createObject()
{
    float x = window_->findChild<QLineEdit *>("lineEdit")->text().toFloat();
    float y = window_->findChild<QLineEdit *>("lineEdit_3")->text().toFloat();
    float z = window_->findChild<QLineEdit *>("lineEdit_2")->text().toFloat();
    auto color = window_->findChild<QLabel *>("label_4")->palette().color(QPalette::Window);
    QVector3D coords = QVector3D(x, y, z);
    return std::make_shared<IObject>();
}

ObjectFactory::ObjectFactory(QMainWindow *window) : window_(window) {}
