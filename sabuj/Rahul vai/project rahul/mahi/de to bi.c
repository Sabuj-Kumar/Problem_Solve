#include<stdio.h>//desimal to binary
#include<conio.h>
int main()
{
    int n,i;
    printf("please enter a desimal number=");
    scanf("%d", &n);
    int remainder, sum=0;
    for(i=1;n!=0;)
    {
        remainder=n%2;
        n=n>>1;
        sum=sum+(remainder*i);
        i=i*10;
    }
    printf("\n binary value %d", sum);

    getch();
    return 0;
}
