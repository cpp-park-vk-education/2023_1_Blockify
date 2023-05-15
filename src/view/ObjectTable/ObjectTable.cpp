#include "ObjectTable.h"
#include <vector>

ObjectTable::ObjectTable(QTableWidget *table) : table_(table) {}
void ObjectTable::addItem(int row, std::shared_ptr<IObject> object)
{
    struct vec3
    {
        std::vector<float> vec;
        vec3()
        {
            vec.resize(3);
        }
        vec3(float x, float y, float z)
        {
            vec.resize(3);
            vec[0] = x;
            vec[1] = y;
            vec[2] = z;
        }
    };
    float x, y, z;
    // заглушки, надо будет взять из object
    x = y = z = 0;
    QColor voxel_color = QColor(0, 0, 255);
    vec3 coords(x, y, z);

    table_->insertRow(row);
    for (int i = 0; i < 4; i++)
    {
        QTableWidgetItem *new_item;
        if (i < 3)
            new_item = new QTableWidgetItem(QString::fromStdString(std::to_string(coords.vec[i])));
        else
        {
            new_item = new QTableWidgetItem("");
            QBrush brush = new_item->background();
            brush.setColor(voxel_color);
            brush.setStyle(Qt::SolidPattern);
            new_item->setBackground(brush);
        }
        table_->setItem(0, i, new_item);
    }
}
void ObjectTable::setItem(int row, std::shared_ptr<IObject> object)
{
    struct vec3
    {
        std::vector<float> vec;
        vec3()
        {
            vec.resize(3);
        }
        vec3(float x, float y, float z)
        {
            vec.resize(3);
            vec[0] = x;
            vec[1] = y;
            vec[2] = z;
        }
    };
    float x, y, z;
    // заглушки, надо будет взять из object
    x = y = z = 0;
    QColor voxel_color = QColor(0, 0, 255);
    vec3 coords(x, y, z);

    if (table_->rowCount() < row)
        return;
    for (int i = 0; i < 4; i++)
    {
        QTableWidgetItem *new_item;
        if (i < 3)
            new_item = new QTableWidgetItem(QString::fromStdString(std::to_string(coords.vec[i])));
        else
        {
            new_item = new QTableWidgetItem("");
            QBrush brush = new_item->background();
            brush.setColor(voxel_color);
            brush.setStyle(Qt::SolidPattern);
            new_item->setBackground(brush);
        }
        table_->setItem(0, i, new_item);
    }
}

void ObjectTable::deleteItem(int row)
{
    table_->removeRow(row);
}

int ObjectTable::getHeight()
{
    return table_->rowCount();
}
