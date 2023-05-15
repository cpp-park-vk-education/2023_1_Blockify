#include "ObjectDrawer.h"

ObjectDrawer::ObjectDrawer(QOpenGLWidget* gl_widget) : gl_widget_(gl_widget) {}
void ObjectDrawer::DrawObjects(std::vector<std::shared_ptr<IObject>>)
{
    return;
}
void ObjectDrawer::DrawObject(std::shared_ptr<IObject>)
{
    return;
}
void ObjectDrawer::Update()
{
    return;
}
