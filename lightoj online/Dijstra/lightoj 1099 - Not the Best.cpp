#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int ,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define p_b push_back
#define p_f push_front
#define lop(v,n) for(int i = v; i < n; i++)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)
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

    int n,cost;
    data(){}
    data(int n,int cost) { this-> n = n,this-> cost = cost; }

    bool operator < (const data &a) const{

        return cost > a.cost;
    }
};

const int sz = (5 * 1e3) + 5;
const int inf = 2e9;
const ll mx = 1e18;
const ll mx_ = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int HX[ ] = {1,1,2,2,-1,-1,-2,-2};
int HY[ ] = {2,-2,1,-1,2,-2,1,-1};

int sc() { int n; cin >> n; return n; }

vector< vector< data > > graph;

int dijstra(int source,int destination){

    int w1[ sz ];
    int w2[ sz ];
    int mn[ sz ];
    bool vis[ sz ];
    bool backtrack[ sz ];

    lop(0,sz) w1[ i ] = -1;
    lop(0,sz) w2[ i ] = -1;
    lop(0,sz) vis[ i ] = false;
    lop(0,sz) backtrack[ i ] = false;

    lop(1,destination+1){

        mn[ i ] = inf;
        for(auto x : graph[ i ]) mn[ i ] = min(mn[ i ],2 * x.cost);
    }

    priority_queue< data > qu;

    qu.push(data(source,0));

    w1[ source ] = 0;

    while( !qu.empty() ){

        data p = qu.top();
        qu.pop();

        if(vis[ p.n ]){

            if(w1[ p.n ] < p.cost && (w2[ p.n ] == -1 || w2[ p.n ] >= p.cost)) w2[ p.n ] = p.cost;

            else continue;
        }
        else vis[ p.n ] = true;

        for(auto x : graph[ p.n ]){

            if(w1[ x.n ] == -1 || w1[ x.n ] > x.cost +  p.cost){

                w2[ x.n ] = w1[ x.n ];
                w1[ x.n ] = x.cost +  p.cost;
                qu.push(data(x.n,w1[ x.n ]));
            }
            else if((w1[ x.n ] != x.cost + p.cost) && (w2[ x.n ] == -1 || w2[ x.n ] > x.cost +  p.cost ))
                qu.push(data(x.n,x.cost + p.cost));
        }
        if(!backtrack[ p.n ]){

            qu.push(data(p.n,w1[ p.n ] + mn[ p.n ]));
            backtrack[ p.n ] = true;
        }
    }
    return w2[ destination ];
}
int main(){

    op
    file();

    int t = sc();

    Case( t ){

        int n = sc(),m = sc();
        vector< vector< data > > v(n + 2);
        swap(v,graph);

        while( m-- ){

            int a = sc(),b = sc(),c = sc();
            graph[ a ].p_b(data(b,c));
            graph[ b ].p_b(data(a,c));
        }

        int ans = dijstra(1,n);

        cout << "Case " << cs << ": " << ans << endl;
    }

    return 0;
}
