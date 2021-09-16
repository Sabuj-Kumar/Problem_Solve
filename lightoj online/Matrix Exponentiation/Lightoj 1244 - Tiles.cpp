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
    in
    #endif // ONLINE_JUDGE
}

const int sz = 3;
const int mod = 10007;

struct matrix{

    int row = 0;
    int col = 0;

    ll mat[ sz ][ sz ];

    matrix(int r = 0,int c = 0){

        row = r;
        col = c;
        memset(mat,0,sizeof mat);
    }
};

vector< matrix > v;

matrix multiply(matrix a,matrix b){

    matrix temp(a.row,b.col);

    for(int i = 0; i < a.row; i++)
    for(int j = 0; j < b.col; j++)
    for(int k = 0; k < b.row; k++){

        temp.mat[ i ][ j ] += (a.mat[ i ][ k ] * b.mat[ k ][ j ]) % mod;
        temp.mat[ i ][ j ] %= mod;
    }
    return temp;
}
void calculation(matrix temp){

    v.pb( temp );

    for(int i = 1; i <= 34; i++) v.pb(multiply(v[ i - 1 ],v[ i - 1 ]));
}
ll power(matrix mtx,ll p){

    if( p < 0 ) return 1;
    else if( p == 0 ) return 2;

    int lg = log2( p );

    matrix ans(3,3);

    ans = v[ lg ];

    p -= (1 << lg);

    for(int i = lg - 1; i >= 0; i--){

        if( (1 << i) <= p){

            ans = multiply(ans,v[ i ]);

            p -= (1 << i);
        }
    }

    matrix a(3,1);

    a = multiply(ans,mtx);

    return a.mat[ 0 ][ 0 ];
}
int main(){

    file();

    matrix mx(3,3),nx(3,1);

    mx.mat[ 0 ][ 0 ] = mx.mat[ 0 ][ 1 ] = 1; mx.mat[ 0 ][ 2 ] = 2;
    mx.mat[ 1 ][ 0 ] = 1,mx.mat[ 2 ][ 1 ] = mx.mat[ 2 ][ 2 ] = 1;
    nx.mat[ 0 ][ 0 ] = 2,nx.mat[ 1 ][ 0 ] = 1,nx.mat[ 2 ][ 0 ] = 1;

    calculation( mx );

    int t;
    ll n;

    sc( t );

    Case( t ){

        sl( n );
        printf("Case %d: %lld\n",cs,power( nx ,n - 2));
    }

    return 0;
}
