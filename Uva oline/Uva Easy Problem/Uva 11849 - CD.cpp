#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long CD1,CD2;

    while(scanf("%lld %lld",&CD1,&CD2))
    {
        if(CD1 == 0 && CD2 == 0)
                 break;

        map<long long,long long> input;
        long long a,count = 0;

        while(CD1--)
        {
            scanf("%lld",&a);
            input[a] = 1;
        }
        while(CD2--)
        {
            scanf("%lld",&a);

            if(input[a] == 1)
              count++;
        }
        printf("%lld\n",count);
    }
    return 0;
}
