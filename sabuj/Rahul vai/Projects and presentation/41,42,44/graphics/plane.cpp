#include <stdio.h>

#include <graphics.h>

#include <stdlib.h>

int main()

{

int g,s,x=500,y=400,m,k,z,f,x2=300,y2=50,x1=1,y1=400;

detectgraph(&g,&m);

initgraph(&g,&m," ");

for(;x1<600;x1+=1)

{

cleardevice();
delay(500);
line(5,420,590,420);






line(x1,y1+10,x1+150,y1);

line(x1+90,y1-30,x1+150,y1);

line(x1+90,y1-30,x1+30,y1-10);

line(x1+30,y1-10,x1,y1-50);

line(x1,y1-50,x1,y1+10);

circle(x1+110,y1+13,8);

circle(x1+20,y1+15,5);

if(x1%3==0)

{

   line(x1+17,y1+15,x1+22,y1+15);

   line(x1+105,y1+13,x1+115,y1+13);

}

else

{

   line(x1+20,y1+12,x1+20,y1+18);

   line(x1+110,y1+7,x1+110,y1+20);

}

}

x1=1;

y1=350;

for(;x1<600;x1+=2,y1--)

{

cleardevice();

 delay(4000);

line(x1,y1+50,x1+150,y1);

line(x1+150,y1,x1+90,y1-20);

line(x1+90,y1-20,x1+30,y1+20);

line(x1+30,y1+20,x1,y1-30);

line(x1,y1-30,x1,y1+50);



}



cleardevice();



getch();

closegraph();

}

