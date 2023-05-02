#pragma once
#include <memory>
#include "IImage.h"

class IImageConverter {

public:

    IImageConverter() = default;

    virtual ~IImageConverter() = default;

    virtual std::unique_ptr<IImage> convert(std::shared_ptr<IImage> image) = 0;

};
