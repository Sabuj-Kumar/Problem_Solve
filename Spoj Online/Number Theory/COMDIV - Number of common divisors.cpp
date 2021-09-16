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

const int N = 1e6+5;
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

    file();

    int t;

    sc( t );

    while(t--){

        int n,m,a,b;

        sc( n );
        sc( m );

        int gcd = __gcd(n,m);

        int cnt = 0;

        for(int i = 1; i <= sqrt(gcd); i++){

            if(i * i == gcd) cnt++;
            else if(gcd % i == 0) cnt += 2;
        }

        printf("%d\n",cnt);
    }

    return 0;
}




