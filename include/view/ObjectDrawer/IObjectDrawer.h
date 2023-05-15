#pragma once
#include "../IObject.h"
#include <vector>
#include <memory>
class IObjectDrawer{
    public:
        virtual void DrawObjects(std::vector<std::shared_ptr<IObject>>) = 0;
        virtual void DrawObject(std::shared_ptr<IObject>) = 0;
        virtual void Update() = 0;
};
