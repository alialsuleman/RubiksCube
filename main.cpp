#include<windows.h>
#ifdef APPLE
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<cmath>
#include <bits/stdc++.h>

#include<iostream>
#include<chrono>
#include<thread>
#include<dos.h>
using namespace std ;
void display();
void reshape(int,int);
void timer(int);
void timer2(int);
void timer3(int);
void Key(unsigned char key, int x, int y) ;

GLfloat Cx=5,Cy=-3,Cz=3;
float color[4][4][4][6][4]= {0.0},  color2 [4][4][6][3] ;;
bool ok[4][4][4]= {0} ;
int y1[4][2]= {{0,0},{2,0},{2,2},{0,2}},y2[4][2]= {{2,0},{2,2},{0,2},{0,0}},x1[4][2]= {{0,1},{1,0},{2,1},{1,2}},x2[4][2]= {{1,0},{2,1},{1,2},{0,1}} ;

vector  < pair < int, int > > vc ;

void move1 (int,bool ) ;

void mouse(int x,int y)
{

    cout << x<< " " <<y << "\n" ;
    /*

    double x1 = (x-300)/5;
    double y1 =  (y-300)/5 ;


    if (x1<0)
        Cx= min(-1*x1,100.0) ;
    else
        Cx= max(-1*x1,-100.0) ;
    if (y1>0)
        Cy= max(-1*y1,-100.0) ;
    else
        Cy= min(-y1,100.0) ;

    cout << Cx<< " "<< Cy<< "\n"  ;
   */

}

void accSwap (int ind, int in)
{
    int ind1, ind2, ind3 ;
    for (int w1=0; w1<4 ; w1++)
        for (int w2=0; w2<6; w2++)
            for (int w3=0 ; w3<3; w3++)
            {
                if(ind==1)
                {
                    ind1=in, ind2 =y2[w1][0], ind3=y2[w1][1] ;
                }
                if(ind==2)
                {
                    ind1 =y2[w1][0], ind2=y2[w1][1],ind3= in ;
                }
                if(ind==3)
                {
                    ind1 =y2[w1][0],ind2= in, ind3=y2[w1][1] ;
                }
                color[ind1][ind2][ind3][w2][w3]= color2[y1[w1][0]][y1[w1][1]][w2][w3] ;
            }
    for (int w1=0; w1<4 ; w1++)
        for (int w2=0; w2<6; w2++)
            for (int w3=0 ; w3<3; w3++)
            {
                if(ind==1)
                {
                    ind1=in, ind2 =x2[w1][0], ind3=x2[w1][1] ;
                }
                if(ind==2)
                {
                    ind1 =x2[w1][0], ind2=x2[w1][1],ind3= in ;
                }
                if(ind==3)
                {
                    ind1 =x2[w1][0],ind2= in, ind3=x2[w1][1] ;
                }
                color[ind1][ind2][ind3][w2][w3]= color2[x1[w1][0]][x1[w1][1]][w2][w3] ;
            }

}

void changeColor1(int in)
{
    for (int w1  = 0; w1<3; w1++)
        for (int w2 =0; w2<3; w2++)
        {

            color2[w1][w2][4][0]= color[in][w1][w2][4][0] ;
            color2[w1][w2][4][1]= color[in][w1][w2][4][1] ;
            color2[w1][w2][4][2]= color[in][w1][w2][4][2] ;
            color2[w1][w2][5][0]= color[in][w1][w2][5][0] ;
            color2[w1][w2][5][1]= color[in][w1][w2][5][1] ;
            color2[w1][w2][5][2]= color[in][w1][w2][5][2] ;
            color2[w1][w2][2][0]= color[in][w1][w2][0][0] ;
            color2[w1][w2][2][1]= color[in][w1][w2][0][1] ;
            color2[w1][w2][2][2]= color[in][w1][w2][0][2] ;
            color2[w1][w2][0][0]= color[in][w1][w2][3][0] ;
            color2[w1][w2][0][1]= color[in][w1][w2][3][1] ;
            color2[w1][w2][0][2]= color[in][w1][w2][3][2] ;
            color2[w1][w2][3][0]= color[in][w1][w2][1][0] ;
            color2[w1][w2][3][1]= color[in][w1][w2][1][1] ;
            color2[w1][w2][3][2]= color[in][w1][w2][1][2] ;
            color2[w1][w2][1][0]= color[in][w1][w2][2][0] ;
            color2[w1][w2][1][1]= color[in][w1][w2][2][1] ;
            color2[w1][w2][1][2]= color[in][w1][w2][2][2] ;
        }
    accSwap(1, in) ;

}

void changeColor2(int in)
{
    for (int w1  = 0; w1<3; w1++)
        for (int w2 =0; w2<3; w2++)
        {
            color2[w1][w2][2][0]= color[w1][w2][in][2][0] ;
            color2[w1][w2][2][1]= color[w1][w2][in][2][1] ;
            color2[w1][w2][2][2]= color[w1][w2][in][2][2] ;
            color2[w1][w2][3][0]= color[w1][w2][in][3][0] ;
            color2[w1][w2][3][1]= color[w1][w2][in][3][1] ;
            color2[w1][w2][3][2]= color[w1][w2][in][3][2] ;
            color2[w1][w2][0][0]= color[w1][w2][in][5][0] ;
            color2[w1][w2][0][1]= color[w1][w2][in][5][1] ;
            color2[w1][w2][0][2]= color[w1][w2][in][5][2] ;
            color2[w1][w2][4][0]= color[w1][w2][in][0][0] ;
            color2[w1][w2][4][1]= color[w1][w2][in][0][1] ;
            color2[w1][w2][4][2]= color[w1][w2][in][0][2] ;
            color2[w1][w2][1][0]= color[w1][w2][in][4][0] ;
            color2[w1][w2][1][1]= color[w1][w2][in][4][1] ;
            color2[w1][w2][1][2]= color[w1][w2][in][4][2] ;
            color2[w1][w2][5][0]= color[w1][w2][in][1][0] ;
            color2[w1][w2][5][1]= color[w1][w2][in][1][1] ;
            color2[w1][w2][5][2]= color[w1][w2][in][1][2] ;
        }
    accSwap(2, in) ;
}

void changeColor3(int in)
{
    for (int w1  = 0; w1<3; w1++)
    {
        for (int w2 =0; w2<3; w2++)
        {
            color2[w1][w2][0][0]= color[w1][in][w2][0][0] ;
            color2[w1][w2][0][1]= color[w1][in][w2][0][1] ;
            color2[w1][w2][0][2]= color[w1][in][w2][0][2] ;
            color2[w1][w2][1][0]= color[w1][in][w2][1][0] ;
            color2[w1][w2][1][1]= color[w1][in][w2][1][1] ;
            color2[w1][w2][1][2]= color[w1][in][w2][1][2] ;
            color2[w1][w2][4][0]= color[w1][in][w2][2][0] ;
            color2[w1][w2][4][1]= color[w1][in][w2][2][1] ;
            color2[w1][w2][4][2]= color[w1][in][w2][2][2] ;
            color2[w1][w2][2][0]= color[w1][in][w2][5][0] ;
            color2[w1][w2][2][1]= color[w1][in][w2][5][1] ;
            color2[w1][w2][2][2]= color[w1][in][w2][5][2] ;
            color2[w1][w2][5][0]= color[w1][in][w2][3][0] ;
            color2[w1][w2][5][1]= color[w1][in][w2][3][1] ;
            color2[w1][w2][5][2]= color[w1][in][w2][3][2] ;
            color2[w1][w2][3][0]= color[w1][in][w2][4][0] ;
            color2[w1][w2][3][1]= color[w1][in][w2][4][1] ;
            color2[w1][w2][3][2]= color[w1][in][w2][4][2] ;
        }
    }
    accSwap(3, in) ;
}

float inc[]= {-2.1, 0, 2.1} ;
void cube(int i, int j, int z)
{
    glBegin(GL_QUADS);									// Draw A Quad
    glColor3f(color[i][j][z][0][0],color[i][j][z][0][1],color[i][j][z][0][2]);
    glVertex3f(inc[i]+ 1.0f,inc[j]+ 1.0f,inc[z]-1.0f);			// Top Right Of The Quad (Top)
    glVertex3f(inc[i]-1.0f,inc[j]+ 1.0f,inc[z]-1.0f);			// Top Left Of The Quad (Top)
    glVertex3f(inc[i]-1.0f,inc[j]+ 1.0f, inc[z]+1.0f);			// Bottom Left Of The Quad (Top)
    glVertex3f( inc[i]+1.0f,inc[j]+ 1.0f,inc[z]+ 1.0f);			// Bottom Right Of The Quad (Top)
    glColor3f(color[i][j][z][1][0],color[i][j][z][1][1],color[i][j][z][1][2]);
    glVertex3f( inc[i]+1.0f,inc[j]-1.0f, inc[z]+1.0f);			// Top Right Of The Quad (Bottom)
    glVertex3f(inc[i]-1.0f,inc[j]-1.0f, inc[z]+1.0f);			// Top Left Of The Quad (Bottom)
    glVertex3f(inc[i]-1.0f,inc[j]-1.0f,inc[z]-1.0f);			// Bottom Left Of The Quad (Bottom)
    glVertex3f(inc[i]+ 1.0f,inc[j]-1.0f,inc[z]-1.0f);			// Bottom Right Of The Quad (Bottom)
    glColor3f(color[i][j][z][2][0],color[i][j][z][2][1],color[i][j][z][2][2]);
    glVertex3f( inc[i]+1.0f,inc[j]+ 1.0f,inc[z]+ 1.0f);			// Top Right Of The Quad (Front)
    glVertex3f(inc[i]-1.0f,inc[j]+ 1.0f,inc[z]+ 1.0f);			// Top Left Of The Quad (Front)
    glVertex3f(inc[i]-1.0f,inc[j]-1.0f, inc[z]+1.0f);			// Bottom Left Of The Quad (Front)
    glVertex3f( inc[i]+1.0f,inc[j]-1.0f,inc[z]+ 1.0f);			// Bottom Right Of The Quad (Front)
    glColor3f(color[i][j][z][3][0],color[i][j][z][3][1],color[i][j][z][03][2]);
    glVertex3f(inc[i]+ 1.0f,inc[j]-1.0f,inc[z]-1.0f);			// Bottom Left Of The Quad (Back)
    glVertex3f(inc[i]-1.0f,inc[j]-1.0f,inc[z]-1.0f);			// Bottom Right Of The Quad (Back)
    glVertex3f(inc[i]-1.0f, inc[j]+1.0f,inc[z]-1.0f);			// Top Right Of The Quad (Back)
    glVertex3f(inc[i]+ 1.0f,inc[j]+ 1.0f,inc[z]-1.0f);			// Top Left Of The Quad (Back)
    glColor3f(color[i][j][z][4][0],color[i][j][z][4][1],color[i][j][z][4][2]);
    glVertex3f(inc[i]-1.0f, inc[j]+1.0f,inc[z]+ 1.0f);			// Top Right Of The Quad (Left)
    glVertex3f(inc[i]-1.0f,inc[j]+ 1.0f,inc[z]-1.0f);			// Top Left Of The Quad (Left)
    glVertex3f(inc[i]-1.0f,inc[j]-1.0f,inc[z]-1.0f);			// Bottom Left Of The Quad (Left)
    glVertex3f(inc[i]-1.0f,inc[j]-1.0f,inc[z]+ 1.0f);			// Bottom Right Of The Quad (Left)
    glColor3f(color[i][j][z][5][0],color[i][j][z][5][1],color[i][j][z][5][2]);
    glVertex3f(inc[i]+ 1.0f,inc[j]+ 1.0f,inc[z]-1.0f);			// Top Right Of The Quad (Right)
    glVertex3f( inc[i]+1.0f,inc[j]+ 1.0f,inc[z]+ 1.0f);			// Top Left Of The Quad (Right)
    glVertex3f( inc[i]+1.0f,inc[j]-1.0f,inc[z]+ 1.0f);			// Bottom Left Of The Quad (Right)
    glVertex3f( inc[i]+1.0f,inc[j]-1.0f,inc[z]-1.0f);			// Bottom Right Of The Quad (Right)
    glEnd();

}
void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glFrustum(-3,3,-3,3,3,100);
    glLoadIdentity();


}


int  m1=0, m2 =0, cn1 =0, cn2=0 ;
void Loop(int state )
{
    if (m1)
    {
        int a1 =  vc[cn1].first ;
        int a2 =  vc[cn1].second ;
        move1(a1,a2) ;
        cn1++ ;
        if (cn1>=vc.size())
            m1=0 ;
    }
    else if (m2)
    {
        int a1 =  vc[cn2].first ;
        int a2 =  !vc[cn2].second ;
        move1(a1,a2) ;
        cn2++ ;
        if (cn2>=vc.size())
        {
            m2=0 ;
            cn2=0 ;
            cn1=0 ;
            vc.clear() ;
        }
    }
    glutTimerFunc(300, Loop, 0);
}
void colorInit(){
       for (int i=0 ; i<3; i++)
        for (int j=0 ; j<3; j++)
            for (int k=0 ; k<3; k++)
            {
                color[i][j][k][0][0]=0.8 ;
                color[i][j][k][0][1]=0 ;
                color[i][j][k][0][2]=0 ;
                color[i][j][k][1][0]=0 ;
                color[i][j][k][1][1]=0.8 ;
                color[i][j][k][1][2]=0 ;
                color[i][j][k][2][0]=0 ;
                color[i][j][k][2][1]=0 ;
                color[i][j][k][2][2]=0.8 ;
                color[i][j][k][3][0]=0.8 ;
                color[i][j][k][3][1]=0.8 ;
                color[i][j][k][3][2]=0 ;
                color[i][j][k][4][0]=0.8 ;
                color[i][j][k][4][1]=0 ;
                color[i][j][k][4][2]=0.8 ;
                color[i][j][k][5][0]=0 ;
                color[i][j][k][5][1]=0.8 ;
                color[i][j][k][5][2]=0.8 ;
            }
}

int main(int argc, char *argv[])
{

    colorInit() ;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE| GLUT_DEPTH);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Window 1");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    glutKeyboardFunc(Key);
    glutTimerFunc(1, Loop, 0);
    glutMotionFunc(mouse) ;
    init();

    glutMainLoop();
}
float angle=0.0,angle2=0.0,angle3=0.0 , angleX=15.0, angleY=45.0 , angleZ=0.0;
int  a=0,b=0,c=0 ;

void display()
{
   glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   glRotatef(angleX , 1,0,0) ;
   glRotatef(angleY , 0,1,0) ;
   glRotatef(angleZ , 0,0,1) ;


 //gluLookAt(0,0,0,Cx,Cy,Cz,0,1,0);

    for (int i= 0 ; i<=2 ; i++)
        for (int j =0 ; j<=2 ; j+=1)
            for (int z = 0; z<=2; z+=1)
            {
                glPushMatrix() ;

                if (ok[i][j][z])
                {
                    glRotatef(angle,int(a),int (b),int (c))  ;
                }
                cube(i,j,z) ;
                glPopMatrix() ;
            }

    glutSwapBuffers();
}
void reshape(int w,int h)
{
    glViewport(0,0,h,w);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20,20,-20,20,-20,20);
    glMatrixMode(GL_MODELVIEW);
}
bool flag1= 0, flag2=0, flag3=0 ;
int index;
int cnt=0 ;
bool all=0 ;
bool clo ;
void timer(int )
{

    glutTimerFunc(1000/60,timer,0);
    float speed =6.0 ;

    if (clo)
        angle-=speed*2;
    else
        angle+=speed*2;


    if((!clo&&angle>90)||(clo&& angle<-90)&&(flag1||flag2||flag3))
    {

        angle=0 ;

        if (flag1==1)
        {
            if(clo)
            {
             changeColor1(index) ;
                changeColor1(index) ;
            }
            changeColor1(index) ;
            for (int w1=0; w1<3; w1++)
                for (int w2=0; w2<3; w2++)
                    ok[index][w1][w2]=0 ;
        }
        else if(flag2==1)
        {
            if (clo)
            {
                changeColor2(index) ;
                changeColor2(index) ;
            }
            changeColor2(index) ;
            for (int w1=0; w1<3; w1++)
                for (int w2=0; w2<3; w2++)
                    ok[w1][w2][index]=0 ;
        }
        else if (flag3)
        {

            changeColor3(index) ;
            if (clo)
            {
                changeColor3(index) ;
                changeColor3(index) ;
            }
            for (int w1=0; w1<3; w1++)
                for (int w2=0; w2<3; w2++)
                    ok[w1][index][w2]=0 ;
        }
        flag1=0 ;
        flag2=0 ;
        flag3=0 ;
        return ;
    }
    // cout << angle << "\n" ;
    glutPostRedisplay();
}
int tim, cur=1 ;;
void Key(unsigned char key, int x, int y)
{


    if (key == 'z')
        angleX +=2;
    else if (key=='x')
        angleX-=2 ;
    else if (key=='c')
        angleY+=2 ;
    else if (key=='v')
        angleY-=2 ;
    else if (key=='b')
        angleZ+=2 ;
    else if (key=='n')
        angleZ-=2 ;
    else if (key=='s')
    {
        if(vc.size()!=0)
        {
            reverse(vc.begin(),vc.end()) ;
            m2=1 ;
            cn2=0 ;
        }

    }
    else if (key=='d')
    {
        int t =rand()%5+10 ; //10 - 14
        while (t--)
        {
            int randd = rand()%6+1 ;
            int f =rand()%2 ;
            vc.push_back({randd,f});
        }
        m1=1;
        m2=0 ;
        cout <<vc.size() << "\n" ; ;
    }
    else if (key=='1')
    {
        cur=1;
    }
    else if (key=='2')
    {
        cur=2;
    }
    else if (key=='3')
    {
        cur=3;
    }
    else if (key=='4')
    {
        cur=4;
    }
    else if (key=='5')
    {
        cur=5;
    }
    else if (key=='6')
    {
        cur=6;
    }


    if (key=='q')
    {
        vc.push_back({cur,0});
        m1=1, m2=0 ;
    }

    else if (key=='w')
    {
        vc.push_back({cur,1});
        m1=1, m2=0 ;
    }

glutPostRedisplay();

}

void move1 (int i,bool h )
{

    Sleep(tim) ;
    clo=h ;
    a=0, b=0, c=0 ;
    angle =0 ;
    if (i==1)
    {
        a=1;
        flag1=1 ;
        index=2 ;
        for (int w1=0; w1<3; w1++)
            for (int w2=0; w2<3; w2++)
                ok[index][w1][w2]=1 ;
    }
    else if (i==2)
    {
        a=1 ;
        flag1=1 ;
        index=0 ;
        for (int w1=0; w1<3; w1++)
            for (int w2=0; w2<3; w2++)
                ok[index][w1][w2]=1 ;


    }
    else if (i==3)
    {
        b=-1;
        flag3=1 ;
        index=0 ;
        for (int w1=0; w1<3; w1++)
            for (int w2=0; w2<3; w2++)
                ok[w1][index][w2]=1 ;
    }
    else if (i==4)
    {
        b=-1;
        flag3=1 ;
        index=2 ;
        for (int w1=0; w1<3; w1++)
            for (int w2=0; w2<3; w2++)
                ok[w1][index][w2]=1 ;
    }
      else if (i==5)
    {
        c=1 ;
        flag2=1 ;
        index=0 ;
        for (int w1=0; w1<3; w1++)
            for (int w2=0; w2<3; w2++)
                ok[w1][w2][index]=1 ;
    }
    else if (i==6)
    {
        c=1 ;
        flag2=1 ;
        index=2 ;
        for (int w1=0; w1<3; w1++)
            for (int w2=0; w2<3; w2++)
                ok[w1][w2][index]=1 ;
    }
}
