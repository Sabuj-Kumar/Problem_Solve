#include <graphics.h>
#include <dos.h>
#include<stdio.h>
#include<conio.h>
int main()
{
   int i, j = 2, gd = DETECT, gm;
    char ch='\0';
    FILE *fp;
    fp=fopen("a.jpg","r+");
    bool dbflag= false,closeflag=true;
    initwindow(1000,800,"My Game",0, 0, dbflag, closeflag);
   initgraph(&gd,&gm,"C:\\TC\\BGI");

   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   outtextxy(0,0,"Press any key to view the moving car");
   readimagefile("a.jpg",10, 20,INT_MAX, INT_MAX);
   getch();
  int dx1=700,k=0,dx2=750,dc=800,dx3=100,dx4=110,dy3=480,dy4=500;
   bool t=false;
   ch ='q';
   for( i = 0 ;i<=1000 ; )
   {
       for(;ch;)
       bar(0,500,1000,505);// gameline(street)
       rectangle(150,450,200,500);//x,y,x,y
        ///first rectangle
       bar(dx1,450,dx2,500);// left,top,right,bottom
        ///first circle
       circle(800-k,475,25);
       dx1=dx1-10;
       dx2=dx2-10;
       bar(dx3,dy3,dx4,dy4);
       k=k+10;
       if(dx1==-50)
       {
           dx1=700;
           dx2=750;
       }
       if(k==750)
       {
           k=0;
           dc=800;
       }

       delay(50);
       cleardevice();

   }

   getch();
   closegraph();
   return 0;
}
