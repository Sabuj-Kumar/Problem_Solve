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
vector< int > graph[ 110 ];
bool vis[ 110 ];
int ans;

int DFS(int node){

    vis[ node ] = true;

    int cnt = 0;

    for(auto x : graph[ node ]){

        if(!vis[ x ]){

            int num = DFS( x );

            if(num % 2 == 0) ans++;
            else cnt += num;
        }
    }

    return cnt + 1;
}
int main(){

    file();

    int n,m;

    cin >> n >> m;

    while(m--){

        int a,b;

        cin >> a >> b;

        graph[ a ].pb( b );
        graph[ b ].pb( a );
    }

    DFS( 1 );

    cout << ans << endl;

    return 0;
}
