#pragma once
#include "IOperation.h"
#include "IVoxelEngine.h"
#include "IObjectDrawer.h"
#include <memory>
class AddLandscapeOperation : public IOperation {
    public:
        AddLandscapeOperation(std::shared_ptr<IVoxelEngine>);
        ~AddLandscapeOperation() = default;
        void execute() override;
        void undo() override;
    private:
        std::shared_ptr<IVoxelEngine> engine_;
};
