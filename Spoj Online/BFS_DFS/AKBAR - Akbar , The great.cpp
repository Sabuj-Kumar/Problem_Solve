#include<bits/stdc++.h>
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
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUGDE
    in;
    #endif // ONLINE_JUGDE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

struct node{

    ll prev;
    ll dis;
    ll name;
};

const int N = 1e6+10;
vector< int > graph[ N ];
int vis[ N ];

bool BFS(ll s,ll d){

    bool res = true;

    node temp;
    temp.name = s;
    temp.dis = d;
    temp.prev = -1;

    queue< node > q;

    q.push(temp);

    while( !q.empty() ){

        temp = q.front();

        q.pop();

        vis[ temp.name ]++;

        if(vis[ temp.name ] == 1) res = false;

        for(auto x : graph[ temp.name ]){

            if(x == temp.prev) continue;

            if(temp.dis > 0){

                node temp1;

                temp1.name = x;
                temp1.dis = temp.dis - 1;
                temp1.prev = temp.name;

                q.push(temp1);
            }
        }
    }
    return res;
}
int main(){

    //file();

    int t;
    sc( t );

    while(t--){

        ll n,r,m;
        sl( n );
        sl( r );
        sl( m );

        for(ll i = 0; i <= n; i++){

            vis[ i ] = 0;
            graph[ i ].clear();
        }

        for(int i = 0; i < r; i++){

            ll a,b;
            sl( a );
            sl( b );

            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }

        bool flag = true;

        for(int i = 0; i < m; i++){

            ll s,d;

            sl( s );
            sl( d );

            if(flag){ if(BFS(s,d)) flag = false; }
        }

        if(flag) {

            for(int i = 1; i <= n; i++) if(vis[ i ] == 0) { flag = false; break; }

            if(flag) printf("Yes");
            else printf("No");
        }
        else printf("No");
        printf("\n");
    }
    return 0;
}
