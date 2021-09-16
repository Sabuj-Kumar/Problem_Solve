#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll>
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

const int N = 300;

string a,b;
vector< int > graph[ N ];
int mx,cnt;
bool vis[ N ];
unordered_map<string,int> mp;

int check(string s){

    static int cnt = 0;

    for(int i = 0; i < s.size(); i++)
        if(isupper(s[ i ])) s[ i ] += 32;

    if(mp[ s ] == 0) cnt++;
    else return mp[ s ];

    return mp[ s ] = cnt;
}
void DFS(int node,int depth){

    if(vis[ node ]) return;

    mx = max(depth,mx);

    vis[ node ] = true;

    for(auto x : graph[ node ])
        DFS(x , depth + 1);
}
int main(){

    //file();

    int n;
    string s;

    cin >> n;

    for(int i = 1; i <= n; i++){

        cin >> a >> s >> b;

        int x = check( a );
        int y = check( b );

        graph[ x ].pb( y );
        graph[ y ].pb( x );
    }

    mx = -1;

    DFS( 2, 1);

    cout << mx << endl;

    return 0;
}
