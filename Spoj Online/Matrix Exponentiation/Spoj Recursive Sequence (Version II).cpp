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
struct matrix{

    ll row,col;
    ll mat[ 18 ][ 18 ];

    matrix(ll r = 0,ll c = 0){

        row = r;
        col = c;
        memset(mat,0,sizeof mat);
    }
};

ll d,n,m,mod;

matrix multiply(matrix a,matrix b){

    matrix temp(a.row,b.col);

    for(int i = 0; i < a.row; i++)
    for(int j = 0; j < b.col; j++)
    for(int k = 0; k < a.col; k++){

        temp.mat[ i ][ j ] += (a.mat[ i ][  k ] * b.mat[ k ][ j ]) % mod;
        temp.mat[ i ][ j ] %= mod;
    }
    return temp;
}

matrix power(matrix mtx,ll p){

    if(p == 1) return mtx;

    if(p & 1) return multiply(mtx,power(mtx,p-1));

    matrix temp = power(mtx,p/2);

    return multiply(temp,temp);
}

int main(){

    file();

    int t;

    sc( t );

    while( t-- ){

        sl( d );

        matrix temp(d + 1,d + 1),f(d+1,1);

        for(int i = 0; i < d; i++) cin >> f.mat[ i ][ 0 ];
        for(int i = d - 1; i >= 0; i--) cin >> temp.mat[ d - 1 ][ i ];
        temp.mat[ d ][ 0 ] = temp.mat[ d ][ d ] = 1;
        for(int i = 0; i < d - 1; i++) temp.mat[ i ][ i + 1 ] = 1;

        sl( n );
        sl( m );
        sl( mod );

        matrix ans = multiply(power(temp,n - 1),f);
        matrix ans1 = multiply(power(temp,m),f);

        ll a = ans1.mat[ d  ][ 0 ];
        ll b = ans.mat[ d  ][ 0 ];

        printf("%lld\n",(a - b + mod) % mod);
    }

    return 0;
}
