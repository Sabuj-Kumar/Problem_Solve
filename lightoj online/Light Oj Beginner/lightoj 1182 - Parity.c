#include<stdio.h>
#define pf printf
#define sc scanf
int a[1000];
int main()
{
    long long Case;
    int i,j,k,n,count=0;
    sc("%lld",&Case);
    for(i=1; i<=Case; i++)
    {
      sc("%d",&n);
      for(j=0; n>0 ;j++)
      {
        a[j]=n%2;
        n=n/2;
      }
      for(k=j-1;k>=0;k--)
      {
       if(a[k]==1)
           count++;
      }
      if(count%2==0)
           pf("Case %d: even\n",i);
      else
           pf("Case %d: odd\n",i);

      count=0;
    }

 return 0;
}
