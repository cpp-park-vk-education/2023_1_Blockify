#include "ObjectPlacer/ObjectPlacer.h"

ObjectPlacer::ObjectPlacer(std::unique_ptr<IObjectFactory> landScape): landScape_(std::move(landScape)) {
}

std::vector<IObject> ObjectPlacer::makeLandScape() {





    return landScape_->make();
}
