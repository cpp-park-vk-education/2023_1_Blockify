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
#include <glm/gtc/noise.hpp>
#include <random>
std::vector<std::vector<float>> terrain;
// Функция генерации ландшафта на основе шума Перлина
std::vector<std::vector<float>> generateTerrain(int width, int height, float frequency, int octaves, float persistence)
{
    std::vector<std::vector<float>> terrain(height, std::vector<float>(width));

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            float amplitude = 1.0f;
            float total = 0.0f;
            float max_value = 0.0f;

            for (int i = 0; i < octaves; ++i)
            {
                float frequency_pow = std::pow(frequency, i);
                float amplitude_pow = std::pow(persistence, i);

                total += glm::perlin(glm::vec2(x * frequency_pow, y * frequency_pow)) * amplitude_pow;
                max_value += amplitude_pow;
            }

            terrain[y][x] = total / max_value;
        }
    }

    return terrain;
}

// Функция для вывода ландшафта в консоль
void printTerrain(const std::vector<std::vector<float>>& terrain,int x,int y,int z)
{
    int i = 0;
    for (const auto& row : terrain)
    {
        int j  = 0;
        for (float value : row)
        {
            for (float value_ = 0 ; value_ < value;value_+=0.01)
            if (value_ < -0.1f)
                draw_cube(x+i,y+value_*100,z+j,228, 230, 142);
            else if (value_ > 0.2f)
                draw_cube(x+i,y+value_*100,z+j,255,255,255);
            else
                draw_cube(x+i,y+value_*100,z+j,0,220,0);
                
            j++;
        }
        
        i++;
    }
}
void print(const std::vector<std::vector<float>>& terrain)
{
    for (const auto& row : terrain)
    {
        for (float value : row)
        {
           std::cout << value<<" ";
        }
        std::cout << std::endl;
    }
}
void initLighting()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat position[] = {1.0f, 1.0f, 1.0f, 0.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}
void display()
{
    
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glClearColor(146.0/255, 173.0/255, 173.0/255, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5, 2,-3, 0, 0, -2,0, 100, 0);
    
      // Вычисляем положение камеры на окружности с радиусом cameraRadius
    
    for (int j = 0 ; j<4;j++){
    for(int i = 0; i <4 ; i++){ 
        draw_cube(0+i,j,-20,100,0,0);
    }
    }
    for (int j = 0 ; j<4;j++){
    for(int i = 0; i <4 ; i++){ 
        draw_cube(0+i,j,-24,0,0,100);
    }
    }
    for (int j = 0 ; j<4;j++){
    for(int i = 0; i <4 ; i++){ 
        draw_cube(0+i,0,-24+j,100,0,100);
    }
    }
    for (int j = 0 ; j<4;j++){
    for(int i = 0; i <4 ; i++){ 
        draw_cube(i,4,-24+j,100,0,100);
    }
    }
    for (int j = 0 ; j<4;j++){
    for(int i = 0; i <4 ; i++){ 
        draw_cube(0+i,j,-22,0,0,100);
    }}
    for (int i = 0; i < 20;i++){
        draw_cube(0,10+floor(10*cos((360/20)*i)),-22+floor(10*sin((360/20)*i)),0,0,100);
    }
    printTerrain(terrain,-10,-10,-10);


     glutSwapBuffers();
    

}

int main(int argc, char** argv)
{
    int width = 40;
    int height = 20;
    float frequency = 0.1f;
    int octaves = 5;
    float persistence = 0.5f;

     terrain = generateTerrain(width, height, frequency, octaves, persistence);
    print(terrain);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cube Example");
    
    glEnable(GL_DEPTH_TEST);
    initLighting();
    glutDisplayFunc(display);
    //glutSpecialFunc(specialKeys);
    
    
    glutReshapeFunc(reshape);
   

    glutMainLoop();

    return 0;
}