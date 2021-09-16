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

vector< vector < int > > graph,tgraph;
vector< bool > vis,check;
vector< int > order,com;
int n,m,ans;

int value(int x){

    if(x < 0){

        x = -x;
        x--;
        return (x << 1) + 1;
    }

    x--;

    return (x << 1);
}

void topsort(int node){

    vis[ node ] = true;

    for(auto x : graph[ node ])
        if(!vis[ x ]) topsort( x );

    order.pb( node );
}

void scc(int node,int cnt){

    com[ node ] = cnt;

    for(auto x : tgraph[ node ])
        if(com[ x ] == -1) scc(x,cnt);
}

bool _2_SAT(int n){

    ans = 0;
    int cnt = 0;

    for(int i = 0; i < n; i++) if(!vis[ i ]) topsort( i );

    reverse(order.begin(),order.end());

    for(int i = 0; i < n; i++)
        if(com[ order[ i ] ] == -1) scc(order[ i ],cnt++);

    for(int i = 0; i < n; i += 2){

        if(com[ i ] == com[ i + 1 ]) return false;

        ans += check[ i / 2 ] = com[ i ] > com[ i + 1 ];
    }

    return true;
}
int main(){

    file();

    int t;

    cin >> t;

    Case( t ){

        cin >> n >> m;

        vector< vector< int > > v1(2 * m + 5),v2(2 * m + 5);
        vector< int > p(2 * m + 5,-1);
        vector< bool > b(2 * m + 5,false),c(2 * m + 5,false);

        order.clear();
        swap(v1,graph);
        swap(v2,tgraph);
        swap(p,com);
        swap(vis,b);
        swap(check,c);

        for(int i = 0; i < n; i++){

            int x,y;

            cin >> x >> y;

            x = value( x );
            y = value( y );

            graph[ x^1 ].pb( y );
            graph[ y^1 ].pb( x );

            tgraph[ x ].pb( y^1 );
            tgraph[ y ].pb( x^1 );
        }

        cout << "Case "<< cs << ": ";

        if(_2_SAT(2 * m)){

            cout << "Yes" << endl << ans;

            for(int i = 0; i < m; i++) if(check[ i ]) cout << " " << i + 1;

            puts("");
        }
        else cout <<"No" << endl;
    }

    return 0;
}
