#pragma once
#include <memory>
#include "IObject.h"
class IObjectTable{
  public:
    virtual void addItem(int, std::shared_ptr<IObject>) = 0;
    virtual void setItem(int, std::shared_ptr<IObject>) = 0;
    virtual void deleteItem(int, std::shared_ptr<IObject>) = 0;
};
