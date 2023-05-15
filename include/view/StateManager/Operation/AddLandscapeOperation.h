#pragma once
#include "IOperation.h"
#include "IVoxelEngine.h"
#include "IObjectDrawer.h"
#include <memory>
#include <vector>
class AddLandscapeOperation : public IOperation {
    public:
        AddLandscapeOperation(std::shared_ptr<IVoxelEngine>, std::vector<IObject>);
        ~AddLandscapeOperation() = default;
        void execute() override;
        void undo() override;
    private:
        std::shared_ptr<IVoxelEngine> engine_;
        std::vector<IObject> object_array_;
};
