#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int main(void)
{
    int gd=DETECT,gm,i=-300,j;
    /*for car structure*/
    int poly[16]={100,100,250,100,250,50,300,50,325,90,325,140,100,140,100,100};
    int tpoly[16]={100,100,250,100,250,50,300,50,325,90,325,140,100,140,100,100};
    initgraph(&gd,&gm,"");
    getch();
    //for enter   
    printf("Press enter to move the car  :)");
   while(!kbhit())
  {
   for(j=0;j<16;j+=2)
  {
   poly[j]=tpoly[j]+i;
   }
   fillpoly(8,poly);
   setfillstyle(5,7);
   bar(275+i,60,295+i,85);
   setfillstyle(5,8);
   fillellipse(140+i,140,20,20);
   fillellipse(280+i,140,20,20);
   setfillstyle(1,0);
   fillellipse(140+i,140,10,10);
   fillellipse(280+i,140,10,10);
   setcolor(15);
   line(0,160,639,160);
   setcolor(0);
   setfillstyle(1,4);
   delay(20);
   cleardevice();
   i++;
   if(i>550)
   i=-300;
   }
   closegraph();
}
