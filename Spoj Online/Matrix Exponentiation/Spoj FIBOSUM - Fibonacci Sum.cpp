#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll ,ll >
#define pb push_back
#define pf push_back
#define ft first
#define sd second
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

    ll mat[ 2 ][ 2 ];
};

ll mod = 1000000007;

matrix multiply(matrix a,matrix b){

    matrix temp;

    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
    temp.mat[ i ][ j ] = 0;

    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
    for(int k = 0; k < 2; k++){

        temp.mat[ i ][ j ] += (a.mat[ i ][ k ] * b.mat[ k ][ j ]) % mod;
        temp.mat[ i ][ j ] %= mod;
    }
    return temp;
}

matrix power(matrix mtx,ll n){

    if( n == 1 ) return mtx;

    if(n & 1) return multiply(mtx,power(mtx,n-1));

    matrix temp = power(mtx,n/2);

    return multiply(temp,temp);
}

int main(){

    file();

    int t;

    sc( t );

    while( t-- ){

        ll n,m;

        sl( n );
        sl( m );

        matrix N,M,temp;

        for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
        temp.mat[ i ][ j ] = 0;

        temp.mat[ 1 ][ 1 ] = 0;
        temp.mat[ 0 ][ 0 ] = temp.mat[ 0 ][ 1 ] = temp.mat[ 1 ][ 0 ] = 1;

        N = power(temp,n+1);
        M = power(temp,m+2);

        printf("%lld\n",(M.mat[ 0 ][ 1 ] - N.mat[ 0 ][ 1 ] + mod ) % mod);
    }

    return 0;
}
