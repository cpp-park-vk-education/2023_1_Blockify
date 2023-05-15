#include "AddLandscapeOperation.h"
AddLandscapeOperation::AddLandscapeOperation(std::shared_ptr<IVoxelEngine> engine, std::vector<IObject> object_array)
: engine_(engine), object_array_(object_array) {}
void AddLandscapeOperation::execute()
{
    return;
}
void AddLandscapeOperation::undo() {
    return;
}
