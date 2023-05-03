#pragma once
#include "IImageConverter.h"

class PngConverter : public IImageConverter {

public:

  PngConverter() = default;

  std::unique_ptr<IImage> convert(const IImage* image) final;
};
