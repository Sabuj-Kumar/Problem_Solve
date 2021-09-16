#include<stdio.h>
#include<conio.h>
int main()
{
    int a,b,c;
    printf("Enter The value of a and b\n ");
    scanf("%d%d",&a,&b);
    c=a & b;
    printf("%d",c);
    getch();
    return 0;
}
