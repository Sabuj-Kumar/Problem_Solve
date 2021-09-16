// Sin(x) series expansion
#include<stdio.h>
#include<conio.h>
#include<math.h>
int factorial(int n)
{
    int result = 1;
    for(;n>0;n--)
    {
       result = result * n ;
    }
    return result;
}

int main()
{
    int n,i;
    float x,sum=0;
    printf("Give the value of x = ");
    scanf("%f",&x);
    printf("\nGive the value of n terms = ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        if(i%2==1) // odd terms
        sum =sum + pow(x,2*i - 1) / factorial(2*i-1);
        else
        sum =sum - pow(x,2*i - 1) / factorial(2*i-1);
    }
    printf("\nThe sum is = %.2f",sum);
    getch();
    return 0;
}
