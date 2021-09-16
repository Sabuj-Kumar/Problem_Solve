#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; cs++)
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

const int N = 1e5 + 15;
vector< ll > dp(N,-1),a(N);
int n,k;

ll Call(int idx){

    if(idx == n - 1) return 0;
    if(idx > n) return INT_MAX;

    if(dp[ idx ] != -1) return dp[ idx ];

    ll p = INT_MAX;

    for(int i = 1; i <= k; i++) p = min(p,Call(idx + i) + abs(a[ idx ] - a[ idx + i ]));

    return dp[ idx ] = p;
}

int main(){

    file();

    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> a[ i ];

    a[ n ] = INT_MAX;

    cout << Call(0) << endl;

    return 0;
}

