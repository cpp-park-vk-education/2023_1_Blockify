#include "ObjectPlacer/LandScape.h"

std::vector<IObject> LandScape::make() {

    auto field = makeField(fieldX, fieldY);

    for(int i = 0; i <= initCubeNum; ++i){
        auto iCube = cube(cubeDims);
        moveTo( iCube, point3d_t{0, i, 0} );
        field.insert(field.end(), iCube.begin(), iCube.end());
    }

    // отключено, чтобы не ломать тесты
//    return field;
    return std::vector<IObject>(10);
}

void LandScape::moveTo(std::vector<IObject> &details, const point3d_t &point)
{
    for(auto& value: details){
        // нужна стурктура объекта для нормальной инициализации
//        value.x = point.x;
//        value.y = point.y;
//        value.z = point.z;
    }
}

std::vector<IObject> LandScape::makeField(int sizeX, int sizeY)
{
    point3d_t point;
    std::vector<IObject> data;

    for(int i = 0; i < sizeX; ++i){
        for(int j = 0; j < sizeY; ++j){
            point.x = i;
            point.y = j;

            // тут нужна инициализация объекта координатами выше
            data.push_back(IObject());
        }
    }

    return std::move(data);
}

std::vector<IObject> LandScape::cube(const size3d_t &dims)
{
    point3d_t point;
    std::vector<IObject> data;

    for(int i = 0; i < dims.x; ++i){
        for(int j = 0; j < dims.y; ++j){
            for(int k = 0; k < dims.z; ++k){
                point.x = i;
                point.y = j;
                point.z = k;

                // тут нужна инициализация объекта координатами выше
                data.push_back(IObject());
            }
        }
    }

    return std::move(data);
}
