#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
void myInit();
void display1();
void road();
void mouse(int, int, int, int);
void move();
void building();
void wheel(int,int);
int iteration = 0;
//void keyboard(unsigned char, int x, int y);
void Specialkey(int key, int x, int y);
int flag = 0;
int x = 0, y = 0;
bool alternate = true;
int co = 1;
float xr = 0, yr = 0;
char instr[10000];
//string str;
int flagsec = 0;
int scorecount = 0;
float xx = 0, yy = 0;
float x0[4][2] = { { 30,16 },{ 30,30 },{ 0,60 },{ 0,75 } };
float x1[4][2] = { { 0,26 },{ 0,40 },{ 30,80 },{ 30,95 } };
//void idlefunc(int value);



void print(const char *a, float x, float y)//For displaying text on the screen at required position.
{
	glRasterPos2f(x, y);
	for (int i = 0; a[i] != '\0'; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, a[i]);
	}


}


void firstdisp()//Welcome text
{
	glClearColor(0.6, 0.6, 0.6, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.8, 0);
	glVertex2f(0, 0);
	glColor3f(0, 0.8, 0.5);
	glVertex2f(0, 100);
	glColor3f(0, 0.8, 0.5);
	glVertex2f(100, 0);


	glColor3f(0.6, 0.8, 0);
	glVertex2f(100, 100);
	glColor3f(0, 0.8, 0.5);
	glVertex2f(0, 100);
	glColor3f(0, 0.8, 0.5);
	glVertex2f(100, 0);
	glEnd();
	glFlush();

	glColor3f(0, 0, 0);
	print("CAR RACING GAME.", 40, 80);
	glBegin(GL_LINES);
	{
		glVertex2f(38, 78);
		glVertex2f(58, 78);
	}
	glEnd();
	print("RULES:-", 15, 70);
	print("*Player car will be of blue color.", 15, 60);
	print("*Player can drive his car using action keys.", 15, 65);
	print("*Player car should not collide with any other obstacle on the road.", 15, 55);
	print("*Obstacle car is of orange color.", 15, 50);
	glBegin(GL_LINE_LOOP);
	glVertex2f(24.5, 43);
	glVertex2f(24.5, 39);
	glVertex2f(68.5, 39);
	glVertex2f(68.5, 43);
	glEnd();
	print("PRESS ANY MOUSE BUTTON TO START THE GAME", 25, 40);
	print("Project By:", 60, 30);
	print("Richa Bhuwania", 68,26);
	print("1RN15CS087", 68, 22);
	glFlush();

}


void car(int x, int y)
{
	//road();
	glColor3f(0.0f, 0.2f, 0.8f);//Dark blue
	glBegin(GL_POLYGON);
	glVertex2f(x + 29, y + 0);
	glVertex2f(x + 35, y + 0);
	glVertex2f(x + 35, y + 8);
	glVertex2f(x + 34, y + 12);
	glVertex2f(x + 30, y + 12);
	glVertex2f(x + 29, y + 8);
	glEnd();
	glLineWidth(1);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 29, y + 0);
	glVertex2f(x + 31, y + 2);

	glVertex2f(x + 33, y + 2);

	glVertex2f(x + 33, y + 8);

	glVertex2f(x + 31, y + 8);
	glVertex2f(x + 31, y + 2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x + 33, y + 2);
	glVertex2f(x + 35, y + 0);

	glVertex2f(x + 33, y + 8);
	glVertex2f(x + 34, y + 12);

	glVertex2f(x + 31, y + 8);
	glVertex2f(x + 30, y + 12);
	glEnd();

	wheel(x, y);
	//wheel
	/*glColor3f(0, 0, 0);					//to draw afirst  wheel
	glPushMatrix();
	glTranslatef(x+29, y+2, 0);
	glRotatef(360, x + 29, y + 2, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 29, y + 2, 0);
	glutWireSphere(0.3, 20, 20);
	//glutSolidSphere(3, 50, 50);
	glPopMatrix();

	glColor3f(0, 0, 0);					//to draw a 2nd top  wheel
	glPushMatrix();
	glTranslatef(x + 29, y + 8, 0);
	glRotatef(360, x + 29, y + 8, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 29, y + 8, 0);
	glutWireSphere(0.3, 20, 20);
	//glutSolidSphere(3, 50, 50);
	glPopMatrix();
	glColor3f(0, 0, 0);					//to draw a 3rd  wheel
	glPushMatrix();
	glTranslatef(x + 35, y + 2, 0);
	glRotatef(360, x + 35, y + 2, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 35, y + 2, 0);
	glutWireSphere(0.3, 20, 20);
	//glutSolidSphere(3, 50, 50);
	glPopMatrix();

	glColor3f(0, 0, 0);					//to draw a 4th top  wheel
	glPushMatrix();
	glTranslatef(x + 35, y + 8, 0);
	glRotatef(360, x + 35, y + 8, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 35, y + 8, 0);
	glutWireSphere(0.3, 20, 20);
	//glutSolidSphere(3, 50, 50);
	glPopMatrix();*/

	glFlush();


}


void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}


void otherveh(int xv, int yv);

//void moveother(float x, float y);



void callotherveh()
{
	
	if (co == 0)
	{
		for (int j = 0; j < 4; j++)
		{
			//printf("co==0");
			//printf("%d and  %d", x0[j][0], x0[j][1]);
			otherveh(x0[j][0], x0[j][1]);
			//xm = x0[j][0];
			//ym = x0[j][1];
			//game();
			//moveother(xm,ym);
		}

	}
	if (co == 1)
	{
		for (int j = 0; j < 4; j++) {



			otherveh(x1[j][0], x1[j][1]);
			//xm = x0[j][0];
			//ym = x0[j][1];
			//game();
		}
	}
}



void Specialkey(int key, int x, int y)//allow to use navigation key for movement of car
{
	int i = 0;
	switch (key)
	{
	case GLUT_KEY_LEFT: xx = 0; car(xx, yy);

		move();

		break;
	case GLUT_KEY_RIGHT:xx = 30; car(xx, yy);

		move();

		break;
	case GLUT_KEY_UP:
		move();


		break;
	case GLUT_KEY_DOWN: move();



		break;

	}
}


void roadstrt(float x,float y)		//only road
{
	glClearColor(0.3, 0.3, 0.3, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 0, y + 0);
	glVertex2f(x + 20, y + 0);
	glVertex2f(x + 20, y + 100);
	glVertex2f(x + 0, y + 100);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 80, y + 0);
	glVertex2f(x + 100, y + 0);
	glVertex2f(x + 100, y + 100);
	glVertex2f(x + 80, y + 100);
	glEnd();

	//strip
	//glPointSize(1)
	glColor3f(1, 1, 1);
	glLineWidth(8);
	glBegin(GL_LINES);
	glVertex2f(x + 48, y + 0);
	glVertex2f(x + 48, y + 100);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x + 50, y + 0);
	glVertex2f(x + 50, y + 100);
	glEnd();
	//rule
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(83, 14);
	glVertex2f(83, 23);
	glVertex2f(96, 23);
	glVertex2f(96, 14);
	glEnd();
	glColor3f(1.0f, 0.0f, 1.0f);//Dark Purple
	print("<-- left  move", 84, 20);
	print("--> right move", 84, 15);
	building();
	callotherveh();
	
	
}


void boundary()		//second screen
{
	//callotherveh();
	//
	glClearColor(0.3, 0.3, 0.3, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 0, y + 0);
	glVertex2f(x + 20, y + 0);
	glVertex2f(x + 20, y + 100);
	glVertex2f(x + 0, y + 100);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 80, y + 0);
	glVertex2f(x + 100, y + 0);
	glVertex2f(x + 100, y + 100);
	glVertex2f(x + 80, y + 100);
	glEnd();

	//strip
	//glPointSize(1)
	glColor3f(1, 1, 1);
	glLineWidth(8);
	glBegin(GL_LINES);
	glVertex2f(x + 48, y + 0);
	glVertex2f(x + 48, y + 100);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x + 50, y + 0);
	glVertex2f(x + 50, y + 100);
	glEnd();
	callotherveh();
	car(0, 0);
	building();
	
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(35, 54);
	glVertex2f(35, 58);
	glVertex2f(62, 58);
	glVertex2f(62, 54);
	glEnd();
	glColor3f(1.0f, 0.0f, 1.0f);//Dark Purple
	print("PRESS R TO START THE GAME", 35.5, 55);


	//rules
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(59.5, 19);
	glVertex2f(59.5, 28);
	glVertex2f(72, 28);
	glVertex2f(72, 19);
	glEnd();
	glColor3f(1.0f, 0.0f, 1.0f);//Dark Purple
	print("<-- left  move", 60, 20);
	print("--> right move", 60, 25);


	//k1 = 1;

	glutSwapBuffers();

	glFlush();

}

void building()
{
	glColor3f(0.3f, 0.3f, 0.3f);	//lowest
	glBegin(GL_POLYGON);
	glVertex2f(0, 28);
	glVertex2f(8, 20);
	glVertex2f(8, 21);
	glVertex2f(1, 29);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.3f);	//2nd lowest
	glBegin(GL_POLYGON);
	glVertex2f(8, 20);
	glVertex2f(18, 22);
	glVertex2f(18, 23);
	glVertex2f(8, 21);
	glEnd();
	

	glColor3f(0.5f, 0.5f, 0.5f);		//middle bigger
	glBegin(GL_POLYGON);
	glVertex2f(0, 29);
	glVertex2f(3.5, 30);
	glVertex2f(3.5, 29);
	glVertex2f(3.5, 26);
	glVertex2f(5, 26);
	glVertex2f(8, 28);
	glVertex2f(11, 24);
	glVertex2f(14, 26);
	glVertex2f(14, 29);
	glVertex2f(18, 23);
	glVertex2f(8, 21);
	glEnd();

	glColor3f(0.4f, 0.4f, 0.4f);	//
	glBegin(GL_POLYGON);
	glVertex2f(3.5, 30);
	glVertex2f(3.5, 29);
	glVertex2f(3.5, 26);
	glVertex2f(5, 24);
	glVertex2f(8, 28);
	glVertex2f(11, 24);
	glVertex2f(14, 26);
	glVertex2f(14, 63);
	glVertex2f(11, 60);
	glVertex2f(8, 64);
	glVertex2f(5, 60);
	glVertex2f(3, 63);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.3f);	//top thinner 1st
	glBegin(GL_POLYGON);
	glVertex2f(3, 63);
	glVertex2f(5, 60);
	glVertex2f(5.5, 61);
	glVertex2f(4, 63);
	glEnd();


	glColor3f(0.3f, 0.3f, 0.3f);	//top thinner 2nd
	glBegin(GL_POLYGON);
	glVertex2f(5, 60);
	glVertex2f(8, 64);
	glVertex2f(8, 65);
	glVertex2f(5.5, 61);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.3f);	//top thinner 3nd
	glBegin(GL_POLYGON);
	glVertex2f(8, 64);
	glVertex2f(11, 60);
	glVertex2f(11, 61);
	glVertex2f(8, 65);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.3f);	//top thinner 2nd
	glBegin(GL_POLYGON);
	glVertex2f(11, 60);
	glVertex2f(14, 63);
	glVertex2f(13, 63);
	glVertex2f(11, 61);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.3f);	//top thinner 2nd
	glBegin(GL_POLYGON);
	glVertex2f(13, 63);
	glVertex2f(14, 63);
	glVertex2f(8, 70);
	glVertex2f(8, 69);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.3f);	//top thinner 2nd
	glBegin(GL_POLYGON);
	glVertex2f(8, 69);
	glVertex2f(8, 70);
	glVertex2f(3, 63);
	glVertex2f(4, 63);
	glEnd();

	glColor3f(0.5f, 0.5f, 0.5f);	//top middle
	glBegin(GL_POLYGON);
	glVertex2f(4, 63);
	glVertex2f(5.5, 61);
	glVertex2f(7.5, 65);
	glVertex2f(11, 61);
	glVertex2f(13, 63);
	glVertex2f(8, 69);

	glEnd();

	//down door
	glLineWidth(2);
	glColor3f(0.3f, 0.3f, 0.3f);	//top thinner 2nd
	glBegin(GL_LINE_LOOP);
	glVertex2f(3.5, 26);
	glVertex2f(5, 24);
	glVertex2f(5, 30);
	glVertex2f(3.5, 29);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.3f);	//top thinner 2nd
	glBegin(GL_LINE_LOOP);
	glVertex2f(5, 24);
	glVertex2f(7.5, 27);
	glVertex2f(7.5, 31);
	glVertex2f(5, 30);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.3f);	//top thinner 2nd
	glBegin(GL_LINE_LOOP);
	glVertex2f(7.5, 27);
	glVertex2f(11, 24);
	glVertex2f(11, 30);
	glVertex2f(7.5, 31);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.3f);	//top thinner 2nd
	glBegin(GL_LINE_LOOP);
	glVertex2f(11, 24);
	glVertex2f(14, 26);
	glVertex2f(14, 31);
	glVertex2f(11, 30);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.3f);	//door
	glBegin(GL_LINE_LOOP);
	glVertex2f(12, 24.5);
	glVertex2f(12, 29);
	glVertex2f(13, 29);
	glVertex2f(13, 25.1);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.3f);	//lines vertical
	glBegin(GL_LINES);
	glVertex2f(5, 30);
	glVertex2f(5, 60);
	glVertex2f(7.5, 31);
	glVertex2f(7.5, 62.3);
	glVertex2f(11, 30);
	glVertex2f(11, 60);

	//hoz line
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(3, 59);
	glVertex2f(5, 59);
	glVertex2f(3.3, 57);
	glVertex2f(5, 57);
	glVertex2f(3.3, 55);
	glVertex2f(5, 55);
	glVertex2f(3.4, 53);
	glVertex2f(5, 53);
	glVertex2f(3.4, 51);
	glVertex2f(5, 51);
	glVertex2f(3.4, 49);
	glVertex2f(5, 49);
	glVertex2f(3.4, 47);
	glVertex2f(5, 47);
	glVertex2f(3.5, 45);
	glVertex2f(5, 45);
	glVertex2f(3.5, 43);
	glVertex2f(5, 43);
	glVertex2f(3.5, 41);
	glVertex2f(5, 41);
	glVertex2f(3.5, 39);
	glVertex2f(5, 39);
	glVertex2f(3.5, 37);
	glVertex2f(5, 37);
	glVertex2f(3.5, 35);
	glVertex2f(5, 35);
	glVertex2f(3.5, 33);
	glVertex2f(5, 33);


	glVertex2f(7.5, 62);
	glVertex2f(5, 59);
	glVertex2f(7.5, 60);
	glVertex2f(5, 57);
	glVertex2f(7.5, 58);
	glVertex2f(5, 55);
	glVertex2f(7.5, 56);
	glVertex2f(5, 53);
	glVertex2f(7.5, 54);
	glVertex2f(5, 51);
	glVertex2f(7.5, 52);
	glVertex2f(5, 49);
	glVertex2f(7.5, 50);
	glVertex2f(5, 47);
	glVertex2f(7.5, 48);
	glVertex2f(5, 45);
	glVertex2f(7.5, 46);
	glVertex2f(5, 43);
	glVertex2f(7.5, 44);
	glVertex2f(5, 41);
	glVertex2f(7.5, 42);
	glVertex2f(5, 39);
	glVertex2f(7.5, 40);
	glVertex2f(5, 37);
	glVertex2f(7.5, 38);
	glVertex2f(5, 35);
	glVertex2f(7.5, 36);
	glVertex2f(5, 33);


	glVertex2f(7.5, 62);
	glVertex2f(11, 59);
	glVertex2f(7.5, 60);
	glVertex2f(11, 57);
	glVertex2f(7.5, 58);
	glVertex2f(11, 55);
	glVertex2f(7.5, 56);
	glVertex2f(11, 53);
	glVertex2f(7.5, 54);
	glVertex2f(11, 51);
	glVertex2f(7.5, 52);
	glVertex2f(11, 49);
	glVertex2f(7.5, 50);
	glVertex2f(11, 47);
	glVertex2f(7.5, 48);
	glVertex2f(11, 45);
	glVertex2f(7.5, 46);
	glVertex2f(11, 43);
	glVertex2f(7.5, 44);
	glVertex2f(11, 41);
	glVertex2f(7.5, 42);
	glVertex2f(11, 39);
	glVertex2f(7.5, 40);
	glVertex2f(11, 37);
	glVertex2f(7.5, 38);
	glVertex2f(11, 35);
	glVertex2f(7.5, 36);
	glVertex2f(11, 33);
	//4th horizontal line

	glVertex2f(14, 62);
	glVertex2f(11, 59);
	glVertex2f(14, 60);
	glVertex2f(11, 57);
	glVertex2f(14, 58);
	glVertex2f(11, 55);
	glVertex2f(14, 56);
	glVertex2f(11, 53);
	glVertex2f(14, 54);
	glVertex2f(11, 51);
	glVertex2f(14, 52);
	glVertex2f(11, 49);
	glVertex2f(14, 50);
	glVertex2f(11, 47);
	glVertex2f(14, 48);
	glVertex2f(11, 45);
	glVertex2f(14, 46);
	glVertex2f(11, 43);
	glVertex2f(14, 44);
	glVertex2f(11, 41);
	glVertex2f(14, 42);
	glVertex2f(11, 39);
	glVertex2f(14, 40);
	glVertex2f(11, 37);
	glVertex2f(14, 38);
	glVertex2f(11, 35);
	glVertex2f(14, 36);
	glVertex2f(11, 33);


	//horizontal lines

	glEnd();

	//after some gap building



	//2nd build right side

	glColor3f(0.7f, 0.7f, 0.7f);	//bottom left
	glBegin(GL_POLYGON);
	glVertex2f(84, 60);
	//glVertex2f(83.5, 58);
	glVertex2f(83.5, 50);
	glVertex2f(87, 40);
	glVertex2f(87, 50);
	glEnd();

	glColor3f(0.7f, 0.7f, 0.7f);	//bottom right
	glBegin(GL_POLYGON);
	glVertex2f(87, 40);
	glVertex2f(87, 50);
	glVertex2f(96, 55);
	glVertex2f(96, 45);
	//glVertex2f(87, 50);
	glEnd();

	glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
	glBegin(GL_POLYGON);
	glVertex2f(83.8, 61);
	glVertex2f(83.8, 62);
	glVertex2f(87, 50);
	glVertex2f(87, 51);
	//glVertex2f(87, 50);
	glEnd();

	glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
	glBegin(GL_POLYGON);
	glVertex2f(87, 50);
	glVertex2f(87, 51);
	glVertex2f(96, 56);
	glVertex2f(96, 55);
	//glVertex2f(87, 50);
	glEnd();

	glColor3f(0.7f, 0.7f, 0.7f);	//bottom right
	glBegin(GL_POLYGON);
	glVertex2f(84.5, 63);
	glVertex2f(84, 61);
	glVertex2f(87, 51);
	glVertex2f(96, 56);
	glVertex2f(96, 56);
	glVertex2f(95.5, 60);
	glVertex2f(87,56);
	//glVertex2f(87, 50);
	glEnd();

	glColor3f(0.0f, 0.5f, 1.0f);//baby Blue  middle left
	glBegin(GL_POLYGON);
	glVertex2f(83.5, 65);
	glVertex2f(83.5, 64);
	glVertex2f(87, 56);
	glVertex2f(87, 57);
	//glVertex2f(87, 50);
	glEnd();

	glColor3f(0.0f, 0.5f, 1.0f);//baby Blue	middle right
	glBegin(GL_POLYGON);
	glVertex2f(87, 57);
	glVertex2f(87, 56);
	glVertex2f(96.5, 59);
	glVertex2f(96.5, 60);
	//glVertex2f(87, 50);
	glEnd();

	glColor3f(0.7f, 0.7f, 0.7f);	//TOP right
	glBegin(GL_POLYGON);
	glVertex2f(85, 68);
	glVertex2f(83.5, 65);
	glVertex2f(86, 60);
	glVertex2f(96, 62);
	glVertex2f(95, 68);
	glVertex2f(96.5, 60);
	glVertex2f(87, 57);
	glVertex2f(84.5, 67);

	//glVertex2f(87, 50);
	glEnd();


	glColor3f(0.7f, 0.7f, 0.7f);	//middle 
	glBegin(GL_LINES);
	glVertex2f(85, 68);
	glVertex2f(83.5, 65);
	glVertex2f(96.5, 60);
	glVertex2f(95, 68);
	
	//glVertex2f(87, 50);
	glEnd();


	glColor3f(0.4f, 0.4f, 0.4f);	//TOP LEFT
	glBegin(GL_POLYGON);
	glVertex2f(85, 74);
	glVertex2f(85, 65);
	glVertex2f(88, 60);
	glVertex2f(88, 68);

	//glVertex2f(87, 50);
	glEnd();

	glColor3f(0.4f, 0.4f, 0.4f);	//TOP right
	glBegin(GL_POLYGON);
	glVertex2f(88, 60);
	glVertex2f(88, 68);
	glVertex2f(96, 70);
	glVertex2f(96,62);

	//glVertex2f(87, 50);
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);//Brown;//Bronze	//TOP right
	glBegin(GL_POLYGON);
	glVertex2f(85, 74);
	glVertex2f(88, 68);
	glVertex2f(96, 70);
	glVertex2f(93, 76);

	//glVertex2f(87, 50);
	glEnd();



	glColor3f(0.0f, 0.0f, 0.0f);//door
	glBegin(GL_LINES);
	glVertex2f(89.5, 41.5);
	glVertex2f(89.5, 47);

	glVertex2f(89.5, 47);
	glVertex2f(91.5, 49);

	glVertex2f(91.5, 49);
	glVertex2f(91.5, 42.3);
	

	//glVertex2f(87, 50);
	glEnd();
	//helipad
	glColor3f(0, 0, 0);					//to draw afirst  wheel
	glPushMatrix();
	glTranslatef(90.5, 72, 0);
	glRotatef(360, 90.5, 72, 0);
	glutSolidSphere(2.5, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(90.5, 72,  0);
	glutWireSphere(2.5, 20, 20);
	//glutSolidSphere(3, 50, 50);
	glPopMatrix();

	//H

	glBegin(GL_LINES);
	glVertex2f(89.5, 73.5);
	glVertex2f(89.5, 70.5);

	glVertex2f(89.5, 72.0);
	glVertex2f(91.5, 72.0);

	glVertex2f(91.5, 73.5);
	glVertex2f(91.5, 70.5);
	glEnd();


	//rule condtn
	



	glFlush();
}

void game()
{
	glColor3f(0, 1, 1);
	if (co == 0)
	{
		if (xx >= 0 && xx < 12)
		{
			if (yy >= 60 && yy <= 75)
			{
				glColor3f(0, 0, 0);
				glBegin(GL_POLYGON);
				glVertex2f(42, 49);
				glVertex2f(42, 63);
				glVertex2f(58, 63);
				glVertex2f(58, 49);
				glEnd();
				glColor3f(0, 1, 1);
				print("Opppss!!!!", 45.5, 60);
				print("GAME OVER", 44, 55);
				print("Your SCORE is:", 43, 50);
				print(instr, 55, 50);
				glutSwapBuffers();
				glFlush();
				for (long z = 0; z < 1000000000; z++);
				exit(0);
			}
		}
		if (xx >= 30 && xx <= 52)
		{
			if (yy >= 16 && yy <= 42)
			{
				glColor3f(0, 0, 0);
				glBegin(GL_POLYGON);
				glVertex2f(42, 49);
				glVertex2f(42, 63);
				glVertex2f(58, 63);
				glVertex2f(58, 49);
				glEnd();
				glColor3f(0, 1, 1);
				print("Opppss!!!!", 45.5, 60);
				print("GAME OVER", 44, 55);
				print("Your SCORE is:", 43, 50);
				print(instr, 55, 50);
				glutSwapBuffers();
				glFlush();
				for (long z = 0; z < 1000000000; z++);
				exit(0);

			}
		}
	}
	if (co == 1)
	{
		if (xx >= 0 && xx < 12)
		{
			if (yy >= 26 && yy <= 52)
			{
				glColor3f(0, 0, 0);
				glBegin(GL_POLYGON);
				glVertex2f(42, 49);
				glVertex2f(42, 63);
				glVertex2f(58, 63);
				glVertex2f(58, 49);
				glEnd();
				glColor3f(0, 1, 1);
				print("Opppss!!!!", 45.5, 60);
				print("GAME OVER", 44, 55);
				print("Your SCORE is:", 43, 50);
				print(instr, 55, 50);
				glutSwapBuffers();
				glFlush();
				for (long z = 0; z < 1000000000; z++);
				exit(0);

			}
		}
		if (xx >= 30 && xx <= 52)
		{
			if (yy >= 80 && yy <= 100)
			{
				glColor3f(0, 0, 0);
				glBegin(GL_POLYGON);
				glVertex2f(42, 49);
				glVertex2f(42, 63);
				glVertex2f(59, 63);
				glVertex2f(59, 49);
				glEnd();
				glColor3f(0, 1, 1);
				print("Opppss!!!!", 45.5, 60);
				print("GAME OVER", 44, 55);
				print("Your SCORE is:", 43, 50);
				print(instr, 55, 50);
				glutSwapBuffers();
				glFlush();
				for (long z = 0; z < 1000000000; z++);
				exit(0);

			}
		}
	}
	iteration += 1;
	if (iteration >= 1000000)
	{
		glColor3f(0, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(39, 49);
		glVertex2f(39, 63);
		glVertex2f(61, 63);
		glVertex2f(61, 49);
		glEnd();
		glColor3f(0, 1, 1);
		print("CONGRATULATIONS!!!!", 40, 60);
		print("YOU WON", 44, 55);
		print("Your SCORE is:", 40,50 );
		print(instr, 52,50 );
		//glutSwapBuffers();
		//glFlush();
		glutSwapBuffers();
		glFlush();
		for (long z = 0; z < 1000000000; z++);
		exit(0);


	}
}


void move()
{
	int i;
	roadstrt(xr, yr);



	//glLoadIdentity();
	for (i = 0; i < 50; i++)
	{
		glClearColor(0.3, 0.3, 0.3, 0.5);
		glClear(GL_COLOR_BUFFER_BIT);
		//yr += 0.01;
		//if (yr >= 100)
		//	yr = 0;
		roadstrt(xr, yr);
		//overpos();
		//otherveh(xv, yv);
		xx = xx;
		yy = yy + 0.25;

		if (yy >= 100)
		{
			yy = 0;
			//callotherveh();
			if (alternate == true)
			{
				co = 0;
				alternate = false;
			}
			if (alternate == true)
			{
				co = 1;
				alternate = true;
			}




		}
		scorecount += 1;
		glColor3f(0, 0, 0);
		
		print("SCORE:", 9, 85);
		//itoa(scorecount,instr,10);
		snprintf(instr, 10, "%d", scorecount);
		print(instr, 16, 85);
		car(xx, yy);
		game();
		if (xx < 0)
			xx = 0;
		if (xx > 75)
			xx = 30;
		car(xx, yy);
		game();
		glutSwapBuffers();
		glFlush();
		//glutSpecialFunc(Specialkey);

	}
}
void road()
{
	//printf("in road");
	glClearColor(0.3, 0.3, 0.3, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 0, y + 0);
	glVertex2f(x + 20, y + 0);
	glVertex2f(x + 20, y + 100);
	glVertex2f(x + 0, y + 100);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 80, y + 0);
	glVertex2f(x + 100, y + 0);
	glVertex2f(x + 100, y + 100);
	glVertex2f(x + 80, y + 100);
	glEnd();

	//strip
	//glPointSize(1)
	glColor3f(1, 1, 1);
	glLineWidth(8);
	glBegin(GL_LINES);
	glVertex2f(x + 48, y + 0);
	glVertex2f(x + 48, y + 100);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x + 50, y + 0);
	glVertex2f(x + 50, y + 100);
	glEnd();
	

	callotherveh();
	move();
	glutSwapBuffers();
	glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
	//printf("out of key");
	if (key == 'r' || key == 'R')
	{
		flagsec = 1;
		//printf("in of key");
		road();
		//k1 = 1;
		//display();
		//move()glColor3f(1, 0, 0);

	}
}
void wheel(int x, int y)
{
	glColor3f(0, 0, 0);					//to draw afirst  wheel
	glPushMatrix();
	glTranslatef(x + 29, y + 2, 0);
	glRotatef(360, x + 29, y + 2, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 29, y + 2, 0);
	glutWireSphere(0.3, 20, 20);
	//glutSolidSphere(3, 50, 50);
	glPopMatrix();

	glColor3f(0, 0, 0);					//to draw a 2nd top  wheel
	glPushMatrix();
	glTranslatef(x + 29, y + 8, 0);
	glRotatef(360, x + 29, y + 8, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 29, y + 8, 0);
	glutWireSphere(0.3, 20, 20);
	//glutSolidSphere(3, 50, 50);
	glPopMatrix();
	glColor3f(0, 0, 0);					//to draw a 3rd  wheel
	glPushMatrix();
	glTranslatef(x + 35, y + 2, 0);
	glRotatef(360, x + 35, y + 2, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 35, y + 2, 0);
	glutWireSphere(0.3, 20, 20);
	//glutSolidSphere(3, 50, 50);
	glPopMatrix();

	glColor3f(0, 0, 0);					//to draw a 4th top  wheel
	glPushMatrix();
	glTranslatef(x + 35, y + 8, 0);
	glRotatef(360, x + 35, y + 8, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 35, y + 8, 0);
	glutWireSphere(0.3, 20, 20);
	//glutSolidSphere(3, 50, 50);
	glPopMatrix();
}
void otherveh(int x, int y)
{
	glColor3f(1.0f, 0.5f, 0.0f);//Orange
	glBegin(GL_POLYGON);
	glVertex2f(x + 29, y + 0);
	glVertex2f(x + 35, y + 0);
	glVertex2f(x + 35, y + 8);
	glVertex2f(x + 34, y + 12);
	glVertex2f(x + 30, y + 12);
	glVertex2f(x + 29, y + 8);
	glEnd();
	glLineWidth(1);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 29, y + 0);
	glVertex2f(x + 31, y + 2);


	glVertex2f(x + 33, y + 2);

	glVertex2f(x + 33, y + 8);
	//	glVertex2f(x + 34, y + 2);

	glVertex2f(x + 31, y + 8);
	glVertex2f(x + 31, y + 2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x + 33, y + 2);
	glVertex2f(x + 35, y + 0);

	glVertex2f(x + 33, y + 8);
	glVertex2f(x + 34, y + 12);

	glVertex2f(x + 31, y + 8);
	glVertex2f(x + 30, y + 12);
	glEnd();
	//moveother(xv, yv);
	wheel(x, y);
	
	glFlush();

}
void mouse(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("flag");
		flag = 1;
		boundary();

	}
	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
		flag = 1; boundary();
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		flag = 1; boundary();
	}
}
void display1()
{
	if (flag == 0)
	{
		firstdisp();
		glutSwapBuffers();
		glFlush();
	}
}
void idlefunc(int value)
{
	yy += 0.1;
	if (yy >= 100)
		yy = 0;

	glutTimerFunc(100, idlefunc, 80);
	if (flag == 0)
	{
		glutPostRedisplay();
	}

	if (flagsec != 0)
	{
		move();
	}
	//glutPostRedisplay();


}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1500, 900);
	glutCreateWindow("CAR RACING");
	myInit();
	flag = 0;
	glutDisplayFunc(display1);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(Specialkey);
	//glutKeyboardFunc(Normalkey);

	glutTimerFunc(100, idlefunc, 80);
	glutMainLoop();
	return 0;

}
