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
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 4 * 1e3;

int fish[ N ];
int dis[ N ][ N ];
vector< pii > graph[ N ];
set<pair< int,pii > > q;

void clear_(){

    for(int i = 0; i < N; i++){

        fish[ i ] = 0;
        for(int j = 0; j < N; j++)
        dis[ i ][ j ] = INT_MAX;
    }
}

void In(int node,int fsh,int cost){

    if(dis[ node ][ fsh ] <= cost) return;

    pair< int,pii > tmp = make_pair(dis[ node ][ fsh ],make_pair(node,fsh));

    if(q.find(tmp) != q.end()) q.erase( tmp );

    dis[ node ][ fsh ] = cost;

    tmp.ft = cost;

    q.insert(tmp);
}
void Dijstra(int node){

    In(node,fish[ node ],0);

    while(!q.empty()){

        int node = q.begin()->sd.ft;
        int fsh = q.begin()->sd.sd;
        int cost = q.begin()->ft;

        q.erase(q.begin());

        for(auto x : graph[ node ]) In(x.ft,fsh|fish[ x.ft ],cost+x.sd);
    }
}
int main() {

    file();

    int n = I(),m = I(),k = I();

    clear_();

    for(int i = 1; i <= n; i++){

        int x,num = I();

        while(num--){

            x = I();

            fish[ i ] |= (1 << (x - 1));
        }
    }

    while(m--){

        int a = I(),b = I(),c = I();

        graph[ a ].pb({b,c});
        graph[ b ].pb({a,c});
    }

    Dijstra( 1 );

    int ans = INT_MAX;

    for(int i = 0; i < (1 << k); i++)
        for(int j = i; j < (1 << k); j++)
            if((i | j) == (1 << k) - 1)
                ans = min(ans,max(dis[ n ][ i ],dis[ n ][ j ]));

    printf("%d\n",ans);

    return 0;
}
