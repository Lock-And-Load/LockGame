#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int ansOne = 1;
int ansTwo = 4;
int ansThree = 2;

// TODO - DYNAMIC CHANGE
int cylinderThetaOne = ansOne * 60;
int cylinderThetaTwo = ansTwo * 60;
int cylinderThetaThree = ansThree * 60;

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

GLfloat cylinderFaceColors[][3] = {
    {0.90196, 0.29020, 0.09804},
    {0.96078, 0.48627, 0.00000},
    {1.00000, 0.62745, 0.00000},
    {0.98431, 0.75294, 0.17647},
    {0.68627, 0.70588, 0.16863},
    {0.40784, 0.62353, 0.21961}
};

void lockCube(){
    glColor3d(0.6, 0.3, 0.9);
    glPushMatrix();
	glScaled(0.9, 0.9, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
}

void lockBarFace(int a, int b, int c, int d) {

	glBegin(GL_POLYGON);
	glNormal3f(0 ,0, 1);
        glVertex3fv(lockBarVertices[a]);
        glNormal3f(0 ,0, 1);
        glVertex3fv(lockBarVertices[b]);
        glNormal3f(0 ,0, 1);
        glVertex3fv(lockBarVertices[c]);

        glVertex3fv(lockBarVertices[d]);
	glEnd();
}

void lockBar(){
    glPushMatrix();
    glTranslated(0, 0.3, 0);
    glScaled(0.5, 0.5, 0.5);
    glRotated(-45, 0, 0, 1);

    // LOCK BAR FACES
    glColor3d(0.8, 0.8, 0.8);
    lockBarFace(0, 1, 2, 3);

    glColor3d(0.8, 0.8, 0.8);
    lockBarFace(0, 8, 9, 1);

    glColor3d(0.45, 0.45, 0.45);
    lockBarFace(0, 8, 11, 3);

    glColor3d(0.8, 0.8, 0.8);
    lockBarFace(3, 11, 10, 2);

    glColor3d(0.5, 0.5, 0.5);
    lockBarFace(1, 9, 10, 2);

    glColor3d(0.55, 0.55, 0.55);
    lockBarFace(9, 13, 12, 10);

    glColor3d(0.85, 0.85, 0.85);
    lockBarFace(9, 8, 14, 13);

    glColor3d(0.85, 0.85, 0.85);
    lockBarFace(8, 14, 15, 11);

    glColor3d(0.55, 0.55, 0.55);
    lockBarFace(11, 15, 12, 10);

    glColor3d(0.8, 0.8, 0.8);
    lockBarFace(4, 12, 13, 5);

    glColor3d(0.45, 0.45, 0.45);
    lockBarFace(5, 13, 14, 6);

    glColor3d(0.8, 0.8, 0.8);
    lockBarFace(6, 14, 15, 7);

    glColor3d(0.5, 0.5, 0.5);
    lockBarFace(7, 15, 12, 4);

    glColor3d(0.6, 0.6, 0.6);
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
    glColor3d(0.6, 0.8, 0.6);
    glPushMatrix();

    glColor3fv(cylinderFaceColors[0]);
    numberCylinderFourFace(0, 1, 7, 6);
    glColor3fv(cylinderFaceColors[1]);
    numberCylinderFourFace(1, 2, 8, 7);
    glColor3fv(cylinderFaceColors[2]);
    numberCylinderFourFace(2, 3, 9, 8);
    glColor3fv(cylinderFaceColors[3]);
    numberCylinderFourFace(3, 4, 10, 9);
    glColor3fv(cylinderFaceColors[4]);
    numberCylinderFourFace(4, 5, 11, 10);
    glColor3fv(cylinderFaceColors[5]);
    numberCylinderFourFace(5, 0, 6, 11);

    glColor3d(0.6, 0.6, 0.6);
    numberCylinderSixFace(0, 1, 2, 3, 4, 5);
    numberCylinderSixFace(6, 7, 8, 9, 10, 11);

    glPopMatrix();

}

void numberCylinderOne(){
    glPushMatrix();
    glScaled(0.15, 0.1, 0.15);
    glTranslated(2, 3, 1.25);
    glRotated(30 - cylinderThetaOne, 0, 1, 0);
    glRotated(90, 1, 0, 0);
    numberCylinder();
    glPopMatrix();
}

void numberCylinderTwo(){
    glPushMatrix();
    glScaled(0.15, 0.1, 0.15);
    glTranslated(2, 0, 1.25);
    glRotated(30 - cylinderThetaTwo, 0, 1, 0);
    glRotated(90, 1, 0, 0);
    numberCylinder();
    glPopMatrix();
}

void numberCylinderThree(){
    glPushMatrix();
    glScaled(0.15, 0.1, 0.15);
    glTranslated(2, -3, 1.25);
    glRotated(30 - cylinderThetaThree, 0, 1, 0);
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

void guessSphereOne(){
    glPushMatrix();
    glTranslated(-0.3, 0, 0.25);
    glColor3fv(cylinderFaceColors[1]);
    glutSolidSphere(0.05, 10, 10);
    glPopMatrix();
}

void guessSphereTwo(){
    glPushMatrix();
    glTranslated(-0.15, 0, 0.25);
    glColor3fv(cylinderFaceColors[4]);
    glutSolidSphere(00.05, 10, 10);
    glPopMatrix();
}

void guessSphereThree(){
    glPushMatrix();
    glTranslated(0, 0, 0.25);
    glColor3fv(cylinderFaceColors[2]);
    glutSolidSphere(0.05, 10, 10);
    glPopMatrix();
}

void guessCubes(){
    glPushMatrix();
    guessSphereOne();
    guessSphereTwo();
    guessSphereThree();
    glPopMatrix();
}

void lock(){
    glPushMatrix();
    lockCube();
    numberCylinders();
    guessCubes();

    glPushMatrix();
    // FINAL LOCATION
    // glTranslated(0, 0.35, 0);
    lockBar();
    glPopMatrix();

    glPopMatrix();
}


void display(void)
{
    glClearColor(0.9, 1, 1.0, 1.0);
	glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	//glPushMatrix();
	//glRotated(22.5, 0, 1, 0);
	//glRotated(90, 1, 0, 0);
	glPushMatrix();
	glScaled(1.5, 1.5, 1.5);
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
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glutMainLoop();
	return 0;
}


