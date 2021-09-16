#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int ,int >
#define pll pair< ll , ll >
#define pb push_back
#define pf push_back
#define f first
#define s second
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

struct data{

    int x,y,c;
    data(){}
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const{

        return c > a.c;
    }
};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big_mod(ll n,ll p,ll mod){

    if( !p ) return 1;

    ll x  = 0;

    if( !(p % 2) ) {

        x = big_mod(n,p/2,mod);
        return (x * x) % mod;
    }
    x = big_mod(n,p-1,mod);
    return ((n % mod) * x) % mod;
}

vector<vector< int > > graph;
int dis[ 3000 ],mp[ 3000 ];

void BFS(int s){

    queue< int > q;
    q.push( s );
    dis[ s ] = 0;

    while( !q.empty() ){

        int n = q.front();
        q.pop();

        for(auto x : graph[ n ]){

            if(dis[ x ] == -1){

                dis[ x ] = dis[ n ] + 1;
                q.push( x );
                mp[ dis[ x ] ]++;
            }
        }
    }
}

int main(){

    op
    file();

    int n;

    while(cin >> n){

        vector< vector< int > > v( n + 5 );
        swap(graph,v);

        int k,a;

        lop(i,0,n){

            cin >> k;

            while( k-- ){

                cin >> a;
                graph[ i ].pb( a );
            }
        }

        cin >> k;

        while( k-- ){

            cin >> a;

            if(graph[ a ].size() > 0){

                memset(dis,-1,sizeof dis);
                memset(mp,0,sizeof mp);

                BFS( a );

                int m = 0,d;

                lop(i,1,n+1){

                    if( mp[ i ] > m ){

                        m = mp[ i ];
                        d = i;
                    }
                }
                cout << m << " " << d << endl;
            }
            else cout << "0" << endl;
        }
    }

    return 0;
}
