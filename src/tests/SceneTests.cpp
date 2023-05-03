#include "Scene/Scene.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"


class CameraMock : public ICamera {
public:
    MOCK_METHOD(std::unique_ptr<IImage>, getMap, (), (override));
};

class FileManagerMock : public IFileManager {
public:
    MOCK_METHOD(void, saveImage, (const IImage*), (override));
};

class ImageConverterMock : public IImageConverter {
public:
    MOCK_METHOD(std::unique_ptr<IImage>, convert, (const IImage*), (override));
};

class CameraStub : public ICamera {
public:
    virtual std::unique_ptr<IImage> getMap() { return std::make_unique<BmpImage>(); };
};

class FileManagerStub : public IFileManager {
public:
    virtual void saveImage(const IImage *) {};
};

class ImageConverterStub : public IImageConverter {
public:
    virtual std::unique_ptr<IImage> convert(const IImage * = nullptr) { return std::make_unique<PngImage>(); };
};

class SceneTestFixture : public testing::Test {

public:

    std::unique_ptr<Scene> scene_;

    CameraStub cameraStub_;

    FileManagerStub fileManagerStub_;

    std::unique_ptr<ImageConverterStub> imageConverterStub_ = std::make_unique<ImageConverterStub>();

    CameraMock cameraMock_;

    FileManagerMock fileManagerMock_;

    std::unique_ptr<ImageConverterMock> imageConverterMock_ = std::make_unique<ImageConverterMock>();

};

TEST_F(SceneTestFixture, ScenePreviewCameraGetterTest) {

    scene_ = std::make_unique<Scene>(cameraMock_, fileManagerStub_, std::move(imageConverterStub_));

    EXPECT_CALL(cameraMock_, getMap());
    scene_->preview();
}

TEST_F(SceneTestFixture, ScenePreviewImageConverterTest) {

    auto imageConverterMockPtr = imageConverterMock_.get();
    scene_ = std::make_unique<Scene>(cameraStub_, fileManagerStub_, std::move(imageConverterMock_));

    EXPECT_CALL(*imageConverterMockPtr, convert(cameraStub_.getMap().get()));
    scene_->preview();
}

TEST_F(SceneTestFixture, SceneGenerateCameraGetterTest) {

    scene_ = std::make_unique<Scene>(cameraMock_, fileManagerStub_, std::move(imageConverterStub_));

    EXPECT_CALL(cameraMock_, getMap());
    scene_->generate();
}

TEST_F(SceneTestFixture, SceneGenerateImageConverterTest) {

    auto imageConverterMockPtr = imageConverterMock_.get();
    scene_ = std::make_unique<Scene>(cameraStub_, fileManagerStub_, std::move(imageConverterMock_));

    EXPECT_CALL(*imageConverterMockPtr, convert);
    scene_->generate();
}

TEST_F(SceneTestFixture, SceneGenerateFileManagerSaveTest) {

    scene_ = std::make_unique<Scene>(cameraStub_, fileManagerMock_, std::move(imageConverterStub_));

    EXPECT_CALL(fileManagerMock_, saveImage);
    scene_->generate();
}

TEST_F(SceneTestFixture, PreviewPNGreturnTest) {
    scene_ = std::make_unique<Scene>(cameraStub_, fileManagerStub_, std::move(imageConverterStub_));
    EXPECT_EQ(scene_->preview()->getType(), image_t::PNG);
}

TEST(PngConverterTestSuit, PngConverterTest) {

    auto bmpStab = std::make_unique<BmpImage>();

    PngConverter pngConverter;
    EXPECT_EQ(pngConverter.convert(bmpStab.get())->getType(), image_t::PNG);
}

