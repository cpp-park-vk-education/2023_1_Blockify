#pragma once
#include <memory>
#include "IImage.h"

class ICamera {

public:

  virtual std::unique_ptr<IImage> getMap() = 0;

};
