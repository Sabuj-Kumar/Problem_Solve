#include<graphics.h>
#include<conio.h>

main()
{
   int gd = DETECT, gm;

   initgraph(&gd, &gm, "Gadha");

//   rectangle(100,100,200,200);
//circle(100, 100, 50);
int j=4;
char ch='\0';
for(int i=0;i<1000;)
{

   setcolor(j);
   rectangle(100+i, 100, 200+i, 200);
   rectangle(101+i, 101, 201+i, 201);
   rectangle(102+i, 102, 202+i, 202);
   delay(10);
   if(ch=='a')
   {
      i=i+5;
   }
   else if(ch=='s')
   {
       i=i-5;
   }
   j++;
   if(j==15)j=2;
   ch=getch();
   cleardevice();
}
   getch();
   closegraph();
   return 0;
}
