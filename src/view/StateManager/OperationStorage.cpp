#include "OperationStorage.h"

void OperationStorage::push_operation(std::shared_ptr<IOperation> operation)
{
    operations_.push(operation);
}

std::shared_ptr<IOperation> OperationStorage::pop_operation()
{
    if (operations_.empty())
        throw std::out_of_range("There are no operations to undo");
    std::shared_ptr<IOperation> operation = operations_.top();
    operations_.pop();
    return operation;
}
