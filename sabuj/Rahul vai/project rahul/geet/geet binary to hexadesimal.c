#include<stdio.h>
#include<conio.h>
 int main()
 {
     int i,j=1,n,sum=0,remainder;
     scanf("%d", &n);
     for(i=0;n!=0;i++)
     {
         remainder=n%10;
         sum=sum+remainder*j;
         j=j*2;
         n=n/10;
     }
     printf("%X", sum);
     getch();
     return 0;
 }
