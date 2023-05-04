#pragma once
#include "Operation/IOperation.h"
#include <memory>
class IOperationStorage {
    public:
        virtual void push_operation(std::shared_ptr<IOperation>) = 0;
        virtual std::shared_ptr<IOperation> pop_operationo() = 0;
};
