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

const int N = 1e5+10;
vector< int > tree[ N ],cousin[ N ];
int st[ N ],ed[ N ],tim,n;
int table[ N ][ 20 ],level[ N ];

void sparse(int node){

    for(int i = 1; i < 20; i++)
        table[ node ][ i ] = table[ table[ node ][ i - 1 ] ][ i - 1 ];
}
void DFS(int node,int p = 0,int lv = 0){

    st[ node ] = tim++;
    table[ node ][ 0 ] = p;
    level[ node ] = lv;

    sparse(node);

    cousin[ level[ node ] ].pb(st[ node ]);

    for(auto x : tree[ node ]) DFS(x,node,lv+1);

    ed[ node ] = tim;
}

int k_th(int node,int k){

    for(int i = 0; i < 20; i++)
        if(k & (1 << i)) node = table[ node ][ i ];

    return node;
}

int main(){

    file();

    cin >> n;
    int q,a[ n + 3 ];

    for(int i = 1; i <= n; i++){

        cin >> a[ i ];

        if(a[ i ]) tree[ a[ i ] ].pb( i );
    }

    for(int i = 1; i <= n; i++) if(!a[ i ]) DFS( i );

    cin >> q;

    while(q--){

        int v,k;

        cin >> v >> k;

        if(level[ v ] < k){

            cout << 0 << " ";

            continue;
        }

        int ln = level[ v ];

        v = k_th(v,k);

        int low = lower_bound(cousin[ ln ].begin(),cousin[ ln ].end(),st[ v ]) - cousin[ ln ].begin();
        int up = lower_bound(cousin[ ln ].begin(),cousin[ ln ].end(),ed[ v ]) - cousin[ ln ].begin();

        cout << up - low - 1 << " ";
    }

    cout << endl;

    return 0;
}
