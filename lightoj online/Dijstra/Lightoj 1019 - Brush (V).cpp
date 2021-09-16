#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define p_b push_back
#define p_f push_front
#define f first
#define s second
#define lop(v,n) for(int i = v; i < n; i += 1)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,cost;
    data(){}
    data(int x_,int c) { x = x_,cost = c; }
    data(int x_,int y_,int c) { x = x_,y = y_,cost = c; }

    bool operator < (const data &a) const {

       return cost > a.cost;
    }
};

const int inf = 1e9;
const ll inf_ = 1e18;
const int mx = 1e9;

int sc() { int n; scanf("%d",&n); return n; }

int x[ ] = {0,0,1,-1};
int y[ ] = {1,-1,0,0};

vector< vector< data > > graph;
vector< int > vis;

void dijstra(int root){

    priority_queue< data > q;

    vis[ root ] = 0;

    q.push(data(root,0));

    while(!q.empty()){

        data p = q.top();

        q.pop();

       // cout << p.x << endl;

        for(auto a : graph[ p.x ]){

            //cout <<  p.x  << " "<< vis[ p.x ] << " " << a.x << " " << a.cost << " "<< vis[ a.x ] << endl;

            if(vis[ a.x ] > vis[ p.x ] + a.cost){

                vis[ a.x ] = vis[ p.x ] + a.cost;

                q.push(data(a.x,vis[ a.x ]));
            }
        }
    }
}
int main(){

    file();

    int test = sc();

    Lop(cs,1,test+1,1){

        int n = sc(),m = sc();
        vector< vector < data > > temp( n+2 );
        vector< int > v( n+2 );
        swap(graph,temp);
        swap(v,vis);

        lop(0,n+1) vis[ i ] = inf;

        lop(0,m){

            int x = sc(),y = sc(),c = sc();
            graph[ x ].p_b(data(y,c));
            graph[ y ].p_b(data(x,c));
        }

        dijstra( 1 );

        cout << "Case " <<  cs << ": ";

        if(vis[ n ] == inf) cout  << "Impossible" << endl;

        else  cout << vis[ n ] << endl;
    }
    return 0;
}
