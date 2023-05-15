#pragma once
#include <memory>
#include "IImage.h"
#include "IObject.h"
#include "IObjectStorage.h"

class IVoxelEngine{

public:

    virtual void addObject(const std::vector<IObject>& objectVec) = 0;

    virtual void deleteObject() = 0;

    virtual IObject& editObject(const point3d_t point) = 0;

    virtual const IObjectStorage& readStorage() = 0;

    virtual void defaultScene() = 0;

    virtual std::unique_ptr<IImage> previewScene() = 0;

    virtual void generateScene() = 0;
};
