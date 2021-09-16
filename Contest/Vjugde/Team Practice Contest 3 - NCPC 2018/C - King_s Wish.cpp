#include<bits/stdc++.h>
#include<math.h>
#define n 1000010

int a[ n ];
int b[ n ];

using namespace std;

int main()
{
    int test,t;

    scanf("%d",&test);

    for(t = 1; t <= test; t++)
    {
        long long input,i,min_div = 0,root;

        scanf("%lld",&input);

        root = sqrt(input);

        for(i = 2; i <= root; i++)
        {
            if(input % i == 0)
            {
                min_div = i;
                break;
            }
        }
        if(min_div == 0)
            printf("Case %d: Impossible\n",t);

        else
            printf("Case %d: %lld %lld\n",t,(input/min_div),min_div);
    }
    return 0;
}
