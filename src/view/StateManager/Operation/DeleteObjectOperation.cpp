#include "DeleteObjectOperation.h"
DeleteObjectOperation::DeleteObjectOperation(std::shared_ptr<IVoxelEngine> engine, std::shared_ptr<IObject> object, int row, std::shared_ptr<IObjectTable> object_table)
: engine_(engine), object_(object), object_table_(object_table), row_(row) {}
void DeleteObjectOperation::execute()
{
    return;
}
void DeleteObjectOperation::undo() {
    return;
}
