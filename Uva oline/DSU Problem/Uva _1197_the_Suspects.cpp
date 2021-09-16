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
#define in freopen("input.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 30020;
int parent[ N ];

void init(int n){

    for(int i = 0; i <= n; i++) parent[ i ] = i;
}

int find(int x){

    return parent[ x ] == x ? x : parent[ x ] = find(parent[ x ]);
}

void join(int x,int y){

    int xx = find( x );
    int yy = find( y );

    parent[ xx ] = yy;
}
int main(){

    while( true ){

        int n,m;

        cin >> n >> m;

        if(!n and !m) break;

        init( n );

        for(int i = 0; i < m; i++){

            int a,b,c;

            cin >> a >> b;

            for(int j = 1; j < a; j++){

                cin >> c;

                join(b,c);
            }
        }

        int cnt = 1, suspact = find( 0 );

        for(int i = 1; i < n; i++)
          if(find( i ) == suspact) cnt++;
        
        cout << cnt << endl;
    }

    return 0;
}