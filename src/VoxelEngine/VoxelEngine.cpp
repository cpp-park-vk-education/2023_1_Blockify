#include "VoxelEngine/VoxelEngine.h"

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
