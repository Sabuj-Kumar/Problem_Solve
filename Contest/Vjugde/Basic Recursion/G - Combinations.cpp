#include<bits/stdc++.h>
#define space 110

using namespace std;

long long a[ space ][ space ];

long long nCr(long long n,long long r)
{
    if(r == 1)  return n;
    if(n == r)  return 1;

    if(a[ n ][ r ] != -1) return a[ n ][ r ];

    else return a[ n ][ r ] = ( nCr(n-1,r-1) + nCr(n-1,r) );
}
int main()
{
    int n,r,i,j;

    while(cin >> n >> r)
    {
        long long result = 0;

        if(n == 0 && r == 0)
            break;

        for(i = 0; i < space; i++)
          for(j = 0; j < space; j++)
            a[ i ][ j ] = -1;

        result = nCr(n,r);

        cout << n << " things taken " << r << " at a time is " << result << " exactly.\n";
    }
    return 0;
}
