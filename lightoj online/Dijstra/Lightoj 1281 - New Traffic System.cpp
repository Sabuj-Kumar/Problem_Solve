#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define sc3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,c,t;
    data(){}
    data(int x) { this -> x = x; }
    data(int x,int c) { this -> x = x,this -> c = c; }
    data(int x,int c,int t) { this -> x = x,this -> c = c,this -> t = t; }

    bool operator < (const data &a) const{

        return c > a.c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

const int N = 1e4 + 5;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const int mod = 1e9 + 7;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

int n,m,k,d;
int dis[ N ][ 12 ];
vector< vector< data > > graph;

int dijstra(){

    priority_queue< data > q;
    q.push(data(0,0,0));

    memset(dis,-1,sizeof dis);

    dis[ 0 ][ 0 ] = 0;

    while( !q.empty() ){

        data p = q.top();
        q.pop();

        if(p.x == n-1) return p.c;

        for(auto v : graph[ p.x ]){

            if(p.t + v.t <= d){

                v.t += p.t;
                if(v.c + p.c < dis[ v.x ][ v.t ] || dis[ v.x ][ v.t ] == -1){

                    dis[ v.x ][ v.t ] = v.c + p.c;
                    q.push(data(v.x,dis[ v.x ][ v.t ],v.t));
                }
            }
        }
    }
    return -1;
}
int main(){

    file();

    int t;
    sc( t );

    Case( t ){

        sc2(n,m);
        sc2(k,d);
        vector< vector< data > > v( n + 5 );
        swap(v,graph);

        int a,b,c;
        while( m-- ){

            sc3(a,b,c);
            graph[ a ].pb(data(b,c,0));
        }
        while( k-- ){

            sc3(a,b,c);
            graph[ a ].pb(data(b,c,1));
        }

        int ans = dijstra();
        cout << "Case " << cs << ": ";
        if(ans == -1) cout << "Impossible" << endl;
        else cout << ans << endl;
    }
    return 0;
}
