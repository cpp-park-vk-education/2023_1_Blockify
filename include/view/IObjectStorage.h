#pragma once
#include "IObject.h"


class IObjectStorage {

public:

    void add(const std::vector<IObject>& unit);

    void del(const point3d_t& point);


};
