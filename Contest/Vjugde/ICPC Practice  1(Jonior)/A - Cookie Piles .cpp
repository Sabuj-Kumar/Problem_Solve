#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin >> test;

    while(test--)
    {
        long long N,A,D,Total = 0;

        scanf("%lld %lld %lld",&N,&A,&D);

        while(N--)
        {
            Total += A;

            A += D;
        }
        printf("%lld\n",Total);
    }
    return 0;
}
