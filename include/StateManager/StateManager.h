#pragma once
#include "IStateManager.h"
#include "IObjectTable.h"
#include <memory>
class StateManager: public IStateManager {
    public:
        StateManager(std::shared_ptr<IObjectTable>, std::shared_ptr<IOperationStorage>);
        ~StateManager() = default;
        void deleteObject(std::shared_ptr<IObject>) override;
        void addObject(std::shared_ptr<IObject>) override;
        void addLandscape() override;
};
