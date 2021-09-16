#include <stdio.h>
#include <conio.h>
#include <graphics.h>
int main()
{
    int gd = DETECT, gm, midx, midy, radius, x, y, tempx, tempy;

   radius = 100;

   initgraph(&gd, &gm, "C:\\TC\\BGI");
 while (!kbhit())
 {printf("You haven't pressed a key.\n");
  }    char ch=getch();
      printf("\n%c",ch);

   return 0;
}
