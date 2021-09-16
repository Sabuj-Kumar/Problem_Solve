#include<bits/stdc++.h>

using namespace std;

long long a,b,c,d,e,f;

long long ar[ 10001 ];

long long dp(long long n)
{
    if(ar[ n ] != -1) return ar[ n ];

    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;

    return ar[ n ] = ( dp(n-1) + dp(n-2) + dp(n-3) + dp(n-4) + dp(n-5) + dp(n-6) ) % 10000007;
}

int main()
{
    long long test,n,i;

    scanf("%lld",&test);

    for(i = 1; i <= test; i++)
    {
        memset(ar,-1,sizeof(ar));

        scanf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&n);

        printf("Case %lld: %lld\n",i,(dp(n)%10000007));
    }
    return 0;
}
