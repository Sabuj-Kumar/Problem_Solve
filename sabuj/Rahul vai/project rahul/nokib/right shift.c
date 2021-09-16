#include<stdio.h>//right shift
#include<conio.h>
int main()
{
    int c,x,n;
    printf("enter x and n\n");
    scanf("%d%d", &x, &n);
    c = x >> n;
    printf("%d", c);

getch();
return 0;
}

