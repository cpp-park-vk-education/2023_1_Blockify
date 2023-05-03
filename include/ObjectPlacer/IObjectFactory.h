#pragma once
#include <vector>
#include "IObject.h"

class IObjectFactory {

public:

  IObjectFactory() = default;
  virtual ~IObjectFactory() = default;

  virtual std::vector<IObject> make() = 0;
};
