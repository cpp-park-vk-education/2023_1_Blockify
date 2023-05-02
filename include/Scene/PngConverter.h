#pragma once
#include "IImageConverter.h"

class PngConverter : public IImageConverter {

public:

  PngConverter() = default;

  std::unique_ptr<IImage> convert(std::shared_ptr<IImage> image) final;
};
