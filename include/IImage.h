#pragma once
#include <fstream>

#include <png.h>
#include <boost/gil.hpp>
#include <boost/gil/extension/io/png.hpp>
#include <boost/gil/extension/io/bmp.hpp>

enum class image_t {
    BMP,
    PNG,
    JPEG,
    EMPTY
};


class IImage {

public:

    IImage() = default;

    virtual ~IImage() = default;

    IImage(const IImage& other);

    virtual image_t getType() const;

    virtual void read(std::ifstream& input) = 0;

    virtual void write(const std::string& path) const = 0;

    const boost::gil::rgb8_image_t& getImgRef();

protected:

    boost::gil::rgb8_image_t img_;

};


class PngImage : public IImage {

public:

    PngImage();

    ~PngImage() = default;

    PngImage(const IImage& other);

    void operator=(const PngImage& other);

    virtual image_t getType() const override;

    virtual void read(std::ifstream& input) override;

    virtual void write(const std::string& path) const override;

};


class BmpImage : public IImage {

public:

    BmpImage();

    ~BmpImage() = default;

    BmpImage(const IImage &other);

    void operator=(const BmpImage& other);

    virtual image_t getType() const override;

    virtual void read(std::ifstream& input) override;

    virtual void write(const std::string& path) const override;

};


