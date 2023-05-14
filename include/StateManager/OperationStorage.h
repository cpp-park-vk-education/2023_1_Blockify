#pragma once
#include "IOperationStorage.h"
#include <stack>
class OperationStorage : public IOperationStorage {
    public:
        void push_operation(std::shared_ptr<IOperation>) override;
        std::shared_ptr<IOperation> pop_operation() override;
    private:
        std::stack<std::shared_ptr<IOperation>> operations_;
};
