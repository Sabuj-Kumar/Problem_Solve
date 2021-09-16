#include<bits/stdc++.h>

using namespace std;

long long big_mod(long long B,long long P,long long M)
{
    if(P == 0) return 1;

    if(P % 2 == 1) return (B % M *(big_mod(B,P-1,M))) % M;

    else
    {
        long long R = big_mod(B,P/2,M);

        return (R * R) % M;
    }
}
int main()
{
    long long B,P,M;

    while(cin >> B >> P >> M)
        cout << big_mod(B,P,M) << "\n";

    return 0;
}
