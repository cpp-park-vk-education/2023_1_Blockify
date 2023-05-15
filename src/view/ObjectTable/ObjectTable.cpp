#include "ObjectTable.h"

ObjectTable::ObjectTable(QTableWidget *table) : table_(table) {}
void ObjectTable::addItem(int row, std::shared_ptr<IObject>)
{
    return;
}
void ObjectTable::setItem(int row, std::shared_ptr<IObject>)
{
    return;
}
void ObjectTable::deleteItem(int row, std::shared_ptr<IObject>)
{
    return;
}
