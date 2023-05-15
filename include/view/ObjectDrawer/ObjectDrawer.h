#pragma once
#include <QOpenGLWidget>
#include "IObjectDrawer.h"

class ObjectDrawer : public IObjectDrawer
{
public:
    ObjectDrawer(QOpenGLWidget*);
    void DrawObjects(std::vector<std::shared_ptr<IObject>>) override;
    void DrawObject(std::shared_ptr<IObject>) override;
    void Update() override;
private:
    QOpenGLWidget *gl_widget_;
};
