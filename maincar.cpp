 
#include <GLUT/glut.h>
 
#include <GL/glut.h>
 
#include<math.h>
#include <stdlib.h>

 

GLfloat cloud1x = 0.0f; 
GLfloat cloud2x = 0.0f;  
GLfloat angle = 0.0f;   
GLfloat carAndWheelX = 0;  
GLint red;  
GLint green; 
GLint blue; 
GLfloat redf = 1.0f;  
GLfloat greenf = 0.0f;  
GLfloat bluef = 0.0f;  

void init() {

    glClearColor(0.31, 0.58, 0.796, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

}
