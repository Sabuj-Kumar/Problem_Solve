#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

long long fact(long long n)
{
    if(n < 2)
        return 1;

    return n * fact(n - 1);
}
int main()
{
    long long n,result = 0;

    cin>>n;

    result = fact(n);

    cout<<result;

    return 0;
}
