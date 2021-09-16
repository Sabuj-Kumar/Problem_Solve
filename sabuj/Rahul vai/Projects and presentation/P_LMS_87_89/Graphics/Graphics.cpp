#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>

main()
{
   int gd = DETECT, gm, x, y, color, angle = 0;
   struct arccoordstype a, b;

   initgraph(&gd, &gm, "C:\\TC\\BGI");
   delay(2000);

   char c[5];



   settextjustify( CENTER_TEXT, CENTER_TEXT );
   settextstyle(DEFAULT_FONT,HORIZ_DIR,8);
   setcolor(YELLOW);

   for (int i = 3; i >=0; i--)
   {
      sprintf(c,"%d",i);
      outtextxy(getmaxx()/2, getmaxy()/2, c);
      delay(1000);

      if ( i == 0 )
         break;
   }

   while(angle<=1040)
   {
      while(angle<=360){
      setcolor(BLACK);
      arc(getmaxx()/2,getmaxy()/2,angle,angle+2,100);
      setcolor(LIGHTCYAN);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);
      angle = angle+5;
      delay(50);
      }

      while(angle>360 && angle<=720)
      {
      setcolor(BLACK);
      arc(getmaxx()/2,getmaxy()/2,angle,angle+2,150);
      setcolor(LIGHTGREEN);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);
      angle = angle+5;
      delay(50);
      }


      while(angle>720 && angle<=1080)
      {
      setcolor(BLACK);
      arc(getmaxx()/2,getmaxy()/2,angle,angle+2,200);
      getarccoords(&a);
      setcolor(LIGHTBLUE);
      circle(a.xstart,a.ystart,25);
      angle = angle+5;
      delay(50);
      }
   }
   int j;
   for(int i = 0 ; i <= 420 ; i = i + 10, j++ )
   {
      circle(75+i,0,150);
      circle(175+i,410,150);
      setcolor(j);
      delay(100);

      if( i == 420 )
         break;
      if ( j == 15 )
         j = 2;
   }
   getch();
   closegraph();
   return 0;
}
