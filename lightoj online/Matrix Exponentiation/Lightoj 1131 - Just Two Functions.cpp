#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db bouble
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

ll mod,q;
ll n,a1,b1,c1,a2,b2,c2,f1,f2,f3,g1,g2,g3;

struct matrix{

    ll col = 6,row = 6;
    ll mat[ 6 ][ 6 ];
};

matrix multiply(matrix a,matrix b){

    matrix temp;

    for(int i = 0; i < 6; i++)
    for(int j = 0; j < 6; j++)
    temp.mat[ i ][ j ] = 0;

    for(int i = 0; i < a.row; i++)
    for(int j = 0; j < b.col; j++)
    for(int k = 0; k < a.col; k++){

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

    scanf("%d",&t);

    Case( t ){

        scanf("%lld %lld %lld",&a1,&b1,&c1);
        scanf("%lld %lld %lld",&a2,&b2,&c2);
        scanf("%lld %lld %lld",&f1,&f2,&f3);
        scanf("%lld %lld %lld",&g1,&g2,&g3);
        scanf("%lld",&mod);
        scanf("%lld",&q);

        matrix temp;

        for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        temp.mat[ i ][ j ] = 0;

        temp.mat[ 0 ][ 0 ] = a1,temp.mat[ 0 ][ 1 ] = b1,temp.mat[ 0 ][ 5 ] = c1;
        temp.mat[ 1 ][ 0 ] = temp.mat[ 2 ][ 1 ] = temp.mat[ 4 ][ 3 ] = temp.mat[ 5 ][ 4 ] = 1;
        temp.mat[ 3 ][ 2 ] = c2,temp.mat[ 3 ][ 3 ] = a2,temp.mat[ 3 ][ 4 ] = b2;

        printf("Case %d:\n",cs);

        while( q-- ){

            scanf("%lld",&n);

            if(n <= 2){

                if( n == 0 ) printf("%lld %lld\n",f1 % mod,g1 % mod);
                else if( n == 1 ) printf("%lld %lld\n",f2 % mod,g2 % mod);
                else printf("%lld %lld\n",f3 % mod,g3 % mod);

                continue;
            }

            matrix ans = power(temp,n-2);

            ll ansf = (f3 * ans.mat[ 0 ][ 0 ] + f2 * ans.mat[ 0 ][ 1 ] + f1 * ans.mat[ 0 ][ 2 ] + g3 * ans.mat[ 0 ][ 3 ] + g2 * ans.mat[ 0 ][ 4 ] + g1 * ans.mat[ 0 ][  5 ]) % mod;
            ll ansg = (f3 * ans.mat[ 3 ][ 0 ] + f2 * ans.mat[ 3 ][ 1 ] + f1 * ans.mat[ 3 ][ 2 ] + g3 * ans.mat[ 3 ][ 3 ] + g2 * ans.mat[ 3 ][ 4 ] + g1 * ans.mat[ 3 ][  5 ]) % mod;

            printf("%lld %lld\n",ansf,ansg);
        }
    }
    return 0;
}
