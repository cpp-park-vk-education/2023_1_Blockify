#pragma once
#include "IOperation.h"
#include "IVoxelEngine.h"
#include "IObjectDrawer.h"
#include <memory>
class AddLandscapeOperation : public IOperation {
    public:
        AddLandscapeOperation(std::shared_ptr<IVoxelEngine>, std::shared_ptr<IObject>, int);
        ~AddLandscapeOperation() = default;
        void execute() override;
        void undo() override;
};
