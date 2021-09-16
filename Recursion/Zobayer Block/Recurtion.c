#include<stdio.h>
int a[1000];
int recurtion(int x)
{
   printf("%d ",a[x]);
  if(x==0)
    return 0;
  else
   return recurtion(x-1);
}
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    recurtion(n-1);
   return 0;
}
