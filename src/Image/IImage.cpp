#include "IImage.h"

IImage::IImage(const IImage &other): img_(other.img_) {}

image_t IImage::getType() const
{
    return image_t::EMPTY;
}

const boost::gil::rgb8_image_t &IImage::getImgRef()
{
    return img_;
}



