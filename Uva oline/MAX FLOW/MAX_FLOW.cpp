#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define in freopen("in.txt","r",stdin);
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
const int INF = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const int mod = 1e9 + 7;

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big_mod(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big_mod(n,p/2,m);
        return (x * x) % m;
    }

    ll x = big_mod(n,p-1,m);
    return ( (n % m) * x) % m;
}
int I() { int n; scanf("%d",&n); return n; }
ll Il() { ll n; scanf("%lld",&n); return n; }
int n;

vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {

    fill(parent.begin(),parent.end(),-1);

    parent[ s ] = -2;
    queue< pii > q;

    q.push({s,INF});

    while (!q.empty()){

        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {

            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;

                int new_flow = min(flow, capacity[cur][next]);
                if(next == t)
                    return new_flow;

                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {

    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while(new_flow = bfs(s, t, parent)) {

        flow += new_flow;
        int cur = t;

        while(cur != s) {

            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}
int main(){


    return 0;
}
