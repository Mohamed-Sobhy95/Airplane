
//#include <GL/glut.h>


#include<stdio.h>
#include<math.h>
#include<cmath>
# define M_PI 3.142
#include<GL/freeglut.h>
GLfloat Xpos = 0, roadbackward = 0, Ypos = 20, d = 0, e = 0;
void runway();
void keys(int key, int x, int y);
void update(int value)
{


	Xpos += 10.0;	//Plane position takeoff on x axis
	roadbackward -= 10.0;
	if (Xpos > 80 && Ypos<150)
		Ypos += 15;
	if (roadbackward <= -70.0)// moving of run way
		roadbackward = 0.0;
	glutPostRedisplay();

	glutTimerFunc(100, update, 0);//delay
}

void keys(int key, int x, int y) {
	if (key == GLUT_KEY_RIGHT)
	{
		Xpos += 10.0;
		roadbackward -= 10.0;
		if (roadbackward <= -70.0)// moving of run way
			roadbackward = 0.0;
	}
	if (key == GLUT_KEY_UP&&Ypos <= 400)
	{
		Ypos += 15.0;
		roadbackward -= 10.0;
		if (roadbackward <= -70.0)// moving of run way
			roadbackward = 0.0;
	}
	if (key == GLUT_KEY_DOWN&&Ypos>155)
	{
		Ypos -= 15.0;
		roadbackward -= 10.0;
		if (roadbackward <= -70.0)// moving of run way
			roadbackward = 0.0;
	}
	glutPostRedisplay();

}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (Ypos <= 150) {

		runway();

	}



	glPushMatrix();
	glTranslated(Xpos, Ypos, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);//rectangular body
	glVertex2f(0.0, 30.0);
	glVertex2f(0.0, 55.0);
	glVertex2f(135.0, 55.0);
	glVertex2f(135.0, 30.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(Xpos, Ypos, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);//upper triangle construction plane
	glVertex2f(135.0, 55.0);
	glVertex2f(150.0, 50.0);
	glVertex2f(155.0, 45.0);
	glVertex2f(160.0, 40.0);
	glVertex2f(135.0, 40.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(Xpos, Ypos, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);//outline of upper triangle plane
	glVertex2f(135.0, 55.0);
	glVertex2f(150.0, 50.0);
	glVertex2f(155.0, 45.0);
	glVertex2f(160.0, 40.0);
	glVertex2f(135.0, 40.0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslated(Xpos, Ypos, 0.0);
	glColor3f(0.4980392156862745, 0.1450980392156863, 0.007843137254902);
	glBegin(GL_POLYGON);//lower triangle
	glVertex2f(135.0, 40.0);
	glVertex2f(160.0, 40.0);
	glVertex2f(160.0, 37.0);
	glVertex2f(145.0, 30.0);
	glVertex2f(135.0, 30.0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslated(Xpos, Ypos, 0.0);
	glColor3f(0.4980392156862745, 0.1450980392156863, 0.007843137254902);
	glBegin(GL_POLYGON);//back wing
	glVertex2f(0.0, 55.0);
	glVertex2f(0.0, 80.0);
	glVertex2f(10.0, 80.0);
	glVertex2f(40.0, 55.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(Xpos, Ypos, 0.0);
	glColor3f(0.4980392156862745, 0.1450980392156863, 0.007843137254902);
	glBegin(GL_POLYGON);//left side wing
	glVertex2f(65.0, 55.0);
	glVertex2f(50.0, 70.0);
	glVertex2f(75.0, 70.0);
	glVertex2f(90.0, 55.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(Xpos, Ypos, 0.0);
	glColor3f(0.4980392156862745, 0.1450980392156863, 0.007843137254902);
	glBegin(GL_POLYGON);//rightside wing
	glVertex2f(70.0, 40.0);
	glVertex2f(100.0, 40.0);
	glVertex2f(80.0, 15.0);
	glVertex2f(50.0, 15.0);

	glEnd();
	glPopMatrix();

	if (Xpos>500.0)//window position during take off
	{
		Xpos = 0.0;
		roadbackward = 0.0;
	}
	glFlush();
	glutSwapBuffers();
}



void runway()
{

	glColor3f(0.2627, 0.3529, 0.4980392156862745);
	glBegin(GL_POLYGON);// road
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 100.0);
	glVertex2f(500.0, 100.0);
	glVertex2f(500.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(roadbackward, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);//white blocks on road
	glVertex2f(0.0, 40.0);
	glVertex2f(8.0, 60.0);
	glVertex2f(58.0, 60.0);
	glVertex2f(50.0, 40.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(roadbackward, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(100.0, 40.0);
	glVertex2f(108.0, 60.0);
	glVertex2f(158.0, 60.0);
	glVertex2f(150.0, 40.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(roadbackward, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(200.0, 40.0);
	glVertex2f(208.0, 60.0);
	glVertex2f(258.0, 60.0);
	glVertex2f(250.0, 40.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(roadbackward, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(300.0, 40.0);
	glVertex2f(308.0, 60.0);
	glVertex2f(358.0, 60.0);
	glVertex2f(350.0, 40.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(roadbackward, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(400.0, 40.0);
	glVertex2f(408.0, 60.0);
	glVertex2f(458.0, 60.0);
	glVertex2f(450.0, 40.0);
	glEnd();
	glPopMatrix();
}



void myinit()
{

	glClearColor(0.1176470588235294f, 0.5647058823529412f, 1.0f, 0.0f);

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);

}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800.0, 500.0);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Airplane simulator");
	glutDisplayFunc(display);
	myinit();

	glutTimerFunc(100, update, 0);
	glutSpecialFunc(keys);
	glutMainLoop();
	return 0;
}

