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

vector< vector< int > > table;
int n,m;

void sparse(vector< int > &v){

    int lg = 0;

    while((1 << lg) <= n) lg++;

    table = vector<vector< int > > (n,vector< int > ( lg ));

    for(int i = 0; i < n; i++) table[ i ][ 0 ] = v[ i ];

    for(int j = 1; j <= lg; j++)
        for(int i = 0; i  < (n - (1 << (j - 1))); i++)
            table[ i ][ j ] = max(table[ i ][ j - 1 ],table[ i + (1 << (j - 1)) ][ j - 1 ]);
}

int query(int l,int r){

    int lg = 0;
    int R = r - l + 1;

    while((1 << lg) <= R) lg++;

    return max(table[ l ][ lg - 1 ],table[ r - (1 << (lg - 1)) ][ lg - 1 ]);
}
int main(){

    file();

    cin >> n >> m;
    vector< int > v;

    for(int i = 0; i < n; i++) { int a; cin >> a; v.pb( a ); }

    sparse( v );

    int cnt = 0;

    while(m--){

        int l,r;

        cin >> l >> r;

        if(l > r) swap(l,r);

        if(query(l,r - 2) <= v[ l - 1 ]) cnt++;
    }

    cout << cnt << endl;

    return 0;
}
