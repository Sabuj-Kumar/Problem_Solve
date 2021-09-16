#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int power(int a, int b)
{
    int p = 1,i;

    for(i = 0; i < b; i++)
        p *= a;

    return p;
}
int main()
{
    int test,i;

    scanf("%d",&test);

    for(i = 1; i <= test; i++)
    {
        int a,b,c,d,j,p = 0;
        long long bi1,bi2,bi3,bi4;

        int a1 = 0,b1 = 0,c1 = 0,d1 = 0;

        scanf("%d.%d.%d.%d",&a,&b,&c,&d);

        scanf("%lld.%lld.%lld.%lld",&bi1,&bi2,&bi3,&bi4);

        j = 0;
        while(bi1 > 0)
        {
            p = bi1 % 10;
            bi1 /= 10;

            a1 += p * power(2,j);
            j++;
        }
        j = 0;
        while(bi2 > 0)
        {
            p = bi2 % 10;
            bi2 /= 10;

            b1 += p * power(2,j);
            j++;
        }

        j = 0;
        while(bi3 > 0)
        {
            p = bi3 % 10;
            bi3 /= 10;

            c1 += p * power(2,j);
            j++;
        }
        j = 0;
        while(bi4 > 0)
        {
            p = bi4 % 10;
            bi4 /= 10;

            d1 += p * power(2,j);
            j++;
        }
        if(a == a1 )
        {
            if(b == b1)
            {
                if(c == c1)
                {
                    if(d == d1)
                    {
                        printf("Case %d: Yes\n",i);
                    }
                    else
                        printf("Case %d: No\n",i);
                }
                else
                    printf("Case %d: No\n",i);
            }
            else
                printf("Case %d: No\n",i);
        }
        else
            printf("Case %d: No\n",i);
    }
    return 0;
}
