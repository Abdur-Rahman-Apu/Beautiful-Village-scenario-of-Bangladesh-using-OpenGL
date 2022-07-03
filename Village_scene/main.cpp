#include<windows.h>
#include<stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<math.h>
#include<fstream>
#include<string.h>
#include <iostream>
#include<dos.h>
#include <unistd.h>
#include <time.h>
#include <MMsystem.h>

//global variable

float fx=5,fy=6;

//end_declaration
void init(void)
{
  glClearColor(0.29,0.82,0.22,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  //glOrtho(0, 300, 300, 0, -1, 1);
  glOrtho(-100,100,-100,100,-150,150); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=100;i++)

    {
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();

}

void half_circle_for_boat(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=50;i++)

    {
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();

}

void half_circle_for_cow(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=100;i++)

    {
        if(i<=50)
        {
            continue;
        }else
        {
            float angle = 2.0f * 3.1416f * i/100;

            float x = rx * cosf(angle);
            float y = ry * sinf(angle);

            glVertex2f((x+cx),(y+cy));
        }

    }
    glEnd();



}



void make_left_field()
{
    glColor3ub(50,205,50);
    glRectf(-100,-40,-10,40);

    //par
    glColor3ub(239, 178, 76);
    glBegin(GL_POLYGON);
    glVertex2f(-11,6);
    glVertex2f(-9,4);
    glVertex2f(0,12);
    glVertex2f(0,15);
    glEnd();

    glColor3ub(50,205,50);
    glBegin(GL_TRIANGLES);
    glVertex2f(-10,40);
    glVertex2f(-10,5);
    glVertex2f(0,15);
    glEnd();



     //par
    glColor3ub(239, 178, 76);
    glBegin(GL_POLYGON);
    glVertex2f(-10,-30);
    glVertex2f(-7,-30);
    glVertex2f(0,-24);
    glVertex2f(0,-20);
    glEnd();

    glColor3ub(50,205,50);
    glBegin(GL_POLYGON);
    glVertex2f(-10,-30);
    glVertex2f(0,-20);
    glVertex2f(0,3);
    glVertex2f(-10,5);
    glEnd();


    glColor3ub(50,205,50);
    glBegin(GL_TRIANGLES);
    glVertex2f(-10,-30);
    glVertex2f(-10,-40);
    glVertex2f(-4,-30);
    glEnd();

    //par
    glColor3ub(239, 178, 76);
    glRectf(-100,-43,-8,-39);

    glBegin(GL_POLYGON);
    glVertex2f(-11,-41);
    glVertex2f(-8,-43);
    glVertex2f(-4,-34);
    glVertex2f(-4,-30);
    glEnd();
}


void house2()
{
    //first
    glColor3ub(255, 168, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(-40,40);
    glVertex2f(-30,40);
    glVertex2f(-35,50);
    glEnd();

    //line
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-40,40);
    glVertex2f(-35,50);
    glEnd();

    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-30,40);
    glVertex2f(-35,50);
    glEnd();

    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-40,40);
    glVertex2f(-30,40);
    glEnd();
    //line end


    glColor3ub(255, 168, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-30,40);
    glVertex2f(-20,40);
    glVertex2f(-25,50);
    glVertex2f(-35,50);
    glEnd();

    //line
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-35,50);
    glVertex2f(-25,50);
    glVertex2f(-20,40);
    glVertex2f(-30,40);

    glVertex2f(-20,40);
    glVertex2f(-25,50);

    glEnd();


    //bottom
    glColor3ub(255, 168, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-30,25);
    glVertex2f(-21,25);
    glVertex2f(-21,40);
    glVertex2f(-30,40);
    glEnd();

    //Line
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-30,25);
    glVertex2f(-30,40);

    glVertex2f(-30,25);
    glVertex2f(-21,25);

    glVertex2f(-21,25);
    glVertex2f(-21,40);
    glEnd();

    //bottom_left
    glColor3ub(255, 168, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-39,26.5);
    glVertex2f(-30,25);
    glVertex2f(-30,40);
    glVertex2f(-39,40);
    glEnd();

    //lines
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-39,26.5);
    glVertex2f(-30,25);
    glEnd();

    //door
    glColor3ub(250, 130, 49);
    glBegin(GL_POLYGON);
    glVertex2f(-27,25.5);
    glVertex2f(-24,25.5);
    glVertex2f(-24,35);
    glVertex2f(-27,35);
    glEnd();

    //door line
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-27,25);
    glVertex2f(-27,35);

    glVertex2f(-24,25.5);
    glVertex2f(-24,35);

    glVertex2f(-24,35);
    glVertex2f(-27,35);
    glEnd();


    //window
    glColor3ub(250, 130, 49);
    glBegin(GL_POLYGON);
    glVertex2f(-37,30);
    glVertex2f(-33,29.5);
    glVertex2f(-33,35.5);
    glVertex2f(-37,36);
    glEnd();

    //lines
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-37,30);
    glVertex2f(-33,29.5);

    glVertex2f(-33,29.5);
    glVertex2f(-33,35.5);

    glVertex2f(-33,35.5);
    glVertex2f(-37,36);

    glVertex2f(-37,30);
    glVertex2f(-37,36);
    glEnd();

}

void house1()
{


    glColor3ub(255, 168, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(-75,50);
    glVertex2f(-60,48);
    glVertex2f(-68,70);
    glEnd();
    //triangle_line
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);

    //left_two_line
    glVertex2f(-75,50);
    glVertex2f(-68,70);

    glVertex2f(-74,50);
    glVertex2f(-67,70);

    //2line join
    glVertex2f(-75,50);
    glVertex2f(-74,50);


    //right line
    glColor3f(0,0,0);
    glLineWidth(2);
    glVertex2f(-68,70);
    glVertex2f(-60,48);


    //bottom_line
    glVertex2f(-73.5,50);
    glVertex2f(-60,48);

    glEnd();


    //end

    //top
    glColor3ub(255, 168, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-60,48);
    glVertex2f(-37,48);
    glVertex2f(-48,70);
    glVertex2f(-68,70);
    glEnd();

    //top_line
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-60,48);
    glVertex2f(-37,48);

    glLineWidth(2);
    glColor3f(0,0,0);
    glVertex2f(-37,48);
    glVertex2f(-48,70);

    glVertex2f(-48,70);
    glVertex2f(-68,70);



    glEnd();

    //top_bottom
    glColor3ub(255, 168, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-60,20);
    glVertex2f(-39,20);
    glVertex2f(-39,48);
    glVertex2f(-60,48);
    glEnd();

    //window_top_bottom_left
    glColor3ub(250, 130, 49);
    glBegin(GL_POLYGON);
    glVertex2f(-58,30);
    glVertex2f(-54,30);
    glVertex2f(-54,38);
    glVertex2f(-58,38);
    glEnd();

    //line
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);

    //1,2
    glVertex2f(-58,30);
    glVertex2f(-54,30);

    //2,3
    glVertex2f(-54,30);
    glVertex2f(-54,38);

    //3,4
    glVertex2f(-54,38);
    glVertex2f(-58,38);

    //1,4
    glVertex2f(-58,30);
    glVertex2f(-58,38);

    //middle
    glVertex2f(-56,30);
    glVertex2f(-56,38);

    glEnd();

    //door
    glColor3ub(250, 130, 49);
    glBegin(GL_POLYGON);
    glVertex2f(-52,20);
    glVertex2f(-48,20);
    glVertex2f(-48,43);
    glVertex2f(-52,43);
    glEnd();

    //door_line
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);

    //2,3
    glVertex2f(-48,20);
    glVertex2f(-48,43);

    //3,4
    glVertex2f(-48,43);
    glVertex2f(-52,43);

    //1,4
    glVertex2f(-52,20);
    glVertex2f(-52,43);
    glEnd();

    //top_bottom_line
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    //1,2
    glVertex2f(-60,20);
    glVertex2f(-39,20);
    //2,3
    glVertex2f(-39,20);
    glVertex2f(-39,48);
    //1,4
    glVertex2f(-60,20);
    glVertex2f(-60,48);

    //1,4 middle
    glVertex2f(-50,20);
    glVertex2f(-50,43);

    glEnd();

    //window_right_bottom
    glColor3ub(250, 130, 49);
    glBegin(GL_POLYGON);
    glVertex2f(-46,30);
    glVertex2f(-42,30);
    glVertex2f(-42,38);
    glVertex2f(-46,38);
    glEnd();

    //line
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);

    //1,2
    glVertex2f(-46,30);
    glVertex2f(-42,30);

    //2,3
    glVertex2f(-42,30);
    glVertex2f(-42,38);

    //3,4
    glVertex2f(-42,38);
    glVertex2f(-46,38);

    //1,4
    glVertex2f(-46,30);
    glVertex2f(-46,38);

    //middle
    glVertex2f(-44,30);
    glVertex2f(-44,38);

    glEnd();


    //triangle_bottom
    glColor3ub(255, 168, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-74,23);
    glVertex2f(-60,20);
    glVertex2f(-60,48);
    glVertex2f(-74,50);
    glEnd();

        //line
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);

    //1,2
    glVertex2f(-74,23);
    glVertex2f(-60,20);

    //2,3
    glVertex2f(-60,20);
    glVertex2f(-60,48);

    //3,4
    glVertex2f(-60,48);
    glVertex2f(-74,50);

    //1,4
    glVertex2f(-74,23);
    glVertex2f(-74,50);


    glEnd();

    //window_triangle_bottom
    glColor3ub(250, 130, 49);
    glBegin(GL_POLYGON);
    glVertex2f(-71,30);
    glVertex2f(-63,29);
    glVertex2f(-63,39);
    glVertex2f(-71,40);
    glEnd();


    //line
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);

    //1,2
    glVertex2f(-71,30);
    glVertex2f(-63,29);

    //2,3
    glVertex2f(-63,29);
    glVertex2f(-63,39);

    //3,4
    glVertex2f(-63,39);
    glVertex2f(-71,40);

    //1,4
    glVertex2f(-71,30);
    glVertex2f(-71,40);

    //middle
    glVertex2f(-67,40);
    glVertex2f(-67,29);


    glEnd();

}

void khor()
{
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(-85,30);
    glVertex2f(-70,30);
    glVertex2f(-70,50);
    glVertex2f(-85,50);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-85,50);
    glVertex2f(-70,50);
    glVertex2f(-77,60);
    glEnd();

    glColor3ub(44, 103, 5);
    glRectf(-77.5,59,-76.5,63);
}

void big_tree()
{
    //leaf_right
    glColor3ub(48,183,0);
    circle(6,10,-84,60);
    circle(6,10,-82,88);
    circle(6,10,-80,70);
    circle(6,10,-85,65);
    circle(6,10,-85,75);
    circle(6,10,-90,90);
    circle(8,10,-95,87.5);
    circle(6,10,-95,73.7);
    circle(6,10,-97,70);
    circle(6,10,-96,62);


    glColor3ub(109, 33, 79);
    glRectf(-98,0,-92,50);

    glBegin(GL_POLYGON);
    glVertex2f(-98,50);
    glVertex2f(-95,50);
    glVertex2f(-98,65);
    glVertex2f(-99,65);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-95,50);
    glVertex2f(-92,50);
    glVertex2f(-86,65);
    glVertex2f(-87,65);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-92,55);
    glVertex2f(-89,57);
    glVertex2f(-89,65);
    glVertex2f(-90,65);
    glEnd();



    //bottom
    glBegin(GL_TRIANGLES);
    glVertex2f(-98,0);
    glVertex2f(-96,0);
    glVertex2f(-100,-8);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-96,0);
    glVertex2f(-94,0);
    glVertex2f(-95,-5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-94,0);
    glVertex2f(-92,0);
    glVertex2f(-90,-6);
    glEnd();



}

void cow_drink()
{
    glColor3ub(97, 59, 22);
    glRectf(-60,-10,-61,5);



    glColor3ub(243, 156, 18);
    half_circle_for_cow(5,10,-66,-8);

    glColor3ub(133, 216, 229);
    circle(4,2,-66,-9);

    glColor3f(1,1,1);
    circle(5,2,-66,-8);

    glColor3ub(133, 216, 229);
    circle(4,2,-66,-9);

}

void river()
{

    glColor3ub(75, 123, 236);
    glBegin(GL_POLYGON);
    glVertex2f(-100,-100);
    glVertex2f(100,-100);
    glVertex2f(100,40);
    glVertex2f(-100,40);
    glEnd();
}


float bx=0,by=0;
void boat()
{


    glTranslatef(bx,0,0);


    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(bx-85,-60.5);
    glVertex2f(bx-90,-60.5);
    glVertex2f(bx-90,-60);
    glVertex2f(bx-85,-60);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(bx-45,-60.5);
    glVertex2f(bx-50,-60.5);
    glVertex2f(bx-50,-60);
    glVertex2f(bx-45,-60);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(bx-48,-65.5);
    glVertex2f(bx-50,-65.5);
    glVertex2f(bx-50,-65);
    glVertex2f(bx-48,-65);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(bx-80,-67.5);
    glVertex2f(bx-85,-67.5);
    glVertex2f(bx-85,-67);
    glVertex2f(bx-80,-67);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(bx-85,-65);
    glVertex2f(bx-50,-65);
    glVertex2f(bx-45,-50);
    glVertex2f(bx-90,-50);
    glEnd();


    glColor3ub(255, 190, 118);
    glBegin(GL_POLYGON);
    glVertex2f(bx-75,-50);
    glVertex2f(bx-55,-50);
    glVertex2f(bx-55,-35);
    glVertex2f(bx-75,-35);
    glEnd();

    half_circle_for_boat(3,15,bx-55,-50);

    glColor3ub(210, 218, 226);
    half_circle_for_boat(3,15,bx-75,-50);



}


float px=0;

void palm_tree1()
{

    glColor3ub(109, 33, 79);

    glBegin(GL_POLYGON);
    glVertex2f(-10,30);
    glVertex2f(-9,30);
    glVertex2f(-6,45);
    glVertex2f(-7,45);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-6,45);
    glVertex2f(-7,45);
    glVertex2f(-7,60);
    glVertex2f(-6,60);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-7,60);
    glVertex2f(-6,60);
    glTranslatef(px,0,0);
    glVertex2f(px-8,70);
    glVertex2f(px-9,70);
    glEnd();

    //leaf
    glColor3ub(48,183,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(px-10,75);
    glVertex2f(px-8,70);
    glVertex2f(px-15,55);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-10,75);
    glVertex2f(px-8,70);
    glVertex2f(px-20,72);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-12,70);
    glVertex2f(px-6,70);
    glVertex2f(px-12,85);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-10,75);
    glVertex2f(px-8,70);
    glVertex2f(px-2,80);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-9,70);
    glVertex2f(px-7,74);
    glVertex2f(px-2,60);
    glEnd();



}
static int flag=0, k=0;

void move_palm(int value)
{
;

        if(k<2 && flag==0)
        {
          px+=1;
          k=k+1;
          //printf("%d and flag=%d\n",k,flag);
          if(k==2)
          {
              flag=1;
          }

    }
    if(k>0 && flag==1){
        px-=1;
        k--;
        if(k==0)
        {
            flag=0;
        }

    }


    glutPostRedisplay();
    glutTimerFunc(900,move_palm,0);
}



void bottom_field()
{



    //field
    glColor3ub(24,252,0);
    circle(35,20,70,-90);

    glBegin(GL_POLYGON);
    glVertex2f(30,-100);
    glVertex2f(40,-100);
    glVertex2f(40,-79);
    glVertex2f(30,-100);
    glEnd();

    //water
    glColor3ub(75, 123, 236);
    glBegin(GL_POLYGON);
    glVertex2f(40,-70);
    glVertex2f(90,-70);
    glVertex2f(90,-64.9);
    glVertex2f(40,-64.9);
    glEnd();

    //first_flower

    //kando
    glColor3ub(34,139,34);
    glRectf(55.2,-75,56.2,-70);

    //top kando
    glBegin(GL_POLYGON);
    glVertex2f(55.2,-70);
    glVertex2f(56.2,-70);
    glVertex2f(55.2,-60);
    glVertex2f(54.2,-60);
    glEnd();

    //flower
    glColor3f(1,1,0);
    circle(1,2,53.2,-62);
    circle(1,2,54.2,-59);
    circle(1,2,56,-59);
    circle(1,2,57,-61);
    circle(1,2,56.2,-64);
    circle(1,2,54.2,-65);



    //middle_flower
    glColor3f(1,0,0);
    circle(1,2,55,-62);


    //*******second_flower******
    glTranslatef(fx,fy,0);

    //kando
    glColor3ub(34,139,34);
    glRectf(55.2,-75,56.2,-70);

    //top kando
    glBegin(GL_POLYGON);
    glVertex2f(55.2,-70);
    glVertex2f(56.2,-70);
    glVertex2f(55.2,-60);
    glVertex2f(54.2,-60);
    glEnd();

    //flower
    glColor3f(1,1,0);
    circle(1,2,53.2,-62);
    circle(1,2,54.2,-59);
    circle(1,2,56,-59);
    circle(1,2,57,-61);
    circle(1,2,56.2,-64);
    circle(1,2,54.2,-65);



    //middle_flower
    glColor3f(1,0,0);
    circle(1,2,55,-62);

    //********End second flower************

    //**********third_flower***********
    glTranslatef(6,0,0);

    //kando
    glColor3ub(34,139,34);
    glRectf(55.2,-75,56.2,-70);

    //top kando
    glBegin(GL_POLYGON);
    glVertex2f(55.2,-70);
    glVertex2f(56.2,-70);
    glVertex2f(55.2,-60);
    glVertex2f(54.2,-60);
    glEnd();

    //flower
    glColor3f(1,1,0);
    circle(1,2,53.2,-62);
    circle(1,2,54.2,-59);
    circle(1,2,56,-59);
    circle(1,2,57,-61);
    circle(1,2,56.2,-64);
    circle(1,2,54.2,-65);



    //middle_flower
    glColor3f(1,0,0);
    circle(1,2,55,-62);

    //***fourth_flower
    glTranslatef(1,-13,0);

    //kando
    glColor3ub(34,139,34);
    glRectf(55.2,-75,56.2,-70);

    //top kando
    glBegin(GL_POLYGON);
    glVertex2f(55.2,-70);
    glVertex2f(56.2,-70);
    glVertex2f(55.2,-60);
    glVertex2f(54.2,-60);
    glEnd();

    //flower
    glColor3f(1,1,0);
    circle(1,2,53.2,-62);
    circle(1,2,54.2,-59);
    circle(1,2,56,-59);
    circle(1,2,57,-61);
    circle(1,2,56.2,-64);
    circle(1,2,54.2,-65);



    //middle_flower
    glColor3f(1,0,0);
    circle(1,2,55,-62);


    //******fifth_flower***********
    glTranslatef(-7,-5,0);

    //kando
    glColor3ub(34,139,34);
    glRectf(55.2,-75,56.2,-70);

    //top kando
    glBegin(GL_POLYGON);
    glVertex2f(55.2,-70);
    glVertex2f(56.2,-70);
    glVertex2f(55.2,-60);
    glVertex2f(54.2,-60);
    glEnd();

    //flower
    glColor3f(1,1,0);
    circle(1,2,53.2,-62);
    circle(1,2,54.2,-59);
    circle(1,2,56,-59);
    circle(1,2,57,-61);
    circle(1,2,56.2,-64);
    circle(1,2,54.2,-65);



    //middle_flower
    glColor3f(1,0,0);
    circle(1,2,55,-62);


    //*******grass*******
    glColor3ub(0,128,0);
    glBegin(GL_POLYGON);
    glVertex2f(37,-70);
    glVertex2f(45,-70);
    glVertex2f(45,-65);
    glVertex2f(38,-65);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(38,-70);
    glVertex2f(44,-70);
    glVertex2f(36,-60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(40,-70);
    glVertex2f(45,-70);
    glVertex2f(41,-55);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(40,-70);
    glVertex2f(45,-70);
    glVertex2f(47,-60);
    glEnd();

    //***********second_grass**********
    glTranslatef(26,-5,0);
    glColor3ub(0,128,0);
    glBegin(GL_POLYGON);
    glVertex2f(38,-70);
    glVertex2f(45,-70);
    glVertex2f(45,-65);
    glVertex2f(38,-65);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(38,-70);
    glVertex2f(44,-70);
    glVertex2f(36,-60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(40,-70);
    glVertex2f(45,-70);
    glVertex2f(41,-55);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(40,-70);
    glVertex2f(45,-70);
    glVertex2f(47,-60);
    glEnd();

    //grass

    //right
    glColor3ub(0,100,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(58,-70);
    glVertex2f(60,-70);
    glVertex2f(63,-25);
    glEnd();


    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    glVertex2f(60,-70);
    glVertex2f(62,-70);
    glVertex2f(68,-25);
    glEnd();

    //middle
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    glVertex2f(56,-70);
    glVertex2f(58,-70);
    glVertex2f(57,-25);
    glEnd();

    //left
    glColor3ub(0,100,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(55,-70);
    glVertex2f(57,-70);
    glVertex2f(53,-25);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(53,-70);
    glVertex2f(55,-70);
    glVertex2f(48,-25);
    glEnd();

    glColor3f(1,1,1);

    glBegin(GL_TRIANGLES);
    glVertex2f(51,-70);
    glVertex2f(53,-70);
    glVertex2f(40,-25);
    glEnd();





}

void right_field()
{
    glColor3ub(50,205,50);
    glRectf(60,0,100,40);
    glBegin(GL_POLYGON);
    glVertex2f(60,0);
    glVertex2f(100,0);
    glVertex2f(100,40);
    glVertex2f(40,40);
    glEnd();


    //par
    glColor3ub(239, 178, 76);
    glBegin(GL_POLYGON);
    glVertex2f(60,-4);
    glVertex2f(60,0);
    glVertex2f(40,40);
    glVertex2f(40,38);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(60,-3.5);
    glVertex2f(100,-3.5);
    glVertex2f(100,0);
    glVertex2f(60,0);
    glEnd();


    //child
    glColor3ub(0, 151, 230);
    glBegin(GL_TRIANGLES);
    glVertex2f(58,28);
    glVertex2f(62,28);
    glVertex2f(60,34);
    glEnd();

    //head
    glColor3ub(251, 197, 49);
    circle(1,2,60,35);

    glColor3ub(6, 82, 221);
    glBegin(GL_POLYGON);
    glVertex2f(58,24);
    glVertex2f(62,24);
    glVertex2f(62,28);
    glVertex2f(58,28);
    glEnd();

    glColor3ub(251, 197, 49);
    glRectf(58.4,22,59.2,24);
    glRectf(60.8,22,61.5,24);

    glRectf(57,30,60,32);


    //tree
    glColor3ub(97, 59, 22);
    glBegin(GL_POLYGON);
    glVertex2f(80,20);
    glVertex2f(83,20);
    glVertex2f(83,40);
    glVertex2f(80,40);
    glEnd();

    //bottom
    glBegin(GL_TRIANGLES);
    glVertex2f(80,20);
    glVertex2f(82,20);
    glVertex2f(78,15);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(81,20);
    glVertex2f(83,20);
    glVertex2f(82,15);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(81,20);
    glVertex2f(83,20);
    glVertex2f(80,15);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(81,20);
    glVertex2f(83,20);
    glVertex2f(85,15);
    glEnd();

    //leaf
    glBegin(GL_POLYGON);
    glVertex2f(80,40);
    glVertex2f(82,40);
    glVertex2f(78,45);
    glVertex2f(78,43);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(81,40);
    glVertex2f(83,40);
    glVertex2f(85,45);
    glVertex2f(85,47);
    glEnd();

    glColor3ub(0,128,0);
    circle(3,5,77,48);
    circle(3,5,75,48);
    circle(3,5,77,53);
    circle(3,5,81,50);
    circle(3,5,80,58);
    circle(3,5,85,55);
    circle(3,5,85,52);
    circle(3,5,87,52);
    circle(3,5,83,49);
    circle(3,5,83,48);
    circle(3,5,86,46);


    //man
    //body
    glColor3ub(189, 197, 129);
    glBegin(GL_TRIANGLES);
    glVertex2f(75,19);
    glVertex2f(79.5,17);
    glVertex2f(78.5,25);
    glEnd();

    //hand
    glColor3ub(248, 239, 186);
    glBegin(GL_POLYGON);
    glVertex2f(74,20);
    glVertex2f(76,21);
    glVertex2f(76,22);
    glVertex2f(74,21);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(74,19);
    glVertex2f(79,19);
    glVertex2f(79,21);
    glVertex2f(74,20);
    glEnd();

    //last
    glColor3ub(39, 60, 117);
    glBegin(GL_POLYGON);
    glVertex2f(77,14);
    glVertex2f(79.2,14);
    glVertex2f(79.2,18);
    glVertex2f(77,18);
    glEnd();

    glColor3ub(39, 60, 117);
    glBegin(GL_POLYGON);
    glVertex2f(72.5,14);
    glVertex2f(75.5,14);
    glVertex2f(76.5,18.5);
    glVertex2f(73.5,18.5);
    glEnd();

    glColor3ub(39, 60, 117);
    glBegin(GL_POLYGON);
    glVertex2f(77,14);
    glVertex2f(78,14);
    glVertex2f(77,18);
    glVertex2f(74,18);
    glEnd();

    //mouth
    glColor3ub(255, 234, 167);
    circle(1,2,78,26);



    //hat
    glColor3ub(53, 59, 72);
    glBegin(GL_TRIANGLES);
    glVertex2f(79,31);
    glVertex2f(76,28);
    glVertex2f(80,26);
    glEnd();



}


int sx[20]={-80,-85,-70,-60,-50,-40,-35,-25,-15,-5,5,10,18,22,30,45,55,78,87,96};
int sy[20]={43,47,54,65,76,87,98,57,63,89,45,56,67,88,79,60,50,70,80,90};

void night()
{
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-100,40);
    glVertex2f(100,40);
    glVertex2f(100,100);
    glVertex2f(-100,100);
    glEnd();

    glColor3ub(246, 241, 213);
    circle(10,14,46,80);

    glColor3f(1,1,1);
    for(int i=0;i<20;i++)
    {
        circle(0.5,0.6,sx[i],sy[i]);
    }


}

void cow()
{



     //milk
    glColor3ub(255, 190, 118);
    half_circle_for_cow(3,5,-39,-12);



    //leg_3
    glColor3f(1,1,1);
    glRectf(-40,-22,-38.5,-17);
    glColor3f(0,0,0);
    half_circle_for_boat(1,2.4,-39.3,-22);

    //milk
    glColor3ub(255, 190, 118);
    glRectf(-41,-17.5,-40.5,-16.1);
    glRectf(-40,-18,-39.5,-17);
    glRectf(-39,-18,-38.5,-17);
    glRectf(-38,-18,-37.5,-17);


    //body
    glColor3f(1,1,1);
    circle(10,10,-45,-6);
    //end

    //shing
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-56,10);
    glVertex2f(-54,10);
    glVertex2f(-55,13);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-50,10);
    glVertex2f(-52,10);
    glVertex2f(-51,13);
    glEnd();

    //mouth
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    //1,2
    glVertex2f(-56,0);
    glVertex2f(-50,0);

    //2,3
    glVertex2f(-50,0);
    glVertex2f(-50,10);

    //3,4
    glVertex2f(-50,10);
    glVertex2f(-56,10);

    //1,4
    glVertex2f(-56,0);
    glVertex2f(-56,10);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-56,0);
    glVertex2f(-50,0);
    glVertex2f(-50,10);
    glVertex2f(-56,10);
    glEnd();

    //end
    //line_start

    glColor3f(0,0,0);
    glBegin(GL_LINES);

    //1,2
    glVertex2f(-55,-3);
    glVertex2f(-51,-3);

    //2,3
    glVertex2f(-51,-3);
    glVertex2f(-51,4);


    //3,4
    glVertex2f(-51,4);
    glVertex2f(-55,4);

    //1,4
    glVertex2f(-55,-3);
    glVertex2f(-55,4);
    glEnd();
    //end;

    //Eye
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-55,-3);
    glVertex2f(-51,-3);
    glVertex2f(-51,4);
    glVertex2f(-55,4);
    glEnd();

    //kornia
    glColor3f(0,0,0);
    circle(0.5,1,-55,6);
    circle(0.5,1,-51,6);
    glColor3ub(75, 123, 236);
    circle(0.3,0.5,-54.8,6.2);
    circle(0.3,0.5,-50.8,6.2);

    //nose
    glColor3f(0,0,0);
    circle(0.5,1,-54,2);
    circle(0.5,1,-52,2);
    //inside
    glColor3ub(220, 192, 195);
    circle(0.3,0.5,-54,2.2);
    circle(0.3,0.5,-52,2.2);

    //mouth
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-54,-1);
    glVertex2f(-52,-1);
    glEnd();

    //first_leg
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-53,-18);
    glVertex2f(-51,-18);
    glVertex2f(-50,-10);
    glVertex2f(-54,-10);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-52.5,-23);
    glVertex2f(-51.5,-23);
    glVertex2f(-51,-18);
    glVertex2f(-53,-18);
    glEnd();

    //2

    glColor3f(0,0,0);
    half_circle_for_boat(1,2.4,-52,-25);

    //second_leg

    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-48,-20);
    glVertex2f(-46,-20);
    glVertex2f(-46,-15);
    glVertex2f(-49,-15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-47.04,-23);
    glVertex2f(-46.04,-23);
    glVertex2f(-46,-20);
    glVertex2f(-48,-20);
    glEnd();

    glColor3f(0,0,0);
    half_circle_for_boat(1,2.4,-46.9,-24);

    //4
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-37,-17);
    glVertex2f(-35,-17);
    glVertex2f(-35,-8);
    glVertex2f(-39,-10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-37,-22);
    glVertex2f(-35.6,-22);
    glVertex2f(-35,-17);
    glVertex2f(-37,-17);
    glEnd();

    glColor3f(0,0,0);
    half_circle_for_boat(1,2.4,-36.5,-24);

    //ear
    glColor3f(1,1,1);
    circle(1,1,-57,8);
    circle(1,1,-49,8);

    //design
    glColor3f(0,0,0);
    circle(2,2,-45,2);

    circle(3,3,-50,-8);
    circle(3,3,-40,-5);

    //rope
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);

    glVertex2f(-60,2);
    glVertex2f(-61,2);

    glVertex2f(-61,2);
    glVertex2f(-56,0);

    glEnd();
}

void moving_lej()
{
    //lej
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-35,-5);
    glVertex2f(-34,-6);
    glVertex2f(-32.4,-5.9);
    glVertex2f(-36,-2);
    glEnd();

    //lej
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-33.5,-12);
    glVertex2f(-32.5,-12);
    glVertex2f(-32.5,-6);
    glVertex2f(-33.5,-6);
    glEnd();

    glColor3f(0,0,0);
    circle(0.5,1.5,-33,-12);
}



void boat_man()
{
    //hand
    glColor3f(248, 239, 186);
    glBegin(GL_POLYGON);
    glVertex2f(bx-85,-44);
    glVertex2f(bx-82,-44);
    glVertex2f(bx-82,-43);
    glVertex2f(bx-85,-42);
    glEnd();



    //body
    glColor3ub(189, 197, 129);
    glBegin(GL_TRIANGLES);
    glVertex2f(bx-82.8,-47);
    glVertex2f(bx-86.8,-47);
    glVertex2f(bx-84.8,-40);
    glEnd();

    //last
    glColor3ub(39, 60, 117);
    glBegin(GL_POLYGON);
    glVertex2f(bx-87,-50);
    glVertex2f(bx-81,-50);
    glVertex2f(bx-83,-47);
    glVertex2f(bx-87,-47);
    glEnd();

    //mouth
    glColor3ub(255, 234, 167);
    circle(1,2,bx-85,-40);



    //hat
    glColor3ub(53, 59, 72);
    glBegin(GL_TRIANGLES);
    glVertex2f(bx-86,-42);
    glVertex2f(bx-84,-37);
    glVertex2f(bx-87,-36);
    glEnd();

    //hand_lathi
    glColor3ub(109, 33, 79);
    glBegin(GL_POLYGON);
    glVertex2f(bx-86,-50);
    glVertex2f(bx-85,-50);
    glVertex2f(bx-79,-35);
    glVertex2f(bx-80,-35);
    glEnd();


}

void boat_move()
{
    bx+=0.02;
    if(bx>100)
    {
        bx=-50;
    }
    glutPostRedisplay();
}


static float kx=0;
static int j=0;
static int point=0;
void move_kite(int value)
{
     if(j<3 && point==0)
    {
        kx+=1;
        j++;

        if(j==3)
        {
            point=1;
        }
    }else if(j>0 && point==1){
        kx-=1;
        j--;

        if(j==0)
        {
            point=0;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(900,move_kite,0);
}

void kite()
{

    //bottom

    //line
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(57,30);
    glVertex2f(53,40);

    glVertex2f(53,40);
    glVertex2f(45,60);

    //move_able_line
    glVertex2f(45,60);
    glTranslatef(kx,0,0);
    glVertex2f(kx+28,75);
    glEnd();

    //bottom
    glColor3ub(255, 165, 2);
    glBegin(GL_TRIANGLES);
    glVertex2f(kx+30,72);
    glVertex2f(kx+28,67);
    glVertex2f(kx+32,67);
    glEnd();

    //left_up
    glColor3ub(255, 242, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(kx+25,75);
    glVertex2f(kx+30,75);
    glVertex2f(kx+30,80);
    glEnd();

    //left_bottom
    glColor3ub(255, 56, 56);
    glBegin(GL_TRIANGLES);
    glVertex2f(kx+25,75);
    glVertex2f(kx+30,75);
    glVertex2f(kx+30,70);
    glEnd();

    //right_up
    glColor3ub(50, 255, 126);
    glBegin(GL_TRIANGLES);
    glVertex2f(kx+30,75);
    glVertex2f(kx+35,75);
    glVertex2f(kx+30,80);
    glEnd();

    //right_bottom
    glColor3ub(30, 144, 255);
    glBegin(GL_TRIANGLES);
    glVertex2f(kx+30,75);
    glVertex2f(kx+35,75);
    glVertex2f(kx+30,70);
    glEnd();



}

float brx=0;
void bird1()
{
    //first bird
    //toth
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(brx-29,79);
    glVertex2f(brx-29,81);
    glVertex2f(brx-26,80);
    glEnd();
    //mouth
    glColor3ub(255, 242, 0);
    circle(1,2,brx-30,80);
    //eye
    glColor3f(0,0,0);
    circle(0.2,0.5,brx-30,80);

    //up_triangle
    glColor3ub(50, 255, 126);
    glBegin(GL_TRIANGLES);
    glVertex2f(brx-39,87);
    glVertex2f(brx-33,87);
    glVertex2f(brx-36,77);
    glEnd();

    //lej
    glBegin(GL_TRIANGLES);
    glVertex2f(brx-45,79);
    glVertex2f(brx-40,79);
    glVertex2f(brx-45,89);
    glEnd();

    //body
    glColor3ub(232, 65, 24);
    circle(5,3,brx-36,80);
}

void bird1_move()
{
    brx+=0.02;
    if(brx>200)
    {
        brx=-110;
    }
    glutPostRedisplay();
}

float brx2=-1;
void bird2()
{
    //second bird
    //toth
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(brx2+89,89);
    glVertex2f(brx2+89,91);
    glVertex2f(brx2+86,90);
    glEnd();

    //mouth
    glColor3ub(50, 255, 126);
    circle(1,2,brx2+90,90);
    //eye
    glColor3f(0,0,0);
    circle(0.2,0.5,brx2+90,90);

    //up_triangle
    glColor3ub(50, 255, 126);
    glBegin(GL_TRIANGLES);
    glVertex2f(brx2+93,95);
    glVertex2f(brx2+97,95);
    glVertex2f(brx2+95,90);
    glEnd();

    //lej
    glBegin(GL_TRIANGLES);
    glVertex2f(brx2+102,89);
    glVertex2f(brx2+97,89);
    glVertex2f(brx2+102,96);
    glEnd();

    //body
    glColor3ub(255, 159, 26);
    circle(4,3,brx2+95,90);
}

void bird2_move()
{
     brx2-=0.02;
    if(brx2<-200)
    {
        brx2=-1;
    }
    glutPostRedisplay();
}


void palm_tree2()
{
    glColor3ub(109, 33, 79);
    glTranslatef(80,5,0);
    glBegin(GL_POLYGON);
    glVertex2f(-10,30);
    glVertex2f(-9,30);
    glVertex2f(-6,45);
    glVertex2f(-7,45);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-6,45);
    glVertex2f(-7,45);
    glVertex2f(-7,60);
    glVertex2f(-6,60);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-7,60);
    glVertex2f(-6,60);
    glTranslatef(px,0,0);
    glVertex2f(px-8,70);
    glVertex2f(px-9,70);
    glEnd();

    //leaf
    glColor3ub(48,183,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(px-10,75);
    glVertex2f(px-8,70);
    glVertex2f(px-15,55);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-10,75);
    glVertex2f(px-8,70);
    glVertex2f(px-20,72);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-12,70);
    glVertex2f(px-6,70);
    glVertex2f(px-12,85);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-10,75);
    glVertex2f(px-8,70);
    glVertex2f(px-2,80);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-9,70);
    glVertex2f(px-7,74);
    glVertex2f(px-2,60);
    glEnd();
}

void palm_tree3()
{
    glColor3ub(109, 33, 79);
    glTranslatef(98,5,0);
    glBegin(GL_POLYGON);
    glVertex2f(-10,30);
    glVertex2f(-9,30);
    glVertex2f(-6,45);
    glVertex2f(-7,45);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-6,45);
    glVertex2f(-7,45);
    glVertex2f(-7,60);
    glVertex2f(-6,60);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-7,60);
    glVertex2f(-6,60);
    glTranslatef(px,0,0);
    glVertex2f(px-8,70);
    glVertex2f(px-9,70);
    glEnd();

    //leaf
    glColor3ub(48,183,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(px-10,75);
    glVertex2f(px-8,70);
    glVertex2f(px-15,55);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-10,75);
    glVertex2f(px-8,70);
    glVertex2f(px-20,72);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-12,70);
    glVertex2f(px-6,70);
    glVertex2f(px-12,85);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-10,75);
    glVertex2f(px-8,70);
    glVertex2f(px-2,80);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-9,70);
    glVertex2f(px-7,74);
    glVertex2f(px-2,60);
    glEnd();
}

float mf=0,mf2=0,my=0;

void fish_move()
{
    mf+=0.01;
    if(mf>100)
    {
        mf=-102;
    }
    glutPostRedisplay();
}


void fish1()
{

    glTranslatef(0,-30,0);
    glColor3f(1,0,0);
    glRectf(mf-80,-50,mf-77,-45);

    //front
    glBegin(GL_TRIANGLES);
    glVertex2f(mf-77,-50);
    glVertex2f(mf-77,-45);
    glVertex2f(mf-75,-48);
    glEnd();

    //back
    glBegin(GL_TRIANGLES);
    glVertex2f(mf-80,-50);
    glVertex2f(mf-80,-45);
    glVertex2f(mf-82,-48);
    glEnd();

    //lej
    glBegin(GL_TRIANGLES);
    glVertex2f(mf-84,-45);
    glVertex2f(mf-82,-48);
    glVertex2f(mf-84,-50);
    glEnd();

    //eye
    glColor3f(0,0,0);
    circle(0.4,0.5,mf-77,-48);


}
void fish2()
{

    glTranslatef(5,-35,0);
    glColor3f(1,0,0);
    glRectf(mf-80,my-50,mf-77,my-45);



    //front
    glBegin(GL_TRIANGLES);
    glVertex2f(mf-77,my-50);
    glVertex2f(mf-77,my-45);
    glVertex2f(mf-75,my-48);
    glEnd();

    //back
    glBegin(GL_TRIANGLES);
    glVertex2f(mf-80,my-50);
    glVertex2f(mf-80,my-45);
    glVertex2f(mf-82,my-48);
    glEnd();

    //lej
    glBegin(GL_TRIANGLES);
    glVertex2f(mf-84,my-45);
    glVertex2f(mf-82,my-48);
    glVertex2f(mf-84,my-50);
    glEnd();

    //eye
    glColor3f(0,0,0);
    circle(0.4,0.5,mf-77,my-48);


}
void fish3()
{

    glTranslatef(10,-30,0);
    glColor3f(1,0,0);
    glRectf(mf-80,my-50,mf-77,my-45);



    //front
    glBegin(GL_TRIANGLES);
    glVertex2f(mf-77,my-50);
    glVertex2f(mf-77,my-45);
    glVertex2f(mf-75,my-48);
    glEnd();

    //back
    glBegin(GL_TRIANGLES);
    glVertex2f(mf-80,my-50);
    glVertex2f(mf-80,my-45);
    glVertex2f(mf-82,my-48);
    glEnd();

    //lej
    glBegin(GL_TRIANGLES);
    glVertex2f(mf-84,my-45);
    glVertex2f(mf-82,my-48);
    glVertex2f(mf-84,my-50);
    glEnd();

    //eye
    glColor3f(0,0,0);
    circle(0.4,0.5,mf-77,my-48);


}

void stairs()
{
    glColor3ub(239, 178, 76);
    glBegin(GL_POLYGON);
    glVertex2f(-10,-15);
    glVertex2f(0,-15);
    glVertex2f(0,-5);
    glVertex2f(-10,-5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-24,-15);
    glVertex2f(-10,-15);
    glVertex2f(-10,-5);
    glVertex2f(-20,-5);
    glEnd();

    //big house road
    glBegin(GL_POLYGON);
    glVertex2f(-34,5);
    glVertex2f(-30,5);
    glVertex2f(-48,19.5);
    glVertex2f(-52,19.5);
    glEnd();

    //small house road
    glBegin(GL_POLYGON);
    glVertex2f(-33,5);
    glVertex2f(-29,5);
    glVertex2f(-24,24.5);
    glVertex2f(-27,24.5);
    glEnd();

    //join
    glBegin(GL_POLYGON);
    glVertex2f(-36,8);
    glVertex2f(-24,-15);
    glVertex2f(-20,-5);
    glVertex2f(-29,8);
    glEnd();
}
void small_boat()
{
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(4,0);
    glVertex2f(13,0);
    glVertex2f(17,6);
    glVertex2f(0,6);
    glEnd();

    glColor3ub(251, 197, 49);

    glBegin(GL_POLYGON);
    glVertex2f(6,6);
    glVertex2f(14,6);
    glVertex2f(14,11);
    glVertex2f(6,11.7);
    glEnd();



    half_circle_for_boat(2,5,13,6);

    glColor3ub(245, 246, 250);
    half_circle_for_boat(2,6,6,6);

    //lathi
    glColor3ub(97, 59, 22);
    glBegin(GL_POLYGON);
    glVertex2f(-1,0);
    glVertex2f(0,0);
    glVertex2f(0,10);
    glVertex2f(-1,10);
    glEnd();
}

void sun()
{

    glColor3ub(255, 242, 0);
    circle(10,14,46,80);
}
void sky()
{
    glColor3ub(15, 188, 249);
    glBegin(GL_POLYGON);
    glVertex2f(-100,40);
    glVertex2f(100,40);
    glVertex2f(100,100);
    glVertex2f(-100,100);
    glEnd();
    sun();
}


void stop_cloud1()
{
    glColor3f(1,1,1);
    circle(4,5,-20,80);
    circle(4,5,-24,80);
    circle(4,5,-22,83);
    circle(4,5,-28,81);
}

void stop_cloud2()
{
    glTranslatef(100,0,0);
    glColor3f(1,1,1);
    circle(4,5,-20,80);
    circle(4,5,-24,80);
    circle(4,5,-22,83);
    circle(4,5,-28,81);
}

void stop_cloud3()
{
    glTranslatef(60,-3,0);
    glColor3f(1,1,1);
    circle(4,5,-20,80);
    circle(4,5,-24,80);
    circle(4,5,-22,83);
    circle(4,5,-28,81);
}


float mc1=0;
void moving_cloud1()
{
    glTranslatef(mc1,0,0);
    glColor3f(1,1,1);
    circle(4,5,-80,80);
    circle(4,5,-84,80);
    circle(4,5,-82,83);
    circle(4,5,-88,81);
}

void move_cloud1()
{
    mc1+=0.02;
    if(mc1>200)
    {
        mc1=-100;
    }
    glutPostRedisplay();
}


float mc2=0;
void moving_cloud2()
{
    glTranslatef(mc2,0,0);
    glColor3f(1,1,1);
    circle(4,5,-180,70);
    circle(4,5,-184,70);
    circle(4,5,-182,73);
    circle(4,5,-188,71);
}

void move_cloud2()
{
    mc2+=0.02;
    if(mc2>400)
    {
        mc2=0;
    }
    glutPostRedisplay();
}

float ma=-55;
void move_plane()
{
    ma+=0.05;
    if(ma>250)
    {
        ma=-55;
    }
    glutPostRedisplay();
}


void window(float x1)
{
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-70+x1+ma,87);
    glVertex2f(-69+x1+ma,87);
    glVertex2f(-69+x1+ma,88);
    glVertex2f(-70+x1+ma,88);
    glEnd();
}
void airplane()
{
    //last_fly
    //1

    glBegin(GL_POLYGON);
    glColor3ub(252, 92, 101);
    glVertex2f(-77+ma,82);
    glVertex2f(-76+ma,82);
    glVertex2f(-72+ma,86);
    glVertex2f(-73+ma,86);
    glEnd();

    //2

    glBegin(GL_POLYGON);
    glColor3ub(252, 92, 101);
    glVertex2f(-73+ma,90);
    glVertex2f(-71+ma,90);
    glVertex2f(-70+ma,93);
    glVertex2f(-71+ma,93);
    glEnd();

    //last_top
    glBegin(GL_POLYGON);
    glColor3ub(254, 211, 48);
    glVertex2f(-73+ma,88);
    glVertex2f(-68+ma,88);
    glVertex2f(-75+ma,95);
    glVertex2f(-77+ma,95);
    glEnd();

    //body
    glBegin(GL_POLYGON);
    glColor3ub(254, 211, 48);
    glVertex2f(-70+ma,83);
    glVertex2f(-55+ma,83);
    glVertex2f(-55+ma,90);
    glVertex2f(-70+ma,90);
    glEnd();

    //window
    for(int i=0;i<=12;i+=2){
            window(i);
    }

    //body_fly
    //top
    glBegin(GL_POLYGON);
    glColor3ub(38, 222, 129);
    glVertex2f(-65+ma,90);
    glVertex2f(-62+ma,90);
    glVertex2f(-66+ma,95);
    glVertex2f(-67+ma,95);
    glEnd();

    //bottom
    glBegin(GL_POLYGON);
    glColor3ub(38, 222, 129);
    glVertex2f(-65+ma,83);
    glVertex2f(-62+ma,83);
    glVertex2f(-66+ma,80);
    glVertex2f(-67+ma,80);
    glEnd();

    //last
    glBegin(GL_POLYGON);
    glColor3ub(254, 211, 48);
    glVertex2f(-75+ma,85.5);
    glVertex2f(-70+ma,83);
    glVertex2f(-70+ma,88);
    glVertex2f(-75+ma,88);
    glEnd();






    //front
    glBegin(GL_TRIANGLES);
    glColor3ub(253, 150, 68);
    glVertex2f(-55+ma,90);
    glVertex2f(-55+ma,83);
    glVertex2f(-50+ma,85);
    glEnd();

    //front_window
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-56+ma,88);
    glVertex2f(-53+ma,88);
    glVertex2f(-54+ma,89);
    glVertex2f(-56+ma,89);
    glEnd();
}

void hill()
{
    glColor3f(0,1,0);
    int p=0;
    for(int n=0;n<=50;n++)
    {
        glPushMatrix();
        glTranslatef(p,0,0);
        half_circle_for_boat(2,4,-100,40);
        glPopMatrix();
        p+=4;

    }

}
void small_tree()
{
    glColor3ub(97, 59, 22);
    glBegin(GL_POLYGON);
    glVertex2f(80,20);
    glVertex2f(82,20);
    glVertex2f(82,40);
    glVertex2f(80,40);
    glEnd();

    //bottom
    glBegin(GL_TRIANGLES);
    glVertex2f(80,20);
    glVertex2f(82,20);
    glVertex2f(78,15);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(81,20);
    glVertex2f(83,20);
    glVertex2f(82,15);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(81,20);
    glVertex2f(83,20);
    glVertex2f(80,15);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(81,20);
    glVertex2f(83,20);
    glVertex2f(85,15);
    glEnd();

    //leaf
    glBegin(GL_POLYGON);
    glVertex2f(80,40);
    glVertex2f(82,40);
    glVertex2f(78,45);
    glVertex2f(78,43);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(81,40);
    glVertex2f(82,40);
    glVertex2f(85,45);
    glVertex2f(85,47);
    glEnd();

    glColor3ub(0,128,0);
    circle(3,5,77,48);
    circle(3,5,75,48);
    circle(3,5,77,53);
    circle(3,5,81,50);
    circle(3,5,80,58);
    circle(3,5,85,55);
    circle(3,5,85,52);
    circle(3,5,87,52);
    circle(3,5,83,49);
    circle(3,5,83,48);
    circle(3,5,85,46);
}
void stand_tree()
{
    glPushMatrix();
    glTranslatef(-110,10,0);
    small_tree();
    glPopMatrix();
}
void stand_palm()
{
    glColor3ub(109, 33, 79);
    glBegin(GL_POLYGON);
    glVertex2f(-10,30);
    glVertex2f(-9,30);
    glVertex2f(-6,45);
    glVertex2f(-7,45);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-6,45);
    glVertex2f(-7,45);
    glVertex2f(-7,60);
    glVertex2f(-6,60);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-7,60);
    glVertex2f(-6,60);
    glTranslatef(px,0,0);
    glVertex2f(px-8,70);
    glVertex2f(px-9,70);
    glEnd();

    //leaf
    glColor3ub(48,183,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(px-10,75);
    glVertex2f(px-8,70);
    glVertex2f(px-15,55);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-10,75);
    glVertex2f(px-8,70);
    glVertex2f(px-20,72);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-12,70);
    glVertex2f(px-6,70);
    glVertex2f(px-12,85);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-10,75);
    glVertex2f(px-8,70);
    glVertex2f(px-2,80);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(px-9,70);
    glVertex2f(px-7,74);
    glVertex2f(px-2,60);
    glEnd();

}

void flower2()
{


    glColor3ub(11, 102, 35);
    circle(1,1,-15,13);
    //red
    glColor3ub(11, 102, 35);
    glRectf(-15,13,-15.5,18);
    glColor3f(1,0,0);
    circle(1.8,1.8,-15.3,20);

    //right_only
    glColor3ub(11, 102, 35);
    glBegin(GL_POLYGON);
    glVertex2f(-15.5,13);
    glVertex2f(-15,13);
    glVertex2f(-17.5,19);
    glVertex2f(-18,19);
    glEnd();

    //yellow

    glColor3ub(11, 102, 35);
    glBegin(GL_POLYGON);
    glVertex2f(-16,13);
    glVertex2f(-15.5,13);
    glVertex2f(-19.5,18);
    glVertex2f(-20,18);
    glEnd();

    glColor3ub(255, 242, 0);
    circle(1.8,1.8,-20,18);

    //right_only
    glColor3ub(11, 102, 35);
    glBegin(GL_POLYGON);
    glVertex2f(-16,12.5);
    glVertex2f(-9,13.5);
    glVertex2f(-9,14.5);
    glVertex2f(-16,13.5);
    glEnd();

    //red
    glColor3ub(11, 102, 35);
    glBegin(GL_POLYGON);
    glVertex2f(-16,12.5);
    glVertex2f(-11,17.5);
    glVertex2f(-11,18.5);
    glVertex2f(-16,13.5);
    glEnd();

    glColor3f(1,0,0);
    circle(1.8,1.8,-11,19);

    //left_only
    glColor3ub(11, 102, 35);
    glBegin(GL_POLYGON);
    glVertex2f(-21,12.8);
    glVertex2f(-12,12.5);
    glVertex2f(-12,13.5);
    glVertex2f(-21,13.8);
    glEnd();

}
float dx=0,dy=0;



void duck()
{
    //glRotatef(180,0,1,0);
    //body
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(dx+5,dy-30);
    glVertex2f(dx+10,dy-30);
    glVertex2f(dx+10,dy-25);
    glVertex2f(dx+2,dy-25);
    glEnd();
    //mouth
    glColor3ub(255, 159, 26);
    glBegin(GL_TRIANGLES);
    glVertex2f(dx+10,dy-25);
    glVertex2f(dx+10,dy-20);
    glVertex2f(dx+12,dy-25);
    glEnd();
}


void day()
{
    glClear(GL_COLOR_BUFFER_BIT);
    sky();

    hill();
    stand_tree();






    //night();


    stop_cloud1();

    glPushMatrix();
    stop_cloud2();
    glPopMatrix();

    glPushMatrix();
    stop_cloud3();
    glPopMatrix();

    glPushMatrix();
    airplane();
    glPopMatrix();

    glPushMatrix();
    moving_cloud1();
    move_cloud1();
    glPopMatrix();

    glPushMatrix();
    moving_cloud2();
    move_cloud2();
    glPopMatrix();

    glPushMatrix();
    bird2();
    bird2_move();
    glPopMatrix();

    glPushMatrix();
    bird1();
    bird1_move();
    glPopMatrix();



    river();


    make_left_field();

    stairs();


    glPushMatrix();
    palm_tree1();
    glPopMatrix();


    glPushMatrix();
    palm_tree2();
    glTranslatef(-20,0,0);
    palm_tree1();
    glPopMatrix();


    //glPushMatrix();
    //glTranslatef(7,-17,0);
    //stand_palm();
    //glPopMatrix();



    glPushMatrix();
    palm_tree3();
    glPopMatrix();


    khor();

    big_tree();

    house2();

    house1();

    cow_drink();
    flower2();

    glPushMatrix();
    glTranslatef(2,-45,0);
    flower2();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-50,-45,0);
    flower2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-60,-15,0);
    flower2();
    glPopMatrix();


    glPushMatrix();
    right_field();
    glPopMatrix();

    glPushMatrix();
    moving_lej();
    glPopMatrix();

    //duck
    glPushMatrix();
    duck();

    glTranslatef(10,7,0);
    duck();

    glTranslatef(6,-8,0);
    duck();

    glPopMatrix();

    cow();

    glPushMatrix();
    boat();
    boat_man();
    boat_move();
    glPopMatrix();

    glPushMatrix();
    bottom_field();
    glPopMatrix();

    kite();

    glPushMatrix();
    fish1();
    fish_move();
    glPopMatrix();

    glPushMatrix();
    fish2();
    glPopMatrix();

    glPushMatrix();
    fish3();
    glPopMatrix();

    glPushMatrix();
    small_boat();
    glPopMatrix();


    glFlush();




glutSwapBuffers();
}

void dark()
{
    glClear(GL_COLOR_BUFFER_BIT);


    night();

    hill();
    stand_tree();


    stop_cloud1();

    glPushMatrix();
    stop_cloud2();
    glPopMatrix();

    glPushMatrix();
    stop_cloud3();
    glPopMatrix();

    glPushMatrix();
    airplane();
    glPopMatrix();

    glPushMatrix();
    moving_cloud1();
    move_cloud1();
    glPopMatrix();

    glPushMatrix();
    moving_cloud2();
    move_cloud2();
    glPopMatrix();

    glPushMatrix();
    bird2();
    bird2_move();
    glPopMatrix();

    glPushMatrix();
    bird1();
    bird1_move();
    glPopMatrix();



    river();

/*
    //graph
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2f(-100,0);
    glVertex2f(100,0);
    glVertex2f(0,100);
    glVertex2f(0,-100);
    glEnd();
    //end
*/

    make_left_field();

    stairs();


    glPushMatrix();
    palm_tree1();
    glPopMatrix();


    glPushMatrix();
    palm_tree2();
    glPopMatrix();

    glPushMatrix();
    palm_tree3();
    glPopMatrix();

    khor();

    big_tree();

    house2();

    house1();

    cow_drink();

    flower2();

    glPushMatrix();
    glTranslatef(2,-45,0);
    flower2();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-50,-45,0);
    flower2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-60,-15,0);
    flower2();
    glPopMatrix();

    glPushMatrix();
    right_field();
    glPopMatrix();

    glPushMatrix();
    moving_lej();
    glPopMatrix();

    cow();

    glPushMatrix();
    boat();
    boat_man();
    boat_move();
    glPopMatrix();

    glPushMatrix();
    bottom_field();
    glPopMatrix();



    kite();

    glPushMatrix();
    fish1();
    fish_move();
    glPopMatrix();

    glPushMatrix();
    fish2();
    glPopMatrix();

    glPushMatrix();
    fish3();
    glPopMatrix();

    glPushMatrix();
    small_boat();
    glPopMatrix();


    //duck
    glPushMatrix();
    duck();

    glTranslatef(10,7,0);
    duck();

    glTranslatef(6,-8,0);
    duck();

    glPopMatrix();


    glFlush();




glutSwapBuffers();
}




float m,n;

void line1()
{
    int i=3,j=-3;
    glLineWidth(2);
    glColor3f(1,1,1);

    glBegin(GL_LINES);

    glVertex2f(-99,m+i);
    glVertex2f(-97,n+j);

    glVertex2f(-95,m+i);
    glVertex2f(-93,n+j);

    glVertex2f(-91,m+i);
    glVertex2f(-89,n+j);

    glVertex2f(-87,m+i);
    glVertex2f(-85,n+j);

    glVertex2f(-83,m+i);
    glVertex2f(-81,n+j);

    glVertex2f(-79,m+i);
    glVertex2f(-77,n+j);

    glVertex2f(-75,m+i);
    glVertex2f(-73,n+j);


    glVertex2f(-71,m+i);
    glVertex2f(-69,n+j);

    glVertex2f(-67,m+i);
    glVertex2f(-65,n+j);


    glVertex2f(-63,m+i);
    glVertex2f(-61,n+j);


    glVertex2f(-59,m+i);
    glVertex2f(-57,n+j);


    glVertex2f(-55,m+i);
    glVertex2f(-53,n+j);


    glVertex2f(-51,m+i);
    glVertex2f(-49,n+j);


    glVertex2f(-47,m+i);
    glVertex2f(-45,n+j);


    glVertex2f(-43,m+i);
    glVertex2f(-41,n+j);


    glVertex2f(-39,m+i);
    glVertex2f(-37,n+j);

    glVertex2f(-35,m+i);
    glVertex2f(-33,n+j);

    glVertex2f(-31,m+i);
    glVertex2f(-29,n+j);


    glVertex2f(-27,m+i);
    glVertex2f(-25,n+j);

    glVertex2f(-23,m+i);
    glVertex2f(-21,n+j);

    glVertex2f(-19,m+i);
    glVertex2f(-17,n+j);

    glVertex2f(-15,m+i);
    glVertex2f(-13,n+j);

    glVertex2f(-11,m+i);
    glVertex2f(-9,n+j);

    glVertex2f(-7,m+i);
    glVertex2f(-5,n+j);

    glVertex2f(-3,m+i);
    glVertex2f(-1,n+j);

    glVertex2f(1,m+i);
    glVertex2f(3,n+j);



    glVertex2f(5,m+i);
    glVertex2f(7,n+j);


    glVertex2f(9,m+i);
    glVertex2f(11,n+j);



    glVertex2f(13,m+i);
    glVertex2f(15,n+j);

    glVertex2f(17,m+i);
    glVertex2f(19,n+j);

    glVertex2f(21,m+i);
    glVertex2f(23,n+j);

    glVertex2f(25,m+i);
    glVertex2f(27,n+j);

    glVertex2f(29,m+i);
    glVertex2f(31,n+j);


    glVertex2f(33,m+i);
    glVertex2f(35,n+j);

    glVertex2f(37,m+i);
    glVertex2f(39,n+j);

    glVertex2f(41,m+i);
    glVertex2f(43,n+j);

    glVertex2f(45,m+i);
    glVertex2f(47,n+j);

    glVertex2f(49,m+i);
    glVertex2f(51,n+j);


    glVertex2f(53,m+i);
    glVertex2f(55,n+j);

    glVertex2f(57,m+i);
    glVertex2f(59,n+j);


    glVertex2f(61,m+i);
    glVertex2f(63,n+j);


    glVertex2f(65,m+i);
    glVertex2f(67,n+j);


    glVertex2f(69,m+i);
    glVertex2f(71,n+j);


    glVertex2f(73,m+i);
    glVertex2f(75,n+j);

    glVertex2f(77,m+i);
    glVertex2f(79,n+j);

    glVertex2f(81,m+i);
    glVertex2f(83,n+j);

    glVertex2f(85,m+i);
    glVertex2f(87,n+j);

    glVertex2f(89,m+i);
    glVertex2f(91,n+j);

    glVertex2f(93,m+i);
    glVertex2f(95,n+j);
    glEnd();
}


void line2()
{
    int i=20,j=14;

    glLineWidth(2);
    glColor3f(1,1,1);

    glBegin(GL_LINES);

    glVertex2f(-99,m+i);
    glVertex2f(-97,n+j);

    glVertex2f(-95,m+i);
    glVertex2f(-93,n+j);

    glVertex2f(-91,m+i);
    glVertex2f(-89,n+j);

    glVertex2f(-87,m+i);
    glVertex2f(-85,n+j);

    glVertex2f(-83,m+i);
    glVertex2f(-81,n+j);

    glVertex2f(-79,m+i);
    glVertex2f(-77,n+j);

    glVertex2f(-75,m+i);
    glVertex2f(-73,n+j);


    glVertex2f(-71,m+i);
    glVertex2f(-69,n+j);

    glVertex2f(-67,m+i);
    glVertex2f(-65,n+j);


    glVertex2f(-63,m+i);
    glVertex2f(-61,n+j);


    glVertex2f(-59,m+i);
    glVertex2f(-57,n+j);


    glVertex2f(-55,m+i);
    glVertex2f(-53,n+j);


    glVertex2f(-51,m+i);
    glVertex2f(-49,n+j);


    glVertex2f(-47,m+i);
    glVertex2f(-45,n+j);


    glVertex2f(-43,m+i);
    glVertex2f(-41,n+j);


    glVertex2f(-39,m+i);
    glVertex2f(-37,n+j);

    glVertex2f(-35,m+i);
    glVertex2f(-33,n+j);

    glVertex2f(-31,m+i);
    glVertex2f(-29,n+j);


    glVertex2f(-27,m+i);
    glVertex2f(-25,n+j);

    glVertex2f(-23,m+i);
    glVertex2f(-21,n+j);

    glVertex2f(-19,m+i);
    glVertex2f(-17,n+j);

    glVertex2f(-15,m+i);
    glVertex2f(-13,n+j);

    glVertex2f(-11,m+i);
    glVertex2f(-9,n+j);

    glVertex2f(-7,m+i);
    glVertex2f(-5,n+j);

    glVertex2f(-3,m+i);
    glVertex2f(-1,n+j);

    glVertex2f(1,m+i);
    glVertex2f(3,n+j);



    glVertex2f(5,m+i);
    glVertex2f(7,n+j);


    glVertex2f(9,m+i);
    glVertex2f(11,n+j);



    glVertex2f(13,m+i);
    glVertex2f(15,n+j);

    glVertex2f(17,m+i);
    glVertex2f(19,n+j);

    glVertex2f(21,m+i);
    glVertex2f(23,n+j);

    glVertex2f(25,m+i);
    glVertex2f(27,n+j);

    glVertex2f(29,m+i);
    glVertex2f(31,n+j);


    glVertex2f(33,m+i);
    glVertex2f(35,n+j);

    glVertex2f(37,m+i);
    glVertex2f(39,n+j);

    glVertex2f(41,m+i);
    glVertex2f(43,n+j);

    glVertex2f(45,m+i);
    glVertex2f(47,n+j);

    glVertex2f(49,m+i);
    glVertex2f(51,n+j);


    glVertex2f(53,m+i);
    glVertex2f(55,n+j);

    glVertex2f(57,m+i);
    glVertex2f(59,n+j);


    glVertex2f(61,m+i);
    glVertex2f(63,n+j);


    glVertex2f(65,m+i);
    glVertex2f(67,n+j);


    glVertex2f(69,m+i);
    glVertex2f(71,n+j);


    glVertex2f(73,m+i);
    glVertex2f(75,n+j);

    glVertex2f(77,m+i);
    glVertex2f(79,n+j);

    glVertex2f(81,m+i);
    glVertex2f(83,n+j);

    glVertex2f(85,m+i);
    glVertex2f(87,n+j);

    glVertex2f(89,m+i);
    glVertex2f(91,n+j);

    glVertex2f(93,m+i);
    glVertex2f(95,n+j);
    glEnd();
}


void line3()
{
    int i=40,j=34;
     glLineWidth(2);
    glColor3f(1,1,1);

    glBegin(GL_LINES);

    glVertex2f(-99,m+i);
    glVertex2f(-97,n+j);

    glVertex2f(-95,m+i);
    glVertex2f(-93,n+j);

    glVertex2f(-91,m+i);
    glVertex2f(-89,n+j);

    glVertex2f(-87,m+i);
    glVertex2f(-85,n+j);

    glVertex2f(-83,m+i);
    glVertex2f(-81,n+j);

    glVertex2f(-79,m+i);
    glVertex2f(-77,n+j);

    glVertex2f(-75,m+i);
    glVertex2f(-73,n+j);


    glVertex2f(-71,m+i);
    glVertex2f(-69,n+j);

    glVertex2f(-67,m+i);
    glVertex2f(-65,n+j);


    glVertex2f(-63,m+i);
    glVertex2f(-61,n+j);


    glVertex2f(-59,m+i);
    glVertex2f(-57,n+j);


    glVertex2f(-55,m+i);
    glVertex2f(-53,n+j);


    glVertex2f(-51,m+i);
    glVertex2f(-49,n+j);


    glVertex2f(-47,m+i);
    glVertex2f(-45,n+j);


    glVertex2f(-43,m+i);
    glVertex2f(-41,n+j);


    glVertex2f(-39,m+i);
    glVertex2f(-37,n+j);

    glVertex2f(-35,m+i);
    glVertex2f(-33,n+j);

    glVertex2f(-31,m+i);
    glVertex2f(-29,n+j);


    glVertex2f(-27,m+i);
    glVertex2f(-25,n+j);

    glVertex2f(-23,m+i);
    glVertex2f(-21,n+j);

    glVertex2f(-19,m+i);
    glVertex2f(-17,n+j);

    glVertex2f(-15,m+i);
    glVertex2f(-13,n+j);

    glVertex2f(-11,m+i);
    glVertex2f(-9,n+j);

    glVertex2f(-7,m+i);
    glVertex2f(-5,n+j);

    glVertex2f(-3,m+i);
    glVertex2f(-1,n+j);

    glVertex2f(1,m+i);
    glVertex2f(3,n+j);



    glVertex2f(5,m+i);
    glVertex2f(7,n+j);


    glVertex2f(9,m+i);
    glVertex2f(11,n+j);



    glVertex2f(13,m+i);
    glVertex2f(15,n+j);

    glVertex2f(17,m+i);
    glVertex2f(19,n+j);

    glVertex2f(21,m+i);
    glVertex2f(23,n+j);

    glVertex2f(25,m+i);
    glVertex2f(27,n+j);

    glVertex2f(29,m+i);
    glVertex2f(31,n+j);


    glVertex2f(33,m+i);
    glVertex2f(35,n+j);

    glVertex2f(37,m+i);
    glVertex2f(39,n+j);

    glVertex2f(41,m+i);
    glVertex2f(43,n+j);

    glVertex2f(45,m+i);
    glVertex2f(47,n+j);

    glVertex2f(49,m+i);
    glVertex2f(51,n+j);


    glVertex2f(53,m+i);
    glVertex2f(55,n+j);

    glVertex2f(57,m+i);
    glVertex2f(59,n+j);


    glVertex2f(61,m+i);
    glVertex2f(63,n+j);


    glVertex2f(65,m+i);
    glVertex2f(67,n+j);


    glVertex2f(69,m+i);
    glVertex2f(71,n+j);


    glVertex2f(73,m+i);
    glVertex2f(75,n+j);

    glVertex2f(77,m+i);
    glVertex2f(79,n+j);

    glVertex2f(81,m+i);
    glVertex2f(83,n+j);

    glVertex2f(85,m+i);
    glVertex2f(87,n+j);

    glVertex2f(89,m+i);
    glVertex2f(91,n+j);

    glVertex2f(93,m+i);
    glVertex2f(95,n+j);
    glEnd();
}

void line4()
{

    int i=-14,j=-20;
     glLineWidth(2);
    glColor3f(1,1,1);

    glBegin(GL_LINES);

    glVertex2f(-99,m+i);
    glVertex2f(-97,n+j);

    glVertex2f(-95,m+i);
    glVertex2f(-93,n+j);

    glVertex2f(-91,m+i);
    glVertex2f(-89,n+j);

    glVertex2f(-87,m+i);
    glVertex2f(-85,n+j);

    glVertex2f(-83,m+i);
    glVertex2f(-81,n+j);

    glVertex2f(-79,m+i);
    glVertex2f(-77,n+j);

    glVertex2f(-75,m+i);
    glVertex2f(-73,n+j);


    glVertex2f(-71,m+i);
    glVertex2f(-69,n+j);

    glVertex2f(-67,m+i);
    glVertex2f(-65,n+j);


    glVertex2f(-63,m+i);
    glVertex2f(-61,n+j);


    glVertex2f(-59,m+i);
    glVertex2f(-57,n+j);


    glVertex2f(-55,m+i);
    glVertex2f(-53,n+j);


    glVertex2f(-51,m+i);
    glVertex2f(-49,n+j);


    glVertex2f(-47,m+i);
    glVertex2f(-45,n+j);


    glVertex2f(-43,m+i);
    glVertex2f(-41,n+j);


    glVertex2f(-39,m+i);
    glVertex2f(-37,n+j);

    glVertex2f(-35,m+i);
    glVertex2f(-33,n+j);

    glVertex2f(-31,m+i);
    glVertex2f(-29,n+j);


    glVertex2f(-27,m+i);
    glVertex2f(-25,n+j);

    glVertex2f(-23,m+i);
    glVertex2f(-21,n+j);

    glVertex2f(-19,m+i);
    glVertex2f(-17,n+j);

    glVertex2f(-15,m+i);
    glVertex2f(-13,n+j);

    glVertex2f(-11,m+i);
    glVertex2f(-9,n+j);

    glVertex2f(-7,m+i);
    glVertex2f(-5,n+j);

    glVertex2f(-3,m+i);
    glVertex2f(-1,n+j);

    glVertex2f(1,m+i);
    glVertex2f(3,n+j);



    glVertex2f(5,m+i);
    glVertex2f(7,n+j);


    glVertex2f(9,m+i);
    glVertex2f(11,n+j);



    glVertex2f(13,m+i);
    glVertex2f(15,n+j);

    glVertex2f(17,m+i);
    glVertex2f(19,n+j);

    glVertex2f(21,m+i);
    glVertex2f(23,n+j);

    glVertex2f(25,m+i);
    glVertex2f(27,n+j);

    glVertex2f(29,m+i);
    glVertex2f(31,n+j);


    glVertex2f(33,m+i);
    glVertex2f(35,n+j);

    glVertex2f(37,m+i);
    glVertex2f(39,n+j);

    glVertex2f(41,m+i);
    glVertex2f(43,n+j);

    glVertex2f(45,m+i);
    glVertex2f(47,n+j);

    glVertex2f(49,m+i);
    glVertex2f(51,n+j);


    glVertex2f(53,m+i);
    glVertex2f(55,n+j);

    glVertex2f(57,m+i);
    glVertex2f(59,n+j);


    glVertex2f(61,m+i);
    glVertex2f(63,n+j);


    glVertex2f(65,m+i);
    glVertex2f(67,n+j);


    glVertex2f(69,m+i);
    glVertex2f(71,n+j);


    glVertex2f(73,m+i);
    glVertex2f(75,n+j);

    glVertex2f(77,m+i);
    glVertex2f(79,n+j);

    glVertex2f(81,m+i);
    glVertex2f(83,n+j);

    glVertex2f(85,m+i);
    glVertex2f(87,n+j);

    glVertex2f(89,m+i);
    glVertex2f(91,n+j);

    glVertex2f(93,m+i);
    glVertex2f(95,n+j);
    glEnd();
}

void line5()
{
    int i=-35,j=-39;
     glLineWidth(2);
    glColor3f(1,1,1);

    glBegin(GL_LINES);

    glVertex2f(-99,m+i);
    glVertex2f(-97,n+j);

    glVertex2f(-95,m+i);
    glVertex2f(-93,n+j);

    glVertex2f(-91,m+i);
    glVertex2f(-89,n+j);

    glVertex2f(-87,m+i);
    glVertex2f(-85,n+j);

    glVertex2f(-83,m+i);
    glVertex2f(-81,n+j);

    glVertex2f(-79,m+i);
    glVertex2f(-77,n+j);

    glVertex2f(-75,m+i);
    glVertex2f(-73,n+j);


    glVertex2f(-71,m+i);
    glVertex2f(-69,n+j);

    glVertex2f(-67,m+i);
    glVertex2f(-65,n+j);


    glVertex2f(-63,m+i);
    glVertex2f(-61,n+j);


    glVertex2f(-59,m+i);
    glVertex2f(-57,n+j);


    glVertex2f(-55,m+i);
    glVertex2f(-53,n+j);


    glVertex2f(-51,m+i);
    glVertex2f(-49,n+j);


    glVertex2f(-47,m+i);
    glVertex2f(-45,n+j);


    glVertex2f(-43,m+i);
    glVertex2f(-41,n+j);


    glVertex2f(-39,m+i);
    glVertex2f(-37,n+j);

    glVertex2f(-35,m+i);
    glVertex2f(-33,n+j);

    glVertex2f(-31,m+i);
    glVertex2f(-29,n+j);


    glVertex2f(-27,m+i);
    glVertex2f(-25,n+j);

    glVertex2f(-23,m+i);
    glVertex2f(-21,n+j);

    glVertex2f(-19,m+i);
    glVertex2f(-17,n+j);

    glVertex2f(-15,m+i);
    glVertex2f(-13,n+j);

    glVertex2f(-11,m+i);
    glVertex2f(-9,n+j);

    glVertex2f(-7,m+i);
    glVertex2f(-5,n+j);

    glVertex2f(-3,m+i);
    glVertex2f(-1,n+j);

    glVertex2f(1,m+i);
    glVertex2f(3,n+j);



    glVertex2f(5,m+i);
    glVertex2f(7,n+j);


    glVertex2f(9,m+i);
    glVertex2f(11,n+j);



    glVertex2f(13,m+i);
    glVertex2f(15,n+j);

    glVertex2f(17,m+i);
    glVertex2f(19,n+j);

    glVertex2f(21,m+i);
    glVertex2f(23,n+j);

    glVertex2f(25,m+i);
    glVertex2f(27,n+j);

    glVertex2f(29,m+i);
    glVertex2f(31,n+j);


    glVertex2f(33,m+i);
    glVertex2f(35,n+j);

    glVertex2f(37,m+i);
    glVertex2f(39,n+j);

    glVertex2f(41,m+i);
    glVertex2f(43,n+j);

    glVertex2f(45,m+i);
    glVertex2f(47,n+j);

    glVertex2f(49,m+i);
    glVertex2f(51,n+j);


    glVertex2f(53,m+i);
    glVertex2f(55,n+j);

    glVertex2f(57,m+i);
    glVertex2f(59,n+j);


    glVertex2f(61,m+i);
    glVertex2f(63,n+j);


    glVertex2f(65,m+i);
    glVertex2f(67,n+j);


    glVertex2f(69,m+i);
    glVertex2f(71,n+j);


    glVertex2f(73,m+i);
    glVertex2f(75,n+j);

    glVertex2f(77,m+i);
    glVertex2f(79,n+j);

    glVertex2f(81,m+i);
    glVertex2f(83,n+j);

    glVertex2f(85,m+i);
    glVertex2f(87,n+j);

    glVertex2f(89,m+i);
    glVertex2f(91,n+j);

    glVertex2f(93,m+i);
    glVertex2f(95,n+j);
    glEnd();
}

void line6()
{
    int i=-50,j=-54;
     glLineWidth(2);
    glColor3f(1,1,1);

    glBegin(GL_LINES);

    glVertex2f(-99,m+i);
    glVertex2f(-97,n+j);

    glVertex2f(-95,m+i);
    glVertex2f(-93,n+j);

    glVertex2f(-91,m+i);
    glVertex2f(-89,n+j);

    glVertex2f(-87,m+i);
    glVertex2f(-85,n+j);

    glVertex2f(-83,m+i);
    glVertex2f(-81,n+j);

    glVertex2f(-79,m+i);
    glVertex2f(-77,n+j);

    glVertex2f(-75,m+i);
    glVertex2f(-73,n+j);


    glVertex2f(-71,m+i);
    glVertex2f(-69,n+j);

    glVertex2f(-67,m+i);
    glVertex2f(-65,n+j);


    glVertex2f(-63,m+i);
    glVertex2f(-61,n+j);


    glVertex2f(-59,m+i);
    glVertex2f(-57,n+j);


    glVertex2f(-55,m+i);
    glVertex2f(-53,n+j);


    glVertex2f(-51,m+i);
    glVertex2f(-49,n+j);


    glVertex2f(-47,m+i);
    glVertex2f(-45,n+j);


    glVertex2f(-43,m+i);
    glVertex2f(-41,n+j);


    glVertex2f(-39,m+i);
    glVertex2f(-37,n+j);

    glVertex2f(-35,m+i);
    glVertex2f(-33,n+j);

    glVertex2f(-31,m+i);
    glVertex2f(-29,n+j);


    glVertex2f(-27,m+i);
    glVertex2f(-25,n+j);

    glVertex2f(-23,m+i);
    glVertex2f(-21,n+j);

    glVertex2f(-19,m+i);
    glVertex2f(-17,n+j);

    glVertex2f(-15,m+i);
    glVertex2f(-13,n+j);

    glVertex2f(-11,m+i);
    glVertex2f(-9,n+j);

    glVertex2f(-7,m+i);
    glVertex2f(-5,n+j);

    glVertex2f(-3,m+i);
    glVertex2f(-1,n+j);

    glVertex2f(1,m+i);
    glVertex2f(3,n+j);



    glVertex2f(5,m+i);
    glVertex2f(7,n+j);


    glVertex2f(9,m+i);
    glVertex2f(11,n+j);



    glVertex2f(13,m+i);
    glVertex2f(15,n+j);

    glVertex2f(17,m+i);
    glVertex2f(19,n+j);

    glVertex2f(21,m+i);
    glVertex2f(23,n+j);

    glVertex2f(25,m+i);
    glVertex2f(27,n+j);

    glVertex2f(29,m+i);
    glVertex2f(31,n+j);


    glVertex2f(33,m+i);
    glVertex2f(35,n+j);

    glVertex2f(37,m+i);
    glVertex2f(39,n+j);

    glVertex2f(41,m+i);
    glVertex2f(43,n+j);

    glVertex2f(45,m+i);
    glVertex2f(47,n+j);

    glVertex2f(49,m+i);
    glVertex2f(51,n+j);


    glVertex2f(53,m+i);
    glVertex2f(55,n+j);

    glVertex2f(57,m+i);
    glVertex2f(59,n+j);


    glVertex2f(61,m+i);
    glVertex2f(63,n+j);


    glVertex2f(65,m+i);
    glVertex2f(67,n+j);


    glVertex2f(69,m+i);
    glVertex2f(71,n+j);


    glVertex2f(73,m+i);
    glVertex2f(75,n+j);

    glVertex2f(77,m+i);
    glVertex2f(79,n+j);

    glVertex2f(81,m+i);
    glVertex2f(83,n+j);

    glVertex2f(85,m+i);
    glVertex2f(87,n+j);

    glVertex2f(89,m+i);
    glVertex2f(91,n+j);

    glVertex2f(93,m+i);
    glVertex2f(95,n+j);
    glEnd();
}

void line7()
{

    int i=-60,j=-66;
     glLineWidth(2);
    glColor3f(1,1,1);

    glBegin(GL_LINES);

    glVertex2f(-99,m+i);
    glVertex2f(-97,n+j);

    glVertex2f(-95,m+i);
    glVertex2f(-93,n+j);

    glVertex2f(-91,m+i);
    glVertex2f(-89,n+j);

    glVertex2f(-87,m+i);
    glVertex2f(-85,n+j);

    glVertex2f(-83,m+i);
    glVertex2f(-81,n+j);

    glVertex2f(-79,m+i);
    glVertex2f(-77,n+j);

    glVertex2f(-75,m+i);
    glVertex2f(-73,n+j);


    glVertex2f(-71,m+i);
    glVertex2f(-69,n+j);

    glVertex2f(-67,m+i);
    glVertex2f(-65,n+j);


    glVertex2f(-63,m+i);
    glVertex2f(-61,n+j);


    glVertex2f(-59,m+i);
    glVertex2f(-57,n+j);


    glVertex2f(-55,m+i);
    glVertex2f(-53,n+j);


    glVertex2f(-51,m+i);
    glVertex2f(-49,n+j);


    glVertex2f(-47,m+i);
    glVertex2f(-45,n+j);


    glVertex2f(-43,m+i);
    glVertex2f(-41,n+j);


    glVertex2f(-39,m+i);
    glVertex2f(-37,n+j);

    glVertex2f(-35,m+i);
    glVertex2f(-33,n+j);

    glVertex2f(-31,m+i);
    glVertex2f(-29,n+j);


    glVertex2f(-27,m+i);
    glVertex2f(-25,n+j);

    glVertex2f(-23,m+i);
    glVertex2f(-21,n+j);

    glVertex2f(-19,m+i);
    glVertex2f(-17,n+j);

    glVertex2f(-15,m+i);
    glVertex2f(-13,n+j);

    glVertex2f(-11,m+i);
    glVertex2f(-9,n+j);

    glVertex2f(-7,m+i);
    glVertex2f(-5,n+j);

    glVertex2f(-3,m+i);
    glVertex2f(-1,n+j);

    glVertex2f(1,m+i);
    glVertex2f(3,n+j);



    glVertex2f(5,m+i);
    glVertex2f(7,n+j);


    glVertex2f(9,m+i);
    glVertex2f(11,n+j);



    glVertex2f(13,m+i);
    glVertex2f(15,n+j);

    glVertex2f(17,m+i);
    glVertex2f(19,n+j);

    glVertex2f(21,m+i);
    glVertex2f(23,n+j);

    glVertex2f(25,m+i);
    glVertex2f(27,n+j);

    glVertex2f(29,m+i);
    glVertex2f(31,n+j);


    glVertex2f(33,m+i);
    glVertex2f(35,n+j);

    glVertex2f(37,m+i);
    glVertex2f(39,n+j);

    glVertex2f(41,m+i);
    glVertex2f(43,n+j);

    glVertex2f(45,m+i);
    glVertex2f(47,n+j);

    glVertex2f(49,m+i);
    glVertex2f(51,n+j);


    glVertex2f(53,m+i);
    glVertex2f(55,n+j);

    glVertex2f(57,m+i);
    glVertex2f(59,n+j);


    glVertex2f(61,m+i);
    glVertex2f(63,n+j);


    glVertex2f(65,m+i);
    glVertex2f(67,n+j);


    glVertex2f(69,m+i);
    glVertex2f(71,n+j);


    glVertex2f(73,m+i);
    glVertex2f(75,n+j);

    glVertex2f(77,m+i);
    glVertex2f(79,n+j);

    glVertex2f(81,m+i);
    glVertex2f(83,n+j);

    glVertex2f(85,m+i);
    glVertex2f(87,n+j);

    glVertex2f(89,m+i);
    glVertex2f(91,n+j);

    glVertex2f(93,m+i);
    glVertex2f(95,n+j);
    glEnd();
}

void move_rain()
{
    m-=.089;
    n-=.089;
    if(m<-40)
    {
        m=-10;
        n=-10;
    }
    glutPostRedisplay();
}

void line8()
{

    int i=-75,j=-81;
     glLineWidth(2);
    glColor3f(1,1,1);

    glBegin(GL_LINES);

    glVertex2f(-99,m+i);
    glVertex2f(-97,n+j);

    glVertex2f(-95,m+i);
    glVertex2f(-93,n+j);

    glVertex2f(-91,m+i);
    glVertex2f(-89,n+j);

    glVertex2f(-87,m+i);
    glVertex2f(-85,n+j);

    glVertex2f(-83,m+i);
    glVertex2f(-81,n+j);

    glVertex2f(-79,m+i);
    glVertex2f(-77,n+j);

    glVertex2f(-75,m+i);
    glVertex2f(-73,n+j);


    glVertex2f(-71,m+i);
    glVertex2f(-69,n+j);

    glVertex2f(-67,m+i);
    glVertex2f(-65,n+j);


    glVertex2f(-63,m+i);
    glVertex2f(-61,n+j);


    glVertex2f(-59,m+i);
    glVertex2f(-57,n+j);


    glVertex2f(-55,m+i);
    glVertex2f(-53,n+j);


    glVertex2f(-51,m+i);
    glVertex2f(-49,n+j);


    glVertex2f(-47,m+i);
    glVertex2f(-45,n+j);


    glVertex2f(-43,m+i);
    glVertex2f(-41,n+j);


    glVertex2f(-39,m+i);
    glVertex2f(-37,n+j);

    glVertex2f(-35,m+i);
    glVertex2f(-33,n+j);

    glVertex2f(-31,m+i);
    glVertex2f(-29,n+j);


    glVertex2f(-27,m+i);
    glVertex2f(-25,n+j);

    glVertex2f(-23,m+i);
    glVertex2f(-21,n+j);

    glVertex2f(-19,m+i);
    glVertex2f(-17,n+j);

    glVertex2f(-15,m+i);
    glVertex2f(-13,n+j);

    glVertex2f(-11,m+i);
    glVertex2f(-9,n+j);

    glVertex2f(-7,m+i);
    glVertex2f(-5,n+j);

    glVertex2f(-3,m+i);
    glVertex2f(-1,n+j);

    glVertex2f(1,m+i);
    glVertex2f(3,n+j);



    glVertex2f(5,m+i);
    glVertex2f(7,n+j);


    glVertex2f(9,m+i);
    glVertex2f(11,n+j);



    glVertex2f(13,m+i);
    glVertex2f(15,n+j);

    glVertex2f(17,m+i);
    glVertex2f(19,n+j);

    glVertex2f(21,m+i);
    glVertex2f(23,n+j);

    glVertex2f(25,m+i);
    glVertex2f(27,n+j);

    glVertex2f(29,m+i);
    glVertex2f(31,n+j);


    glVertex2f(33,m+i);
    glVertex2f(35,n+j);

    glVertex2f(37,m+i);
    glVertex2f(39,n+j);

    glVertex2f(41,m+i);
    glVertex2f(43,n+j);

    glVertex2f(45,m+i);
    glVertex2f(47,n+j);

    glVertex2f(49,m+i);
    glVertex2f(51,n+j);


    glVertex2f(53,m+i);
    glVertex2f(55,n+j);

    glVertex2f(57,m+i);
    glVertex2f(59,n+j);


    glVertex2f(61,m+i);
    glVertex2f(63,n+j);


    glVertex2f(65,m+i);
    glVertex2f(67,n+j);


    glVertex2f(69,m+i);
    glVertex2f(71,n+j);


    glVertex2f(73,m+i);
    glVertex2f(75,n+j);

    glVertex2f(77,m+i);
    glVertex2f(79,n+j);

    glVertex2f(81,m+i);
    glVertex2f(83,n+j);

    glVertex2f(85,m+i);
    glVertex2f(87,n+j);

    glVertex2f(89,m+i);
    glVertex2f(91,n+j);

    glVertex2f(93,m+i);
    glVertex2f(95,n+j);
    glEnd();
}


void line9()
{

    int i=-85,j=-91;
     glLineWidth(2);
    glColor3f(1,1,1);

    glBegin(GL_LINES);

    glVertex2f(-99,m+i);
    glVertex2f(-97,n+j);

    glVertex2f(-95,m+i);
    glVertex2f(-93,n+j);

    glVertex2f(-91,m+i);
    glVertex2f(-89,n+j);

    glVertex2f(-87,m+i);
    glVertex2f(-85,n+j);

    glVertex2f(-83,m+i);
    glVertex2f(-81,n+j);

    glVertex2f(-79,m+i);
    glVertex2f(-77,n+j);

    glVertex2f(-75,m+i);
    glVertex2f(-73,n+j);


    glVertex2f(-71,m+i);
    glVertex2f(-69,n+j);

    glVertex2f(-67,m+i);
    glVertex2f(-65,n+j);


    glVertex2f(-63,m+i);
    glVertex2f(-61,n+j);


    glVertex2f(-59,m+i);
    glVertex2f(-57,n+j);


    glVertex2f(-55,m+i);
    glVertex2f(-53,n+j);


    glVertex2f(-51,m+i);
    glVertex2f(-49,n+j);


    glVertex2f(-47,m+i);
    glVertex2f(-45,n+j);


    glVertex2f(-43,m+i);
    glVertex2f(-41,n+j);


    glVertex2f(-39,m+i);
    glVertex2f(-37,n+j);

    glVertex2f(-35,m+i);
    glVertex2f(-33,n+j);

    glVertex2f(-31,m+i);
    glVertex2f(-29,n+j);


    glVertex2f(-27,m+i);
    glVertex2f(-25,n+j);

    glVertex2f(-23,m+i);
    glVertex2f(-21,n+j);

    glVertex2f(-19,m+i);
    glVertex2f(-17,n+j);

    glVertex2f(-15,m+i);
    glVertex2f(-13,n+j);

    glVertex2f(-11,m+i);
    glVertex2f(-9,n+j);

    glVertex2f(-7,m+i);
    glVertex2f(-5,n+j);

    glVertex2f(-3,m+i);
    glVertex2f(-1,n+j);

    glVertex2f(1,m+i);
    glVertex2f(3,n+j);



    glVertex2f(5,m+i);
    glVertex2f(7,n+j);


    glVertex2f(9,m+i);
    glVertex2f(11,n+j);



    glVertex2f(13,m+i);
    glVertex2f(15,n+j);

    glVertex2f(17,m+i);
    glVertex2f(19,n+j);

    glVertex2f(21,m+i);
    glVertex2f(23,n+j);

    glVertex2f(25,m+i);
    glVertex2f(27,n+j);

    glVertex2f(29,m+i);
    glVertex2f(31,n+j);


    glVertex2f(33,m+i);
    glVertex2f(35,n+j);

    glVertex2f(37,m+i);
    glVertex2f(39,n+j);

    glVertex2f(41,m+i);
    glVertex2f(43,n+j);

    glVertex2f(45,m+i);
    glVertex2f(47,n+j);

    glVertex2f(49,m+i);
    glVertex2f(51,n+j);


    glVertex2f(53,m+i);
    glVertex2f(55,n+j);

    glVertex2f(57,m+i);
    glVertex2f(59,n+j);


    glVertex2f(61,m+i);
    glVertex2f(63,n+j);


    glVertex2f(65,m+i);
    glVertex2f(67,n+j);


    glVertex2f(69,m+i);
    glVertex2f(71,n+j);


    glVertex2f(73,m+i);
    glVertex2f(75,n+j);

    glVertex2f(77,m+i);
    glVertex2f(79,n+j);

    glVertex2f(81,m+i);
    glVertex2f(83,n+j);

    glVertex2f(85,m+i);
    glVertex2f(87,n+j);

    glVertex2f(89,m+i);
    glVertex2f(91,n+j);

    glVertex2f(93,m+i);
    glVertex2f(95,n+j);
    glEnd();
}


void line10()
{
    int i=56,j=50;
     glLineWidth(2);
    glColor3f(1,1,1);

    glBegin(GL_LINES);

    glVertex2f(-99,m+i);
    glVertex2f(-97,n+j);

    glVertex2f(-95,m+i);
    glVertex2f(-93,n+j);

    glVertex2f(-91,m+i);
    glVertex2f(-89,n+j);

    glVertex2f(-87,m+i);
    glVertex2f(-85,n+j);

    glVertex2f(-83,m+i);
    glVertex2f(-81,n+j);

    glVertex2f(-79,m+i);
    glVertex2f(-77,n+j);

    glVertex2f(-75,m+i);
    glVertex2f(-73,n+j);


    glVertex2f(-71,m+i);
    glVertex2f(-69,n+j);

    glVertex2f(-67,m+i);
    glVertex2f(-65,n+j);


    glVertex2f(-63,m+i);
    glVertex2f(-61,n+j);


    glVertex2f(-59,m+i);
    glVertex2f(-57,n+j);


    glVertex2f(-55,m+i);
    glVertex2f(-53,n+j);


    glVertex2f(-51,m+i);
    glVertex2f(-49,n+j);


    glVertex2f(-47,m+i);
    glVertex2f(-45,n+j);


    glVertex2f(-43,m+i);
    glVertex2f(-41,n+j);


    glVertex2f(-39,m+i);
    glVertex2f(-37,n+j);

    glVertex2f(-35,m+i);
    glVertex2f(-33,n+j);

    glVertex2f(-31,m+i);
    glVertex2f(-29,n+j);


    glVertex2f(-27,m+i);
    glVertex2f(-25,n+j);

    glVertex2f(-23,m+i);
    glVertex2f(-21,n+j);

    glVertex2f(-19,m+i);
    glVertex2f(-17,n+j);

    glVertex2f(-15,m+i);
    glVertex2f(-13,n+j);

    glVertex2f(-11,m+i);
    glVertex2f(-9,n+j);

    glVertex2f(-7,m+i);
    glVertex2f(-5,n+j);

    glVertex2f(-3,m+i);
    glVertex2f(-1,n+j);

    glVertex2f(1,m+i);
    glVertex2f(3,n+j);



    glVertex2f(5,m+i);
    glVertex2f(7,n+j);


    glVertex2f(9,m+i);
    glVertex2f(11,n+j);



    glVertex2f(13,m+i);
    glVertex2f(15,n+j);

    glVertex2f(17,m+i);
    glVertex2f(19,n+j);

    glVertex2f(21,m+i);
    glVertex2f(23,n+j);

    glVertex2f(25,m+i);
    glVertex2f(27,n+j);

    glVertex2f(29,m+i);
    glVertex2f(31,n+j);


    glVertex2f(33,m+i);
    glVertex2f(35,n+j);

    glVertex2f(37,m+i);
    glVertex2f(39,n+j);

    glVertex2f(41,m+i);
    glVertex2f(43,n+j);

    glVertex2f(45,m+i);
    glVertex2f(47,n+j);

    glVertex2f(49,m+i);
    glVertex2f(51,n+j);


    glVertex2f(53,m+i);
    glVertex2f(55,n+j);

    glVertex2f(57,m+i);
    glVertex2f(59,n+j);


    glVertex2f(61,m+i);
    glVertex2f(63,n+j);


    glVertex2f(65,m+i);
    glVertex2f(67,n+j);


    glVertex2f(69,m+i);
    glVertex2f(71,n+j);


    glVertex2f(73,m+i);
    glVertex2f(75,n+j);

    glVertex2f(77,m+i);
    glVertex2f(79,n+j);

    glVertex2f(81,m+i);
    glVertex2f(83,n+j);

    glVertex2f(85,m+i);
    glVertex2f(87,n+j);

    glVertex2f(89,m+i);
    glVertex2f(91,n+j);

    glVertex2f(93,m+i);
    glVertex2f(95,n+j);
    glEnd();
}

void line11()
{

    int i=76,j=70;
     glLineWidth(2);
     glColor3f(1,1,1);

    glBegin(GL_LINES);

    glVertex2f(-99,m+i);
    glVertex2f(-97,n+j);

    glVertex2f(-95,m+i);
    glVertex2f(-93,n+j);

    glVertex2f(-91,m+i);
    glVertex2f(-89,n+j);

    glVertex2f(-87,m+i);
    glVertex2f(-85,n+j);

    glVertex2f(-83,m+i);
    glVertex2f(-81,n+j);

    glVertex2f(-79,m+i);
    glVertex2f(-77,n+j);

    glVertex2f(-75,m+i);
    glVertex2f(-73,n+j);


    glVertex2f(-71,m+i);
    glVertex2f(-69,n+j);

    glVertex2f(-67,m+i);
    glVertex2f(-65,n+j);


    glVertex2f(-63,m+i);
    glVertex2f(-61,n+j);


    glVertex2f(-59,m+i);
    glVertex2f(-57,n+j);


    glVertex2f(-55,m+i);
    glVertex2f(-53,n+j);


    glVertex2f(-51,m+i);
    glVertex2f(-49,n+j);


    glVertex2f(-47,m+i);
    glVertex2f(-45,n+j);


    glVertex2f(-43,m+i);
    glVertex2f(-41,n+j);


    glVertex2f(-39,m+i);
    glVertex2f(-37,n+j);

    glVertex2f(-35,m+i);
    glVertex2f(-33,n+j);

    glVertex2f(-31,m+i);
    glVertex2f(-29,n+j);


    glVertex2f(-27,m+i);
    glVertex2f(-25,n+j);

    glVertex2f(-23,m+i);
    glVertex2f(-21,n+j);

    glVertex2f(-19,m+i);
    glVertex2f(-17,n+j);

    glVertex2f(-15,m+i);
    glVertex2f(-13,n+j);

    glVertex2f(-11,m+i);
    glVertex2f(-9,n+j);

    glVertex2f(-7,m+i);
    glVertex2f(-5,n+j);

    glVertex2f(-3,m+i);
    glVertex2f(-1,n+j);

    glVertex2f(1,m+i);
    glVertex2f(3,n+j);



    glVertex2f(5,m+i);
    glVertex2f(7,n+j);


    glVertex2f(9,m+i);
    glVertex2f(11,n+j);



    glVertex2f(13,m+i);
    glVertex2f(15,n+j);

    glVertex2f(17,m+i);
    glVertex2f(19,n+j);

    glVertex2f(21,m+i);
    glVertex2f(23,n+j);

    glVertex2f(25,m+i);
    glVertex2f(27,n+j);

    glVertex2f(29,m+i);
    glVertex2f(31,n+j);


    glVertex2f(33,m+i);
    glVertex2f(35,n+j);

    glVertex2f(37,m+i);
    glVertex2f(39,n+j);

    glVertex2f(41,m+i);
    glVertex2f(43,n+j);

    glVertex2f(45,m+i);
    glVertex2f(47,n+j);

    glVertex2f(49,m+i);
    glVertex2f(51,n+j);


    glVertex2f(53,m+i);
    glVertex2f(55,n+j);

    glVertex2f(57,m+i);
    glVertex2f(59,n+j);


    glVertex2f(61,m+i);
    glVertex2f(63,n+j);


    glVertex2f(65,m+i);
    glVertex2f(67,n+j);


    glVertex2f(69,m+i);
    glVertex2f(71,n+j);


    glVertex2f(73,m+i);
    glVertex2f(75,n+j);

    glVertex2f(77,m+i);
    glVertex2f(79,n+j);

    glVertex2f(81,m+i);
    glVertex2f(83,n+j);

    glVertex2f(85,m+i);
    glVertex2f(87,n+j);

    glVertex2f(89,m+i);
    glVertex2f(91,n+j);

    glVertex2f(93,m+i);
    glVertex2f(95,n+j);
    glEnd();
}



void rain()
{

    line1();
    line2();
    line3();
    line4();
    line5();
    line6();
    line7();
    line8();
    line9();
    line10();
    line11();

}

void lighting(int value)
{
    printf("before flag=%d\n",flag);
    if(flag==0)
    {

        glClearColor(1,1,1,1);

        flag=1;
    }else
    {
        glClearColor (0.0, 0.0, 0.0, 0.0);
        sndPlaySound("D:\\GRAPHICS LAB\\abc\\thunder.wav",SND_ASYNC);
        flag=0;
    }

}
void cloud_sky()
{
    glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(-100,40);
    glVertex2f(100,40);
    glVertex2f(100,100);
    glVertex2f(-100,100);
    glEnd();

}

float bc=1,bc2=-1;
void blackcloud1()
{
    glColor3ub(149, 165, 166);
    circle(20,20,bc-40,70);
    circle(10,15,bc-50,80);
    circle(10,15,bc-35,80);
    circle(10,15,bc-25,70);
    circle(10,15,bc-63,67);
    circle(10,15,bc-55,60);
    circle(10,15,bc-30,60);
    circle(10,15,bc-45,60);
}

void blackcloud3()
{
    glColor3ub(149, 165, 166);
    circle(20,20,bc-75,70);
    circle(10,15,bc-85,80);
    circle(10,15,bc-70,80);
    circle(10,15,bc-60,70);
    circle(10,15,bc-98,67);
    circle(10,15,bc-90,60);
    circle(10,15,bc-65,60);
    circle(10,15,bc-80,60);
}

void black_move1()
{

    if(bc<25)
    {
        bc+=.02;
        glutPostRedisplay();
    }else{

    }
}
void blackcloud2()
{
    glColor3ub(149, 165, 166);
    circle(20,20,bc2+40,70);
    circle(10,15,bc2+50,80);
    circle(10,15,bc2+35,80);
    circle(10,15,bc2+25,70);
    circle(10,15,bc2+63,67);
    circle(10,15,bc2+55,60);
    circle(10,15,bc2+30,60);
    circle(10,15,bc2+45,60);
}

void blackcloud4()
{
    glColor3ub(149, 165, 166);
    circle(20,20,bc2+75,70);
    circle(10,15,bc2+85,80);
    circle(10,15,bc2+70,80);
    circle(10,15,bc2+60,70);
    circle(10,15,bc2+98,67);
    circle(10,15,bc2+90,60);
    circle(10,15,bc2+65,60);
    circle(10,15,bc2+80,60);
}

void black_move2()
{
    if(bc2>-20)
    {
        bc2-=0.02;
        glutPostRedisplay();
    }else
    {

    }
}

void raining(void)
{

    glClear(GL_COLOR_BUFFER_BIT);


    river();
    cloud_sky();

    glPushMatrix();
    airplane();
    glPopMatrix();

    glPushMatrix();
    blackcloud1();
    black_move1();
    glPopMatrix();

    glPushMatrix();
    blackcloud2();
    black_move2();
    glPopMatrix();


    glPushMatrix();
    blackcloud3();
    glPopMatrix();

    glPushMatrix();
    blackcloud4();
    glPopMatrix();

    hill();
    stand_tree();


    glPushMatrix();
    small_boat();
    glPopMatrix();


    glPushMatrix();
    make_left_field();
    glPopMatrix();

    khor();
    glPushMatrix();
    house2();
    glPopMatrix();

    glPushMatrix();
    house1();
    glPopMatrix();

    glPushMatrix();

    big_tree();
    cow_drink();

    glPopMatrix();


    flower2();

    glPushMatrix();
    glTranslatef(2,-45,0);
    flower2();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-50,-45,0);
    flower2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-60,-15,0);
    flower2();
    glPopMatrix();


    glPushMatrix();
    boat();
    boat_man();
    boat_move();
    glPopMatrix();


    glPushMatrix();
    palm_tree1();
    glPopMatrix();


    glPushMatrix();
    palm_tree2();
    glTranslatef(-20,0,0);
    palm_tree1();
    glPopMatrix();




    glPushMatrix();
    palm_tree3();
    glPopMatrix();

    glPushMatrix();
    bottom_field();
    glPopMatrix();

    glPushMatrix();
    right_field();
    glPopMatrix();


    glPushMatrix();
    palm_tree2();
    palm_tree3();
    glPopMatrix();

    glPushMatrix();
    fish1();
    fish_move();
    glPopMatrix();

    glPushMatrix();
    fish2();
    glPopMatrix();

    glPushMatrix();
    fish3();
    glPopMatrix();


    glPushMatrix();
    stairs();
    glPopMatrix();

    //duck
    glPushMatrix();
    duck();

    glTranslatef(10,7,0);
    duck();

    glTranslatef(6,-8,0);
    duck();

    glPopMatrix();


    glPushMatrix();
    rain();
    move_rain();
    glPopMatrix();

    glPushMatrix();
    small_boat();
    glPopMatrix();

	glFlush();
	glutSwapBuffers();
}


void renderbitmap(float x, float y, void *font, char *string)
{
    char *c;
    glRasterPos2f(x,y);
    for(c=string; *c !='\0';c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void introscreen()
{
    glColor3f(1,1,1);
    char buf[100] = {0};
    sprintf(buf,"BEAUTIFUL VILLAGE SCENARIO OF BANGLADESH");
    renderbitmap(-40,30,GLUT_BITMAP_HELVETICA_18,buf);

    sprintf(buf,"DESIGNED BY");
    renderbitmap(10,0,GLUT_BITMAP_HELVETICA_18,buf);

    sprintf(buf,"ABDUR RAHMAN APU");
    renderbitmap(20,-10,GLUT_BITMAP_HELVETICA_18,buf);

    sprintf(buf,"ID:191-15-13025");
    renderbitmap(20,-20,GLUT_BITMAP_HELVETICA_18,buf);

    sprintf(buf,"DAFFODIL INTERNATIONAL UNIVERSITY");
    renderbitmap(20,-30,GLUT_BITMAP_HELVETICA_18,buf);
}
void draw()
{

    glClear(GL_COLOR_BUFFER_BIT);
    introscreen();
    glFlush();

    glutSwapBuffers();

}
//bangladesh flag
void title()
{
    glColor3ub(5, 196, 107);
    char buf[100] = {0};

    sprintf(buf,"Bangladesh emerged as a new nation in the world on 16th December, 1971");
    renderbitmap(300,660,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    sprintf(buf,":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    renderbitmap(400,640,GLUT_BITMAP_TIMES_ROMAN_24,buf);

    glColor3f(1, 0, 0);
    sprintf(buf,"Around thirty lakh people died during the war");
    renderbitmap(500,100,GLUT_BITMAP_TIMES_ROMAN_24,buf);

}

void start(void)
{
      glClearColor(0.96, 0.89, 0.55,1.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
      glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
      glLoadIdentity();
      //glOrtho(0, 300, 300, 0, -1, 1);
      glOrtho(0,1500,0,700,-150,150); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}
void bangladesh()
{

    glClear(GL_COLOR_BUFFER_BIT);


    title();

    //rectangle
    glPushMatrix();
    glColor3ub(0, 103, 71);
    glBegin(GL_POLYGON);
    glVertex2f(300,200);
    glVertex2f(1200,200);
    glVertex2f(1200,600);
    glVertex2f(300,600);
    glEnd();
    glPopMatrix();
    //end


    //circle
    glPushMatrix();
    glColor3ub(218, 41, 28);
    circle(190,180,760,400);
    glPopMatrix();
    //end

    //map
    glPushMatrix();

    //top
    glColor3ub(241, 196, 15);
    glBegin(GL_POLYGON);
    glVertex2f(700,470);
    glVertex2f(760,470);
    glVertex2f(760,510);
    glVertex2f(740,500);
    glVertex2f(680,520);
    glVertex2f(670,500);
    glEnd();

    //left triangle
    glColor3ub(241, 196, 15);
    glBegin(GL_TRIANGLES);
    glVertex2f(700,440);
    glVertex2f(700,470);
    glVertex2f(660,460);
    glEnd();

    //right triangle
    glColor3ub(241, 196, 15);
    glBegin(GL_TRIANGLES);
    glVertex2f(800,440);
    glVertex2f(900,460);
    glVertex2f(800,470);
    glEnd();


    //middle box
    glColor3ub(241, 196, 15);
    glBegin(GL_POLYGON);
    glVertex2f(700,340);
    glVertex2f(800,340);
    glVertex2f(800,470);
    glVertex2f(700,470);
    glEnd();

    //bottom right
    glColor3ub(241, 196, 15);
    glBegin(GL_QUADS);
    glVertex2f(800,400);
    glVertex2f(840,400);
    glVertex2f(840,290);
    glVertex2f(800,290);
    glEnd();
    glPopMatrix();

    //end



    //bottom_fighter_man
    glPushMatrix();
    glColor3f(0,0,0);
    //head
    circle(40,30,130,200);

    //gola
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(108,160);
    glVertex2f(152,160);
    glVertex2f(152,180);
    glVertex2f(108,180);
    glEnd();


    //body
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(90,100);
    glVertex2f(168,100);
    glVertex2f(168,170);
    glVertex2f(90,170);
    glEnd();

    //left hand
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(30,150);
    glVertex2f(90,150);
    glVertex2f(90,170);
    glVertex2f(30,170);
    glEnd();

    ////left hand up
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(25,150);
    glVertex2f(50,150);
    glVertex2f(70,250);
    glVertex2f(50,250);
    glEnd();

    //right hand
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(168,150);
    glVertex2f(225,150);
    glVertex2f(225,170);
    glVertex2f(168,170);
    glEnd();

    //right hand up
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(200,170);
    glVertex2f(225,170);
    glVertex2f(200,250);
    glVertex2f(180,250);
    glEnd();



    //left leg
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(75,70);
    glVertex2f(110,70);
    glVertex2f(130,100);
    glVertex2f(90,100);
    glEnd();

    //right leg
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(150,70);
    glVertex2f(180,70);
    glVertex2f(168,170);
    glVertex2f(130,100);
    glEnd();

    //gun
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(30,250);
    glVertex2f(250,250);
    glVertex2f(250,250);
    glVertex2f(30,270);
    glEnd();



    glPopMatrix();


    glFlush();





    glutSwapBuffers();
}



void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'd':
		    init();
			glutDisplayFunc(day);
			sndPlaySound("D:\\GRAPHICS LAB\\PROJECT\\Village_scene\\Sound\\day.wav",SND_ASYNC);
			break;

        case 'f':
            //glutDestroyWindow(1);
            glutInitWindowPosition(0,0);
            glutInitWindowSize(1500,700);
            start();
            glutDisplayFunc(bangladesh);
            sndPlaySound("Sound\\bd.wav",SND_ASYNC);
            break;


        case 'i':
            sndPlaySound("D:\\GRAPHICS LAB\\PROJECT\\Village_scene\\Sound\\bd.wav",SND_ASYNC);
			break;


        case 'l':
            sndPlaySound("D:\\GRAPHICS LAB\\PROJECT\\Village_scene\\Sound\\thunder.wav",SND_ASYNC);
			break;



		case 'n':
		    init();
            glutDisplayFunc(dark);
            sndPlaySound("D:\\GRAPHICS LAB\\PROJECT\\Village_scene\\Sound\\night.wav",SND_ASYNC);

			break;

        case 'N':
            sndPlaySound("D:\\GRAPHICS LAB\\PROJECT\\Village_scene\\Sound\\night.wav",SND_ASYNC);
            break;

        case 'p':
			glPushMatrix();
			glutIdleFunc(move_plane);
			glPopMatrix();
			break;

        case 'P':
            glutIdleFunc(NULL);
            break;

        case 'r':
            init();
            glutDisplayFunc(raining);
            //glutTimerFunc(900,move_palm,0);
            //glutTimerFunc(900,move_kite,0);
            sndPlaySound("D:\\GRAPHICS LAB\\PROJECT\\Village_scene\\Sound\\rain.wav",SND_ASYNC);

            break;
		case 's':
			 sndPlaySound(NULL,SND_ASYNC);
			 break;

        case 'w':
            sndPlaySound("D:\\GRAPHICS LAB\\PROJECT\\Village_scene\\Sound\\intro.wav",SND_ASYNC);
			break;

	  default:
			break;
	}
}

void spe_key(int key, int x, int y)
{

	switch (key) {
		case GLUT_KEY_LEFT:
                dx-=1;
                glutPostRedisplay();
				break;

		case GLUT_KEY_RIGHT:

				dx+=1;
				glutPostRedisplay();
				break;

        case GLUT_KEY_UP:

				dy+=1;
				glutPostRedisplay();
				break;

        case GLUT_KEY_DOWN:

				dy-=1;
				glutPostRedisplay();
				break;

	  default:
			break;
	}
}




int main(int argc,char **argv){


    //instruction

    printf("\n\n\t\t\t**********************Village scenario of Bangladesh**********************");


    printf("\n\n\t\tPage:");
    printf("\n\n\t\t1. Press 'b' for bangladesh flag page");
    printf("\n\n\t\t2. Press 'd' for day mode");
    printf("\n\n\t\t3. Press 'n' for night mode");
    printf("\n\n\t\t4. Press 'r' for rain mode");


    printf("\n\n\n\n\t\t Background music:");
    printf("\n\n\t\t2. Press 'w' for first page music.");
    printf("\n\n\t\t3. Press 'i' for bangladesh flag page music");
    printf("\n\n\t\t4. Press 'D' for day page music");
    printf("\n\n\t\t5. Press 'N' for night page music");
    printf("\n\n\t\t6. Press 'r' for rain page music");
    printf("\n\n\t\t7. Press 'l' for thunder music");
    printf("\n\n\t\t8. Press 's' to stop music");

    printf("\n\n\n\n\t\t Movement:");
    printf("\n\n\t\t1. Press arrow key for moving ducks.");
    printf("\n\n\t\t2. Press 'p' for moving airplane");
    printf("\n\n\t\t3. Press 'P' to stop airplane");







    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1500,700);
    glutCreateWindow("Village");
    init();
    glutDisplayFunc(draw);
    sndPlaySound("D:\\GRAPHICS LAB\\PROJECT\\Village_scene\\Sound\\intro.wav",SND_ASYNC);
    glutKeyboardFunc(my_keyboard);
    glutSpecialFunc(spe_key);
    glutTimerFunc(900,move_palm,0);
    glutTimerFunc(900,move_kite,0);
    glutMainLoop();
    return 0;
}
