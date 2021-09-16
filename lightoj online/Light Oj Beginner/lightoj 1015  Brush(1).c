#include<stdio.h>
int main()
{
    int i,j,sum=0,n,a,dig;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for(j=0;j<a;j++)
        {
            scanf("%d",&dig);
            if(dig>=0)
            {
             sum+=dig;
            }
        }
        printf("Case %d: %d\n",i,sum);
        sum=0;
    }

 return 0;
}
