#include "VoxelEngine/VoxelEngine.h"

void VoxelEngine::addObject(const std::vector<IObject>& objectVec)
{
    storage_->add(objectVec);
}

void VoxelEngine::deleteObject()
{
    storage_->del(point);
}

std::shared_ptr<IObject> VoxelEngine::editObject(const point3d_t point)
{
    return storage_->getObject(point);
}

const IObjectStorage& VoxelEngine::readStorage()
{
    return *storage_.get();
}

void VoxelEngine::defaultScene()
{
   auto landScape = objectPlacer_->makeLandScape();
   storage_->add(landScape);

//   emit newObjectsAvailable;
}

void VoxelEngine::previewScene()
{
    return Scene.preview();
}

void VoxelEngine::generateScene()
{
    Scene.generate();
}
