#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int gameMode = 1; // 0 - pad lock, 1 - number lock

GLfloat keyZ = 0.75;
GLfloat keyTheta = 0;
GLfloat lockBarY = 0;
int keyPosition = 0;
int lockAndKeyAction = -1; // 0 - outside, 1 - inside the lock

int numberLockPosition = 0;

int ansOne = 1;
int ansTwo = 4;
int ansThree = 2;

int currentFaceOne = 0;
int currentFaceTwo = 0;
int currentFaceThree = 0;

// TODO - DYNAMIC CHANGE
int cylinderThetaOne = 0;
int cylinderThetaTwo = 0;
int cylinderThetaThree = 0;

GLfloat cubeVertices[][3] = {
    {-0.5, -0.5, -0.5},
	{0.5, -0.5, -0.5},
	{0.5, 0.5, -0.5},
	{-0.5, 0.5, -0.5},
	{-0.5, -0.5, 0.5},
	{0.5, -0.5, 0.5},
	{0.5, 0.5, 0.5},
	{-0.5, 0.5, 0.5}
};

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

void lockBarFace(int a, int b, int c, int d) {
	glBegin(GL_POLYGON);
        glVertex3fv(lockBarVertices[a]);
        glVertex3fv(lockBarVertices[b]);
        glVertex3fv(lockBarVertices[c]);
        glVertex3fv(lockBarVertices[d]);
	glEnd();
}

void lockBar(){
    glPushMatrix();
    glTranslated(0, 0.3, 0);
    glScaled(0.5, 0.5, 0.5);
    glRotated(-45, 0, 0, 1);
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

// -----------------
// LOCK AND KEY CODE
// -----------------
void cubeFace(int a, int b, int c, int d) {
	glBegin(GL_POLYGON);
        glVertex3fv(cubeVertices[a]);
        glVertex3fv(cubeVertices[b]);
        glVertex3fv(cubeVertices[c]);
        glVertex3fv(cubeVertices[d]);
	glEnd();
}

void lockCube(){
    glColor3d(1, 0, 0);
    glPushMatrix();
	glScaled(0.9, 0.9, 0.5);
	glPushMatrix();

	glColor3d(0.9, 0, 0);
	cubeFace(0, 3, 2, 1);

	glColor3d(0.9, 0, 0);
	cubeFace(2, 3, 7, 6);

	glColor3d(0.8, 0, 0);
	cubeFace(0, 4, 7, 3);

	glColor3d(0.95, 0, 0);
	cubeFace(1, 2, 6, 5);

	glColor3d(1, 0, 0);
	cubeFace(4, 5, 6, 7);

	glColor3d(0.75, 0, 0);
	cubeFace(0, 1, 5, 4);

	glPopMatrix();
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

void lock(){
    glPushMatrix();
    lockCube();
    lockFrontDecagon();
    lockKeyholePentagon();
    glPushMatrix();
    glTranslated(0, lockBarY, 0);
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

void animateKey(){
    if(lockAndKeyAction == 0){
        if(keyZ >= -0.175){
            keyZ -= 0.0005;
        }
        if(keyZ < -0.175){
            keyPosition = 1;
        }
        if(keyPosition == 1 && keyTheta <= 360){
            keyTheta+= 0.5;
        }
        if(keyTheta>360){
            keyPosition = 2;
        }
        if(keyPosition == 2 && lockBarY <= 0.35){
            lockBarY+=0.001;
        }
    }

    if(lockAndKeyAction == 1){
        if(keyPosition == 2 && lockBarY >= 0){
            lockBarY-=0.001;
        }
        if(lockBarY<0){
            keyPosition = 1;
        }
        if(keyPosition == 1 && keyTheta >=0) {
            keyTheta -= 0.5;
        }
        if(keyTheta < 0){
            keyPosition = 0;
        }
        if(keyPosition == 0 && keyZ <= 0.75){
            keyZ += 0.0005;
        }
    }

    glutPostRedisplay();
}

void displayLockAndKey(){
    glPushMatrix();
	glRotated(22.5, 0, 1, 0);
	glRotated(-25, 1, 0, 0);
        glPushMatrix();
            glScaled(1.5, 1.5, 1.5);
            glPushMatrix();
            lock();
            glPopMatrix();
            glPushMatrix();
            // FINAL TRANSLATE -
            // glTranslated(0, 0, -0.175);
            // INITIAL TRANSLATE -
            glTranslated(0, 0, keyZ);
            glRotated(-keyTheta, 0, 0, 1); // TODO - FIX ROTATION
            key();
            glPopMatrix();
        glPopMatrix();
	glPopMatrix();
}

void lockAndKeyKeyboard( unsigned char key, int x, int y){
    if(key == 'l'){
        keyZ = 0.75;
        keyTheta = 0;
        lockBarY = 0;
        keyPosition = 0;
        lockAndKeyAction = 0;
        glutPostRedisplay();
    }
    if(key == 'u'){
        keyZ = -0.175;
        keyTheta = 360;
        lockBarY = 0.35;
        keyPosition = 2;
        lockAndKeyAction = 1;
        glutPostRedisplay();
    }
}
// -----------------
// LOCK AND KEY CODE
// -----------------

// -----------------
// NUMBER LOCK CODE
// -----------------
void numberLockCube(){
    glColor3d(0.6, 0.3, 0.9);
    glPushMatrix();
	glScaled(0.9, 0.9, 0.5);
	glutSolidCube(1.0);
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

void guessSpheres(){
    glPushMatrix();
    guessSphereOne();
    guessSphereTwo();
    guessSphereThree();
    glPopMatrix();
}

void numberLock(){
    glPushMatrix();
    numberLockCube();
    numberCylinders();
    guessSpheres();

    glPushMatrix();
    // FINAL LOCATION
    glTranslated(0, lockBarY, 0);
    lockBar();
    glPopMatrix();

    glPopMatrix();
}

void displayNumberLock(){
    //glPushMatrix();
	//glRotated(22.5, 0, 1, 0);
	//glRotated(90, 1, 0, 0);
	glPushMatrix();
	glScaled(1.5, 1.5, 1.5);
	numberLock();
	glPopMatrix();
	//glPopMatrix();
}

void animateNumberLock(){
    if(currentFaceOne == ansOne && currentFaceTwo == ansTwo && currentFaceThree == ansThree && lockBarY <= 0.35){
        numberLockPosition = 1;
    }
    if(numberLockPosition == 1 && lockBarY <= 0.35){
        lockBarY += 0.001;
    }
    if(lockBarY > 0.35 && (currentFaceOne != ansOne || currentFaceTwo != ansTwo || currentFaceThree != ansThree)){
        numberLockPosition = 0;
    }
    if(numberLockPosition == 0 && lockBarY >0){
        lockBarY -= 0.001;
    }
    glutPostRedisplay();
}

void numberLockKeyboard(unsigned char key, int x, int y){

    // CYLINDER ONE KEY HANDLER
    if(key == '7'){
        cylinderThetaOne += 60;
        currentFaceOne = (++currentFaceOne) % 6;
        printf("current face of cylinder 1 : %d\n", currentFaceOne);
    }
    if(key == '9'){
        cylinderThetaOne -= 60;
        currentFaceOne = (--currentFaceOne) % 6;
        if(currentFaceOne == -1) currentFaceOne = 5;
        printf("current face of cylinder 1 : %d\n", currentFaceOne);
    }

    // CYLINDER TWO KEY HANDLER
    if(key == '4'){
        cylinderThetaTwo += 60;
        currentFaceTwo = (++currentFaceTwo) % 6;
        printf("current face of cylinder 2 : %d\n", currentFaceTwo);
    }
    if(key == '6'){
        cylinderThetaTwo -= 60;
        currentFaceTwo = (--currentFaceTwo) % 6;
        if(currentFaceTwo == -1) currentFaceTwo = 5;
        printf("current face of cylinder 2 : %d\n", currentFaceTwo);
    }

    // CYLINDER THREE KEY HANDLER
    if(key == '1'){
        cylinderThetaThree += 60;
        currentFaceThree = (++currentFaceThree) % 6;
        printf("current face of cylinder 3 : %d\n", currentFaceThree);
    }
    if(key == '3'){
        cylinderThetaThree -= 60;
        currentFaceThree = (--currentFaceThree) % 6;
        if(currentFaceThree == -1) currentFaceThree = 5;
        printf("current face of cylinder 3 : %d\n", currentFaceThree);
    }


    glutPostRedisplay();
}
// -----------------
// NUMBER LOCK CODE
// -----------------

void mouse(int btn, int state, int x, int y){
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        gameMode = 0;
    }
    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        gameMode = 1;
    }
    glutPostRedisplay();
}

void display(void) {
    glClearColor(0.9, 1, 1.0, 1.0);
	glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    if(gameMode == 0){
        displayLockAndKey();
    } else {
        displayNumberLock();
    }

	glutSwapBuffers();
    glFlush();
}

void myreshape(int w,int h) {
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

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 35);
	glutCreateWindow("lock and key game");

	glutMouseFunc(mouse);
	if(gameMode == 0){
        glutKeyboardFunc(lockAndKeyKeyboard);
        glutIdleFunc(animateKey);
    } else {
        glutKeyboardFunc(numberLockKeyboard);
        glutIdleFunc(animateNumberLock);
    }

	glutDisplayFunc(display);
	glutReshapeFunc(myreshape);
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glutMainLoop();
	return 0;
}


