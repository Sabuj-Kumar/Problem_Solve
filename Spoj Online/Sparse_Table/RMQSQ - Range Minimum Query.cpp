#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
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

const int N = 1e5 + 10;
int n;
vector< int > v;
int table[ N ][ 30 ];

void build(){

    for(int i = 0; i < n; i++) table[ i ][ 0 ] = v[ i ];

    for(int j = 1; (1 << j) < n; j++){

        for(int i = 0; (i + (1 << j) - 1) < n; i++){

            if(table[ i ][ j - 1 ] <= table[ i + (1 << (j - 1)) ][ j - 1 ])
                table[ i ][ j ] = table[ i ][ j - 1 ];

            else table[ i ][ j ] = table[ i + (1 << (j - 1)) ][ j - 1 ];
        }
    }
}
int main(){

    file();
    cin >> n;

    vector< int > a(n + 2);
    swap(v,a);

    for(int i = 0; i < n; i++) cin >> v[ i ];

    build();

    int q;

    cin >> q;

    while(q--){

        int l,r;

        cin >> l >> r;

        if(l > r) swap(l,r);

        int j = (int)log2(r - l + 1);

        if(table[ l ][ j ] <= table[ r - (1 << j) + 1 ][ j ])
            cout << table[ l ][ j ] << endl;

        else cout << table[ r - (1 << j) + 1 ][ j ] << endl;
    }

    return 0;
}
