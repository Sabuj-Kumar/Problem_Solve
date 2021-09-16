#include<stdio.h>
#include<bits/stdc++.h>

int dp[35];

using namespace std;

long long fib(long long n)
{
    if(dp[ n ] != -1)
      return dp[ n ];

    if(n == 0) return 1;
    if(n == 1) return 1;

    return dp[ n ] = fib(n - 1) + fib(n - 2);
}
int main()
{
    long long n,result;

    memset(dp,-1,sizeof(dp));

    cin>> n;

    result =  fib(n - 1);

    cout<< result << endl;

    return 0;
}
