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

const int N = 1e5 + 100;
int n,q,k = 30;
int table[ N ][ 30 ][ 2 ];

void sparse(vector< int > &v){

    int lg = log2(n);

    for(int i = 0; i < n; i++) table[ i ][ 0 ][ 0 ] = table[ i ][ 0 ][ 1 ] = v[ i ];

    for(int j = 1; j <= lg; j++){

        for(int i = 0; (i + (1 << j)) <= n; i++){

            table[ i ][ j ][ 0 ] = min(table[ i ][ j - 1 ][ 0 ],table[ i + (1 << (j - 1 )) ][ j - 1 ][ 0 ]);
            table[ i ][ j ][ 1 ] = max(table[ i ][ j - 1 ][ 1 ],table[ i + (1 << (j - 1 )) ][ j - 1 ][ 1 ]);
        }
    }
}

db calculate(int l,int r){

    int mn = 0,mx = 0,l_mx = 0,r_mx = 0,mxi = 0;

    int lg = log2(r - l + 1);

    mn = min(table[ l ][ lg ][ 0 ],table[ r - (1 << lg) + 1 ][ lg ][ 0 ]);
    mx = max(table[ l ][ lg ][ 1 ],table[ r - (1 << lg) + 1 ][ lg ][ 1 ]);

    if(l > 0){

        lg = log2(l);
        l_mx = max(table[ 0 ][ lg ][ 1 ],table[ l - 1 - (1 << lg) + 1 ][ lg ][ 1 ]);
    }

    if(r < n - 1){

        lg = log2(n-r-1);
        r_mx = max(table[ r + 1 ][ lg ][ 1 ],table[ n - 1 - (1 << lg) + 1 ][ lg ][ 1 ]);
    }

    mxi = max(l_mx,r_mx);

    return mn + max((db)(mx - mn) / 2,(db)mxi);
}
int main(){

    file();

    cin >> n;

    vector< int > v;

    for(int i = 0; i < n; i++){

        int a;

        cin >> a;

        v.pb( a );
    }

    sparse( v );

    cin >> q;

    while(q--){

        int l,r;

        cin >> l >> r;

        db ans = calculate(l,r);

        cout << fixed << setprecision(1) << ans << endl;
    }

    return 0;
}
