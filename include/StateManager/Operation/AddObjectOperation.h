#pragma once
#include "IOperation.h"
#include "IObject.h"
#include "IVoxelEngine.h"
#include "IObjectDrawer.h"
#include "IObjectTable.h"
#include <memory>
class AddObjectOperation : public IOperation {
    public:
        AddObjectOperation(std::shared_ptr<IVoxelEngine>, std::shared_ptr<IObject>, int, std::shared_ptr<IObjectTable>);
        ~AddObjectOperation() = default;
        void execute() override;
        void undo() override;
};
