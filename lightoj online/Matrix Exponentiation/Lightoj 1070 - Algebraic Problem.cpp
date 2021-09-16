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

    ull mat[ 2 ][ 2 ];
};

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

ull p,q,n;

matrix multiply(matrix a,matrix b){

    matrix temp;

    memset(temp.mat,0,sizeof temp.mat);

    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
    for(int k = 0; k < 2; k++)
    temp.mat[ i ][ j ] += a.mat[ i ][ k ] * b.mat[ k ][ j ];

    return temp;
}

matrix power(matrix mtx,ull pw){

    if(pw == 1) return mtx;

    if(pw & 1) return multiply(mtx,power(mtx,pw-1));

    matrix temp = power(mtx,pw/2);

    return multiply(temp,temp);
}
int main(){

    file();

    int t = I();

    Case( t ) {

        cin >> p >> q >> n;

        matrix temp;

        temp.mat[ 0 ][ 0 ] = p; temp.mat[ 0 ][ 1 ] = -q;
        temp.mat[ 1 ][ 0 ] = 1; temp.mat[ 1 ][ 1 ] = 0;

        printf("Case %d: ",cs);

        if(n <= 1){

            if( n ) cout << p << endl;
            else puts("2");
            continue;
        }

        matrix ans = power(temp,n-1);

        cout << p * ans.mat[ 0 ][ 0 ] + 2 * ans.mat[ 0 ][ 1 ] << endl;
    }
    return 0;
}
