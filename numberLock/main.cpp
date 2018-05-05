#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

GLfloat lockBarVertices[][3] = {
        {-0.54643, -0.70357, 0},
        {-0.42143, -0.57857, 0.25},
        {-0.29643, -0.45357, 0},
        {-0.42143, -0.57857, -0.25},
        {0.68927, 0.06073, 0},
        {0.81427, 0.18573, 0.25},
        {0.93927, 0.31073, 0},
        {0.81427, 0.18573, -0.25},
        {-1.25, 0, 0},
        {-1.0, 0, 0.25},
        {-0.75, 0, 0},
        {-1.0, 0, -0.25},
        {0, 0.75, 0},
        {0, 1, 0.25},
        {0, 1.25, 0},
        {0, 1, -0.25}
    };

GLfloat numberCylinderVertices[][3] = {
        {-0.86603, 0.5, -1.0},
        {0, 1, -1.0},
        {0.86603, 0.5, -1.0},
        {0.86603, -0.5, -1.0},
        {0, -1, -1.0},
        {-0.86603, -0.5, -1.0},
        {-0.86603, 0.5, 1.0},
        {0, 1, 1.0},
        {0.86603, 0.5, 1.0},
        {0.86603, -0.5, 1.0},
        {0, -1, 1.0},
        {-0.86603, -0.5, 1.0}
    };

void lockCube(){
    glColor3d(1, 0, 0);
    glPushMatrix();
	glScaled(0.9, 0.9, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
}

void lockBarFace(int a, int b, int c, int d) {

	glBegin(GL_POLYGON);
        glVertex3fv(lockBarVertices[a]);
        glVertex3fv(lockBarVertices[b]);
        glVertex3fv(lockBarVertices[c]);
        glVertex3fv(lockBarVertices[d]);
	glEnd();
}

void lockBar(){
    glColor3d(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslated(0, 0.3, 0);
    glScaled(0.5, 0.5, 0.5);
    glRotated(-45, 0, 0, 1);
    lockBarFace(0, 1, 2, 3);
    lockBarFace(0, 8, 9, 1);
    lockBarFace(0, 8, 11, 3);
    lockBarFace(3, 11, 10, 2);
    lockBarFace(1, 9, 10, 2);
    lockBarFace(9, 13, 12, 10);
    lockBarFace(9, 8, 14, 13);
    lockBarFace(8, 14, 15, 11);
    lockBarFace(11, 15, 12, 10);
    lockBarFace(4, 12, 13, 5);
    lockBarFace(5, 13, 14, 6);
    lockBarFace(6, 14, 15, 7);
    lockBarFace(7, 15, 12, 4);
    lockBarFace(4, 5, 6, 7);
    glPopMatrix();
}

void numberCylinderFourFace(int a, int b, int c, int d) {

	glBegin(GL_POLYGON);
        glVertex3fv(numberCylinderVertices[a]);
        glVertex3fv(numberCylinderVertices[b]);
        glVertex3fv(numberCylinderVertices[c]);
        glVertex3fv(numberCylinderVertices[d]);
	glEnd();
}

void numberCylinderSixFace(int a, int b, int c, int d, int e, int f) {

	glBegin(GL_POLYGON);
        glVertex3fv(numberCylinderVertices[a]);
        glVertex3fv(numberCylinderVertices[b]);
        glVertex3fv(numberCylinderVertices[c]);
        glVertex3fv(numberCylinderVertices[d]);
        glVertex3fv(numberCylinderVertices[e]);
        glVertex3fv(numberCylinderVertices[f]);
	glEnd();
}

void numberCylinder(){
    glColor3d(0.1, 0.2, 0.6);
    glPushMatrix();
    numberCylinderFourFace(0, 1, 7, 6);
    numberCylinderFourFace(1, 2, 8, 7);
    numberCylinderFourFace(2, 3, 9, 8);
    numberCylinderFourFace(3, 4, 10, 9);
    numberCylinderFourFace(4, 5, 11, 10);
    numberCylinderFourFace(5, 0, 6, 11);
    numberCylinderSixFace(0, 1, 2, 3, 4, 5);
    numberCylinderSixFace(6, 7, 8, 9, 10, 11);
    glPopMatrix();

}

void numberCylinderOne(){
    glPushMatrix();
    glScaled(0.15, 0.1, 0.15);
    glTranslated(2, 3, 1.25);
    glRotated(30, 0, 1, 0);
    glRotated(90, 1, 0, 0);
    numberCylinder();
    glPopMatrix();
}

void numberCylinderTwo(){
    glPushMatrix();
    glScaled(0.15, 0.1, 0.15);
    glTranslated(2, 0, 1.25);
    glRotated(30, 0, 1, 0);
    glRotated(90, 1, 0, 0);
    numberCylinder();
    glPopMatrix();
}

void numberCylinderThree(){
    glPushMatrix();
    glScaled(0.15, 0.1, 0.15);
    glTranslated(2, -3, 1.25);
    glRotated(30, 0, 1, 0);
    glRotated(90, 1, 0, 0);
    numberCylinder();
    glPopMatrix();
}

void numberCylinders(){
    glPushMatrix();
    numberCylinderOne();
    numberCylinderTwo();
    numberCylinderThree();
    glPopMatrix();
}

void lock(){
    glPushMatrix();
    lockCube();
    numberCylinders();
    glPushMatrix();
    // FINAL LOCATION
    // glTranslated(0, 0.35, 0);
    lockBar();
    glPopMatrix();
    glPopMatrix();
}


void display(void)
{
    glClearColor(1.0, 1, 1.0, 1.0);
	glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	GLfloat mat_ambient[]   = {0.4f, 0.4f, 0.4f, 1.0f};
	GLfloat mat_diffuse[]   = {0.9f, 0.9f, 0.9f, 1.0f};
	GLfloat mat_specular[]  = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat mat_shininess[] = {50.0f};

	glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	GLfloat lightIntensity[] = {0.9f, 0.9f, 0.9f, 0.9f};
	GLfloat light_position[] = {2.0f, 8.0f, 3.0f, 0.0f};

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	//glRotated(-25, 1, 0, 0);
	glPushMatrix();
	lock();
	glPopMatrix();
	//glPopMatrix();

	glutSwapBuffers();
    glFlush();
}

void myreshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		 glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else
		 glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	 glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 35);
	glutCreateWindow("KEY SIMULATION");
	glutDisplayFunc(display);
	glutReshapeFunc(myreshape);
	//glutMouseFunc(mouse);
	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}


