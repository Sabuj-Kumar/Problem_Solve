#include <graphics.h>
#include <stdio.h>

int main()
{
    int i;

    char ch;

    bool dbflag = false,closeflag = true;

    initwindow(1000,2000,"CAR....", 0, 0, dbflag, closeflag);

    for( i = 0 ; i <= 1000; )
    {
        if( ch == 'R' )
        {
            if( i <= 740 )
            i += 10;
        }
        if( ch == 'L' )
        {
          if( i >= 10 )
           i -= 10;
        }

        setfillstyle(SOLID_FILL,BLUE);

        rectangle(80+i,295,170+i,400);

        rectangle(0+i,365,80+i,400);

        rectangle(170+i,370,250+i,400);

        rectangle(110+i,330,140+i,350);

        circle(75+i,410,15);

        circle(80+i,410,15);

        circle(175+i,410,15);

        circle(180+i,410,15);

        floodfill(40,10,WHITE);

        circle(750, 100, 50);

        setfillstyle(SOLID_FILL,WHITE);

        floodfill(750, 100, WHITE);

        fillellipse(485,430,520,5);

        delay(10);

        ch = getch();

        cleardevice();
    }

    getch();

    closegraph();

    return 0;
}
