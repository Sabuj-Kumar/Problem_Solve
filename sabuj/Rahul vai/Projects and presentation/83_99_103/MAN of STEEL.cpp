#include <graphics.h>
#include <dos.h>
#include<stdio.h>
#include<conio.h>
int main()
{
    int i, j=1,k=2,r=3;
    int ch='\0';

   bool dbflag= false,closeflag=true;
    initwindow(800,1000,"MAN of STEEL",0, 0, dbflag, closeflag);

   for( i = 0 ;i<=500 ; )
   {
      if((int)ch==77)
       {
           i=i+1;
      }
      if((int)ch==75)
       {
           i=i-1;
      }
      if(int(ch=='a'))
      {
      j=j+2;
      }
    if((int)(ch=='s'))
      {
       j=j-2;
      }
     if((int)(ch=='t'))
       {
       k=k+15;
       }
        if((int)(ch=='r'))
   {
       k=k-15;
   }
    {
    rectangle(300,350,450,550);
    rectangle(301,351,451,551);
    rectangle(302,352,452,552);
    rectangle(303,353,453,553);
    rectangle(304,354,454,554);

    rectangle(300,550,450,600);
    rectangle(301,551,451,601);
    rectangle(302,552,452,602);
    rectangle(303,553,453,603);
    rectangle(304,554,454,604);



setcolor(14);
{
         line(530,460, 450, 350);
         line(531,461, 451, 351);
         line(532,462, 452, 352);
         line(533,463, 453, 353);

         fillellipse(512, 460,19, 5);

         line(495,455, 450, 390);
         line(496,456, 451, 391);
         line(497,457, 452, 392);
         line(498,458, 453, 393);

         line(250,455, 300, 390);
         line(251,456, 301, 391);
         line(252,457, 302, 392);
         line(253,458, 303, 393);

         fillellipse(232, 455,20, 5);

          line(300, 350, 210, 450);
          line(301, 351, 211, 451);
          line(302, 352, 212, 452);
          line(303, 353, 213, 453);

         line(360, 350, 365,320);
         line(390, 350, 385,320);
         {

         circle(375, 270, 50);
         circle(395, 260, 7);
         circle(360, 260, 7);

         fillellipse(395, 260, 7+j,7);
         fillellipse(360, 260,7+j,7);

         }
            arc(395, 250, 0, 150, 7);
            arc(360, 250, 0, 170, 7);

          int gd=DETECT,gm,points[]={375,275,380,285,370,285,367,290};
          fillpoly(4, points);

          fillellipse(375, 305,17, 4);

          fillellipse(285, 554,5, 8);
          fillellipse(277, 557,5, 8);
          fillellipse(267, 559,5, 8);
          fillellipse(260, 559,5, 8);
          fillellipse(252, 557,5, 8);

          fillellipse(475, 550,5, 8);
          fillellipse(484, 550,5, 8);
          fillellipse(490, 550,5, 8);
          fillellipse(495, 550,5, 8);
          fillellipse(500, 550,5, 8);


        line(250, 550, 210, 450);
        line(280, 540, 250, 450);

        fillellipse(265, 545,25, 15);


        line(495,455, 470, 530);
        line(530,460, 500, 540);

        fillellipse(490, 535,25, 15);

        line(410,700, 377, 600);
        line(470,700, 444, 600);

        fillellipse(440, 705,30, 8);

        line(460+i,820+i, 470, 700+i);
        line(410+i,820+i, 410, 700+i);
        {
        rectangle(410+i,840+i,469+i,820+i);
        }


line(350,700, 377, 600);
line(300,700, 310, 600);

fillellipse(325, 705,25, 8);

line(360+i,820+i, 345, 700+i);
line(310+i,820+i, 300, 700+i);

{
rectangle(360+i,840+i,270+i,820+i);
}
fillellipse(375, 230,55, 13);
fillellipse(375, 220,25, 19);

fillellipse(323, 270,3, 9);
fillellipse(426, 270,3, 9);

line(500,555, 500,70);
line(501,555, 501,70);
line(502,555, 502,70);
line(503,555, 503,70);
line(504,555, 504,70);
line(505,555, 505,70);
    }
setcolor(8);
line(250,555, 250*i,770);
line(251,555, 251*i,770);
line(252,555, 252*i,770);
line(253,555, 253*i,770);
line(254,555, 254*i,770);
line(255,555, 255*i,770);
{
    setfillstyle(SOLID_FILL,BLUE);
    setcolor(BLUE);
    rectangle(300,350,450,550);
    floodfill(303,351,BLUE);

    fillellipse(5+250*2*i, 820,25, 19);

    setfillstyle(SOLID_FILL,GREEN);
    setcolor(GREEN);
    rectangle(300,550,450,600);
    floodfill(301,551,GREEN);

    fillellipse(-10+250*2*i, 820,25, 19);

}
{
    setfillstyle(SOLID_FILL,GREEN);
    setcolor(GREEN);
    rectangle(500,50,750+k-r,200);
    //
    floodfill(501,51,GREEN);
    floodfill(501,51,GREEN);

    setfillstyle(SOLID_FILL,RED);
    setcolor(RED);
    circle(580+k,120,50);
    floodfill(581+k,121,RED);

}
   ch=getch();
      cleardevice();
   }

    }
      getch();

   closegraph();
   return 0;
}





































