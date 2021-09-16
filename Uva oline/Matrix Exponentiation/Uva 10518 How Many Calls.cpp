#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll ,ll >
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

ll n,base;

struct matrix{

    ll row = 0,col = 0;

    ll mat[ 3 ][ 3 ];

    matrix(ll r = 0,ll c = 0){

        row = r;
        col = c;
        memset(mat,0,sizeof mat);
    }
};
matrix multiply(matrix a,matrix b){

    matrix temp(3,3);

    for(int i = 0; i < 3; i++)
    for(int k = 0; k < 3; k++){

        if(a.mat[ i ][ k ] == 0) continue;

        for(int j = 0; j < 3; j++){

            temp.mat[ i ][ j ] += (a.mat[ i ][ k ] % base * b.mat[ k ][ j ] % base) % base;
            temp.mat[ i ][ j ] %= base;
        }
    }
    return temp;
}
matrix power(matrix a,ll p){

    if(p <= 1) return a;

    if(p & 1) return multiply(a,power(a,p-1));

    matrix temp = power(a,p/2);

    return multiply(temp,temp);
}
int main(){

    file();

    int t = 0;

    while(cin >> n >> base and (n or base)){

        matrix temp(3,3),ans(3,1);

        for(int i = 0; i < 3; i++) temp.mat[ 0 ][ i ] = 1;
        temp.mat[ 1 ][ 0 ] = temp.mat[ 2 ][ 2 ] = 1;
        ans.mat[ 0 ][ 0 ] = ans.mat[ 1 ][ 0 ] = ans.mat[ 2 ][ 0 ] = 1;

        if(n > 1) ans = multiply(power(temp,n-1),ans);

        printf("Case %d: %lld %lld %lld\n",++t,n,base,ans.mat[ 0 ][ 0 ]);
    }

    return 0;
}
