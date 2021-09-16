#include<stdio.h>
int main()
{
    long long a[100000],count=1,store=0;
    long long i,j,n,m,k,p=0;
    scanf("%lld",&n);
    for(k=1;k<=n;k++)
    {
        scanf("%lld",&m);
        count=1;

        for(i=0;i<m;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i=0;i<m;i++)
        {
            for(j=i;j<m;j++)
            {
                if(a[i]>a[j])
                {
                    store=a[i];
                    a[i]=a[j];
                    a[j]=store;
                }
            }
            //printf("%lld ",a[i]);
        }
        p=a[0];
        for(i=1;i<m;i++)
        {
            if(p==a[i])
                continue;
            else
                count++;
            p=a[i];
        }
        //printf("%d\n");
        printf("Case %lld: %lld\n",k,count);
    }

    return 0;
}
