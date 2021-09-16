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
#define lop(i,v,n) for(int i = v; i < n; i++)
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

vector< int > graph[ 2010 ];
int cnt;

void DFS(int n,int level){

    cnt = max(cnt,level);

    for(auto x : graph[ n ]){

        if(x != n) DFS( x,level+1 );
    }
}
int main(){

    file();

    int n;

    cin >> n;

    for(int i = 1; i <= n; i++){

        int a;

        cin >> a;

        if(a != -1) graph[ a ].pb( i );
    }

    cnt = 0;

    for(int i = 1; i <= n; i++) DFS( i,0 );

    cout << cnt + 1 << endl;

    return 0;
}
