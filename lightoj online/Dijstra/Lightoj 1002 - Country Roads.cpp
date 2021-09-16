#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define pii pair< int,int >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define db double
#define ldb long double
#define in freopen("in.txt","r",stdin);
#define lop(v,n) for(int i = v; i < n; i += 1)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,cost;
    data(){}
    data(int x_,int cost_) { x = x_,cost = cost_; }
    bool operator < (const data &a) const{

        return cost > a.cost;
    }
};

const int inf = 1e9;
const ll mx = 1e18;
const int siz = 1e6;

vector< vector < data > > graph;
vector< int > dis( siz );
int sc() { int n; scanf("%d",&n); return n; }

void intl(int n){

    lop(0,n) dis[ i ] = inf;
}
void dij(int d){

    priority_queue< data > q;

    q.push(data(d,0) );
    dis[ d ] = 0;

    while(!q.empty()){

        data p = q.top();

        q.pop();

        for(auto v : graph[ p.x ]){

            int temp = max(dis[ p.x ],v.cost);

            if(temp < dis[ v.x ]){

                dis[ v.x ] = temp;

                q.push(data(v.x,dis[ v.x ]));
            }
        }
    }
}
int main(){

    file();

    int test = sc();

    lop(1,test+1){

        graph.clear();
        int n = sc(),m = sc();
        vector< vector< data > > temp( n );
        swap(temp,graph);

        intl( n );

        while( m-- ){

            int x = sc(), y = sc(),c = sc();
            graph[ x ].pb( data(y,c) );
            graph[ y ].pb( data(x,c) );
        }

        int s = sc();

        dij( s );

        cout << "Case " << i << ":" << endl;

        for(int j = 0; j < n; j++){

            if(dis[ j ] == inf) cout << "Impossible" << endl;
            else cout << dis[ j ] << endl;
        }
    }

    return 0;
}
