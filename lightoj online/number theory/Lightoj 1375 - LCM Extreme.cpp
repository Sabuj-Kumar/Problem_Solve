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

const int N = 3 * 1e6 + 10;
int ph[ N ];
ull ans[ N ];
ull f[ N ];

void phi(){

    memset(ph,0,sizeof ph);
    memset(f,0,sizeof f);

    ph[ 1 ] = 1;

    for(ull i = 2; i < N; i++){
        if(!ph[ i ]){
            for(ull j = i; j < N; j += i){

                if(!ph[ j ]) ph[ j ] = j;

                ph[ j ] = ph[ j ] / i * (i -1);
            }
        }
    }

    ans[ 0 ] = ans[ 1 ] = 0;

    for(ull i = 2; i < N; i++){
        for(ull j = i; j < N; j += i)
            f[ j ] += (j * ph[ i ]/2) * i;

        ans[ i ] = ans[ i - 1 ] + f[ i ];
    }
}
int main(){

    phi();

    file();

    ull n;

    scanf("%llu",&n);

    Case( n ){

        ull val;

        scanf("%llu",&val);

        printf("Case %d: %llu\n",cs,ans[ val ]);
    }

    return 0;
}
