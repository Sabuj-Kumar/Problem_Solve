#include<stdio.h>
int main()
{
    int i,j,sum=0,a,b,n,swap=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        if(a>b)
         {
            swap=a;
            a=b;
            b=swap;
         }
        for(j=a;j<=b;j++)
            {
              if(j%2==1)
               sum+=j;
            }

        printf("Case %d: %d\n",i,sum);
        sum=0;
    }
    return 0;
}
