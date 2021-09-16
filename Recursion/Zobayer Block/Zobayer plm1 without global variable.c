#include<stdio.h>
int recursion(int a,int *b)
{
    printf("%d ",a);
    if(a==1)
    return 0;
    else
    recursion(a-1,b);
}
int main()
{
    int i,n,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    recursion(n,a);
  return 0;
}
