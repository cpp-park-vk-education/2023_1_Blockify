#pragma once

#include <memory>
#include "IImage.h"

class IFileManager {

public:

    virtual void saveImage(const IImage *image) = 0;

};
