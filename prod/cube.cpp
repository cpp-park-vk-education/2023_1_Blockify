#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/detail/compute_vector_relational.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>    
#include<iostream>           
#include <GL/glut.h>
#include <math.h>
#include "cube.hpp"


// Параметры камеры
float cameraX = 0.0f;
float cameraY = 0.0f;
float cameraZ = -10.0f;
float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;

void draw_cube(int x, int y , int z,int r,int g,int b);

void draw_cube(int x, int y , int z,int r,int g,int b){
    glPushMatrix();
    
    
    glTranslatef(x*0.1f, y*0.1f, z*0.1f);
    
    // Отрисовка куба
    glColor3f(r/255.f, g/255.f, b/255.f); 
    glutSolidCube(0.1f);
    glPopMatrix();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / height, 0.2f, 100.0f);
}

