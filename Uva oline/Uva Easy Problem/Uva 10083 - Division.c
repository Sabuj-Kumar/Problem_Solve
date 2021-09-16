#include<stdio.h>
#include<math.h>
int main()
{
  long long t,a,b,div=0;
  scanf("%d%d%d",&t,&a,&b);
  div=(pow(t,a)-1)/(pow(t,b)-1);
  printf("(%d^%d-1)/(%d^%d-1)");


 return 0;
}
