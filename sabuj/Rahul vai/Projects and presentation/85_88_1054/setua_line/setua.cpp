#include<graphics.h>
#include<conio.h>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
   int gd = DETECT, gm,points[]={320,150,420,300,250,300,320,150},p,j=1,x=5,y=0;
   char str[100],key=80;
   //initgraph(&gd, &gm, "C:\\TC\\BGI");
   initwindow(640, 480);
    rectangle(10,0,100,380);
    rectangle(250,10,500,100);
    rectangle(500,100,110,400);
    rectangle(0,400,639,479);
    setcolor(RED);
    circle(630,240,5);
   for(;;)
    {
        if(j==14)
            j=1;
        setcolor(j);
        circle(x,y,3);
        j++;
        if((x<0 || x>640) || (y<0 || y>480) ){
            cleardevice();
            setcolor(15);
            outtext("Game Over.....");
            break;
        }

        if(getpixel(x+2,y+2)==15){
            cleardevice();
            setcolor(15);
            outtext("Game Over.....");
            break;
        }
        if(getpixel(x-2,y-2)==15){
            cleardevice();
            setcolor(15);
            outtext("Game Over.....");
            break;
        }
        if(getpixel(x-2,y+2)==15){
            cleardevice();
            setcolor(15);
            outtext("Game Over.....");
            break;
        }
        if(getpixel(x+2,y-2)==15){
            cleardevice();
            setcolor(15);
            outtext("Game Over.....");
            break;
        }
        if((x>=628 && x<=632) && (y>=238 && y<=242)){
            cleardevice();
            setcolor(15);
            outtextxy(200,240,"Congratulation.......You have success to reached the station");
            break;
        }
        if (kbhit())
        {
          key =getch();
        }
        if(key==75)
            x--;
        else if(key==77)
            x++;
        else if(key==72)
            y--;
        else if(key==80)
            y++;
        delay(30);
   }
   getch();
   closegraph();
   return 0;
}
