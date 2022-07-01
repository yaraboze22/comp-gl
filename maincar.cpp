 
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

void display(void)
{
    

    glClear(GL_COLOR_BUFFER_BIT);

    
   
    
    

    
    //----------CAR AND WHEELS----------
    //car and wheels are pushed in matrix so they can be translated on th X axis
    glPushMatrix();
    glTranslatef(carAndWheelX, 0.0f, 0.0f);
    
    //----------CAR TOP----------
    glColor3f(redf, greenf, bluef);
    glBegin(GL_POLYGON);
    glVertex2f(-100, -80);
    glVertex2f(-105, -85);
    glVertex2f(-55, -85);
    glVertex2f(-60, -80);
    glEnd();
    
    //----------CAR BODY----------
    glColor3f(redf, greenf, bluef);
    glBegin(GL_POLYGON);
    glVertex2f(-110, -85);
    glVertex2f(-110, -95);
    glVertex2f(-50, -95);
    glVertex2f(-50, -85);
    glEnd();
    
    //----------CAR HEADLIGHTS----------
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-55, -88);
    glVertex2f(-55, -91);
    glVertex2f(-50, -91);
    glVertex2f(-50, -88);
    glEnd();
    
    //----------WHEEL 1----------
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-95 + 5 * cos(theta), -95 + 5 * sin(theta));
    }
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-95  + 2.5 * cos(theta), -95 + 2.5 * sin(theta));
    }
    glEnd();
    //----------END OF WHEEL 1----------
    
    //----------WHEEL 2----------
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-65 + 5 * cos(theta), -95 + 5 * sin(theta));
    }
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-65  + 2.5 * cos(theta), -95 + 2.5 * sin(theta));
    }
    glEnd();
    //----------END OF WHEEL 2----------
    glPopMatrix();
    
    
    
    //----------WHEEL 1 BAR----------
    //wheel bar is pushed in a matrix so it can be rotated and translated
    glPushMatrix();
    glTranslatef(carAndWheelX + -95.0f, -95.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-1*carAndWheelX + 95.0f, 95.0f, 0.0f);
    glTranslatef(carAndWheelX, 0.0, 0.0);
    glColor3f((float)46/255, (float)43/255, (float)42/255);
    glBegin(GL_POLYGON);
    glVertex2f(-97, -96);
    glVertex2f(-97, -94);
    glVertex2f(-93, -94);
    glVertex2f(-93, -96);
    glEnd();
    glPopMatrix();

    //----------WHEEL 2 BAR----------
    //whee2 bar is pushed in a matrix so it can be rotated and translated
    glPushMatrix();
    glTranslatef(carAndWheelX + -65.0f, -95.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-1*carAndWheelX + 65.0f, 95.0f, 0.0f);
    glTranslatef(carAndWheelX, 0.0, 0.0);
    glColor3f((float)46/255, (float)43/255, (float)42/255);
    glBegin(GL_POLYGON);
    glVertex2f(-67, -96);
    glVertex2f(-67, -94);
    glVertex2f(-63, -94);
    glVertex2f(-63, -96);
    glEnd();
    glPopMatrix();
    
    
    glutSwapBuffers();

}








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
