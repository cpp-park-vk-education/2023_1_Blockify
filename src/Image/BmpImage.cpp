#include "IImage.h"

BmpImage::BmpImage(): IImage() {}

BmpImage::BmpImage(const IImage &other): IImage(other)
{
}

void BmpImage::operator=(const BmpImage &other)
{
    img_ = other.img_;
}

image_t BmpImage::getType() const
{
    return image_t::BMP;
}

void BmpImage::read(std::ifstream &input)
{
    read_image( input, img_, boost::gil::bmp_tag() );
}

void BmpImage::write(const std::string& path) const
{
    auto cpImg = img_;
    write_view(path , view( cpImg ), boost::gil::bmp_tag() );
}
