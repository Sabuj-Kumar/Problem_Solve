#include<stdio.h>
int main()
{
    int sum=0,i,n,a,b,c;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a>b && a>c)
        {
          sum=(b*b)+(c*c)-(a*a);
        }
        else if(b>a && b>c)
        {
            sum=(a*a)+(c*c)-(b*b);
        }
        else if(c>a && c>b)
        {
            sum=(a*a)+(b*b)-(c*c);
        }
        else
        {
            sum=1;
        }

        if(sum==0)
            {
                printf("Case %d: yes\n",i);
            }
        else
            {
                printf("Case %d: no\n",i);
            }
        sum=0;
    }

    return 0;
}
