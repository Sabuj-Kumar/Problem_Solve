#include<stdio.h>
#include<conio.h>


int main()
{
    int i,x,y;
    scanf("%d%d",&x,&y);
     int result = 1;
    for (i=0;i<y;i++)
      {
          result *= x;
      }

printf("\n%d",result);

    getch();
    return 0;
}
