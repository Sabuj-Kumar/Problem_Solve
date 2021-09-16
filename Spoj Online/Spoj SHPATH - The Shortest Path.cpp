#include<bits/stdc++.h>
#define ll long long
#define ull unsinged long long
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define lop(i,v,n,j) for(int i = v; i < n; i += j)
#define lop_(i,v,n,j) for(int i = n - 1; i >= 0; i += j)
#define in freopen("in.txt","r",stdin)
#define optimizer ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

const int mx = 1e6;
const int mx_ = 1e9;
const ll mxx = 1e18;

vector< pii > graph[ mx ];
int sc() { int n; scanf("%d",&n); return n; }
ll sc_() { ll n; scanf("%lld",&n); return n; }
void pf(int ans) { printf("%d\n",ans); }

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}
struct data {

    int x,cost;
    data() {}
    data(int x_,int cost_) { x = x_,cost = cost_; }
    bool operator < (const data &a) const{

        return cost > a.cost;
    }
};

int dijstra(int source,int dis,int siz){

    priority_queue< data > q;
    vector< int > cost(siz+5,mx_);
    cost[ source ] = 0;

    q.push(data(source,dis));

    while( !q.empty() ){

        data p = q.top();
        q.pop();

        if(p.x == dis) return cost[ dis ];
        for(auto v : graph[ p.x ]){

            if(cost[ v.f ] > cost[ p.x ] + v.s){

                cost[ v.f ] = cost[ p.x ] + v.s;
                q.push(data(v.f,cost[ v.f ]));
            }
        }
    }
}
int main(){

    file();
    //optimizer;
    int test = sc();
    while(test--) {

        int c = 0,city = sc();
        int x = city;
        for(int i = 0; i < mx; i++) graph[ i ].clear();
        string s,d;
        unordered_map< string,int > mp;

        while( city-- ){

            cin >> s;
            int node = sc();
            mp[ s ] = ++c;

            while( node-- ){

                int x = sc(),cost = sc();
                graph[ mp[ s ] ].pb({x,cost});
                graph[ x ].pb({mp[ s ],cost});
            }
        }

        int connect = sc();
        while( connect-- ){

            cin >> s >> d;
            pf(dijstra(mp[ s ],mp[ d ],x));
        }
        if(test > 0)cout << endl;
    }

    return 0;
}
