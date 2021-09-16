#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

long long maximum(long long a[],long long big,long long n)
{
    if(n < 0) return big;
    if(big < a[ n ]) big = a[ n ];
    maximum(a,big,n-1);
}
int main()
{
    long long n,i;

    cin>> n;

    long long a[ n ];

    for(i = 0; i < n; i++)
        cin>> a[ i ];

    cout<< maximum(a,-10000000000,n-1) << endl;

    return 0;
}
