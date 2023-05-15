#include "IImage.h"

PngImage::PngImage(): IImage() {}

PngImage::PngImage(const IImage &other): IImage(other)
{
}

void PngImage::operator=(const PngImage &other)
{
    img_ = other.img_;
}

image_t PngImage::getType() const
{
    return image_t::PNG;
}

void PngImage::read(std::ifstream &input)
{
    read_image( input, img_, boost::gil::png_tag() );
}

void PngImage::write(const std::string &path) const
{
    auto cpImg = img_;
    write_view(path , view( cpImg ), boost::gil::png_tag() );
}
