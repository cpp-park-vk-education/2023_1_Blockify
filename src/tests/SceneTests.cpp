#include "Scene/Scene.h"
#include "gtest/gtest.h"

TEST(ImageConverterCase, PngConverterTest) {

    auto bmpStab = std::make_unique<BmpImage>();

    PngConverter pngConverter;
    EXPECT_EQ(pngConverter.convert(std::move(bmpStab))->getType(), image_t::PNG);
}
