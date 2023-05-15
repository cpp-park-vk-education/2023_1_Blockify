#pragma once
#include <memory>
#include "IObject.h"
class IObjectTable{
  public:
    virtual void addItem(int, std::shared_ptr<IObject>) = 0;
    virtual void setItem(int, std::shared_ptr<IObject>) = 0;
    virtual std::shared_ptr<IObject> getItem(int) = 0;
    virtual void deleteItem(int) = 0;
    virtual int getHeight() = 0;
    virtual int getCurrentRow() = 0;
};
