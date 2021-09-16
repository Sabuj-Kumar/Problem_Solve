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

const int N = 110;

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }
vector< int > prm;
bool fg[ N ];

void seive(){

    for(int i = 4; i <= N; i += 2) fg[ i ] = true;

    for(int i = 3; i * i <= N; i += 2)
        if(!fg[ i ])
            for(int j = i * i; j <= N; j += 2 * i)
                fg[ j ] = true;

    prm.pb( 2 );
    for(int i = 3; i <= N; i += 2) if(!fg[ i ]) prm.pb( i );
}

int main(){

    seive();

    file();

    int n;

    scanf("%d",&n);

    Case( n ){

        int val;

        sc( val );

        int pwr[ 1002 ];

        memset(pwr,0,sizeof pwr);

        for(int i = 0; prm[ i ] <= val; i++){

            int cnt = 0;
            int temp = val;

            while(temp){

                cnt += temp/prm[ i ];
                temp /= prm[ i ];
            }

            pwr[ i ] = cnt;
        }

        printf("Case %d: %d = ",cs,val);

        for(int i = 0; prm[ i ] <= val; i++){

            if(i > 0) printf(" * ");

            printf("%d (%d)",prm[ i ],pwr[ i ]);
        }
        puts("");
    }
    return 0;
}
