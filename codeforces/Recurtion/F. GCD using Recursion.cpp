#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

long long GCD(long long a,long long b)
{
    if(b == 0) return a;

    return GCD(b , a % b);
}

int main()
{
    long long a,b,result = 0;

    cin>> a >> b;

    if(a < 0 || b < 0)
    {
        if( a < 0 )
            a *= -1;

        if( b < 0)
            b *= -1;
    }

    if(a < b)
       swap(a , b);

    result = GCD(a,b);

    cout<< result << endl;

    return 0;
}
