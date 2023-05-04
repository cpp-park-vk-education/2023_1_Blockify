#pragma once
#include <memory>
#include "IObject.h"
#include "IObjectStorage.h"
class IVoxelEngine{
    public:
        virtual void addObject() = 0;
        virtual void deleteObject() = 0;
        virtual std::shared_ptr<IObject> editObject(int) = 0;
        virtual std::shared_ptr<IObjectStorage> readStorage() = 0;
        virtual void defaultScene() = 0;
        virtual void previewScene() = 0;
        virtual void generateScene() = 0;
};
