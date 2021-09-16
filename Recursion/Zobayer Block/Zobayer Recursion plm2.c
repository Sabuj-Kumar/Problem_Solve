#include<stdio.h>
int array[1000];
int recursion(int a,int b)
{
 printf("%d %d\n",array[a],array[b]);
 if(a==b)
 return 0;
 else
 return recursion(a+1,b-1);
}
int main()
{
  int n,i,x=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&array[i]);
  recursion(x,n-1);
  return 0;
}
