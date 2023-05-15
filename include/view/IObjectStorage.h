#pragma once
#include "IObject.h"


class IObjectStorage {

public:

    virtual void add(const std::vector<IObject>& unit) = 0;

    virtual void del(const point3d_t& point) = 0;

    virtual IObject& getObject(const point3d_t& point) = 0;

};
