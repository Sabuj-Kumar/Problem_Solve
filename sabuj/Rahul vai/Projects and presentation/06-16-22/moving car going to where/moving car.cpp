#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
int main()
{
 int a=DETECT,m,i=5,n;
 //int j=5,k;
 //scanf("%d",&i);
 initgraph(&a,&m,"c:\\tc\\bgi") ;
 //setbkcolor(BLACK);
 //setcolor(8);
 //for(j=1;j<=k;j++)
 //{
 outtextxy( 250,110 ," WE <3 UAP ");
 outtextxy( 102,250 ," phrma ");
 outtextxy( 202,250 ," eee ");
 outtextxy( 302,250 ," cvl ");
 outtextxy( 300,150 ," but this car is going to where ...????");
 outtextxy( 350,180 ,"u'll find out soon :P");
 outtextxy( 490,240 ," CSE ");
 outtextxy( 490,262 ," rokz ");
 outtextxy( 490,301 ," so do");
 outtextxy( 490,325 ,"  we ");
 rectangle(100,250,150,310);//1ST building
 line(100,280,150,280);//1st building 1st floor
 rectangle(100,310,150,350);//1st building
 rectangle(200,250,250,310);//2nd building 1 floor
 line(200,280,250,280);//2nd building 2rd floor
 rectangle(200,250,250,350);//2nd building 1st floor
 rectangle(300,250,350,350);//3rd building
 line(300,280,350,280);//3rd building 2nd floor
 setbkcolor(YELLOW);
 //setcolor(8);
 line(300,310,350,310);
 //line(300,330,350,330);//3rd building extra floor
 rectangle(460,230,540,350);//4th building
 line(460,260,540,260);//"
 line(460,290,540,290);//"
 line(460,325,540,325);//"
 //outtextxy( 550,270 ,"  got it :D ");
 ////////////////////////////  DRAWING ROAD  \\\\\\\\\\\\\\\\\\\\\\\\\\\

 line(0,350,639,350);  ///// 1st road line
 line(0,460,639,460);  ///// 2nd road line
 line(0,550,639,540); /////road line

 ////////////////  DRAWING CAR  \\\\\\\\\\\\\\\\\

 for(i=1;i<=n;i++)// continuous loop
 {
 setviewport(0,355,639,455,1);
 setcolor(RED);
 ellipse(100+i,35,10,170,40,20);
 ellipse(141+i,50,350,90,30,20);
 ellipse(57+i,50,90,180,15,20);
 line(42+i,50,171+i,50);
 circle(60+i,50,10);
 circle(150+i,50,10);
 delay(5);
 clearviewport();
 }
 for(i=1;i<=n;i++)
 {
 setviewport(0,355,639,455,1);
 setcolor(RED);
 ellipse(100+i,35,10,170,40,20);
 ellipse(141+i,50,350,90,30,20);
 ellipse(57+i,50,90,180,15,20);
 line(42+i,50,171+i,50);
 circle(60+i,50,10);
 circle(150+i,50,10);
 delay(50);
 clearviewport();
 getch();
//setbkcolor(GREEN);
 }
 //setbkcolor(RED);
 //outtextxy( 570,300 ,"  got it :D ");
 clearviewport();
 getch();
 return 0;
}
