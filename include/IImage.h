#pragma once

enum class image_t {
    BMP,
    PNG,
    JPEG,
    EMPTY
};

class IImage {
public:
    virtual image_t getType() { return image_t::EMPTY; }
};

class PngImage : public IImage {
public:
    virtual image_t getType() { return image_t::PNG; }
};

class BmpImage : public IImage {
public:
    virtual image_t getType() { return image_t::BMP; }
};
