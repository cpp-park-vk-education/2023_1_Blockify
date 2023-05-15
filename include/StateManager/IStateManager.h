#pragma once
#include "IOperationStorage.h"
#include "IObject.h"
#include <memory>
class IStateManager {
    public:
        virtual void deleteObject(std::shared_ptr<IObject>) = 0;
        virtual void addObject(std::shared_ptr<IObject>) = 0;
        virtual void addLandscape() = 0;
};
