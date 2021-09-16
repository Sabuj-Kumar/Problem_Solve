#include<bits/stdc++.h>
#define mod 10000000000007
#define ll long long

using namespace std;

int a[ 110 ][ 110 ];
int s() { int n; scanf("%d",&n); return n; }

ll nCr(int n,int r){

    if(n == r) return 1;
    if(r == 1) return n;
    if(a[ n ][ r ] != -1) return a[ n ][ r ];

    return a[ n ][ r ] = ( (nCr(n - 1,r) % mod) + ( nCr(n - 1,r - 1) % mod ) ) % mod;
}

int main(){

    freopen("input.txt","r",stdin);

    int test = s();
    memset(a,-1,sizeof a);

    for(int cs = 1; cs <= test; cs++){

        int n = s();
        int x = s();
        int y = s();

        //cout << n << " " << x << " " << y << endl;

        ll ans1 = nCr(n*n,x);
        ll ans2 = nCr(n*n,y);

        cout << a[ n* n ][ x ] << " " << a[ n* n ][ y ] << " " << ans1 + ans2 << endl;
    }

    return 0;
}
