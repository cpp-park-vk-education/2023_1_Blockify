#pragma once
#include "IOperation.h"
#include "IObject.h"
#include "IObjectDrawer.h"
#include "IVoxelEngine.h"
#include "IObjectTable.h"
#include <memory>
class DeleteObjectOperation : public IOperation {
    public:
        DeleteObjectOperation(std::shared_ptr<IVoxelEngine>, std::shared_ptr<IObject>, int, std::shared_ptr<IObjectTable>);
        ~DeleteObjectOperation() = default;
        void execute() override;
        void undo() override;
};
