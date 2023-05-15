#include "StateManager.h"
#include <QMessageBox>

void StateManager::deleteObject(int row, std::shared_ptr<IObject> object)
{
    std::shared_ptr<IOperation> operation = std::make_shared<DeleteObjectOperation>(object, row, object_table_);
    operation->execute();
    operation_storage_->push_operation(operation);
}
void StateManager::addObject(std::shared_ptr<IObject> object)
{
    int row = object_table_->getHeight();
    std::shared_ptr<IOperation> operation = std::make_shared<AddObjectOperation>(object, row, object_table_);
    operation->execute();
    operation_storage_->push_operation(operation);
}
void StateManager::addLandscape()
{
    return;
}
StateManager::StateManager(std::shared_ptr<IObjectTable> object_table) : object_table_(object_table)
{
    operation_storage_ = std::make_shared<OperationStorage>();
}

void StateManager::Undo()
{
    std::shared_ptr<IOperation> operation;
    try
    {
        operation = operation_storage_->pop_operation();
    }
    catch(const std::exception& e)
    {
        QMessageBox error;
        error.setText(e.what());
        error.exec();
        return;
    }

    operation->undo();
}
