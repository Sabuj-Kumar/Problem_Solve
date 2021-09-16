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
    ll mat[ 2 ][ 2 ];

    matrix(ll r = 0,ll c = 0){

        row = r;
        col = c;
        memset(mat,0,sizeof mat);
    }
};

ll n,mod,a,b;

ll check(ll md){

    if( md == 1 ) return 10;
    if( md == 2 ) return 100;
    if( md == 3 ) return 1000;
    if( md == 4 ) return 10000;
}
matrix multiply(matrix a,matrix b){

    matrix temp(2,2);

    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
    for(int k = 0; k < 2; k++){

        temp.mat[ i ][ j ] += (a.mat[ i ][ k ] * b.mat[ k ][ j ]) % mod;
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

    Case( t ){

        sl( a );
        sl( b );
        sl( n );
        sl( mod );

        mod = check( mod );

        a %= mod;
        b %= mod;

        matrix temp(2,2);
        temp.mat[ 0 ][ 0 ] = temp.mat[ 0 ][ 1 ] = temp.mat[ 1 ][ 0 ] = 1;
        temp.mat[ 1 ][ 1 ] = 0;

        printf("Case %d: ",cs);

        if(n <= 2){

            if(n == 0) printf("%lld\n",a);
            else if(n == 1)  printf("%lld\n",b);
            else  printf("%lld\n",(a + b )% mod);
            continue;
        }

        matrix ans = power(temp,n-1);

        printf("%lld\n",((b * ans.mat[ 0 ][ 0 ]) % mod + (a * ans.mat[ 0 ][ 1 ]) % mod) % mod);
    }

    return 0;
}
