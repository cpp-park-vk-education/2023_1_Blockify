#pragma once

#include "ICamera.h"
#include "IFileManager.h"
#include "PngConverter.h"

class Scene {

public:

    explicit Scene(ICamera &camera, IFileManager &fileManager, std::unique_ptr<IImageConverter> pngConverter);

    std::unique_ptr<IImage> preview();

    void generate();

private:

    ICamera &camera_;

    IFileManager &fileManager_;

    std::unique_ptr<IImageConverter> pngConverter_;

};

