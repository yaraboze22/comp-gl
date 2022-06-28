 
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

//








void timer(int) {
    
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
    cloud1x += 0.30;
    cloud2x += 0.35;
    
    //if cloud is outside the viewport
    if (cloud1x > 120) {
        cloud1x = -120;
    }

    if (cloud2x > 190) {
        cloud2x = -100;
    }
    
    angle += 5;
    carAndWheelX +=1;
    //if car is outside the viewport
    //change the color to any color from 0 to 254 + 20(to avoid darker colors)
    if (carAndWheelX > 250) {
        red = rand() % 255 + 20;
        green = rand() % 255 + 20;
        blue = rand() % 255 + 20;
        
        redf = (float)red/255;
        greenf = (float)green/255;
        bluef = (float)blue/255;
        carAndWheelX = -50;
    }
        
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 800);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(200, 0);

    glutCreateWindow("18101516 - 18101737");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();

    return 0;
}
