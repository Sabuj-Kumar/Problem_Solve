#include<stdio.h>
#include<conio.h>
int main()
{
int max=-1;
int a[20],i,n;
scanf("%d",&n);
for(i=0;i<n;i++)
{
  scanf("%d",&a[i]);
  if(a[i]>max)
  {
   max=a[i];
  }
}
 printf("%d",max);
 getch();
 return 0;
}

