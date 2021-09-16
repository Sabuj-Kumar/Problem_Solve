#include<stdio.h>
#include<conio.h>
int main()
{
    int a,b,c;
    printf("enter two number\n");
    scanf("%d%d",&a,&b);
    c=a%b;
    printf("modulus= %d",c);
    getch();
    return 0;
}
