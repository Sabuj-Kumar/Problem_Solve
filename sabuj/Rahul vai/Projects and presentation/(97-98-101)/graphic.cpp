#include<graphics.h>
main()
{
  int gd=DETECT,gm;
   int ch='\0';
  int i,j,x,y;
     bool dbflag= false,closeflag=true;
    initwindow(1200,1000,"I AM BACK",0, 0, dbflag, closeflag);

    for( i = 0 ;i<=1000 ; )
   {
      if((int)ch==77)
       {
           i=i+10;
      }
      if((int)ch==75)
       {
           i=i-10;
      }

  fillellipse(375-i, 530+i,90, 23);
  fillellipse(375-i, 520+i,40, 29);

for(j=0;j<=1000;j++)
  {
    x=rand()%1200;
    y=rand()%1000;
    putpixel(x,y,15);
  }

      ch=getch();
      cleardevice();
   }
   getch();
  closegraph();
}
