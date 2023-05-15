#pragma once

#include "IObjectFactory.h"
#include "mainwindow.h"
class ObjectFactory : public IObjectFactory
{
    public:
      ObjectFactory(QMainWindow *window);
      std::shared_ptr<IObject> createObject();
    private:
      QMainWindow *window_;
};
