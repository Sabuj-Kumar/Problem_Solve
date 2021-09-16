#include<bits/stdc++.h>
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

const int N = 1e8+10;
const int NN = 5761500;
const long long mod = 1LL << 32;
bitset< N >ok;
unsigned p[ NN ];
unsigned sum[ NN ];
int sz;

void seive(){

    int rt = sqrt( N );

    for(int i = 4; i < N; i += 2) ok[ i ] = 1;

    for(int i = 3; i <= rt; i += 2)
        if(!ok[ i ])
            for(int j = i * i; j < N; j += i)
                ok[ j ] = 1;

    sz = 0;

    for(int i = 2; i < N; i++)
        if(!ok[ i ]) p[ sz++ ] = i;

    sum[ 0 ] = p[ 0 ];

    for(int i = 1; i < sz; i++)
        sum[ i ] = (sum[ i - 1 ] * p[ i ]) % mod;
}

int main(){

    seive();
    file();

    int t;

    scanf("%d",&t);

    for(int cs = 1; cs <= t; cs++){

        int n;

        scanf("%d",&n);

        int idx = upper_bound(p,p+sz,n) - p;

        unsigned ans = sum[ idx - 1 ] % mod;

        for(int i = 0; i < sz and p[ i ] * p[ i ] <= n; i++){

            int pw = p[ i ];
            int tmp = n;
            unsigned int res = 1;

            tmp /= pw;

            while(tmp >= pw){

                tmp /= pw;

                res = (res * pw) % mod;
            }

            ans = (res * ans) % mod;
        }

        printf("Case %d: %u\n",cs,ans);
    }
    return 0;
}
