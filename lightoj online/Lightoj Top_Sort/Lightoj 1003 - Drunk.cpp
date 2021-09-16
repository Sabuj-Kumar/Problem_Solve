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
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e5;
int n;
vector< int > graph[ N ];
unordered_map< string,int > mp;
int vis[ N ];
bool flag;

void DFS(int node){

    vis[ node ] = 1;

    for(auto x : graph[ node ]){

        if(vis[ x ] == 2) continue;

        if(vis[ x ] == 1){

            flag = false;
            return;
        }
        DFS( x );
    }
    vis[ node ] = 2;
}

bool check(int x,int y){

    for(auto u : graph[ x ])
        if(u == y) return false;

    return true;
}
int main(){

    file();

    int t = I();

    Case( t ){

        memset(vis,0,sizeof vis);
        for(int i = 0; i < 30000; i++) graph[ i ].clear();
        mp.clear();

        n = I();
        int cnt = 0;
        string s,p;

        for(int i = 0; i < n; i++){

            cin >> s >> p;

            if(!mp[ s ]) mp[ s ] = ++cnt;
            if(!mp[ p ]) mp[ p ] = ++cnt;

            if(check(mp[ s ],mp[ p ])) graph[ mp[ s ] ].pb(mp[ p ]);
        }

        flag = true;

        for(int i = 1; i <= cnt; i++){

            if(vis[ i ] == 0) DFS( i );

            if(!flag) break;
        }

        printf("Case %d: ",cs);
        if( flag ) puts("Yes");
        else puts("No");
    }
    return 0;
}
