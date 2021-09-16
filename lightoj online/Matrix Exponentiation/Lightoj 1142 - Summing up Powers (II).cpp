#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int >
#define pll pair<ll,ll >
#define pb push_back
#define pf push_front
#define ft first
#define sd second
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

ll n,k;

struct matrix{

    ll row,col;

    ll mat[ 32 ][ 32 ];
};

matrix multiply(matrix a,matrix b){

    matrix temp;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){

        temp.mat[ i ][ j ] = 0;
        for(int k = 0; k < n; k++){

            temp.mat[ i ][ j ] += (a.mat[ i ][ k ] * b.mat[ k ][ j ]) % 10;
            temp.mat[ i ][ j ] %= 10;
        }
    }
    return temp;
}
matrix add(matrix a,matrix b){

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    a.mat[ i ][ j ] = (a.mat[ i ][ j ] + b.mat[ i ][ j ]) % 10;

    return a;
}
matrix power(matrix mtx,ll p){

    if(p == 1) return mtx;

    if(p & 1) return multiply(mtx,power(mtx,p-1));

    matrix temp = power(mtx,p/2);

    return multiply(temp,temp);
}
matrix call(matrix a,ll k){

    if(k == 1) return a;

    if(k & 1) return add(call(a,k-1),power(a,k));

    matrix temp = call(a,k/2);

    return add(temp,multiply(temp,power(a,k/2)));
}
void print(matrix a,ll p){

    matrix ans = call(a,p);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        printf("%lld",ans.mat[ i ][ j]);
        printf("\n");
    }
}
int main(){

    file();

    int t;
    sc( t );

    Case( t ){

        sl( n );
        sl( k );

        matrix temp;

        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        sl(temp.mat[ i ][ j ]);

        printf("Case %d:\n",cs);
        print(temp,k);
    }
    return 0;
}
