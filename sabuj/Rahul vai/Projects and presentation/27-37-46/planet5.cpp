#include<graphics.h>
#include<stdio.h>
main()
{
  int gd=DETECT,gm;
  int i,x,y,j=0,k=0;
  char msg[50];

  initgraph(&gd,&gm,"");
  line(0,0,640,0);
  line(0,0,0,480);
  line(639,0,639,480);
  line(639,479,0,479);
    while(1){
  for(j=0;j<=50;j++)
  {
      setcolor(WHITE);
      circle(100,100,j);
      setcolor(LIGHTRED);
       moveto(80,160);

    sprintf(msg,"MOON",getmaxy());
    outtext(msg);
  }
  for(j=0;j<=100;j++)
  {
      setcolor(BLUE);
      circle(300,300,j);
       moveto(275,410);
       setcolor(LIGHTRED);
    sprintf(msg,"EARTH",getmaxy());
    outtext(msg);
  }
  for(i=0;i<=1000;i++)
  {
    x=rand()%639;
    y=rand()%480;
    putpixel(x,y,15);
  }



  getch();
  closegraph();
}
}
/* End of program */
