#include "ObjectFactory.h"

std::shared_ptr<IObject> ObjectFactory::createObject()
{
    return std::make_shared<IObject>();
}
