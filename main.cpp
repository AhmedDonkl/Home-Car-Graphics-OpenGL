#include <windows.h>
#include <gl\gl.h>
#include <GL\glut.h>
#include <cmath>

float theta = 0.0;     // angle to Open or Close house door
float gama = 0.0;      // angle to Open or Close house window
float omega = 0.0;     // angle to move the house left or right
float segma = 0.0;     // angle to move Car forward or backward
float beta = 0.0;      // angle to rotate Car wheels left or right
float alpha = 0.0;     // angle to move Car  front wheels
float delta = 0.0;     // angel to move the car arround the house .

void Init()
{
    glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1,1,-1,1,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}


void display()
{
     delta += 0.15;
     glutPostRedisplay(); // recall Display function
}

void myMouse(int mouse,int state,int x,int y)
{

     if(mouse == GLUT_LEFT_BUTTON)
     {
             glutIdleFunc(display);


     }
     if(mouse == GLUT_RIGHT_BUTTON)
     {
              glutIdleFunc(NULL);
     }
}

void myKey(unsigned char key,int x,int y)
{
     if(key == 'q')
     {
          exit(0);
     }
     else if(key == 'o')  // to open  the house door with suitable angle.
     {
          if(theta < 90)
          theta += 10;
          glutPostRedisplay();
     }
     else if(key == 'c')  // to close the house door with suitable angle.
     {
          if(theta > 0)
          theta -= 10;
          glutPostRedisplay();
     }

     else if(key == 'O')  // to open  the house window with suitable angle.
     {
           if(gama < 100)
          gama += 10;
          glutPostRedisplay();
     }
     else if(key == 'C')  // to Close  the house window with suitable angle.
     {
          if(gama > 0)
          gama -= 10;
          glutPostRedisplay();
     }

     else if(key == 'f')  // to move the car forward in X-axis direction.
     {
          segma += 0.03;
          glutPostRedisplay();
     }
     else if(key == 'b')  // to move the car backward in X-axis direction.
     {
          segma -= 0.03;
          glutPostRedisplay();
     }

     else if(key == 'l')  // to rotate right the car wheels [ rotate only ]
     {
          if(beta > -30)
          beta -= 5;
          glutPostRedisplay();
     }
     else if(key == 'r')  // to rotate left  the car wheels [ rotate only ]
     {
          if(beta < 60)
          beta += 5;
          glutPostRedisplay();
     }

     else if(key == 'L')  // to rotate right the car wheels [ transelate then rotate ]
     {
          if(alpha > -30)
          alpha -= 5;
          glutPostRedisplay();
     }
     else if(key == 'R')  // to rotate left  the car wheels [ transelate then rotate ]
     {
          if(alpha < 60)
          alpha += 5;
          glutPostRedisplay();
     }
}

void Display()

{   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
glPushMatrix();
glScalef( 0.8,0.8,0.7 );
glRotatef(5,0,1,0);

////////////////////////////////////////////////////////////////////////////////
///////////////////////////  House Object Draw  ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

///////////////////////       House roof     ///////////////////////////////////
        // front House Roof
        glPushMatrix();
        glRotatef(35,1,1,0);        // rotate the house by 30 on x,y to show 3D
        glBegin(GL_QUADS);
		glColor3f(1,0.5,0.2);
		glVertex3f(0.0,0.95,-0.1);
		glVertex3f(-0.43,0.65,-0.1);
		glVertex3f(0.43,0.65,-0.1);
		glVertex3f(0.0,0.95,-0.1);

	    // back  House Roof
		glColor3f(1,0.5,0.2);
		glVertex3f(0.0,0.95,-0.3);
		glVertex3f(-0.43,0.65,-0.3);
		glVertex3f(0.43,0.65,-0.3);
		glVertex3f(0.0,0.95,-0.3);

		// 3D left Roof
		glColor3f(1,0.5,0.2);
		glVertex3f(0.0,0.95,-0.1);
		glVertex3f(-0.43,0.65,-0.1);
		glVertex3f(-0.43,0.65,-0.3);
		glVertex3f(0.0,0.95,-0.3);

		// 3D right House Roof
		glColor3f(1,0.5,0.2);
		glVertex3f(0.43,0.65,-0.3);
		glVertex3f(0.0,0.95,-0.3);
		glVertex3f(0.0,0.95,-0.1);
		glVertex3f(0.43,0.65,-0.1);

/////////////////////////    House Body     ////////////////////////////////////
		// 3D front House Body
        glColor3f(0.2,0.3,0.7);
        glVertex3f(-0.43,0.65,-0.1);
		glVertex3f(0.43,0.65,-0.1);
		glVertex3f(0.43,-0.3,-0.1);
		glVertex3f(-0.43,-0.3,-0.1);

		// 3D back  House Body
        glColor3f(0.2,0.3,0.7);
        glVertex3f( -0.43,0.65,-0.3);
		glVertex3f( 0.43,0.65,-0.3);
		glVertex3f(0.43,-0.3,-0.3);
		glVertex3f(-0.43,-0.3,-0.3);

		// 3D down House Body
        glColor3f(0.2,0.3,0.7);
        glVertex3f( -0.43,0.65,-0.3);
		glVertex3f( 0.43,0.65,-0.3);
		glVertex3f( 0.43,0.65,-0.1);
		glVertex3f( -0.43,0.65,-0.1);

		// left House Body
        glColor3f(0.2,0.3,0.7);
        glVertex3f( -0.43,0.65,-0.1);
		glVertex3f( -0.43,0.65,-0.3);
		glVertex3f(-0.43,-0.3,-0.3);
		glVertex3f(-0.43,-0.3,-0.1);

		// Right House Body
		glColor3f(0.2,0.3,0.7);
		glVertex3f( 0.43,0.65,-0.1);
		glVertex3f( 0.43,0.65,-0.3);
		glVertex3f(0.43,-0.3,-0.3);
		glVertex3f(0.43,-0.3,-0.1);
        glEnd();
        glPopMatrix();

////////////////////////    House Window   /////////////////////////////////////
        // Left Closed Window
        glPushMatrix();
        glRotatef(35.5,1,1,0);      // rotate by 35 on x,y
        glTranslatef(-0.4,0,0);
        glRotatef(gama,0,-1,0);    // to open or close the house window  by gama
        glTranslatef(0.4,0,0);
        glBegin(GL_QUADS);
        glColor3f(1,0.7,0);
		glVertex3f(-0.25,0.35,0.0);
		glVertex3f(-0.25,0.55,0.0);
        glVertex3f(-0.4,0.55,0.0);
		glVertex3f(-0.4,0.35,0.0);
		glEnd();
        glPopMatrix();

        // Right Closed Window
        glPushMatrix();
        glRotatef(35,1,1,0);      // rotate by 35 on x,y
        glTranslatef(0.25,0,0);
        glRotatef(gama,0,1,0);    // to open or close the house window  by gama
        glTranslatef(-0.25,0,0);
        glBegin(GL_QUADS);
        glColor3f(1,0.7,0);
		glVertex3f(0.1,0.35,0.0);
		glVertex3f(0.1,0.55,0.0);
        glVertex3f(0.25,0.55,0.0);
        glVertex3f(0.25,0.35,0.0);
        glEnd();
        glPopMatrix();

        // Left Opend Window
        glPushMatrix();
        glRotatef(35,1,1,0);        // rotate by 35 on x,y
        glBegin(GL_QUADS);
        glColor3f(0,0,0);
		glVertex3f(-0.4,0.35,0.0);
		glVertex3f(-0.25,0.35,0.0);
		glVertex3f(-0.25,0.55,0.0);
        glVertex3f(-0.4,0.55,0.0);

        // Right Opend Window
        glColor3f(0,0,0);
		glVertex3f(0.25,0.35,0.0);
		glVertex3f(0.1,0.35,0.0);
		glVertex3f(0.1,0.55,0.0);
        glVertex3f(0.25,0.55,0.0);
        glEnd();
        glPopMatrix();

////////////////////////    House  Door    /////////////////////////////////////
        // house closed door
        glPushMatrix();
        glRotatef(35,1,1,0);     // rotate by 35 on x,y
        glRotatef(theta,0,1,0);  // to open  the house door by theta
        glBegin(GL_QUADS);
        glColor3f(1,0.7,0);
		glVertex3f(-0.15,0.22,0.0);
		glVertex3f(0.0,0.22,0.0);
		glVertex3f(0.0,-0.25,0.0);
		glVertex3f(-0.15,-0.25,0.0);
        glEnd();
        glPopMatrix();

		// house opened door
		glPushMatrix();
        glRotatef(35,1,1,0); // rotate by 35 on x,y
        glBegin(GL_QUADS);
        glColor3f(0,0,0);
		glVertex3f(-0.15,0.22,0.0);
		glVertex3f(0.0,0.22,0.0);
		glVertex3f(0.0,-0.25,0.0);
		glVertex3f(-0.15,-0.25,0.0);
		glEnd();
        glPopMatrix();




////////////////////////////////////////////////////////////////////////////////
///////////////////////////////  Car Object Draw  //////////////////////////////
////////////////////////////////////////////////////////////////////////////////

glTranslatef(0.2,0.0,0.3);   //  transelate the car on x , z axis
glScalef( 1.0,0.9,1.0 );     //  to control car size
glTranslatef(0, 0.4, 0.87);
glPushMatrix();
glTranslatef(0.0,0.4,-0.8);
glRotatef(delta,0,1,0.3);      // to move or stop the car arround the house.
glTranslatef(0.0,-0.40,0.8);

    glPushMatrix();
    glRotatef(-20,1,1,0);            // rotate by -20 on x , y
    glTranslatef(segma,0,0);
    glRotatef(segma,0,0,0);         //to move the car forward or backward in X-axis direction.


///////////////////////////////  Car body  /////////////////////////////////////
            // front Car Body
            glPushMatrix();
            glRotatef(35,1,1,0);          // rotate by 35 on x,y
            glBegin(GL_QUADS);
            glColor3f(0.7,0,0.3);
            glVertex3f( -0.16,-0.5,-0.01);
    		glVertex3f( 0.16,-0.5,-0.01);
    		glVertex3f(0.16,-0.75,-0.01);
    		glVertex3f(-0.16,-0.75,-0.01);

            // back Car Body
            glColor3f(0.7,0,0.3);
            glVertex3f( -0.16,-0.5,-0.15);
    		glVertex3f( 0.16,-0.5,-0.15);
    		glVertex3f(0.16,-0.75,-0.15);
    		glVertex3f(-0.16,-0.75,-0.15);

    		// right car body
    		glColor3f(0.7,0,0.3);
    		glVertex3f(0.16,-0.75,-0.01);
    		glVertex3f(0.16,-0.5,-0.01);
    		glVertex3f(0.55,-0.75,-0.01);
    		glVertex3f(0.16,-0.75,-0.01);

    		// back right car body
    		glColor3f(0.7,0,0.3);
    		glVertex3f(0.16,-0.75,-0.15);
    		glVertex3f(0.16,-0.5,-0.15);
    		glVertex3f(0.55,-0.75,-0.15);
    		glVertex3f(0.16,-0.75,-0.15);

    		// left car body
            glColor3f(0.7,0,0.3);
    		glVertex3f(-0.16,-0.75,-0.01);
    		glVertex3f(-0.16,-0.5,-0.01);
    		glVertex3f(-0.4,-0.75,-0.01);
    		glVertex3f(-0.16,-0.75,-0.01);

    		// back left car body
            glColor3f(0.7,0,0.3);
    		glVertex3f(-0.16,-0.75,-0.15);
    		glVertex3f(-0.16,-0.5,-0.15);
    		glVertex3f(-0.4,-0.75,-0.15);
    		glVertex3f(-0.16,-0.75,-0.15);

    		// top car body
    		glColor3f(0.4,0.6,0.9);
            glVertex3f( -0.16,-0.5,-0.15);
            glVertex3f( 0.16,-0.5,-0.15);
            glVertex3f( 0.16,-0.5,-0.01);
            glVertex3f( -0.16,-0.5,-0.01);

            // left top car
            glColor3f(0.4,0.6,0.9);
            glVertex3f( -0.16,-0.5,-0.15);
            glVertex3f( -0.16,-0.5,-0.01);
            glVertex3f(-0.4,-0.75,-0.01);
    		glVertex3f(-0.4,-0.75,-0.15);

    		// Right top car
            glColor3f(0.4,0.6,0.9);
            glVertex3f(0.16,-0.5,-0.15);
            glVertex3f(0.16,-0.5,-0.01);
            glVertex3f(0.55,-0.75,-0.01);
            glVertex3f(0.55,-0.75,-0.15);

            // front  down car body
            glColor3f(0.7,0,0.3);
            glVertex3f(-0.5,-0.75,-0.01);
    		glVertex3f(0.67,-0.75,-0.01);
    		glVertex3f(0.67,-0.88,-0.01);
    		glVertex3f(-0.5,-0.88,-0.01);

    		// back down car body
            glColor3f(0.7,0,0.3);
            glVertex3f(-0.5,-0.75,-0.15);
    		glVertex3f(0.67,-0.75,-0.15);
    		glVertex3f(0.67,-0.88,-0.15);
    		glVertex3f(-0.5,-0.88,-0.15);

   		    // right down car body
            glColor3f(0.7,0,0.3);
            glVertex3f(0.67,-0.75,-0.15);
    		glVertex3f(0.67,-0.88,-0.15);
    		glVertex3f(0.67,-0.88,-0.01);
    		glVertex3f(0.67,-0.75,-0.01);

    		// left down car body
            glColor3f(0.7,0,0.3);
            glVertex3f(-0.5,-0.75,-0.01);
    		glVertex3f(-0.5,-0.88,-0.01);
    		glVertex3f(-0.5,-0.88,-0.15);
    		glVertex3f(-0.5,-0.75,-0.15);

            // down car
            glColor3f(0.7,0,0.3);
    		glVertex3f(-0.5,-0.88,-0.15);
    		glVertex3f(0.67,-0.88,-0.15);
    		glVertex3f(0.67,-0.88,-0.01);
    		glVertex3f(-0.5,-0.88,-0.01);

            // front elkaboot
            glColor3f(0.4,0.6,0.9);
    		glVertex3f(0.55,-0.75,-0.01);
    		glVertex3f(0.55,-0.75,-0.15);
    		glVertex3f(0.67,-0.75,-0.15);
    		glVertex3f(0.67,-0.75,-0.01);

    		// back elkaboot
            glColor3f(0.4,0.6,0.9);
    		glVertex3f(-0.4,-0.75,-0.15);
    		glVertex3f(-0.4,-0.75,-0.01);
    		glVertex3f(-0.5,-0.75,-0.01);
    		glVertex3f(-0.5,-0.75,-0.15);


///////////////////////////////  Car doors & windows  //////////////////////////
            // back door
    		glColor3f(0.4,0.6,0.9);
            glVertex3f(-0.15,-0.74,-0.009);
    		glVertex3f(-0.03,-0.74,-0.009);
    		glVertex3f(-0.03,-0.88,-0.009);
    		glVertex3f(-0.15,-0.88,-0.009);

    		// front door
    		glColor3f(0.4,0.6,0.9);
            glVertex3f(0.03,-0.74,-0.009);
            glVertex3f(0.14,-0.74,-0.009);
    		glVertex3f(0.14,-0.88,-0.009);
            glVertex3f(0.03,-0.88,-0.009);

             // back window
    		glColor3f(0.4,0.6,0.9);
            glVertex3f(-0.15,-0.55,-0.0095);
    		glVertex3f(-0.03,-0.55,-0.0095);
    		glVertex3f(-0.03,-0.65,-0.0095);
    		glVertex3f(-0.15,-0.65,-0.0095);

    		// front window
            glColor3f(0.4,0.6,0.9);
            glVertex3f(0.03,-0.55,-0.0095);
            glVertex3f(0.14,-0.55,-0.0095);
    		glVertex3f(0.14,-0.65,-0.0095);
            glVertex3f(0.03,-0.65,-0.0095);
            glEnd();
            glPopMatrix();

///////////////////////////////  Car wheels  ///////////////////////////////////
            // right front Car wheel
            glPushMatrix();
            glColor3f(0,0,0);
            glTranslatef(0.17, -0.81, -0.47);
            glRotatef(alpha,0 , 1 , 0);
            glRotatef(beta,0 , 1 , 0);
            glutSolidTorus(0.03, 0.03, 3, 9);  // Draw car wheel
            glPopMatrix();

            // right back Car wheel
            glPushMatrix();
            glColor3f(0,0,0);
            glTranslatef(-0.21, -0.85, -0.3);
            glRotatef(beta,0 , 1 , 0);
            glutSolidTorus(0.03, 0.03, 3, 9);
            glPopMatrix();

            // left front Car wheel
            glPushMatrix();
            glColor3f(0,0,0);
            glTranslatef(0.2, -0.76, -0.63);
            glRotatef(alpha,0 , 1 , 0);
            glRotatef(beta,0 , 1 , 0);
            glutSolidTorus(0.03, 0.03, 3, 9);
            glPopMatrix();

            // left back Car wheel
            glPushMatrix();
            glColor3f(0,0,0);
            glTranslatef(-0.18, -0.78, -0.48);
            glRotatef(beta,0 , 1 , 0);
            glutSolidTorus(0.03, 0.03, 3, 9);
            glPopMatrix();


    glEnd();
    glPopMatrix();     //  closed push for moving the car forward or backward in X-axis direction.

glEnd();
glPopMatrix();        //  closed push for moving the car arround the house

glEnd();
        glPopMatrix();
    	glFlush();

}

static void
idle(void)
{
           glutPostRedisplay();    // recall display function
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(200,100);
	glutCreateWindow("OpenGL Window");
	//glutFullScreen();
	glutDisplayFunc(Display);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKey);
	glutIdleFunc(idle);
    Init();
	glutMainLoop();
	return 0;
}
