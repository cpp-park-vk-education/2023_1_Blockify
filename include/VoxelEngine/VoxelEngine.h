#pragma once

#include "IVoxelEngine.h"

#include "IFileManager.h"
#include "ICamera.h"
#include "Scene/Scene.h"
#include "ObjectPlacer/ObjectPlacer.h"

class VoxelEngine {

public:

    virtual void addObject() = 0;

    virtual void deleteObject() = 0;

    virtual std::shared_ptr<IObject> editObject(int) = 0;

    virtual std::shared_ptr<IObjectStorage> readStorage() = 0;

    virtual void defaultScene();

    virtual std::unique_ptr<IImage> previewScene();

    virtual void generateScene();

public: // private

    std::unique_ptr<IObjectStorage> storage_;

    std::unique_ptr<ICamera> camera_;

    std::unique_ptr<IFileManager> fileManager_;

    ObjectPlacer objectPlacer_;

    Scene scene_;

};
