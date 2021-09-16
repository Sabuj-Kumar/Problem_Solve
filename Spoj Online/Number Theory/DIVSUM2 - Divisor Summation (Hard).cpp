#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e8+5;
ll prime[ N ];
bool vis[ N ];
int idx;

void seive(){

    prime[ idx++ ] = 2;

    for(ll i = 3; i <= N; i += 2){

        if(!vis[ i ]){

            prime[ idx++ ] = i;

            if(i * i > N) continue;

            for(ll j = i * i; j <= N; j += (2 * i)) vis[ j ] = true;
        }
    }
}
int main(){

    seive();

    file();

    int t;

    sc( t );

    while(t--){

        ll sod = 1,n,x;

        sl( n );

        if(n == 2 and n == 1){

            if(n == 1) puts("0");

            else puts("1");

            continue;
        }

        x = n;

        for(int i = 0; i < idx and prime[ i ] * prime[ i ] <= n; i++){

            ll p = prime[ i ],s = prime[ i ];

            while(n % p == 0){

                n /= p;

                s *= p;
            }

            sod *= ((s - 1) / (p - 1));
        }

        if(n != 1) sod *= (n + 1);

        printf("%lld\n",sod - x);
    }

    return 0;
}



