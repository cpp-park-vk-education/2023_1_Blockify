#include "Scene/PngCreator.h"

std::unique_ptr<IImage> PngCreator::create() {
    return std::make_unique<PngImage>();
}
