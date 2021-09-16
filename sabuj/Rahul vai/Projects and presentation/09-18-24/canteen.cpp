#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include <windows.h>
#include <dos.h>

int main()
{

       system("color 40");
       int gd=DETECT,gm;
       initgraph(&gd, &gm, "C://TC//BGI");
       setcolor(RED);

       //setbkcolor();
       int ch,i,j,dx=500,dy=400,rad=0;
    while(1)
    {
        for(i=0;i<=1000;i+=100)
        {
            setcolor(3);

        }

        for(j=0;j<=800;j+=100)
        {
            setcolor(5);

        }

        for(i=145;i<=150;i++)
        {
            setcolor(9);
            circle(dx,dy,rad+i);
        }

        //delay(500);

        ch=getch();
        if(ch=='r')
        {
            dx=dx-20;

        }
        if(ch=='l')
        {
            dx=dx+20;
        }
        if(ch=='s')
        {
            rad=rad-20;
        }
        if(ch=='b')
        {
            rad=rad+20;
        }


       line(0,180,80,180);
       line(0,280,80,280);
       line(640,180,560,180);
       line(640,280,560,280);
       circle(150,150,10);
       circle(80,230,10);
       circle(150,310,10);
       circle(315,190,10);
       circle(315,80,10);
       circle(315,305,10);
       circle(315,415,10);

       line(320,0,320,500);//mid
       circle(320,230,100);//mid

       circle(430,230,10);
       circle(430,110,10);
       circle(430,350,10);

       circle(495,320,10);//stricker
         delay(500);
       getch();

       cleardevice();
    }
       closegraph();

}

