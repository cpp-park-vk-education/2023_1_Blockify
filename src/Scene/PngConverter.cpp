#include "Scene/PngConverter.h"

std::unique_ptr<IImage> PngConverter::convert(const IImage* image) {
    return std::make_unique<PngImage>();
}
