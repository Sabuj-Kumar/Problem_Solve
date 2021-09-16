#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

main()
{
     int i, j = 0,gd = DETECT, gm, midx, midy;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   midx = getmaxx()/2;
   midy = getmaxy()/2;

   setcolor(RED);
   settextstyle(SCRIPT_FONT, HORIZ_DIR, 3);
   settextjustify(CENTER_TEXT, CENTER_TEXT);
  outtextxy(midx, midy+10, "Press any key to start");
   getch();
   cleardevice();
   for( i = 0 ; i <= 420 ; i = i + 10, j++ )
   {

    rectangle(25,275,150,400);
    rectangle(50,275,150,400);
    rectangle(150,350,200,400);
    circle(75,410,10);
    circle(85,410,10);
    circle(175,410,10);
    circle(185,410,10);
    setcolor(j);


      if( i == 420 )
      break;
       ( j == 10 );

         j = 2;
   delay(50);
   cleardevice();
   }
{

   setcolor(WHITE);
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
   rectangle(midx-30,midy-80,midx+30,midy+80);
   circle(midx, midy-50, 22);
   setfillstyle(SOLID_FILL,RED);
   floodfill(midx, midy-50,WHITE);
   setcolor(BLUE);
   outtextxy(midx,midy-50,"STOP");
   delay(2000);
   graphdefaults();
   cleardevice();

}

   for( i = 0 ; i <= 420 ; i = i + 10, j++ )
   {
       rectangle(25,275,150,400);
       rectangle(50,275,150,400);
       rectangle(150,350,200,400);
       circle(75,410,10);
       circle(85,410,10);
       circle(185,410,10);
       circle(175,410,10);
       setcolor(j);


      if( i == 420 )
      break;
       ( j == 10 );

         j = 2;
   delay(50);
   cleardevice();
   }
{
   setcolor(WHITE);
   rectangle(midx-30,midy-80,midx+30,midy+80);
   circle(midx, midy, 20);
   setfillstyle(SOLID_FILL,YELLOW);
   floodfill(midx, midy,WHITE);
   setcolor(BLUE);
   outtextxy(midx-18,midy-3,"READY");

    delay(2000);
    cleardevice();
      for( i = 0 ; i <= 420 ; i = i+10, j++ )
   {
       rectangle(25,275,150,400);
      rectangle(50,275,150,400);
      rectangle(150,350,200,400);
      circle(75,410,10);
      circle(85,410,10);
      circle(185,410,10);
     circle(175,410,10);

      setcolor(j);
      delay(100);

      if( i == 420 )
         break;
      if ( j == 10 )
         j = 2;

      cleardevice();
   }

   setcolor(WHITE);
   rectangle(midx-30,midy-80,midx+30,midy+80);
   circle(midx, midy+50, 22);
   setfillstyle(SOLID_FILL,GREEN);
   floodfill(midx, midy+50,WHITE);
   setcolor(BLUE);
   outtextxy(midx-18,midy+4,"GO");

   settextstyle(SCRIPT_FONT, HORIZ_DIR, 4);
delay(2000);
for( i = 0 ; i <= 420 ; i = i + 10, j++ )
   {
       rectangle(25+i,275,150+i,400);
      rectangle(50+i,275,150+i,400);
      rectangle(150+i,350,200+i,400);
      circle(75+i,410,10);
      circle(85+i,410,10);
      circle(185+i,410,10);
      circle(175+i,410,10);
      setcolor(j);
      delay(100);

      if( i == 420 )
         break;
      if ( j == 15 )
         j = 2;
      cleardevice();
   }
     setcolor(RED);
     outtextxy(midx-150, midy+100, "Press any key to exit...");

   getch();
   closegraph();
   return 0;
}
   }




















