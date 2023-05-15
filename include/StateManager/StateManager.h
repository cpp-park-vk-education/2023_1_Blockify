#pragma once
#include "IStateManager.h"
#include "IObjectTable.h"
#include "OperationStorage.h"
#include <memory>
class StateManager: public IStateManager {
    public:
        StateManager(std::shared_ptr<IObjectTable>);
        ~StateManager() = default;
        void deleteObject(std::shared_ptr<IObject>) override;
        void addObject(std::shared_ptr<IObject>) override;
        void addLandscape() override;
    private:
        std::shared_ptr<IObjectTable> object_table_;
        std::shared_ptr<IOperationStorage> operation_storage_;
};
