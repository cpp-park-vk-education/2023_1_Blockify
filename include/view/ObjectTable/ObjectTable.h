#pragma once
#include "IObjectTable.h"
#include <QTableWidget>
class ObjectTable : public IObjectTable
{
public:
    ObjectTable(QTableWidget *);
    void addItem(int, std::shared_ptr<IObject>) override;
    void setItem(int, std::shared_ptr<IObject>) override;
    std::shared_ptr<IObject> getItem(int) override;
    void deleteItem(int) override;
    int getHeight() override;
    int getCurrentRow() override;
private:
    QTableWidget *table_;
};
