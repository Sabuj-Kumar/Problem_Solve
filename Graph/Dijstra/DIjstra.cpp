#include<bits/stdc++.h>
#define lop(i,n) for(int i = 0; i < n; i++)
#define lop_(i,n) for(int i = n-1; i >= 0; i--)
#define lop_inc(i,n,c) for(int i = 0; i < n; i += c)
#define lop_dec(i,n,c) for(int i = n-1; i >= 0; i -= c)
#define ll long long
#define ull unsigned long long
#define pi acos(-1)
#define pb push_back
#define pf push_front
#define pii pair< int,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define mx 20100
#define in freopen("in.txt","r",stdin)
#define optimizar ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

vector< pii > graph[ mx ];
ll cost[ mx ];
const ull inf = 2e18;
int sc(){ int n; scanf("%d",&n); return n; }
ll sc_(){ ll n; scanf("%lld",&n); return n; }

void pf(int i,ll cost) {

    printf("Case #%d: ",i);

    if(cost == inf) printf("unreachable");

    else printf("%lld",cost);

    printf("\n");
}

struct data {

    int x;
    ll cost;

    data(){ }

    data(int x_,ll cost_) { x = x_,cost = cost_; }

    bool operator < (const data &z) const {

        return this->cost > z.cost;
    }
};

ll dijstra(int st,int dis){

    lop(i,mx) cost[ i ] = inf;

    priority_queue< data > q;

    q.push(data(st,0));

    cost[ st ] = 0;

while( !q.empty() ){

        data p = q.top();

        q.pop();

        for(auto v : graph[ p.x ]){

            if(cost[ v.f ] > cost[ p.x ] + v.s){

                cost[ v.f ] = cost[ p.x ] + v.s;

                q.push(data(v.f,cost[ v.f ]));
            }
        }
    }

    return cost[ dis ];
}
void fast(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int main(){

    fast();
    optimizar;

    int test = sc();

    lop(i,test){

        lop(i,mx) graph[ i ].clear();

        int n = sc(),m = sc(),s = sc(),d = sc();

        lop(j,m){

            int x = sc(),y = sc(),t = sc();

            graph[ x ].pb({y,t});
            graph[ y ].pb({x,t});
        }

        ll ans = dijstra(s,d);

        pf(i+1,ans);
    }
    return 0;
}
