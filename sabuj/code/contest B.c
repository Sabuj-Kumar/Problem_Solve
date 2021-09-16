#include<stdio.h>
int main()
{
    int i,j,sum=0,a,n,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&l);
        for(j=0;j<l;j++)
        {
            scanf("%d",&a);
            sum=sum+(a);
        }
        printf("Case %d: %d\n",i,sum);
        sum=0;
    }
    return 0;
}
