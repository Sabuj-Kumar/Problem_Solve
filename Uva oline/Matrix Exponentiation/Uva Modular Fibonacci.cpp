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

const ll N = 5;
ll mod;
ll n,m;

struct mat{

    ll matrix[ N ][ N ];

    ll row,col;
};

mat matrix_multiply(mat a,mat b){

    mat temp;

    temp.row = a.row;
    temp.col = a.row;

    for(ll i = 0; i < a.row; i++)
        for(ll j = 0; j < b.col; j++){
            temp.matrix[ i ][ j ] = 0;
            for(int k = 0; k < b.row; k++)
                temp.matrix[ i ][ j ] = (temp.matrix[ i ][ j ] + a.matrix[ i ][ k ] * b.matrix[ k ][ j ]) % mod;
        }
    return temp;
}

mat power(mat m,ll p){

    if( p == 1 ) return m;
    if( p & 1 ) return matrix_multiply(m,power(m,p-1));

    mat temp = power(m,p/2);
    return matrix_multiply(temp,temp);
}

int main(){

    file();

    while( cin >> n >> m ){

        mat mtx;
        mtx.row = 2;
        mtx.col = 2;

        mtx.matrix[ 0 ][ 0 ] = mtx.matrix[ 0 ][ 1 ] = mtx.matrix[ 1 ][ 0 ] = 1;
        mtx.matrix[ 1 ][ 1 ] = 0;

        if(n <= 2){

            if( n == 0 ) printf("0\n");
            if( n == 1 or n == 2 ) printf("1\n");

            continue;
        }

        mod = pow(2,m);

        mat ans = power(mtx,n - 2);

        cout << (ans.matrix[ 0 ][ 0 ] + ans.matrix[ 0 ][ 1 ]) % mod << endl;
    }
    return 0;
}
