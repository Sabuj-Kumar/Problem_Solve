#include<stdio.h>
int recursion(int a,int b,int *c)
{
    printf("%d %d\n",a+1,b+1);
    if(a==b)
      return 0;
    else
      recursion(a+1,b-1,c);
}
int main()
{
    int i,n,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    recursion(0,n-1,a);
 return 0;
}
