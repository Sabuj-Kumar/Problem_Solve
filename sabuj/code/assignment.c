#include<stdio.h>
#define pf printf
#define sf scanf
int main()
{
  float sum=0;
  int i,n;

   pf("Enter The N Value : ");
   sf("%d",&n);
    for(i=1; i<=n; i++)
    {
        if(i%2==1)
            sum=sum+(1.0/i);
    }
    pf("%.3f",sum);

    return 0;
}
