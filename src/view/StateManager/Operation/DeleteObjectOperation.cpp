#include "DeleteObjectOperation.h"
DeleteObjectOperation::DeleteObjectOperation(std::shared_ptr<IObject> object, int row, std::shared_ptr<IObjectTable> object_table)
: object_(object), object_table_(object_table), row_(row) {}
void DeleteObjectOperation::execute()
{
    object_table_->deleteItem(row_);
    return;
}
void DeleteObjectOperation::undo() {
    object_table_->addItem(row_, object_);

    return;
}
