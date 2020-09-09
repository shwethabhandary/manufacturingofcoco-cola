#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>
int mouseon=0;
float speed = 0.003;
float speedbottle = 0.2;
int flag = 1;
void cocacolalogo(float, float);
//First Slide Begins
//Background for Second Slide
void background1()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.529,0.3294,0.2196);
        glBegin(GL_POLYGON);
            glVertex3d(0,0,0);
            glVertex3d(100,0,0);
            glVertex3d(100,50,0);
            glVertex3d(0,50,0);
        glEnd();
}

void building(){
    float i;
    //main building
    glColor3f(0.9,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(20, 10, 0.0);
        glVertex3f(70, 10, 0.0);
        glVertex3f(70, 60, 0.0);
        glVertex3f(20, 60, 0.0);
    glEnd();
    glColor3f(0.749,0.0588,0.0902);
    glBegin(GL_POLYGON);
        glVertex3f(20, 60, 0.0);
        glVertex3f(70, 60, 0.0);
        glVertex3f(83, 80, 0.0);
        glVertex3f(33, 80, 0.0);
    glEnd();
    glColor3f(0.408,0.035,0.055);
    glBegin(GL_POLYGON);
        glVertex3f(70, 10, 0.0);
        glVertex3f(83, 30, 0.0);
        glVertex3f(83, 80, 0.0);
        glVertex3f(70, 60, 0.0);
    glEnd();
    glColor3f(0.765,0.765,0.765);
    //Shutter
    glBegin(GL_POLYGON);
        glVertex3f(25, 10, 0.0);
        glVertex3f(65, 10, 0.0);
        glVertex3f(65, 50, 0.0);
        glVertex3f(25, 50, 0.0);
    glEnd();
    glColor3f(0.498,0.498,0.498);
    for(i=10.3;i<=50;i=i+3){
        glBegin(GL_LINES);
            glVertex3f(25,i,0);
            glVertex3f(65,i,0);
        glEnd();

    }
}
//Road
void road(){
    int i;
    //Road
    glColor3f(0.498,0.498,0.498);
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(100,0);
        glVertex2f(100,10);
        glVertex2f(0,10);
    glEnd();
}

//truck
void truck(float x){
    int y=13;
    //The back part
    glBegin(GL_QUADS);
        glColor3f(0.9,0,0);
        glVertex2f(x+10,10-y);
        glVertex2f(x+30,10-y);
        glVertex2f(x+30,30-y);
        glVertex2f(x+10,30-y);

        glColor3f(0.8,0,0);
        glVertex2f(x+10,30-y);
        glVertex2f(x+30,30-y);
        glVertex2f(x+32,34-y);
        glVertex2f(x+12,34-y);

        glColor3f(0.7,0,0);
        glVertex2f(x+30,10-y);
        glVertex2f(x+30,30-y);
        glVertex2f(x+32,34-y);
        glVertex2f(x+32,14-y);
    glEnd();
    //The Front part
    glBegin(GL_QUADS);
        glColor3f(0.6,0.6,0.6);
        glVertex2f(x+30,26-y);
        glVertex2f(x+32,29.733333-y);
        glVertex2f(x+35,29.733333-y);
        glVertex2f(x+33,26-y);

        glColor3f(0.6,0.6,0.6);
        glVertex2f(x+30,17-y);
        glVertex2f(x+34,17-y);
        glVertex2f(x+34,10-y);
        glVertex2f(x+30,10-y);

        glColor3f(0.5,0.5,0.5);
        glVertex2f(x+34,17-y);
        glVertex2f(x+36,20.733333-y);
        glVertex2f(x+36,13.733333-y);
        glVertex2f(x+34,10-y);

        glColor3f(0.2,0.2,0.2);
        glVertex2f(x+34.3,16.3-y);
        glVertex2f(x+35.75,19.2-y);
        glVertex2f(x+35.75,13.3-y);
        glVertex2f(x+34.3,10.5-y);
        //Glasses
        glColor3f(0.2,0.2,0.2);
        glVertex2f(x+30,26-y);
        glVertex2f(x+33,26-y);
        glVertex2f(x+34,17-y);
        glVertex2f(x+30,17-y);

        glColor3f(0.1,0.1,0.1);
        glVertex2f(x+35,29.733333-y);
        glVertex2f(x+33,26-y);
        glVertex2f(x+34,17-y);
        glVertex2f(x+36,20.733333-y);
        //door handle
        glColor3f(0.2,0.2,0.2);
        glVertex2f(x+30.3,16-y);
        glVertex2f(x+31,16-y);
        glVertex2f(x+31,15.2-y);
        glVertex2f(x+30.3,15.2-y);
        //Final touches
        glColor3f(0.9,0.9,0.9);
        glVertex2f(x+30.3,24.4-y);
        glVertex2f(x+30.9,24.4-y);
        glVertex2f(x+31.3,18.4-y);
        glVertex2f(x+30.3,18.4-y);
    glEnd();
    cocacolalogo(x+16,5);
}
//board
void board(){
    //black
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(24, 65, 0.0);
        glVertex3f(68, 65, 0.0);
        glVertex3f(68, 97, 0.0);
        glVertex3f(24, 97, 0.0);
    glEnd();
    //white
    glColor3f(0.9,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(26, 68, 0.0);
        glVertex3f(66, 68, 0.0);
        glVertex3f(66, 94, 0.0);
        glVertex3f(26, 94, 0.0);
    glEnd();
    //drawing the coke bottle
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glVertex3f(30,70,0);
        glVertex3f(33,70,0);
        glVertex3f(33.5,71,0);
        glVertex3f(33.2,74,0);
        glVertex3f(33.5,78,0);
        glVertex3f(33.5,82,0);
        glVertex3f(32.5,87.7,0);
        glVertex3f(32.5,89.4,0);
        glVertex3f(30.5,89.4,0);
        glVertex3f(30.5,87.7,0);
        glVertex3f(29.5,82,0);
        glVertex3f(29.5,78,0);
        glVertex3f(29.9,74,0);
        glVertex3f(29.5,71,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(32.5,89.4,0);
        glVertex3f(32.65,89.5,0);
        glVertex3f(32.5,90.3,0);
        glVertex3f(30.5,90.3,0);
        glVertex3f(30.32,89.5,0);
        glVertex3f(30.40,89.4,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(32.5,90.3,0);
        glVertex3f(32.7,90.5,0);
        glVertex3f(32.5,90.7,0);
        glVertex3f(30.5,90.7,0);
        glVertex3f(30.3,90.5,0);
        glVertex3f(30.5,90.3,0);
    glEnd();//Drawing of coke bottle ends here
    //Drawing the coca cola logo
    glColor3f(1,1,1);
    glPushMatrix();
        glTranslatef(-70,-83,1);
        glScalef(2.2,2.2,1);
        cocacolalogo(50,70);
    glPopMatrix();
    glColor3f(0.7,0,0);
    glPushMatrix();
        glTranslatef(9.5,50.5,1);
        glScalef(0.4,0.4,1);
        cocacolalogo(50,70);
    glPopMatrix();
    glColor3f(0.5,0.5,0.5);

}
//End of First Slide

//Second Slide Begins
//Background for second slide
void background2(){
    glClear(GL_COLOR_BUFFER_BIT);
}
//Conveyor Belt
void conveyor(float k){
    int a;
    glColor3f(0.53,0.53,0.53);
    glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(100,0,0);
        glVertex3f(100,30,0);
        glVertex3f(0,30,0);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(100,0,0);
        glVertex3f(100,30,0);
        glVertex3f(0,30,0);
    glEnd();
    for(a=-30;a<=105;a=a+5){
        glColor3f(0,0,0);
        glBegin(GL_LINES);
            glVertex3f(a+k,0,0);
            glVertex3f(a+k+13,30,0);
        glEnd();
    }
}

//Cocacola logo
void cocacolalogo(float k, float l){
    float m, n;//for letters o and a which repeats twice in coca cola
    glBegin(GL_TRIANGLES);
        //C
        glVertex2f(k+2.3,l+7.833333);
        glVertex2f(k+0.5,l+5.65);
        glVertex2f(k+0.31667,l+3.5333);

        glVertex2f(k+0.31667,l+3.5333);
        glVertex2f(k+1.26667,l+2.4);
        glVertex2f(k+0.66667,l+5.83333);

        glVertex2f(k+1.18,l+2.4);
        glVertex2f(k+3.28333,l+2.3);
        glVertex2f(k+3.88333,l+3.16667);
        //O
        glVertex2f(k+1.9166667,l+6.366667);
        glVertex2f(k+1.183333,l+4.283333);
        glVertex2f(k+2.425,l+6.433333);

        glVertex2f(k+1.183333,l+4.283333);
        glVertex2f(k+1.633333,l+3.733333);
        glVertex2f(k+1.541667,l+4.866667);

        glVertex2f(k+1.633333,l+3.733333);
        glVertex2f(k+2.425,l+6.433333);
        glVertex2f(k+1.616667,l+4.266667);

        glVertex2f(k+1.991667,l+5.65);
        glVertex2f(k+2.441667,l+5.25);
        glVertex2f(k+2.6,l+5.65);
        //C
        glVertex2f(k+3.125,l+6.633333);
        glVertex2f(k+3.266667,l+6.083333);
        glVertex2f(k+3.466667,l+6.616667);

        glVertex2f(k+3.125,l+6.633333);
        glVertex2f(k+2.25,l+4.866667);
        glVertex2f(k+2.308333,l+3.75);

        glVertex2f(k+2.308333,l+3.75);
        glVertex2f(k+2.966667,l+4.233333);
        glVertex2f(k+2.516667,l+4.55);
        //A
        glVertex2f(k+4.241667,l+6.616667);
        glVertex2f(k+3.475,l+6.066667);
        glVertex2f(k+2.983333,l+4.266667);

        glVertex2f(k+2.983333,l+4.266667);
        glVertex2f(k+3.108333,l+3.883333);
        glVertex2f(k+3.6,l+4.233333);

        glVertex2f(k+3.6,l+4.233333);
        glVertex2f(k+4.741667,l+6.616667);
        glVertex2f(k+4.241667,l+6.616667);

        glVertex2f(k+3.6,l+4.233333);
        glVertex2f(k+4.1,l+4.066667);
        glVertex2f(k+4.083333,l+5.216667);

        glVertex2f(k+4.1,l+4.066667);
        glVertex2f(k+4.491667,l+5.1);
        glVertex2f(k+4.08,l+4.483333);

        glVertex2f(k+4.958333,l+6.616667);
        glVertex2f(k+5.116667,l+6.333333);
        glVertex2f(k+5.275,l+6.616667);
        //C
        glVertex2f(k+9.533333,l+7.483333);
        glVertex2f(k+8.925,l+7.05);
        glVertex2f(k+8.708333,l+6.516667);

        glVertex2f(k+8.166667,l+6.916667);
        glVertex2f(k+8.441667,l+7.283333);
        glVertex2f(k+6.733333,l+7.7);

        glVertex2f(k+6.658333,l+7.633333);
        glVertex2f(k+6.433333,l+6);
        glVertex2f(k+6.55,l+6);

        glVertex2f(k+6.55,l+6);
        glVertex2f(k+7.2,l+7.493333);
        glVertex2f(k+6.95,l+7.55);

        glVertex2f(k+6.733333,l+7.7);
        glVertex2f(k+4.866667,l+5.483333);
        glVertex2f(k+4.616667,l+3.333333);

        glVertex2f(k+4.616667,l+3.333333);
        glVertex2f(k+5.65,l+2.266667);
        glVertex2f(k+5.025,l+4.083333);

        glVertex2f(k+5.65,l+2.266667);
        glVertex2f(k+6.358333,l+4.566667);
        glVertex2f(k+5.491667,l+2.683333);

        glVertex2f(k+6.358333,l+4.566667);
        glVertex2f(k+6.183333,l+5.566667);
        glVertex2f(k+5.95,l+5.216667);

        glVertex2f(k+5.95,l+5.216667);
        glVertex2f(k+5.483333,l+3.866667);
        glVertex2f(k+5.933333,l+4.483333);
        //O
        m = 4.916667;
        n = -1.233334;
        glVertex2f(k+m+1.916667,l+n+6.366667);
        glVertex2f(k+m+1.183333,l+n+4.283333);
        glVertex2f(k+m+2.425,l+n+6.433333);

        glVertex2f(k+m+1.183333,l+n+4.283333);
        glVertex2f(k+m+1.633333,l+n+3.733333);
        glVertex2f(k+m+1.541667,l+n+4.866667);

        glVertex2f(k+m+1.633333,l+n+3.733333);
        glVertex2f(k+m+2.425,l+n+6.433333);
        glVertex2f(k+m+1.616667,l+n+4.266667);

        glVertex2f(k+m+1.991667,l+n+5.65);
        glVertex2f(k+m+2.441667,l+n+5.25);
        glVertex2f(k+m+2.6,l+n+5.65);
        //L
        m = 4.941666;n = -1.25;
        glVertex2f(k+8.8,l+7.7);
        glVertex2f(k+7.15,l+3.616667);
        glVertex2f(k+7.216667,l+2.45);

        glVertex2f(k+7.216667,l+2.45);
        glVertex2f(k+m+2.983333,l+n+4.266667);
        glVertex2f(k+7.458333,l+3.366667);

        glVertex2f(k+7.716667,l+4.133333);
        glVertex2f(k+8.925,l+6.483333);
        glVertex2f(k+7.983333,l+5.1);
        //A
        m = 4.941666;
        n = -1.25;
        glVertex2f(k+m+4.241667,l+n+6.616667);
        glVertex2f(k+m+3.475,l+n+6.066667);
        glVertex2f(k+m+2.983333,l+n+4.266667);

        glVertex2f(k+m+2.983333,l+n+4.266667);
        glVertex2f(k+m+3.108333,l+n+3.883333);
        glVertex2f(k+m+3.6,l+n+4.233333);

        glVertex2f(k+m+3.6,l+n+4.233333);
        glVertex2f(k+m+4.741667,l+n+6.616667);
        glVertex2f(k+m+4.241667,l+n+6.616667);

        glVertex2f(k+m+3.6,l+n+4.233333);
        glVertex2f(k+m+4.1,l+n+4.066667);
        glVertex2f(k+m+4.083333,l+n+5.216667);

        glVertex2f(k+m+4.1,l+n+4.066667);
        glVertex2f(k+m+4.491667,l+n+5.1);
        glVertex2f(k+m+4.08,l+n+4.483333);
    glEnd();
}
//Bottles
void bottle(int x, int y, float m){
    float i;
    float k, l;//k and l are used in logo part
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
        glVertex3f(x*m,y*m,0);
        glVertex3f((x+7.5)*m,y*m,0);
        glVertex3f((x+8.75)*m,(y+2.5)*m,0);
        glVertex3f((x+8)*m,(y+10)*m,0);
        glVertex3f((x+8.75)*m,(y+20)*m,0);
        glVertex3f((x+8.75)*m,(y+30)*m,0);
        glVertex3f((x+6.25)*m,(y+44.25)*m,0);
        glVertex3f((x+6.25)*m,(y+48.5)*m,0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f((x+1.25)*m,(y+48.5)*m,0);
        glVertex3f((x+1.25)*m,(y+44.25)*m,0);
        glVertex3f((x-1.25)*m,(y+30)*m,0);
        glVertex3f((x-1.25)*m,(y+20)*m,0);
        glVertex3f((x-0.25)*m,(y+10)*m,0);
        glVertex3f((x-1.25)*m,(y+2.5)*m,0);
        glVertex3f(x*m,y*m,0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f((x+6.25)*m,(y+48.5)*m,0);
        glVertex3f((x+6.625)*m,(y+48.75)*m,0);
        glVertex3f((x+6.25)*m,(y+50.75)*m,0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f((x+1.25)*m,(y+50.75)*m,0);
        glVertex3f((x+0.83)*m,(y+48.75)*m,0);
        glVertex3f((x+1.25)*m,(y+48.5)*m,0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex3f((x+6.25)*m,(y+50.75)*m,0);
        glVertex3f((x+6.75)*m,(y+51.25)*m,0);
        glVertex3f((x+6.25)*m,(y+51.75)*m,0);
        glVertex3f((x+1.25)*m,(y+51.75)*m,0);
        glVertex3f((x+0.75)*m,(y+51.25)*m,0);
        glVertex3f((x+1.25)*m,(y+50.75)*m,0);
    glEnd();
    //Bottle filled with coke
    if(flag == 4 || flag == 5){
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
            glVertex3f(x*m,y*m,0);
            glVertex3f((x+7.5)*m,y*m,0);
            glVertex3f((x+8.75)*m,(y+2.5)*m,0);
            glVertex3f((x+8)*m,(y+10)*m,0);
            glVertex3f((x+8.75)*m,(y+20)*m,0);
            glVertex3f((x+8.75)*m,(y+30)*m,0);
            glVertex3f((x+7)*m,(y+40.25)*m,0);
            glVertex3f((x+0.5)*m,(y+40.25)*m,0);
            glVertex3f((x-1.25)*m,(y+30)*m,0);
            glVertex3f((x-1.25)*m,(y+20)*m,0);
            glVertex3f((x-0.25)*m,(y+10)*m,0);
            glVertex3f((x-1.25)*m,(y+2.5)*m,0);
        glEnd();
    }
    //Logo in bottle
    k = x-1.25;
    l = y+20;
    glColor3f(0.9,0,0);
    glBegin(GL_POLYGON);
        glVertex3f((k+10)*m,l*m,0);
        glVertex3f((k+10)*m,(l+10)*m,0);
        glVertex3f(k*m,(l+10)*m,0);
        glVertex3f(k*m,l*m,0);
    glEnd();
    if(flag==5){
        glColor3f(1,1,1);
        glPushMatrix();
            glScaled(0.5,0.5,1);
            glTranslated(0,0,1);
            cocacolalogo(k, l);
        glPopMatrix();
    }
    else{
        glColor3f(1,1,1);
        cocacolalogo(k, l);
    }
}
//Machine that fills the bottles with coke and caps them
void filler(float x, int y){
    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);
        glVertex3f(x+0.5,y,0);
        glVertex3f(x+3.5,y-20,0);
        glColor3f(0.6,0.6,0.6);
        glVertex3f(x+10,y-20,0);
        glVertex3f(x+13,y,0);
    glEnd();
}

//Coke pouring from the filler machine
void filling(float x, int y ,int i){
    glColor3f(0, 0, 0);
    if(i<=50)
    {glBegin(GL_POLYGON);
            glVertex2f(x+0.4, y);
            glVertex2f(x+0.4, y-45);
            //glColor3f(0.3,0.3,0.3);
            glVertex2f(x+2, y-45);
            glVertex2f(x+2, y);
        glEnd();
    }
}

//Filling coke in third scene
void fillcoke(int x, int y, int i, float j){
    float k = 0, l;
    //bottle(x,y);
    glColor3f(0,0,0);
    //first phase

    if(i<=-10){
        filling(i+2+j,55,i);
        for(l=0;l<=0.125*j;l=l+0.1){
            k=k+0.05;
            glBegin(GL_LINES);
                glVertex2f(x-k,y+l);
                glVertex2f(x+7.5+k,y+l);
            glEnd();
        }
    }
    //Second phase
    else if(i<=10){
        filling(i+2+j,55,i);
        glBegin(GL_POLYGON);
            glVertex2f(x,y);
            glVertex2f(x+7.5,y);
            glVertex2f(x+8.75,y+2.5);
            glVertex2f(x-1.25,y+2.5);
        glEnd();
        for(l=0;l<=0.4*j;l=l+0.1){
            k=k+0.009;
            glBegin(GL_LINES);
                glVertex2f(x-1.25+k, y+2.5+l);
                glVertex2f(x+8.75-k, y+2.5+l);
            glEnd();
        }
    }
    //Third phase
    else {
        filling(i+2+j,55,i);
        glBegin(GL_POLYGON);
            glVertex2f(x,y);
            glVertex2f(x+7.5,y);
            glVertex2f(x+8.75,y+2.5);
            glVertex2f(x+8,y+10);
            glVertex2f(x-0.25,y+10);
            glVertex2f(x-1.25,y+2.5);
        glEnd();
        for(l=0;l<=0.5*j;l=l+0.1){
            k=k+0.008;
            glBegin(GL_LINES);
                glVertex2f(x+8+k, y+10+l);
                glVertex2f(x-0.25-k, y+10+l);
            glEnd();
        }
    }
    //Fourth phase
    /*else if(i<=50){
        filling(i+2+j,55);
        glBegin(GL_POLYGON);
            glVertex2f(x,y);
            glVertex2f(x+7.5,y);
            glVertex2f(x+8.75,y+2.5);
            glVertex2f(x+8,y+10);
            glVertex2f(x+8.75,y+20);
            glVertex2f(x-1.25,y+20);
            glVertex2f(x-0.25,y+10);
            glVertex2f(x-1.25,y+2.5);
        glEnd();
        for(l=0;l<=0.5*j;l=l+0.1){
            glBegin(GL_LINES);
                glVertex2f(x+8.75, y+20+l);
                glVertex2f(x-1.25, y+20+l);
            glEnd();
        }
    }
    //Fifth and final phase, phew!!
    else if(i<=70){
        filling(i+2+j,55);
        glBegin(GL_POLYGON);
            glVertex2f(x,y);
            glVertex2f(x+7.5,y);
            glVertex2f(x+8.75,y+2.5);
            glVertex2f(x+8,y+10);
            glVertex2f(x+8.75,y+20);
            glVertex2f(x+8.75,y+30);
            glVertex2f(x-1.25,y+30);
            glVertex2f(x-1.25,y+20);
            glVertex2f(x-0.25,y+10);
            glVertex2f(x-1.25,y+2.5);
        glEnd();
        for(l=0;l<=0.5*j;l=l+0.1){
            k = k+0.017;
            glBegin(GL_LINES);
                glVertex2f(x+8.75-k, y+30+l);
                glVertex2f(x-1.25+k, y+30+l);
            glEnd();
        }
    }
    else{
        glBegin(GL_POLYGON);
            glVertex2f(x,y);
            glVertex2f(x+7.5,y);
            glVertex2f(x+8.75,y+2.5);
            glVertex2f(x+8,y+10);
            glVertex2f(x+8.75,y+20);
            glVertex2f(x+8.75,y+30);
            glVertex2f(x+7,y+40.25);
            glVertex2f(x+0.5,y+40.25);
            glVertex2f(x-1.25,y+30);
            glVertex2f(x-1.25,y+20);
            glVertex2f(x-0.25,y+10);
            glVertex2f(x-1.25,y+2.5);
        glEnd();
    }*/
    bottle(x, y, 1);
}

//display function
void display(){
    int i,l;
    float j,k;
    if(flag > 2)
        flag = 1;
    if(flag < 1)
        flag = 2;
    if(flag == 1){
        glClearColor(0.6,0.85,0.9176,1);
        background1();
        building();
        road();
        truck(k);
        board();
        k=k+0.04;
        if(k>100) k=-35;
        if(mouseon==1)
        {
            glClearColor(0.6,0.85,0.9176,1);
            background1();
            building();
            road();
            board();
            glColor3f(1.0,0.5,1.0);
            glBegin(GL_POLYGON);
              glVertex2f(25,29.3);
              glVertex2f(65,29.3);
              glVertex2f(65,10);
              glVertex2f(25,10);
            glEnd();
            glColor3f(0,0,0);
            glBegin(GL_LINES);
              glVertex2f(25,29.3);
              glVertex2f(65,29.3);
            glEnd();
        }

        glutSwapBuffers();
    }
   else if(flag == 2){
        mouseon=0;
        j=j+speed;
        glClearColor(0.7,0,0,1);
        background2();
        glColor3f(0.7,0.7,0.7);
        glBegin(GL_POLYGON);
            glVertex3f(0,75,0);
            glVertex3f(100,75,0);
            glColor3f(0.4,0.4,0.4);
            glVertex3f(100,90,0);
            glVertex3f(0,90,0);
        glEnd();
        glColor3f(0.2,0.2,0.2);
        glBegin(GL_POLYGON);
            glVertex3f(0,90,0);
            glVertex3f(100,90,0);
            glColor3f(0,0,0);
            glVertex3f(100,100,0);
            glVertex3f(0,100,0);
        glEnd();
        conveyor(j);
        for(i=-10;i<=90;i=i+20)
            fillcoke(i+j,10,i,j);
        for(i=-13;i<100;i=i+20)
            filler(i+j,75);
        if(j>20) j=0;
        glutSwapBuffers();
    }

    glFlush();
}

void myinit(){

    glMatrixMode(GL_PROJECTION);              // setup viewing projection
    glLoadIdentity();                           // start with identity matrix
    glOrtho(0.0, 100, 0.0, 100, -1.0, 1.0);   // setup a 10x10x2 viewing world
}

void mainmenu(int id){
    switch(id){
        case 1  :   flag++;
                    break;
        case 2  :   flag--;
                    break;
        case 3  :   exit(0);
    }
}
void mouse(int btn,int state,int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        mouseon=1;
    }
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    glutInitWindowPosition(0,0);
    glutInitWindowSize(1500,1000);
    glutCreateWindow ("Mini Project");

    myinit();

    glutCreateMenu(mainmenu);
    glutMouseFunc(mouse);
    glutAddMenuEntry("Next",1);
    glutAddMenuEntry("Previous",2);
    glutAddMenuEntry("Exit",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();

    return 0;
}
