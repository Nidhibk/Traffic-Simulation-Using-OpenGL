#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<GL/glut.h>
#include <math.h>>
#define SPEED 1
#define PI 3.141592653589

float x = -500.0;

int light = 0;
int day = 1;
int d, flag = 0;
static float movy,movx = 40;
int flag1=0;
float q=0.0;
float hz,cz,lz=0;



void draw_pixel(GLint cx, GLint cy)
{
    glBegin(GL_POINTS);
    glVertex2i(cx, cy);
    glPointSize(6);
    glEnd();
}


void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
    draw_pixel(x + h, y + k);
    draw_pixel(-x + h, y + k);
    draw_pixel(x + h, -y + k);
    draw_pixel(-x + h, -y + k);
    draw_pixel(y + h, x + k);
    draw_pixel(-y + h, x + k);
    draw_pixel(y + h, -x + k);
    draw_pixel(-y + h, -x + k);
    glPointSize(6);
}


void draw_circle(GLint h, GLint k, GLint r)
{
    GLint D = 1 - r, x = 0, y = r;
    while (y > x)
    {
        plotpixels(h, k, x, y);
        if (D < 0)
            D += 2 * x + 3;
        else
        {
            D += 2 * (x - y) + 5;
            --y;
        }
        ++x;
    }
    plotpixels(h, k, x-10, y-10);
}
void drawCircle(GLfloat x, GLfloat y,	GLfloat r, GLfloat g, GLfloat b,	GLfloat sx, GLfloat sy,	GLfloat radius)
{
		glPushMatrix();

		glTranslatef(x, y, 0);
		glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
		glColor3ub(r, g, b);
    for (GLfloat i = 0; i < 360; i += 5)glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();

		glPopMatrix();
}
void drawSemiCircle(GLfloat tx, GLfloat ty,	GLfloat sx, GLfloat sy,	GLfloat r, GLfloat g, GLfloat b,	GLfloat radius,
	GLfloat start_angle, GLfloat end_angle) {
		glPushMatrix();

		glTranslatef(tx, ty, 0);
		glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
		glColor3ub(r, g, b);
    for (GLfloat i = start_angle; i < end_angle; i += 5) glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();

		glPopMatrix();
}

void drawSchoolBoy(GLfloat tx, GLfloat ty,	GLfloat sx, GLfloat sy,	GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b){
	glPushMatrix();

	glScalef(sx, sy, 0);
	glTranslatef(tx, ty, 0);

	// Shoes
	drawSemiCircle(1160, 120,1, 1,255, 255, 255,10,-90, 91);

	// Shoe Extension
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(1160, 120);
	glVertex2f(1170, 120);
	glVertex2f(1170, 135);
	glVertex2f(1160, 135);
	glEnd();

	// Pants
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 200);
	glVertex2f(1158, 135);
	glVertex2f(1172, 135);
	glVertex2f(1170, 190);
	glVertex2f(1160, 190);
	glEnd();

	// Shirt
	glBegin(GL_POLYGON);
	glColor3ub(shirt_r, shirt_g, shirt_b);
	glVertex2f(1155, 190);
	glVertex2f(1170, 190);
	glVertex2f(1170, 260);
	glVertex2f(1160, 260);
	glEnd();

	// Bag
	glBegin(GL_POLYGON);
	glColor3ub(156, 86, 47);
	glVertex2f(1170, 250);
	glVertex2f(1180, 245);
	glVertex2f(1185, 200);
	glVertex2f(1170, 195);
	glEnd();

	// Head
	drawCircle(1164, 273,232, 190, 123,1, 1.4,12);

	// Hair
	drawSemiCircle(1167, 277,1, 1,0, 0, 0,14,-80, 180);

	// Nose
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 190, 123);
	glVertex2f(1155, 270);
	glVertex2f(1152, 260);
	glVertex2f(1157, 262);
	glEnd();

	// Eye
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3ub(0, 0, 0);
	glVertex2f(1156, 270);
	glEnd();
	glPointSize(1);

	// Lips
	glPointSize(1);
	glBegin(GL_POINTS);
	glColor3ub(0, 0, 0);
	glVertex2f(1158, 256);
	glVertex2f(1159, 257);
	glVertex2f(1160, 258);
	glEnd();
	glPointSize(6);

	glPopMatrix();
}
void drawhut()
{
    //house
glColor3f(0.3, 0.5, 0.8);

glBegin(GL_POLYGON);

glVertex2f(200, 500);

glVertex2f(600, 500);

glVertex2f(700, 350);

glVertex2f(300, 350);

glEnd();

// Top of Front Wall

glColor3f(0.1, 0.5, 0.0);

glBegin(GL_TRIANGLES);

glVertex2f(200, 500);

glVertex2f(100, 350);

glVertex2f(300, 350);

glEnd();

// Front Wall

glColor3f(0.7, 0.2, 0.3);

glBegin(GL_POLYGON);

glVertex2f(100, 350);

glVertex2f(300, 350);

glVertex2f(300, 100);

glVertex2f(100, 100);

glEnd();

// Front Door

glColor3f(0.7, 0.2, 0.9);

glBegin(GL_POLYGON);

glVertex2f(150, 250);

glVertex2f(250, 250);

glVertex2f(250, 100);

glVertex2f(150, 100);

glEnd();


// Front Door Lock

glColor3f(0.3, 0.7, 0.9);


glVertex2f(170, 170);

glEnd();


//side Wall

glColor3f(0.1, 0.2, 0.3);

glBegin(GL_POLYGON);

glVertex2f(300, 350);

glVertex2f(700, 350);

glVertex2f(700, 100);

glVertex2f(300, 100);

glEnd();

// window one
if(day==1)
{



glColor3f(0.2, 0.4, 0.3);
}
else
{
    glColor3f(1.0, 1.0, 0.0);
}
glBegin(GL_POLYGON);

glVertex2i(330, 320);

glVertex2i(450, 320);

glVertex2i(450, 230);

glVertex2i(330, 230);

glEnd();

// line of window one

glColor3f(0.1, 0.7, 0.5);

glLineWidth(5);

glBegin(GL_LINES);

glVertex2i(390, 320);

glVertex2i(390, 230);

glVertex2i(330, 273);

glVertex2i(450, 273);

glEnd();

if(day==1)
{



glColor3f(0.2, 0.4, 0.3);
}
else
{
    glColor3f(1.0, 1.0, 0.0);
}

glBegin(GL_POLYGON);

glVertex2i(530, 320);

glVertex2i(650, 320);

glVertex2i(650, 230);

glVertex2i(530, 230);

glEnd();

// lines of window two

glColor3f(0.1, 0.7, 0.5);

glLineWidth(5);

glBegin(GL_LINES);

glVertex2i(590, 320);

glVertex2i(590, 230);

glVertex2i(530, 273);

glVertex2i(650, 273);

glEnd();


// Entrance Path




}
void draw_object()
{

    if (day == 1)
    {

        glColor3f(0.15, 0.86, 0.88);
        glBegin(GL_POLYGON);
        glVertex2f(0, 400);
        glVertex2f(0, 700);
        glVertex2f(1000, 700);
        glVertex2f(1000, 400);
        glEnd();







        for (d = 0; d <= 30; d++)
        {
            glColor3f(0.96, 0.27, 0.13);
            draw_circle(875+q, 625, d);
        }



        for (d = 0; d <= 25; d++)
        {   glPushMatrix();
            glColor3f(1.0, 1.0, 1.0);
            glTranslatef(0-q/4,0,0);
            draw_circle(75, 615, d);
            draw_circle(115, 635, d);
            draw_circle(100, 590, d);
            draw_circle(130, 590, d);
            draw_circle(160, 615, d);
            glPopMatrix();

        }
        for (d = 0; d <= 25; d++)
        {glPushMatrix();
        glColor3f(1,1,1);


            glTranslatef(400-q/4,0,0);
            draw_circle(75, 615, d);
            draw_circle(115, 635, d);
            draw_circle(100, 590, d);
            draw_circle(130, 590, d);
            draw_circle(160, 615, d);
            glPopMatrix();

        }
    }
    else
    {
        glPushMatrix();

        glTranslatef(100,0,0);
        drawhut();
        glPopMatrix();


        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0, 400);
        glVertex2f(0, 700);
        glVertex2f(1000, 700);
        glVertex2f(1000, 400);
        glEnd();



        for (d = 0; d <= 30; d++)
        {
            glColor3f(1.0, 1.0, 1.0);
            draw_circle(100, 625, d);
        }

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(520, 630);
        glVertex2f(534, 630);
        glVertex2f(527, 644);
        glVertex2f(520, 639);
        glVertex2f(534, 639);
        glVertex2f(527, 625);
        glEnd();



        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(250, 550);
        glVertex2f(264, 550);
        glVertex2f(257, 564);
        glVertex2f(250, 559);
        glVertex2f(264, 559);
        glVertex2f(257, 545);
        glEnd();



        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(320, 680);
        glVertex2f(334, 680);
        glVertex2f(327, 694);
        glVertex2f(320, 689);
        glVertex2f(334, 689);
        glVertex2f(327, 675);
        glEnd();



        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(640, 600);
        glVertex2f(654, 600);
        glVertex2f(647, 614);
        glVertex2f(640, 609);
        glVertex2f(654, 609);
        glVertex2f(647, 595);
        glEnd();



        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(770, 520);
        glVertex2f(784, 520);
        glVertex2f(777, 534);
        glVertex2f(770, 529);
        glVertex2f(784, 529);
        glVertex2f(777, 515);
        glEnd();



        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(900, 590);
        glVertex2f(914, 590);
        glVertex2f(907, 604);
        glVertex2f(900, 599);
        glVertex2f(914, 599);
        glVertex2f(907, 585);
        glEnd();




    }





    glColor3f(0.24, 0.79, 0.27);
    glBegin(GL_POLYGON);
    glVertex2f(0, 200);
    glVertex2f(0, 400);
    glVertex2f(1000, 400);
    glVertex2f(1000, 200);
    glEnd();





    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(0, 200);
    glVertex2f(1000, 200);
    glVertex2f(1000, 0);
    glEnd();







    glColor3f(0.81, 0.60, 0.28);
    glBegin(GL_POLYGON);
    glVertex2f(50+q, 200);
    glVertex2f(50+q, 500);
    glVertex2f(250+q, 500);
    glVertex2f(250+q, 200);
    glEnd();


    glColor3f(0.52, 0.63, 0.60);
    glBegin(GL_POLYGON);
    glVertex2f(75+q, 375);
    glVertex2f(75+q, 450);
    glColor3f(0.19, 0.29, 0.26);
    glVertex2f(150+q, 450);
    glVertex2f(150+q, 375);
    glEnd();



    glColor3f(0.52, 0.63, 0.60);
    glBegin(GL_POLYGON);
    glVertex2f(115+q, 200);
    glVertex2f(115+q, 325);
    glColor3f(0.19, 0.29, 0.26);
    glVertex2f(185+q, 325);
    glVertex2f(185+q, 200);
    glEnd();



    glColor3f(0.55, 0.14, 0.14);
    glBegin(GL_POLYGON);
    glVertex2f(325+q, 200);
    glVertex2f(325+q, 575);
    glVertex2f(750+q, 575);
    glVertex2f(750+q, 200);
    glEnd();



    for (d = 375; d <= 625; d += 125)
    {
        glColor3f(0.52, 0.63, 0.60);
        glBegin(GL_POLYGON);
        glVertex2f(d+q, 450);
        glVertex2f(d+q, 525);
        glColor3f(0.19, 0.29, 0.26);
        glVertex2f(75+ q + d, 525);
        glVertex2f(75+ q  + d, 450);
        glEnd();
    }
    //triangle
 glBegin(GL_TRIANGLES);

    glColor3f(0.5,0,0);

    glVertex2f(1500.0+q,600.0);
    glVertex2f(1800.0+q,200.0);
    glVertex2f(1200.0+q,200.0);

    glEnd();
glBegin(GL_TRIANGLES);

    glColor3f(0.5,0,0);

    glVertex2f(2100.0+q,600.0);
    glVertex2f(2400.0+q,200.0);
    glVertex2f(1800.0+q,200.0);

    glEnd();

glPushMatrix();
glTranslatef(1650+q,150,0);
glScalef(0.5,0.5,1);
     drawhut();
     glPopMatrix();




    glColor3f(0.52, 0.63, 0.60);
    glBegin(GL_POLYGON);
    glVertex2f(375+q, 325);
    glVertex2f(375+q, 400);
    glColor3f(0.19, 0.29, 0.26);
    glVertex2f(450+q, 400);
    glVertex2f(450+q, 325);
    glEnd();


    glColor3f(0.52, 0.63, 0.60);
    glBegin(GL_POLYGON);
    glVertex2f(512.5+q, 200);
    glVertex2f(512.5+q, 350);
    glColor3f(0.19, 0.29, 0.26);
    glVertex2f(612.5+q, 350);
    glVertex2f(612.5+q, 200);
    glEnd();


    glColor3f(0.40, 0.21, 0.17);
    glBegin(GL_POLYGON);
    glVertex2f(920+q+hz, 200);
    glVertex2f(920+q+hz, 325);
    glVertex2f(945+q+hz, 325);
    glVertex2f(945+q+hz, 200);
    glEnd();


    glColor3f(0.87, 0.82, 0.81);
    glBegin(GL_POLYGON);
    glVertex2f(895+q+hz, 325);
    glVertex2f(895+q+hz, 475);
    glVertex2f(970+q+hz, 475);
    glVertex2f(970+q+hz, 325);
    glEnd();
    glColor3f(1, 1, 1);
     glBegin(GL_POLYGON);
        glVertex2f(750+q+hz,200);
        glVertex2f(900+q+hz,200);
        glVertex2f(900+q+hz,175);
        glVertex2f(750+q+hz,175);
    glEnd();
    glColor3f(1, 1, 1);
     glBegin(GL_POLYGON);
        glVertex2f(750+q+hz,150);
        glVertex2f(900+q+hz,150);
        glVertex2f(900+q+hz,125);
        glVertex2f(750+q+hz,125);
    glEnd();

    glColor3f(1, 1, 1);
     glBegin(GL_POLYGON);
        glVertex2f(750+q+hz,100);
        glVertex2f(900+q+hz,100);
        glVertex2f(900+q+hz,75);
        glVertex2f(750+q+hz,75);
    glEnd();
 glColor3f(1, 1, 1);
     glBegin(GL_POLYGON);
        glVertex2f(750+q+hz,50);
        glVertex2f(900+q+hz,50);
        glVertex2f(900+q+hz,25);
        glVertex2f(750+q+hz,25);
    glEnd();


    for (d = 0; d <= 20; d++)
    {
        glColor3f(0.0, 0.0, 0.0);
        draw_circle(932.5+q+hz, 450, d);
        glColor3f(1.0, 1.0, 0.0);
        draw_circle(932.5+q+hz, 400, d);
        glColor3f(0.0, 1.0, 0.0);
        draw_circle(932.5+q+hz, 350, d);
    }



    glColor3f(0.70, 0.10, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(50 + x+q, 150);
    glVertex2f(35 + x+q, 165);
    glVertex2f(35 + x+q, 200);
    glVertex2f(125 + x+q, 250);
    glVertex2f(250 + x+q, 250);
    glVertex2f(300 + x+q, 200);
    glVertex2f(400 + x+q, 175);
    glVertex2f(400 + x+q, 160);
    glVertex2f(380 + x+q, 150);
    glEnd();



    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(200 + x+q, 200);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(200 + x+q, 235);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2f(240 + x+q, 235);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(275 + x+q, 200);
    glEnd();

    //car1 window2
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(75 + x+q, 200);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(140 + x+q, 235);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2f(180 + x+q, 235);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(180 + x+q, 200);
    glEnd();



    glColor3f(0.89, 0.47, 0.20);
    glBegin(GL_POLYGON);
    glVertex2f(35 + x+q, 175);
    glVertex2f(35 + x+q, 200);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(50 + x+q, 200);
    glVertex2f(50 + x+q, 175);
    glEnd();



    //front
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(380 + x+q, 165);
    glVertex2f(380 + x+q, 175);
    glColor3f(0.89, 0.47, 0.20);
    glVertex2f(400 + x+q, 175);
    glVertex2f(400 + x+q, 165);
    glEnd();



    glColor3f(0.14, 0.42, 0.55);
    glBegin(GL_POLYGON);
    glVertex2f(480 + x+q, 150);
    glVertex2f(480 + x+q, 200);
    glVertex2f(530 + x+q, 300);
    glVertex2f(705 + x+q, 300);
    glVertex2f(770 + x+q, 225);
    glVertex2f(830 + x+q, 190);
    glVertex2f(830 + x+q, 150);
    glEnd();



    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(630 + x+q, 225);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(630 + x+q, 285);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2f(695 + x+q, 285);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(725 + x+q, 225);
    glEnd();


    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(530 + x+q, 225);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(555 + x+q, 285);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2f(615 + x+q, 285);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(615 + x+q, 225);
    glEnd();


    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(805 + x+q, 175);
    glVertex2f(805 + x+q, 195);
    glColor3f(0.89, 0.47, 0.20);
    glVertex2f(830 + x+q, 190);
    glVertex2f(830 + x+q, 175);
    glEnd();



    glColor3f(0.89, 0.47, 0.20);
    glBegin(GL_POLYGON);
    glVertex2f(480 + x+q, 175);
    glVertex2f(480 + x+q, 200);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(505 + x+q, 200);
    glVertex2f(505 + x+q, 175);
    glEnd();






    for (d = 0; d <= 30; d++)
    {
        glColor3f(0.075, 0.075, 0.075);
        draw_circle(125 + x+q, 150, d);
        glColor3f(0.075, 0.075, 0.075);
        draw_circle(275 + x+q, 150, d);
    }


    //car2-wheels
    for (d = 0; d <= 40; d++)
    {
        glColor3f(0.075, 0.075, 0.075);
        draw_circle(565 + x+q, 150, d);
        glColor3f(0.075, 0.075, 0.075);
        draw_circle(730 + x+q, 150, d);
    }





}





void signal()
{
    if (light == 0)
    {
        for (d = 0; d <= 20; d++)
        {
            glColor3f(1.0, 0.0, 0.0);
            draw_circle(932.5+q+hz, 450, d);
            glColor3f(0.0, 0.0, 0.0);
            draw_circle(932.5+q+hz, 350, d);
            if(flag1==1)
{


glPushMatrix();
glColor3f(1,1,1);
for(int i=0;i<20;i++)
{


            {
                movy+=0.00051;

            }

}
            glTranslatef(200,-movy+cz,0);
            drawSchoolBoy(200,200,.5,.5,255,0,0);






glPopMatrix();


}


        }
    }
    else
    {
        for (d = 0; d <= 20; d++)
        {
            glColor3f(0.0, 0.0, 0.0);
            draw_circle(932.5+q+hz, 450, d);
            glColor3f(0.0, 1.0, 0.0);
            draw_circle(932.5+q+hz, 350, d);
            glPushMatrix();
glColor3f(1,1,1);


            glTranslatef(200,movx,0);
            drawSchoolBoy(200,200,.5,.5,255,0,0);



glPopMatrix();


    }
}
}

void myMouseFunc(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) {

            if(x>200 && y<700 && y>400)
            {



        flag = 1;
            }
    }
}



void idle()
{
    if(flag==1)
    {
        glClearColor(1.0,1.0,1.0,1.0);
        if(light==0 && (x>=100 && x<=500))
        {

            x+=SPEED;
        }
        if(light==0 && (x>=530 && x<=1020))
        {

            x+=SPEED;
        }
        if(light==1)
        {
            x+=SPEED;


        }
        if(x>-100 )
        {   light=0;

            flag1=1;
        }
        if(movy>200  )
        {

             movx=-2000;
             light=1;
             q-=SPEED;
        }


        if(x>900)
        {

             hz=1250;
             lz=500;

        }
        if(x>1100)
        {    day=0;

            light=0;
             movy=-40;
             for(int i=0;i<20;i++)



{





             cz-=0.01;


}


            q=-1200.50;


        }
          if(cz<-200  )
        {


             light=1;

        }

        glutPostRedisplay();
    }
}

void main_menu(int index)
{
    switch (index)
    {
    case 1: light = 1;
        break;


    case 2: light = 0;
        break;


    case 3: exit(0);
        break;
    }
}


void myinit()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 700.0);
}


void drawstring(int x, int y, char* string)
{
    char* str;
    glRasterPos2f(x, y);
    for (str = string; *str != '\0'; str++)
    {
        glColor3f(1.0, 1.0, 1.0);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *str);
    }
}
void draweRect(void)
{

    glColor3f(0.0,0.0,1.0);
    glLineWidth(10);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_POLYGON);
        glVertex2i(400,90);
        glVertex2i(700,90);
        glVertex2i(700,150);
        glVertex2i(400,150);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glFlush();
}


void frontscreen()
{
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);


    drawstring(465, 560, "A PROJECT ON");
    drawstring(390, 510, "TRAFFIC SIGNAL SIMULATION");
    drawstring(30, 350, "BY :");
    drawstring(30, 300, "NAWAF SHEIKH   [4NM18CS101]");
    drawstring(30, 250, "NIDHI BK       [4NM18CS220]");

    drawstring(440, 120, "LEFT CLICK  TO  START");


     draweRect();
    glFlush();
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (flag == 0)
        frontscreen();
    if (flag == 1)
    {
        draw_object();
        signal();
    }
    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1366.0, 768.0);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Traffic Signal");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMouseFunc(myMouseFunc);

    myinit();
    glutCreateMenu(main_menu);
    glutAddMenuEntry("green",1);
    glutAddMenuEntry("red",2);
    glutAddMenuEntry("Quit",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);



    glutMainLoop();
}
