#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <cmath>
using namespace std;

#define FPS 120
#define TO_RADIANS 3.14/180.0

#define _USE_MATH_DEFINES // This is needed for Windows to define M_PI
#include <cmath>

#ifndef PI
#define PI 3.14159265358979323846
#endif

const int width = 1280;
const int height = 720;
int i;
float sudut;
double x_geser, y_geser, z_geser;

float pitch = 0.0, yaw = 0.0;
float camX = 2000.0, camZ = 2000.0, terbang = 2000.0;

void display();
void reshape(int w, int h);
void timer(int);
void passive_motion(int, int);
void camera();
void keyboard(unsigned char key, int x, int y);
void keyboard_up(unsigned char key, int x, int y);

struct Motion {
    bool Forward, Backward, Left, Right, Naik, Turun;
};
Motion motion = { false,false,false,false,false,false };

void init() {
    glClearColor(0.529, 0.807, 0.921, 0.0);
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}

void draw_cylinder(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3ub(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
}

//Monumen Kiri
void kubusbintangsilinder1(){
    //Kubus1
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0, 124.5, -210);
    glScalef(3.9, 17.5, 3.9);
    glutSolidCube(500);
    glPopMatrix();
    
    //Kubus2
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0, 124.5, -210);
    glRotatef(22.5f, 0.0f, 1.0f, 0.0f);
    glScalef(3.9, 17.5, 3.9);
    glutSolidCube(500);
    glPopMatrix();
    
    //Kubus3
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0, 124.5, -210);
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
    glScalef(3.9, 17.5, 3.9);
    glutSolidCube(500);
    glPopMatrix();
    
    //Kubus4
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0, 124.5, -210);
    glRotatef(67.5f, 0.0f, 1.0f, 0.0f);
    glScalef(3.9, 17.5, 3.9);
    glutSolidCube(500);
    glPopMatrix();
}

//Monumen Kanan
void kubusbintangsilinder2(){
    //Kubus1
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(4000, 124.5, -210);
    glScalef(3.9, 17.5, 3.9);
    glutSolidCube(500);
    glPopMatrix();
    
    //Kubus2
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(4000, 124.5, -210);
    glRotatef(22.5f, 0.0f, 1.0f, 0.0f);
    glScalef(3.9, 17.5, 3.9);
    glutSolidCube(500);
    glPopMatrix();
    
    //Kubus3
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(4000, 124.5, -210);
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
    glScalef(3.9, 17.5, 3.9);
    glutSolidCube(500);
    glPopMatrix();
    
    //Kubus4
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(4000, 124.5, -210);
    glRotatef(67.5f, 0.0f, 1.0f, 0.0f);
    glScalef(3.9, 17.5, 3.9);
    glutSolidCube(500);
    glPopMatrix();
}

//Monumen Kiri
void kubusbintangsilinder3(){
    //Kubus1
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0, 124.5, -210);
    glScalef(3.4, 26.0, 3.4);
    glutSolidCube(500);
    glPopMatrix();
    
    //Kubus2
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0, 124.5, -210);
    glRotatef(22.5f, 0.0f, 1.0f, 0.0f);
    glScalef(3.4, 26.0, 3.4);
    glutSolidCube(500);
    glPopMatrix();
    
    //Kubus3
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0, 124.5, -210);
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
    glScalef(3.4, 26.0, 3.4);
    glutSolidCube(500);
    glPopMatrix();
    
    //Kubus4
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0, 124.5, -210);
    glRotatef(67.5f, 0.0f, 1.0f, 0.0f);
    glScalef(3.4, 26.0, 3.4);
    glutSolidCube(500);
    glPopMatrix();
}

//Monumen Kanan
void kubusbintangsilinder4(){
    //Kubus1
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(4000, 124.5, -210);
    glScalef(3.4, 26.0, 3.4);
    glutSolidCube(500);
    glPopMatrix();
    
    //Kubus2
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(4000, 124.5, -210);
    glRotatef(22.5f, 0.0f, 1.0f, 0.0f);
    glScalef(3.4, 26.0, 3.4);
    glutSolidCube(500);
    glPopMatrix();
    
    //Kubus3
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(4000, 124.5, -210);
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
    glScalef(3.4, 26.0, 3.4);
    glutSolidCube(500);
    glPopMatrix();
    
    //Kubus4
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(4000, 124.5, -210);
    glRotatef(67.5f, 0.0f, 1.0f, 0.0f);
    glScalef(3.4, 26.0, 3.4);
    glutSolidCube(500);
    glPopMatrix();
}

void kubusbintangsilinder5(){
    
    //Penyangga Monumen Kiri
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0, 124.5, -210);
    glScalef(2.9, 30.0, 2.9);
    glutSolidCube(500);
    glPopMatrix();
    
    //Penyangga Monumen Kanan
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(4000, 124.5, -210);
    glScalef(2.9, 30.0, 2.9);
    glutSolidCube(500);
    glPopMatrix();
    
}

void monumenkiri1() {
    
    kubusbintangsilinder1();
    kubusbintangsilinder3();
    kubusbintangsilinder5();
    
    //Silinder
	glColor4f(1.0, 0.84, 0.0, 1.0); // Warna emas
	glPushMatrix();
	glTranslatef(0, 0, -210); // Geser ke atas 
	glScalef(3.0, 10.0, 3.0);
	glRotatef(-90, 1, 0, 0); // Rotasi agar kerucut menghadap ke bawah
	draw_cylinder(400.0, 450.0, 250, 245, 245);
	glPopMatrix();
	
	//Silinder2
	glColor4f(1.0, 0.84, 0.0, 1.0); // Warna emas
	glPushMatrix();
	glTranslatef(0, 124.5, -210); // Geser ke atas 
	glScalef(3.0, 10.0, 3.0);
	glRotatef(-90, 1, 0, 0); // Rotasi agar kerucut menghadap ke bawah
	draw_cylinder(350.0, 650.0, 250, 245, 245);
	glPopMatrix();
	
	//Silinder3
	glColor4f(1.0, 0.84, 0.0, 1.0); // Warna emas
	glPushMatrix();
	glTranslatef(0, 124.5, -210); // Geser ke atas 
	glScalef(3.0, 10.0, 3.0);
	glRotatef(-90, 1, 0, 0); // Rotasi agar kerucut menghadap ke bawah
	draw_cylinder(300.0, 750.0, 250, 245, 245);
	glPopMatrix();
	
	//Silinder4
	glColor4f(1.0, 0.84, 0.0, 1.0); // Warna emas
	glPushMatrix();
	glTranslatef(0, 124.5, -210); // Geser ke atas 
	glScalef(3.0, 10.0, 3.0);
	glRotatef(-90, 1, 0, 0); // Rotasi agar kerucut menghadap ke bawah
	draw_cylinder(250.0, 820.0, 250, 245, 245);
	glPopMatrix();
	
	//Antena
	glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
	glTranslatef(0.0, 124.5, 950.0); // Geser ke atas 
	glRotatef(-90, 1, 0, 0); 
	glScalef(0.1, 0.1, 5.0);
//	glutSolidCone(780, 1600, 50, 50); // Parameter (radius, height, slices, stacks)
//	draw_cylinder(400.0, 1000.0, 255, 160, 100);
	glutSolidTorus(400, 350, 50, 50);
	glPopMatrix();
	
	//Kerucut
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 8250.0, -210.0); // Geser ke atas
	glRotatef(-90, 1, 0, 0); // Rotasi agar kerucut menghadap ke bawah
	glScalef(1.0, 1.0, 3.0);
	glutSolidTorus(400, 350, 50, 50);
	glPopMatrix();
	
	//Antena
	glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
	glTranslatef(0.0, 8250.0, -210.0); // Geser ke atas 
	glRotatef(-90, 1, 0, 0); 
	glScalef(0.1, 0.1, 5.0); //Untuk Membuat Bentuk Torus Seperti Antena
//	glutSolidCone(780, 1600, 50, 50); // Parameter (radius, height, slices, stacks)
//	draw_cylinder(400.0, 1000.0, 255, 160, 100);
	glutSolidTorus(400, 350, 50, 50);
	glPopMatrix();
	
	//Cagak Kerucut
    glColor3f(0.9, 0.9, 0.9);
    glPushMatrix();
    glTranslatef(0, 7500, -210);
    glScalef(3.0, 0.5, 3.0);
    glutSolidCube(500);
    glPopMatrix();

	//Cincin1
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 500, -210); // Geser ke atas 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0);  
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin2
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 1000, -210); // Geser ke atas 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); 
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin3
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 1500, -210); // Geser ke atas 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0);  
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin4
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 2000, -210); // Geser ke atas 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0);  
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin5
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 2500, -210); // Geser ke atas 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0);  
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin6
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 3000, -210); // Geser ke atas 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); 
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin7
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 3500, -210); // Geser ke atas 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); // Rotasi agar kerucut menghadap ke bawah
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin8
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 4000, -210); // Geser ke atas 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); // Rotasi agar kerucut menghadap ke bawah
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin9
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 4700, -210); // Geser ke atas 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); // Rotasi agar kerucut menghadap ke bawah
	glutSolidTorus(50, 301, 50, 50);
	glPopMatrix();
	
	//Cincin10
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 5200, -210); // Geser ke atas 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); // Rotasi agar kerucut menghadap ke bawah
	glutSolidTorus(50, 301, 50, 50);
	glPopMatrix();
	
	//Cincin11
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 5700, -210); // Geser ke atas 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); // Rotasi agar kerucut menghadap ke bawah
	glutSolidTorus(50, 301, 50, 50);
	glPopMatrix();
	
	//Cincin12
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 6200, -210); // Geser ke atas 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); // Rotasi agar kerucut menghadap ke bawah
	glutSolidTorus(50, 301, 50, 50);
	glPopMatrix();
	
}

void monumenkanan1() {

	kubusbintangsilinder2();
	kubusbintangsilinder4();
    
    //Kubus
    glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
    glTranslatef(4000, 124.5, -210);
    glScalef(1.6, 30, 1.3);
    glutSolidCube(500);
    glPopMatrix();
    
    //Silinder
	glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
	glTranslatef(4000, 0, -210); // Geser ke atas 
	glScalef(3.0, 10.0, 3.0);
	glRotatef(-90, 1, 0, 0); 
//	glutSolidCone(400, 1000, 50, 50); // Parameter (radius, height, slices, stacks)
	draw_cylinder(400.0, 450.0, 250, 245, 245);
	glPopMatrix();
	
	//Silinder2
	glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
	glTranslatef(4000, 124.5, -210); // Geser ke atas 
	glScalef(3.0, 10.0, 3.0);
	glRotatef(-90, 1, 0, 0); 
//	glutSolidCone(400, 1000, 50, 50); // Parameter (radius, height, slices, stacks)
	draw_cylinder(350.0, 650.0, 250, 245, 245);
	glPopMatrix();
	
	//Silinder3
	glColor4f(1.0, 0.84, 0.0, 1.0); 
	glPushMatrix();
	glTranslatef(4000, 124.5, -210); // Geser ke atas 
	glScalef(3.0, 10.0, 3.0);
	glRotatef(-90, 1, 0, 0); 
	draw_cylinder(300.0, 750.0, 250, 245, 245);
	glPopMatrix();
	
	//Silinder4
	glColor4f(1.0, 0.84, 0.0, 1.0); // Warna emas
	glPushMatrix();
	glTranslatef(4000, 124.5, -210); // Geser ke atas
	glScalef(3.0, 10.0, 3.0);
	glRotatef(-90, 1, 0, 0); 
	draw_cylinder(250, 820.0, 250, 245, 245);
	glPopMatrix();
	
	//Kerucut
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(4000.0, 8250.0, -210.0); // Geser ke atas 
	glRotatef(-90, 1, 0, 0); 
	glScalef(1.0, 1.0, 3.0);
	glutSolidTorus(400, 350, 50, 50);
	glPopMatrix();
	
	//Antena
	glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
	glTranslatef(4000.0, 8250.0, -210.0); // Geser ke atas 
	glRotatef(-90, 1, 0, 0); 
	glScalef(0.1, 0.1, 5.0);
//	glutSolidCone(780, 1600, 50, 50); // Parameter (radius, height, slices, stacks)
//	draw_cylinder(400.0, 1000.0, 255, 160, 100);
	glutSolidTorus(400, 350, 50, 50);
	glPopMatrix();
	
	//Cagak Kerucut
    glColor3f(0.9, 0.9, 0.9);
    glPushMatrix();
    glTranslatef(4000, 7500, -210);
    glScalef(3.0, 0.5, 3.0);
    glutSolidCube(500);
    glPopMatrix();
    
	//Cincin1
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(4000, 500, -210);
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); 
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin2
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(4000, 1000, -210); 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); 
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin3
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(4000, 1500, -210); 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); 
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin4
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(4000, 2000, -210); 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); 
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin5
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(4000, 2500, -210); 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0);
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin6
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(4000, 3000, -210); 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); 
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin7
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(4000, 3500, -210); 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); 
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin8
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(4000, 4000, -210); 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); 
	glutSolidTorus(50, 351, 50, 50);
	glPopMatrix();
	
	//Cincin9
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(4000, 4700, -210);  
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); 
	glutSolidTorus(50, 301, 50, 50);
	glPopMatrix();
	
	//Cincin10
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(4000, 5200, -210); 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); 
	glutSolidTorus(50, 301, 50, 50);
	glPopMatrix();
	
	//Cincin11
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(4000, 5700, -210);
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); 
	glutSolidTorus(50, 301, 50, 50);
	glPopMatrix();
	
	//Cincin12
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(4000, 6200, -210); 
	glScalef(3.0, 4.5, 3.0);
	glRotatef(-90, 1, 0, 0); 
	glutSolidTorus(50, 301, 50, 50);
	glPopMatrix();

}

void bangunan(){
	//bangunan kiri
	glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
    glTranslatef(-1500, 0, 1500);
    glScalef(5.5, 3.5, 10.4);
    glRotatef(45, 0.0f, 1.0f, 0.0f); 
    glutSolidCube(500);
    glPopMatrix();
    
    //bangunan tengah
	glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
    glTranslatef(2000, 0, 0);
    glScalef(7.5, 3.5, 5.5);
    glutSolidCube(500);
    glPopMatrix();
    
    //bangunan kanan
	glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
    glTranslatef(5500, 0, 1500);
    glScalef(5.5, 3.5, 10.4);
    glRotatef(-45, 0.0f, 1.0f, 0.0f); 
    glutSolidCube(500);
    glPopMatrix();
    
}

void jembatan(){
	//jembatan
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(2000, 3500, -150.5);
    glScalef(4.5, 1.5, 3.4);
    glutSolidCube(500);
    glPopMatrix();
    
}

void ground() {
    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.702f, 0.443f);
    glVertex3f(-10000.0, 0, -10000.0);

    glColor3f(0.235f, 0.702f, 0.443f);
    glVertex3f(10000.0, 0, -10000.0);

    glColor3f(0.235f, 0.702f, 0.443f);
    glVertex3f(10000.0, 0, 10000.0);

    glColor3f(0.235f, 0.702f, 0.443f);
    glVertex3f(-10000.0, 0, 10000.0);
    glEnd();
}

void draw() {
    monumenkiri1();
    monumenkanan1();
    jembatan();
    bangunan();
    ground();
    cout << "X_GESER = " << x_geser << "     Y_GESER = " << y_geser << "      Z_GESER = " << z_geser << endl;
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();
    draw();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 16.0 / 9.0, 2, 10000);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
    glutPostRedisplay();
    glutWarpPointer(width / 2, height / 2);
    glutTimerFunc(1000 / FPS, timer, 0);
}

void passive_motion(int x, int y) {
    int dev_x, dev_y;
    dev_x = (width / 2) - x;
    dev_y = (height / 2) - y;
    yaw += (float)dev_x / 20.0;
    pitch += (float)dev_y / 20.0;
}


void camera() {
    if (motion.Forward) {
        camX += cos((yaw + 90) * TO_RADIANS) * 10;
        camZ -= sin((yaw + 90) * TO_RADIANS) * 10;
    }
    if (motion.Backward) {
        camX += cos((yaw + 90 + 180) * TO_RADIANS) * 10;
        camZ -= sin((yaw + 90 + 180) * TO_RADIANS) * 10;
    }
    if (motion.Left) {
        camX += cos((yaw + 90 + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 90) * TO_RADIANS) * 2;
    }
    if (motion.Right) {
        camX += cos((yaw + 90 - 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 - 90) * TO_RADIANS) * 2;
    }
    if (motion.Naik) {
        terbang -= 10.0;
    }
    if (motion.Turun) {
        terbang += 10.0;
    }

    if (pitch >= 70)
        pitch = 70;
    if (pitch <= -90)
        pitch = -90;


    glRotatef(-pitch, 1.0, 0.0, 0.0);
    glRotatef(-yaw, 0.0, 1.0, 0.0);

    glTranslatef(-camX, -terbang, -350 - camZ);
    if (terbang < 25)
        terbang = 24;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = true;
        break;
    case 'A':
    case 'a':
        motion.Left = true;
        break;
    case 'S':
    case 's':
        motion.Backward = true;
        break;
    case 'D':
    case 'd':
        motion.Right = true;
        break;
    case 'E':
    case 'e':
        motion.Naik = true;
        break;
    case 'Q':
    case 'q':
        motion.Turun = true;
        break;
    case '6':
        x_geser += 0.5;
        break;
    case '4':
        x_geser -= 0.5;
        break;
    case '8':
        y_geser += 0.5;
        break;
    case '2':
        y_geser -= 0.5;
        break;
    case '9':
        z_geser -= 0.5;
        break;
    case '1':
        z_geser += 0.5;
        break;
    case '`': // KELUAR DARI PROGRAM
        exit(1);
    }
}

void keyboard_up(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = false;
        break;
    case 'A':
    case 'a':
        motion.Left = false;
        break;
    case 'S':
    case 's':
        motion.Backward = false;
        break;
    case 'D':
    case 'd':
        motion.Right = false;
        break;
    case 'E':
    case 'e':
        motion.Naik = false;
        break;
    case 'Q':
    case 'q':
        motion.Turun = false;
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Petronas Beda Dikit Gak Ngaruh - Geraldi Jari Assaji 2100018487");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);

    glutMainLoop();
    return 0;
}
