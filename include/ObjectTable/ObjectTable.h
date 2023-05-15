#pragma once
#include "IObjectTable.h"
#include <QTableWidget>
class ObjectTable : public IObjectTable
{
public:
    ObjectTable(QTableWidget *);
    void addItem(int, std::shared_ptr<IObject>) override;
    void setItem(int, std::shared_ptr<IObject>) override;
    void deleteItem(int) override;
private:
    QTableWidget *table_;
};
