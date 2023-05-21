#ifndef MYLIBRARY_H
#define MYLIBRARY_H

#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/detail/compute_vector_relational.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>    
#include <iostream>           
#include <GL/glut.h>
#include <math.h>

struct Ray
{
    glm::vec3 origin;
    glm::vec3 direction;

    Ray(const glm::vec3 &origin, const glm::vec3 &direction)
        : origin(origin), direction(direction) {}
};

struct OctreeNode
{
    OctreeNode* children[8] = {nullptr};
    bool is_leaf = true;
    glm::vec3 value;
};

class CompactOctree
{
public:
    CompactOctree();
    ~CompactOctree();

    void insert(const glm::vec3 &position, const glm::vec3 &value);
    bool query(const glm::vec3 &position, glm::vec3 &result) const;
    glm::vec3 trace(const Ray &ray, const glm::vec3 &cube_center, const float size);

private:
    glm::vec3 position;
    OctreeNode *root;
    size_t node_count;

    void insert(OctreeNode *node, const glm::vec3 &position, const glm::vec3 &value);
    int intersect_cube(const Ray &ray, const glm::vec3 &cube_center, const float size);
    bool query(const OctreeNode *node, const glm::vec3 &position, glm::vec3 &result) const;
    void delete_node(OctreeNode *node);
    glm::vec3 trace(OctreeNode *node, Ray ray, glm::vec3 cube_center, const float size);
};

class Camera
{
public:
    Camera(const glm::vec3& pos, const glm::vec3& lookat, const glm::vec3& up, const int w, const int h, const float fov);

private:
    glm::vec3 position;
    int width;
    int height;
    float fov;
    float pixel_size;
    std::vector<glm::vec3> directions;

    glm::vec3 trace(OctreeNode* node, const Ray& ray, const glm::vec3& cube_center, const float size);
};

void draw_cube(int x, int y , int z, int r, int g, int b);
void reshape(int width, int height);
void specialKeys(int key, int x, int y);

#endif // MYLIBRARY_H
