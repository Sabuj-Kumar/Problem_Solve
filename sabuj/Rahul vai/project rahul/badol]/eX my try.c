#include<stdio.h>  // 1+ x + x2/2! + x3/3! + x4/4!..............
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
   int i;
   float x,sum=1;
   scanf("%f", &x);
   for(i=0;i<=10;i++)
   {
       sum=sum+pow(x,i)/factorial(i);
   }
   printf("%f", sum);
getch();
return 0;
}
