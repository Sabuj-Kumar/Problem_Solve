#include<stdio.h>
#include<string.h>
int main()
{
    int a[100],i,j,n;
    printf("enter the digit: ");

    scanf("%d",&n);

    for (i=n;i>0;i--)
    {
        a[i]=i%2;

     printf("%d",a[i]);
       i=(i/2)+1;
    }
   for(j=i-1;j>=0;j--)
   {
       printf("%d",a[j]);
   }
}
