#include "OperationStorage.h"
#include <stdexcept>
void OperationStorage::push_operation(std::shared_ptr<IOperation> operation)
{
    operations_.push(operation);
}

std::shared_ptr<IOperation> OperationStorage::pop_operation()
{
    if (operations_.empty())
        throw std::invalid_argument("No operation on the stack");
    std::shared_ptr<IOperation> operation = operations_.top();
    operations_.pop();
    return operation;
}
