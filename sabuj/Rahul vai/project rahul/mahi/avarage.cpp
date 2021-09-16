#include<stdio.h>
#include<conio.h>


int main()
{
   float a[100]={0.00};
   int i,n;
   float sum=0,avarage;
   scanf("%d",&n);

   for(i=0;i<n;i++)
   {
       scanf("%f",&a[i]);
       sum = sum + a[i];
   }


avarage = sum / n;

printf("%f",avarage);

    getch();
    return 0;
}
