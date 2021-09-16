#include<stdio.h>
#include<conio.h>


int main()
{
    int n,i=1,c;
    int rem=0,sum=0,dig;

    printf("\nEnetr the value in Hexadecimal :");
    scanf("%x",&n);

    while(n!=0)
    {
        rem = n%2;
        sum += rem*i;
        n = n>>1;
        i *=10;

    }
    printf("\nThe binary value is %d",sum);




    getch();
    return 0;
}
