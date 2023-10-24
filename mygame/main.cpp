#include <GL/glut.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include<stdio.h>
#include<unistd.h>
int phyWidth=600;
int physHeight= 600;
int logWidth= 100;
int logHeight=100;
int centerx= logWidth/2;
int centery=logHeight/2;
int sqWid=10;
int cx1=50,cy1=30,cx2=50,cy2=50,cx3=50,cy3=70;
//int sqWid=20;
bool sqUp=true;
int ply[5];int ii=0;
int sqDelta=-90;
int maxY=100;
 char strs[10]="";
char str[3],str2[3];
int xr,yr,op,r,rr,ans=-1;
 int count=0;char cnt[5];


void drawSquares();
void mouseClick2(int btn, int state, int x, int y);
void printtext(char*str,int x, int y);
void printsome(char*str,int x, int y);
void init2D(float r, float g, float b);
void Keyboard(unsigned char key, int x, int y);
void mouseClick(int btn, int state, int x, int y);
void display();void display2();
void mouseClick3(int btn, int state, int xx, int yy);




void Timer2(int value) {
glutTimerFunc(1500, Timer2, value);
glutPostRedisplay();
}
void Timer(int value) {
glutTimerFunc(0, Timer, value);
glutPostRedisplay();
}

int cal(int x,int y,int op)
{int r;
switch(op){
  case 42:return x*y;
  case 43:return x+y;
  case 45:return x-y;
  case 47:return x/y;}
}
void game(){
  xr=rand()%10+0;  yr=rand()%10+0;///dool men 0 until 9 only
 op=42+rand()%6;
if (op==46 || op==44) op=op-1;///mesh 3ayzenhom mesh operations aslun
 sprintf (str,"%d%c%d",xr,op,yr);///n2lb int to string
glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0,logWidth,0,logHeight);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity(); printsome("score:",6,90);
glPushMatrix();
glTranslatef(0,sqDelta,0);
glColor3f(1,0,0);
glBegin(GL_QUADS);//square
glVertex2i(45, 70);
glVertex2i(45, 80);
glVertex2i(65, 80);
glVertex2i(65, 70);
 glEnd();
 printtext(str,55,75);
glPopMatrix();
r=cal(xr,yr,op);
glutMouseFunc(mouseClick2);
 /*sprintf(str,"%d",rr);test test test law kano zay b3d walla ea
printsome(str,90,30);
sprintf(str2,"%d",ans);
printtext(str2,90,50);*/
if((ans==rr))
    { count++;
         rr=-1;
    }
 sprintf(cnt,"%d",count);
     printsome(cnt,15,90);
 if (abs(sqDelta)>maxY) sqUp=!sqUp ;
if (sqUp) sqDelta+=10;
if (sqDelta>40)//5eles el w2t
    {ply[ii]=count;
    glutDisplayFunc(display2);
    glutMouseFunc(mouseClick);ii++;Timer2(0);
glFlush();
glutSwapBuffers();

    }
//n change hena 3alashan 60 seconds
glFlush();
glutSwapBuffers();

}


void init2D(float r, float g, float b)
{
    glClearColor(r,g,b,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,logWidth,0.0,logHeight);

}
void printsome(char*str,int x, int y)
{
    glColor3f(0,0.0,1.0);//black
    glRasterPos2d(x,y);
    for(int i=0;i<strlen(str);i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
    }
    glFlush();
}
void printtext(char*str,int x, int y)
{
    glColor3f(1,1.0,1.0);//
    glRasterPos2d(x,y);
    for(int i=0;i<strlen(str);i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
    }
    glFlush();
}

void mouseClick2(int btn, int state, int xx, int yy)///beta3 el l3ba
{int mouseXX ,mouseYY;
 mouseXX = xx;
mouseXX=0.5+1.0*mouseXX*logWidth/phyWidth;
mouseYY = physHeight - yy;
mouseYY=0.5+1.0*mouseYY*logHeight/physHeight;


    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
  {
    //if( mouseXX>=0 && mouseXX<=5 && mouseYY >=0 && mouseYY <=5)
    {rr=cal(xr,yr,op);
    strcpy(strs,"");strcpy(str2,"");
    strcpy(cnt,"");
    glutKeyboardFunc(Keyboard);

    }
  }
}

void mouseClick3(int btn, int state, int xx, int yy)///beta3 el scores
{int mouseXX ,mouseYY;
 mouseXX = xx;
mouseXX=0.5+1.0*mouseXX*logWidth/phyWidth;
mouseYY = physHeight - yy;
mouseYY=0.5+1.0*mouseYY*logHeight/physHeight;


    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
  {
    glutDisplayFunc(display2);
    glutMouseFunc(mouseClick);
    //Timer2(0);

  }
}

void Keyboard(unsigned char key, int x, int y)
 {

{
     if(key=='0'){ strcat(strs,"0");}if(key=='1'){ strcat(strs,"1");}
       if(key=='2'){ strcat(strs,"2");}if(key=='3'){ strcat(strs,"3");}
       if(key=='4'){ strcat(strs,"4");}if(key=='6'){ strcat(strs,"6");}
       if(key=='5'){ strcat(strs,"5");}if(key=='7'){ strcat(strs,"7");}
       if(key=='8'){ strcat(strs,"8");}if(key=='9'){ strcat(strs,"9");}
}
if(key==13)
{
 ans=atoi(strs);//n7awel men string l integer

}

   }
   void score(){
       char s[2];
glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0,logWidth,0,logHeight);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
printsome("Players#                 scores ",6,90);
for(int j=0;j<5;j++)
{
   sprintf(s,"%d",j);
   printsome(s,9,85-(j*5));
   //printsome("-",9,85-(j*5));
   sprintf(s,"%d",ply[j]);
   printsome(s,41,85-(j*5));
}
glutMouseFunc(mouseClick3);
glFlush();
glutSwapBuffers();
}


void mouseClick(int btn, int state, int x, int y)
{int mouseXX ,mouseYY;
 mouseXX = x;
mouseXX=0.5+1.0*mouseXX*logWidth/phyWidth;
mouseYY = physHeight - y;
mouseYY=0.5+1.0*mouseYY*logHeight/physHeight;

    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
{
if( mouseXX>=45 && mouseXX<=65 && mouseYY >=70 && mouseYY <=80)

{//play
sqDelta=-90;count=0;
glutDisplayFunc(game);
}
if( mouseXX>=45 && mouseXX<=65 && mouseYY >=50 && mouseYY <=60)
{
//high
glutDisplayFunc(score);
}
if( mouseXX>=45 && mouseXX<=65 && mouseYY >=30 && mouseYY <=40)
{
//quit
exit(1);

}
}
if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
int status=0;glutSwapBuffers();
   glFlush();
}

glutPostRedisplay();
}



void drawSquares(){//betoo3 awel shasha

    glClear( GL_COLOR_BUFFER_BIT);
   glColor3f(1.0,0.5,0.5);
   glBegin(GL_QUADS);//play
   glVertex2i(45, 70);
glVertex2i(45, 80);
glVertex2i(65, 80);
glVertex2i(65, 70);
 glEnd();
 glBegin(GL_QUADS);//high score
   glVertex2i(45, 50);
glVertex2i(45, 60);
glVertex2i(65, 60);
glVertex2i(65, 50);
 glEnd();
 glBegin(GL_QUADS);//quit
   glVertex2i(45, 30);
glVertex2i(45, 40);
glVertex2i(65, 40);
glVertex2i(65, 30);
 glEnd();
 printsome(" Math Hero", 43, 90 );
 printsome("Play",50,75);
printsome("High score",45,55);
printsome("Quit",50,35);

   glutSwapBuffers();
   glFlush();
   }

  void display(){

     glutDisplayFunc(drawSquares);
glutSwapBuffers();
   glFlush();

   }
   void display2(){

     glutDisplayFunc(drawSquares);
//glutMouseFunc(mouseClick);
//Timer2(0);
glutSwapBuffers();
   glFlush();

   }

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    //initRendering();
    glutInitWindowSize(phyWidth,physHeight);
    glutInitWindowPosition(100,100);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );
glutCreateWindow("OUR GAME");
    init2D(1.0,1.0,0.5);
    glutDisplayFunc(display);
//glutDisplayFunc(drawSquares);
glutMouseFunc(mouseClick);
Timer2(0);
    glutMainLoop();




}
