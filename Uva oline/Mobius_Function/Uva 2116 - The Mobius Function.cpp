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

const int N = 1e4 + 100;
vector< int > prime;
bool vis[ N ];
int mb[ N ];

void seive(){

    int sz = sqrt( N );

    for(int i = 2; i <= sz+1; i++)
        if(!vis[ i ])
            for(int j = i + i; j < N; j += i)
                vis[ j ] = true;

    for(int i = 2; i < N; i++)
        if(!vis[ i ]) prime.pb( i );
}

void mobius(){

    int sz = sqrt( N );

    for(int i = 1; i < N; i++) mb[ i ] = 1;

    for(int i = 0; i < prime.size() and prime[ i ] <= sz+1; i++){

        int x = prime[ i ] * prime[ i ];

        for(int j = x; j < N; j += x) mb[ j ] = 0;
    }

    for(int i = 0; i < prime.size(); i++)
        for(int j = prime[ i ]; j < N; j += prime[ i ])
            mb[ j ] *= -1;
}
int main(){

    seive();
    mobius();

    file();

    int n;

    while(cin >> n){

        if(n == -1) break;

        cout << "M(" << n << ") = " << mb[ n ] << endl;
    }
    return 0;
}
