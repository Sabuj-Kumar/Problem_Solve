#include<graphics.h>
#include<conio.h>

int main()
{
   int gd = DETECT, gm;

   initgraph(&gd, &gm,"");


int j=4;
char ch='\0';
for(int i=0;i<1000;)
{

   setcolor(j);

  circle(100+j+i,100+j+i,50+j+i);
  circle(103+j+i,103+j+i,53+j+i);
  circle(105+j+i,105+j+i,55+j+i);
  circle(107+j+i,107+j+i,57+j+i);
  circle(109+j+i,109+j+i,59+j+i);
  circle(111+j+i,111+j+i,61+j+i);
  circle(113+j+i,113+j+i,63+j+i);
  circle(115+j+i,115+j+i,65+j+i);
  circle(117+j+i,117+j+i,67+j+i);
  circle(119+j+i,119+j+i,69+j+i);
  circle(121+j+i,121+j+i,71+j+i);
  circle(123+j+i,123+j+i,73+j+i);
  circle(125+j+i,125+j+i,75+j+i);


  //floodfill(30,30,j);
   delay(10);
   if(ch=='a')
   {
      i=i+15;
   }
   else if(ch=='s')
   {
       i=i-15;
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
