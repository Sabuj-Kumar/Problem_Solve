#include<stdio.h>//without any function
#include<conio.h>
 int main()
 {
     int a[10];
     int n,i;
     double sum=0;
     scanf("%d",&n);
     for(i=0;i<n;i++)
         {
            scanf("%d", &a[i]);

            sum=sum+a[i];
         }
     sum=sum/n;
     printf("%lf", sum);
     getch();
     return 0;
 }
