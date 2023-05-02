#include "Scene/PngConverter.h"

std::unique_ptr<IImage> PngConverter::convert(std::shared_ptr<IImage> image) {
    return std::make_unique<PngImage>();
}
