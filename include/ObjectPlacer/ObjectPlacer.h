#pragma once

#include <memory>
#include "IObjectFactory.h"

class ObjectPlacer {

public:

    explicit ObjectPlacer(std::unique_ptr<IObjectFactory> landScape);

    std::vector<IObject> makeLandScape();

private:

    std::unique_ptr<IObjectFactory> landScape_;
};