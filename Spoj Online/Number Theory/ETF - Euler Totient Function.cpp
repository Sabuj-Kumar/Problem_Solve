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

const int N = 1e6 + 10;

int phi[ N ];

void phi_cal(){

    phi[ 1 ] = 1;

    for(int i = 2; i < N; i++) phi[ i ] = i - 1;

    for(int i = 2; i < N; i++)
        for(int j = i + i; j < N; j += i)
            phi[ j ] -= phi[ i ];
}
int main(){

    phi_cal();

    file();

    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;

        cout << phi[ n ] << endl;
    }
    return 0;
}
