// cos(x) series expansion //==1-x2/2+x4/24-x6/720
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

    for(i=0;i<=n;i++)
    {
        if(i%2==1) // odd terms
        sum =sum + pow(x,2*i) / factorial(2*i);
        else
        sum =sum - pow(x,2*i) / factorial(2*i);
    }
    printf("\nThe sum is = %.2f",sum);
    getch();
    return 0;
}

