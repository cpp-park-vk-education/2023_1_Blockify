#pragma once

#include "IVoxelEngine.h"

#include "IFileManager.h"
#include "ICamera.h"
#include "Scene/Scene.h"
#include "ObjectPlacer/ObjectPlacer.h"

class VoxelEngine {

public:

    virtual void addObject(const std::vector<IObject>& objectVec);

    virtual void deleteObject();

    virtual IObject& editObject(const point3d_t point);

    virtual const IObjectStorage& readStorage();

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
