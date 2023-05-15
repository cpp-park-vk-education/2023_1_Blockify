#include <iostream>
#include "Scene/Scene.h"

class CameraStub : public ICamera {
public:
    virtual std::unique_ptr<IImage> getMap()
    {
        try {
            std::ifstream imgFile("./resource/image.bmp");
            auto stubImg = std::make_unique<BmpImage>();
            stubImg->read(imgFile);
            return  stubImg;
        }
        catch(...) {
            std::cout << "File open error, check your working directory path\n";
            exit(0);
        }
    }
};

class FileManagerStub : public IFileManager {
public:
    virtual void saveImage(const IImage* img)
    {
        img->write("./resource/image.png");
    }
};

int main() {

    CameraStub camera;
    FileManagerStub fileManager;

    Scene scene{camera, fileManager, std::make_unique<PngConverter>()};

    scene.generate();
    scene.preview()->write("./resource/preview.png");


    return 0;
}
