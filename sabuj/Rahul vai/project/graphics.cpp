#include <graphics.h>
#include <dos.h>
#include<stdio.h>
#include<conio.h>
int main()
{
   int i, j = 2;
    int ch='\0';
  //  FILE *fp;
  //  fp=fopen("a.jpg","r+");
    bool dbflag= false,closeflag=true;
    initwindow(1000,800,"My Game",0, 0, dbflag, closeflag);
   //initgraph(&gd,&gm,"C:\\TC\\BGI");

   settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
   outtextxy(50,50,"press any button");
//readimagefile("a.jpg",10, 20,INT_MAX, INT_MAX);
   getch();

   for( i = 10 ;i<=1000 ; )
   {
      /*if((int)ch==77)
       {
           i=i+10;
      }
      if((int)ch==75)
       {
           i=i-10;
      }*/

      rectangle(50+i,275,150+i,400);
      rectangle(150+i,350,200+i,400);
      circle(75+i,410,10);
      circle(175+i,410,10);
      i++;
      //putimage( 50+i, 275, 0, 10 );
      //setcolor(j);
      delay(10);

      //if( i == 420 )
       //  break;
      if ( j == 15 )
         j = 2;

      //cleardevice(); // clear screen
      //ch='\0';
      //ch=getch();
      cleardevice();
   }

   getch();
   closegraph();
   return 0;
}
