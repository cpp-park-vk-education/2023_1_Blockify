#pragma once

#include "IObjectFactory.h"


class LandScape : public IObjectFactory {

    struct point3d_t {

        int x{0};

        int y{0};

        int z{0};

    };

    using size3d_t = point3d_t;


public:

    virtual std::vector<IObject> make() final;

private:

    std::vector<IObject> makeField(int sizeX, int sizeY);

    std::vector<IObject> cube(const size3d_t& dims);

    void moveTo(std::vector<IObject>& details, const point3d_t& point);

private:

    const int initCubeNum{ 3 };

    const size3d_t& cubeDims{3, 3, 3};

    const int fieldX{ 10 };

    const int fieldY{ 10 };

};
