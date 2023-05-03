#pragma once
#include <memory>

enum class image_t {
    PNG,
    JPEG,
    BIT,
    EMPTY
};

class IImage {
public:
    virtual image_t test() { return image_t::EMPTY; }
};

class IImageProcessor {

public:
    IImageProcessor() = default;

    virtual std::unique_ptr<IImage> create() = 0;

    virtual ~IImageProcessor() = default;
};