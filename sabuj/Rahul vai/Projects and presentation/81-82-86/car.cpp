#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
int main()
{
    int i;
    int ch='\0';

    bool dbflag= false,closeflag=true;
    initwindow(1000,2000,"Rock",0, 0, dbflag, closeflag);
    for( i = 0 ; i<=1000 ; )
    {
        if((int)ch==77)
        {
            i=i+10;
        }
        if((int)ch==75)
        {
            i=i-10;
        }

        rectangle(60+i,275,150+i,400);
        rectangle(-80+i,345,60+i,400);
        rectangle(150+i,350,230+i,400);
        rectangle(90+i,310,120+i,350);

        circle(75+i,410,15);
        circle(80+i,410,15);
        circle(175+i,410,15);
        circle(180+i,410,15);

        setfillstyle(XHATCH_FILL, MAGENTA);
        circle(450, 100, 50);
        floodfill(100, 100, WHITE);

        fillellipse(485, 430,500, 5);



        delay(1000);

        ch=getch();
        cleardevice();
    }

    getch();
    closegraph();
    return 0;
}
