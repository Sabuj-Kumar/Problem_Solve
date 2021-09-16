#include<stdio.h>
#include<math.h>
#define pi 2 * acos(0.0)
#define pf printf
int v=5;
int main()
{
    double sqr=0,crl=0,r,sum=0;
    int i,n;
    scanf("%d",&n);
    printf("%d\n",v);
    for(i=1;i<=n;i++)
    {
        scanf("%lf",&r);
        sqr=4*r*r;
        crl=pi*r*r;
        sum=sqr-crl;
        pf("Case %d: %.2lf\n",i,sum+.0000000001);
    }
    return 0;

}
