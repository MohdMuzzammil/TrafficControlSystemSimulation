#include<stdio.h>
#include<gl/glut.h>
GLint traffic_light=2,flag=0;
GLfloat origin=0,counter=10;
GLfloat traffic_light_color[][3]={{0,1,0},{1,1,0},{1,0,0}};
void car()
{
    glColor3f(1,1,1);
    int count=-20;
    glRasterPos2i(count,-22);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'|');
    for(int i=0;i<3;i++)
    {
        glRasterPos2i(count,-20);
        count+=3;
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'-');
    }
    glRasterPos2i(count,-20);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'/');
    glRasterPos2i(count+1,-17);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'/');
    count+=2;
    for(int i=0;i<5;i++)
    {
        glRasterPos2i(count,-15);
        count+=3;
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'-');
    }
    glRasterPos2i(count,-17);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'\\');
    count+=1;
    glRasterPos2i(count,-20);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'\\');
    for(int i=0;i<5;i++)
    {
        glRasterPos2i(count,-20);
        count+=3;
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'-');
    }
    glRasterPos2i(count,-22);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'|');
    count=-20;
    for(int i=0;i<14;i++)
    {
        if(i==3 || i==10)
        {
            glRasterPos2i(count,-24);
            count+=3;
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'O');
            continue;
        }
        glRasterPos2i(count,-24);
        count+=3;
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'-');
    }
    glFlush();
}
void idle11()
{
    counter-=0.01;
    if(counter<=0)
    {
        traffic_light++;
        traffic_light=traffic_light%3;
        if(traffic_light==2)flag=0;
        else flag=1;
        if(traffic_light==0 || traffic_light==2)
        {
            counter=10;
        }
        else counter=3;
    }
    if(flag)
    {
        origin+=0.05;
        glutPostRedisplay();
    }
    else
    {
        if((origin+20)<150)origin+=0.05;
        if((origin)>170)origin+=0.05;
        glutPostRedisplay();
    }
}
void road()
{
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(-30,0);
    glVertex2i(200,0);
    glVertex2i(200,-30);
    glVertex2i(-30,-30);
    glEnd();
}
void zebra()
{
    glColor3f(1,1,1);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(150,-10);
    glVertex2i(170,-10);
    glVertex2i(150,-5);
    glVertex2i(170,-5);
    glVertex2i(150,-15);
    glVertex2i(170,-15);
    glVertex2i(150,0);
    glVertex2i(170,0);
    glVertex2i(150,-20);
    glVertex2i(170,-20);
    glVertex2i(150,-25);
    glVertex2i(170,-25);
    glVertex2i(150,-30);
    glVertex2i(170,-30);
    glEnd();
}
void traffic_box()
{
    glPushMatrix();
    glColor3fv(traffic_light_color[traffic_light]);
    glBegin(GL_POLYGON);
    glVertex2i(170,160);
    glVertex2i(190,160);
    glVertex2i(190,90);
    glVertex2i(170,90);
    glEnd();
    glPopMatrix();
}
void stand()
{
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(177,90);
    glVertex2i(183,90);
    glVertex2i(183,0);
    glVertex2i(177,0);
    glEnd();
}
void display11()
{
    idle11();
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0.8,1,1);
    road();
    zebra();
    traffic_box();
    stand();
    glPushMatrix();
    glColor3f(1,0,0.3);
    if(origin>200)origin=0;
    glTranslatef(origin,0,0);
    car();
    glPopMatrix();
    glFlush();
}
void init11()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-30,200,-30,200,-30,200);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,1);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Traffic control system");
    glutDisplayFunc(display11);
    init11();
    glutMainLoop();
    return 0;
}
