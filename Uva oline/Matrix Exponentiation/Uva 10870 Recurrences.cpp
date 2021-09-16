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

int d,mod;
const int sz = 18;
ll n;

struct matrix{

    ll row,col;
    ll mat[ sz ][ sz ];

    matrix(ll r = 0,ll c = 0){

        row = r;
        col = c;
        memset(mat,0,sizeof mat);
    }
};

matrix multiply(matrix a,matrix b){

    matrix temp( a.row,b.col);

    for(int i = 0; i < d; i++)
    for(int k = 0; k < d; k++)
    if(a.mat[ i ][ k ])
    for(int j = 0; j < d; j++){

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

    while(cin >> d >> n >> mod){

        if(!(d + n + mod)) break;

        matrix temp(d,d),f(d,d);

        for(int i = 0; i < d; i++) sl(temp.mat[ 0 ][ i ]);
        for(int i = 1; i < d; i++) temp.mat[ i ][ i - 1 ] = 1;
        for(int i = d - 1; i >= 0; i--) sl(f.mat[ i ][ 0 ]);

        if( n <= d) printf("%lld\n",f.mat[ 0 ][ 0 ]);

        else {

            matrix ans = multiply(power(temp,n-d),f);

            printf("%lld\n",ans.mat[ 0 ][ 0 ]);
        }
    }
    return 0;
}
