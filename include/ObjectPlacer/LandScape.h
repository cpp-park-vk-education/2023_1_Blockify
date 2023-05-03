#pragma once

#include "IObjectFactory.h"

class LandScape : public IObjectFactory {

public:

    virtual std::vector<IObject> make() final;
};