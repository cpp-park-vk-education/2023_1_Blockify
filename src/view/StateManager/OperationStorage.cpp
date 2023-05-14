#include "OperationStorage.h"

void OperationStorage::push_operation(std::shared_ptr<IOperation> operation)
{
    return;
}

std::shared_ptr<IOperation> OperationStorage::pop_operation()
{
    std::shared_ptr<IOperation> operation = operations_.top();
    operations_.pop();
    return operation;
}
