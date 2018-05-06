#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

double theta = 0.0;
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

GLfloat keyPentagonBodyVertices[][3] = {
        {0.58779, -0.80902, 1},
        {0.95106, 0.30902, 1},
        {0, 1, 1},
        {-0.95106, 0.30902, 1},
        {-0.58779, -0.80902, 1},
        {0.58779, -0.80902, -1},
        {0.95106, 0.30902, -1},
        {0, 1, -1},
        {-0.95106, 0.30902, -1},
        {-0.58779, -0.80902, -1},
    };

void lockCube(){
    glColor3d(1, 0, 0);
    glPushMatrix();
	glScaled(0.9, 0.9, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
}

void lockFrontDecagon(){
    glColor3d(1, 1, 0);
    glPushMatrix();
    glScaled(0.3, 0.3, 0.5);
    glTranslated(0, -0.505, 0.5002);
    glBegin(GL_POLYGON);
        glVertex3d(0, 1, 0);
        glVertex3d(0.58778, 0.80902, 0);
        glVertex3d(0.95106, 0.30902, 0);
        glVertex3d(0.95106, -0.30902, 0);
        glVertex3d(0.58778, -0.80902, 0);
        glVertex3d(0, -1, 0);
        glVertex3d(-0.58778, -0.80902, 0);
        glVertex3d(-0.95106, -0.30902, 0);
        glVertex3d(-0.95106, 0.30902, 0);
        glVertex3d(-0.58778, 0.80902, 0);
    glEnd();
    glPopMatrix();
}

void lockKeyholePentagon(){
    glColor3d(0, 0, 0);
    glPushMatrix();
    glScaled(0.1, 0.1, 0.5);
    glTranslated(0, -0.415, 0.50040);
    glBegin(GL_POLYGON);
        glVertex3d(0, 1, 0);
        glVertex3d(0.95106, 0.30902, 0);
        glVertex3d(0.58779, -0.80902, 0);
        glVertex3d(0.3, -0.80902, 0);
        glVertex3d(0.3, -3.35, 0);
        glVertex3d(-0.3, -3.35, 0);
        glVertex3d(-0.3, -0.80902, 0);
        glVertex3d(-0.58779, -0.80902, 0);
        glVertex3d(-0.95106, 0.30902, 0);
    glEnd();
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

void lock(){
    glPushMatrix();
    lockCube();
    lockFrontDecagon();
    lockKeyholePentagon();
    glPushMatrix();
    // FINAL LOCATION
    // glTranslated(0, 0.35, 0);
    lockBar();
    glPopMatrix();
    glPopMatrix();
}


void keyBodyPentagonFourFace(int a, int b, int c, int d) {

	glBegin(GL_POLYGON);
        glVertex3fv(keyPentagonBodyVertices[a]);
        glVertex3fv(keyPentagonBodyVertices[b]);
        glVertex3fv(keyPentagonBodyVertices[c]);
        glVertex3fv(keyPentagonBodyVertices[d]);
	glEnd();
}

void keyBodyPentagonFiveFace(int a, int b, int c, int d, int e) {

	glBegin(GL_POLYGON);
        glVertex3fv(keyPentagonBodyVertices[a]);
        glVertex3fv(keyPentagonBodyVertices[b]);
        glVertex3fv(keyPentagonBodyVertices[c]);
        glVertex3fv(keyPentagonBodyVertices[d]);
        glVertex3fv(keyPentagonBodyVertices[e]);
	glEnd();
}

void keyBodyPentagon(){
    glColor3d(0.6, 0.6, 0.6);
    glPushMatrix();
    glScaled(0.09, 0.09, 0.7);
    glTranslated(0, -0.415, 0.9);
    keyBodyPentagonFiveFace(0, 1, 2, 3, 4);
    keyBodyPentagonFourFace(0, 1, 6, 5);
    keyBodyPentagonFourFace(1, 2, 7, 6);
    keyBodyPentagonFourFace(2, 3, 8, 7);
    keyBodyPentagonFourFace(3, 4, 9, 8);
    keyBodyPentagonFourFace(4, 0, 5, 9);
    keyBodyPentagonFiveFace(5, 6, 7, 8, 9);
    glPopMatrix();
}

void keyBlockOne(){
    glColor3f(0.4, 0.9, 0.2);
    glPushMatrix();
    glScaled(0.05, 0.32, 0.1);
    glTranslated(0, -0.6, -0.1);
	glutSolidCube(1.0);
    glPopMatrix();
}

void keyBlockTwo(){
    glColor3f(0.4, 0.1, 0.9);
    glPushMatrix();
    glScaled(0.05, 0.22, 0.1);
    glTranslated(0, -0.6, 1.1);
	glutSolidCube(1.0);
    glPopMatrix();
}

void keyBlockThree(){
    glColor3f(0.1, 0.7, 0.7);
    glPushMatrix();
    glScaled(0.05, 0.26, 0.1);
    glTranslated(0, -0.6, 2.3);
	glutSolidCube(1.0);
    glPopMatrix();
}

void keyBlockFour(){
    glColor3f(0.4, 0.1, 0.6);
    glPushMatrix();
    glScaled(0.05, 0.32, 0.1);
    glTranslated(0, -0.6, 3.5);
	glutSolidCube(1.0);
    glPopMatrix();
}

void keyHandle(){
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    glTranslated(0, -0.04, 1.35);
    glutSolidSphere(0.05, 30, 30);
    glPopMatrix();

    glColor3f(0.4, 1, 0.9);
    glPushMatrix();
    glTranslated(0, -0.04, 1.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.2,0.2,0.2);
    glutSolidTorus(0.15, 0.7, 30, 30);
    glPopMatrix();
}

void keyBlocks(){
    glColor3d(0.6, 0.6, 0.6);
    glPushMatrix();
        keyBlockOne();
        keyBlockTwo();
        keyBlockThree();
        keyBlockFour();
    glPopMatrix();
}

void key(){
    glPushMatrix();
    keyBodyPentagon();
    keyBlocks();
    keyHandle();
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
	glRotated(45, 0, 1, 0);
	glRotated(-25, 1, 0, 0);
	glPushMatrix();
	lock();
	glPopMatrix();
	glPushMatrix();
	// FINAL TRANSLATE -
	// glTranslated(0, 0, -0.175);
	// INITIAL TRANSLATE -
	glTranslated(0, 0, 0.75);
	key();
	glPopMatrix();
	glPopMatrix();

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
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}


