/**************************/
/******GROUP(08)*********/
/******ROLL:-(36,45,49)*******/


#include <stdio.h>
#include <graphics.h>
int main()
{

int gd,gm,i,j=2,k;
 int ch='\0';

bool dbflag= false,closeflag=true;
    initwindow(1000,800,"Graphics",0, 0, dbflag, closeflag);

    setbkcolor(BLUE);

       settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
   outtextxy(50,50,"press any button");
//readimagefile("a.jpg",10, 20,INT_MAX, INT_MAX);
   getch();
     settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
   outtextxy(50,50,"FERARI-200CN ");

    for( k = 0 ;k<=1000 ; )
   {
      if((int)ch==77)
       {
           k=k+10;
      }
      if((int)ch==75)
       {
           k=k-10;
      }
 setcolor(WHITE);
line(250+k,150,450+k,150);

line(250+k,150,150+k,250);

line(450+k,150,550+k,250);

line(60+k,250,150+k,250);

line(60+k,250,60+k,350);

line(60+k,350,140+k,350);

line(200+k,350,400+k,350);

line(550+k,250,550+k,350);

line(460+k,350,550+k,350);

arc(170+k,350,0,180,28);

arc(430+k,350,0,180,28);
setcolor(BROWN);

line(150+k,250,550+k,250);

line(265+k,180,220+k,225);

line(265+k,180,320+k,180);

line(320+k,180,320+k,225);

line(220+k,225,320+k,225);

line(360+k,150,360+k,350);

line(350+k,150,350+k,350);

line(380+k,180,380+k,225);

line(380+k,180,440+k,180);

line(440+k,180,475+k,225);

line(380+k,225,475+k,225);

line(520+k,250,520+k,350);

line(100+k,250,100+k,350);
setcolor(LIGHTMAGENTA);
circle(80+k,270,5);

circle(80+k,300,5);

circle(80+k,330,5);

outtextxy(320+k,260,"--");

outtextxy(490+k,260,"--");

rectangle(530+k,260,550+k,300);

line(530+k,270,550+k,270);

line(530+k,280,550+k,280);

line(530+k,290,550+k,290);
 setcolor(CYAN);

circle(170+k,350,23);

circle(430+k,350,23);
    delay(10);

      if ( j == 15 )
         j = 2;

      ch=getch();
cleardevice();
}
getch();
return 0;
}
