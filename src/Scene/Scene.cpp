#include "Scene/Scene.h"

Scene::Scene(ICamera& camera, IFileManager& fileManager, std::unique_ptr<IImageConverter> pngConverter): camera_(camera),
                                                                                                         fileManager_(fileManager),
                                                                                                         pngConverter_(std::move(pngConverter))
{
}

std::unique_ptr<IImage> Scene::preview()
{
  auto pngImage = pngConverter_->convert(camera_.getMap());
  return pngImage;
}

void Scene::generate()
{
  auto pngImage = pngConverter_->convert(camera_.getMap());
  fileManager_.saveImage(std::move(pngImage));
}
