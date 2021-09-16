#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    scanf("%d",&test);

    while(test--)
    {
        int i,j;
        int n,p,h,count_ = 0;

        scanf("%d",&n);
        scanf("%d",&p);

        int b[ n ];

        memset(b,0,sizeof(b));

        for(i = 0; i < p; i++)
        {
            scanf("%d",&h);

            for(j = h; j < n; j += h)
            {
                if(j % 7 != 0 && j % 7 != 6)
                    b[ j ]++;
            }
        }
        for(i = 1; i < n; i++)
        {
            if(b[ i ] >= 1)
                count_++;
        }
        printf("%d\n",count_);
    }
    return 0;
}
