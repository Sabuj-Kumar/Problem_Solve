#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pb push_back
#define pf push_back
#define f first
#define s second
#define in freopen("input.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lop(i,v,n,j) for(int i = v;i < n; i += j)
#define lop_(i,v,n,j) for(int i = n-1; i >= v; i -= j)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data {

    int x,y,cost;
    data(){}
    data(int x_,int y_) { x = x_,y = y_; }
    data(int x_,int y_,int cost_) { x = x_,y = y_,cost = cost_; }
    bool operator < (const data &a) const{

        return cost > a.cost;
    }
};

const int inf = 1e6;
const ll infl = 1e18;
const ll infl_ = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,1,-1,-1,1};
vector< ll > graph[ 110 ];
vector< ll > level( 110 );

int sc() { int n; scanf("%d",&n); return n; }
ll scl() { ll n; scanf("%lld",&n); return n; }
string ssc() { string s; cin >> s; return s; }

void bfs(ll s,ll d){

    queue< ll > q;
    q.push( s );
    level[ s ] = 0;
    while(!q.empty()){

        ll p = q.front();
        q.pop();

        for(auto x : graph[ p ]){

            if(level[ x ] == inf){

                level[ x ] = level[ p ] + 1;

                q.push( x );
            }
            if(x == d) return;
        }
    }
}
int main(){

    //file();

    ll test = scl();

    cout <<"SHIPPING ROUTES OUTPUT" << endl;

    lop(cs,1,test+1,1){

        lop(i,0,110,1) graph[ i ].clear();

        ll c = 0,m = scl(),n = scl(),k = scl();
        unordered_map < string,ll > mp;

        lop(i,0,m,1) {

            string s = ssc();
            mp[ s ] = ++c;
        }
        lop(i,0,n,1){

            string s = ssc(),ch = ssc();
            graph[ mp[ s ] ].pb( mp[ ch ] );
            graph[ mp[ ch ] ].pb( mp[ s ] );
        }

        cout << endl << "DATA SET  " << cs << endl << endl;

        while(k--){

            lop(i,0,110,1) level[ i ] = inf;
            ll cost = scl();
            string s = ssc(),d = ssc();

            bfs(mp[ s ],mp[ d ]);

            if(level[ mp[ d ] ] == inf) cout << "NO SHIPMENT POSSIBLE" << endl;
            else cout << "$"<< (cost*level[ mp[ d ] ] * 100) << endl;
        }
    }

    cout << endl << "END OF OUTPUT" << endl;

    return 0;
}
