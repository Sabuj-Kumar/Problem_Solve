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

const int N = 1e7+10;
int prime[ N ];
ll a[ N ];

void seive(){

    prime[ 0 ] = 0;
    prime[ 1 ] = 0;
    a[ 0 ] = 0;
    a[ 1 ] = 0;
    a[ 2 ] = 2;

    for(ll i = 4; i < N; i += 2) prime[ i ] = 2;

    for(ll i = 3; i < N; i++){

        if(prime[ i ] == 0){

            prime[ i ] = i;

            for(ll j = i + i; j < N; j += i){

                if(prime[ j ] == 0) prime[ j ] = i;
            }
        }
        a[ i ] = a[ i - 1 ] + prime[ i ];
    }
}
int main(){

    seive();

    file();

    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;

        cout << a[ n ] << endl;
    }

    return 0;
}
