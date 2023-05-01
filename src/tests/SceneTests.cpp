#include "Scene/Scene.h"
#include "gtest/gtest.h"

TEST(ImageProcessorCase, PngCreatorProcessTest) {
    PngCreator pngCreator;
    EXPECT_EQ(pngCreator.create()->test(), image_t::PNG);
}