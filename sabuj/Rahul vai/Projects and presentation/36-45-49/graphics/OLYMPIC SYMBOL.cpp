/**************************/
/******GROUP(08)*********/
/******ROLL:-(36,45,49)*******/


#include <stdio.h>
#include <graphics.h>
int main()
{

int gd,gm,i;

gd=DETECT;

bool dbflag= false,closeflag=true;
    initwindow(1000,800,"Graphics",0, 0, dbflag, closeflag);
    setbkcolor( MAGENTA);
setcolor( WHITE );
 cleardevice();
 settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
  outtextxy(60,30,"  OLYMPIC SYMBOL");
 setcolor(BLUE);
 for(i=75;i<=90;i++)
 {
     delay(200);
circle(250, 250, 1*i);
delay(200);
circle(250, 250, 1*i);
 }
setcolor(BLACK);
for(i=75;i<=90;i++)
{
delay(200);
circle(440, 250,1*i);
delay(200);
circle(440, 250, 1*i);
}
setcolor(RED);
for(i=75;i<=90;i++)
{
     delay(200);
circle(630, 250,1*i);
 delay(200);
circle(630, 250,1*i);
}
 setcolor(YELLOW);
 for(i=75;i<=90;i++)
 {
      delay(200);
circle(345, 350, 1*i);
 delay(200);
circle(345, 350, 1*i);
 }
 setcolor(GREEN);
 for(i=75;i<=90;i++)
 {
     delay(200);
circle(537, 350, 1*i);
delay(200);
circle(537, 350, 1*i);
 }

getch();
return 0;
}
