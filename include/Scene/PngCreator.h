#pragma once
#include "IImageProcessor.h"

class PngImage : public IImage {
public:
    virtual image_t test() { return image_t::PNG; }
};

class PngCreator : public IImageProcessor {
public:
    PngCreator() = default;

    std::unique_ptr<IImage> create() final;

    ~PngCreator() = default;
};