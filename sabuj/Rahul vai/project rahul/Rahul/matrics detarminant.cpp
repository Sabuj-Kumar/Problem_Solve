#include<stdio.h>
#include<conio.h>
int main()
{
    int x1,x2,x3,y1,y2,y3,z1,z2,z3;
    int a,b,c,d;
    printf("Enter 3*3 Matics \n");
    scanf("%d%d%d%d%d%d%d%d%d",&x1,&x2,&x3,&y1,&y2,&y3,&z1,&z2,&z3);
    a=x1*((y2*z3)-(y3*z2));
    b=x2*((y3*z1)-(y1*z3));
    c=x3*((y1*z2)-(y2*z1));
    d=a+b+c;
    printf("Detarminant= %d",d);
    getch();
    return 0;
}
