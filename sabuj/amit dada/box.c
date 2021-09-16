#include<stdio.h>
int main()
{
    int T,n,i,k,j;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
      scanf("%d",&n);
      for(j=0;j<n;j++)
      {
       for(k=0;k<n;k++)
        printf("*");
        printf("\n");
      }
     }
    return 0;
}
