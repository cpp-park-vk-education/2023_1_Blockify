#include "StateManager.h"

void StateManager::deleteObject(std::shared_ptr<IObject>)
{
    return;
}
void StateManager::addObject(std::shared_ptr<IObject>)
{
    return;
}
void StateManager::addLandscape()
{
    return;
}
StateManager::StateManager(std::shared_ptr<IObjectTable> object_table) : object_table_(object_table)
{
    operation_storage_ = std::make_shared<OperationStorage>();
}
