#pragma once

#include "IObject.h"
#include <memory>
class IObjectFactory
{
  public:
    virtual std::shared_ptr<IObject> createObject() = 0;
};
