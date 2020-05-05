// OpenGL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <glut.h>
#include <cmath>
#include "Interval.h"
#include "Curve.h"

typedef struct Point {
	GLfloat x;
	GLfloat y;
	GLfloat z;
} point;


void drawCurve(const Curve &curve)
{
	curve.getInterval().forEach([curve](float x)
		{
			glVertex2f(x, curve(x));
		}, 0.01);
}

void drawCircle(const float radius) {
	const Interval in(-10, 10);
	in.forEach([radius](const float i){
		glVertex2f(radius * cos(i), radius * sin(i));
	}, 0.1);


}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	
	Curve curve([](float x)->float
	{
		return sin(x);
	}, Interval(-100, 100));	
	glBegin(GL_LINE_STRIP);
	drawCurve(curve);

	//drawCircle(100);
	glEnd();
	glFlush();
}


void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int ScaleX = 500;
int ScaleY = 50;
int ScaleZ = 50;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Points");
	glTranslatef(200, 200, 0);
	glScalef(50, 50, 50);

	glutKeyboardFunc([] (unsigned char key, int x, int y)
	{
			printf("%c", key);
		switch (key)
		{
		case 'd':
			glTranslatef(-10, 0, 0);
			break;
		case 'w':
			glTranslatef(0, -10, 0);
			break;
		case 'a':
			glTranslatef(10, 0, 0);
			break;
		case 's':
			glTranslatef(0, 10, 0);
			break;
		case '+':
			glScalef(5, 5, 5);
			//ScaleX += 10;
			//gluOrtho2D(0.0, ScaleX, 0.0, ScaleX);
			glutPostRedisplay();
			
			break;
		case '-':
			glScalef(0.5, 0.5, 0.5);
			break;
		default:
			break;
		}
			
		glutPostRedisplay();

	});
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();
	return 0;
}
