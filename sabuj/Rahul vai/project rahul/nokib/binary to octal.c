#include<stdio.h>//binary to octal
#include<conio.h>
#include<math.h>
int main()
{
    int n,i;
    int sum=0,x;
    printf("enter binary number= ");
    scanf("%d",&n);
    for(i=0;n!=0;i++)
    {
        x=n%10;
       sum=sum+(x*pow(2,i));
        n=n/10;
        
    }
    printf("octal = %o",sum);
    getch();
    return 0;
}
