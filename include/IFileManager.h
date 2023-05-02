#pragma once
#include <memory>
#include "IImage.h"

class IFileManager {

public:

  virtual void saveImage(std::shared_ptr<IImage> image);

};
