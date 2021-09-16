#include<stdio.h>
#include<conio.h>
// find the x y from  a1x+b1y+c1=0  a2x+b2y+c2=0  
int main()
{
    int a1,a2,b1,b2,c1,c2;
    int x,y;
    printf("Enter two equation number a1 b1 c1 a2 b2 c2\n "); 
    scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2);
    x=((b1*c2)-(b2*c1))/((a1*b2)-(a2*b1));
    y=((c1*a2)-(a1*c2))/((a1*b2)-(a2*b1));
    printf("x= %d y= %d",x,y);
    getch();
    return 0;
}
