#include "ObjectFactory.h"
#include <iostream>
#include <QLabel>
#include <QLineEdit>
#include <string>
#include <QVector3D>
using std::string;

std::shared_ptr<IObject> ObjectFactory::createObject()
{
    return std::make_shared<IObject>();
}

ObjectFactory::ObjectFactory(QMainWindow *window) : window_(window) {
    // QLabel *label = window_->findChild<QLabel *>("label_3");
    // std::cout << label->text().toStdString();
    float x = window_->findChild<QLineEdit *>("lineEdit")->text().toFloat();
    float y = window_->findChild<QLineEdit *>("lineEdit_3")->text().toFloat();
    float z = window_->findChild<QLineEdit *>("lineEdit_2")->text().toFloat();

    QVector3D coords = QVector3D(x, y, z);
}
