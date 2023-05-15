#include "ObjectFactory.h"
#include <iostream>
#include <QLabel>
std::shared_ptr<IObject> ObjectFactory::createObject()
{
    return std::make_shared<IObject>();
}

ObjectFactory::ObjectFactory(QMainWindow *window) : window_(window) {
    // QLabel *label = window_->findChild<QLabel *>("label_3");
    // std::cout << label->text().toStdString();
}
