#include <graphics.h>
#include <dos.h>
#include<stdio.h>
#include<conio.h>
int main()
{

    bool dbflag= false,closeflag=true;
    initwindow(1000,800,"My Game",0, 0, dbflag, closeflag);
    char ch;
    int i,j,dx=500,dy=400,rad=0;
    while(1)
    {
        // column
        for(i=0;i<=1000;i+=100)
        {
            setcolor(3);
            //line(i,0,i,800);
        }
        // row
        for(j=0;j<=800;j+=100)
        {
            setcolor(5);
           // line(0,j,1000,j);
        }

        for(i=145;i<=150;i++)
        {
            setcolor(9);
            circle(dx,dy,rad+i);
        }

        //delay(500);

        ch=getch();
        if(ch=='l')
        {
            dx=dx-20;

        }
        if(ch=='r')
        {
            dx=dx+20;
        }
        if(ch=='s')
        {
            rad=rad-5;
        }
        if(ch=='b')
        {
            rad=rad+5;
        }
        cleardevice();
    }
    closegraph();

return 0;
}
