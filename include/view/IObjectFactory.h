#pragma once

#include "IObject.h"
#include <memory>
class IObjectFactoryGUI
{
  public:
    virtual std::shared_ptr<IObject> createObject() = 0;
};
