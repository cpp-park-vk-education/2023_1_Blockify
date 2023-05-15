#include "AddObjectOperation.h"
// добавить передачу voxel engine
AddObjectOperation::AddObjectOperation(std::shared_ptr<IObject> object, int row, std::shared_ptr<IObjectTable> object_table)
: object_(object), object_table_(object_table), row_(row) {}
void AddObjectOperation::execute() {
    object_table_->addItem(row_, object_);

    // engine_->createObject();
    return;
}
void AddObjectOperation::undo() {
    object_table_->deleteItem(row_);


    // engine_->deleteObject();
    //написать удаление из общего хранилища(добавлять возможно тоже стоит в execute)
    return;
}
