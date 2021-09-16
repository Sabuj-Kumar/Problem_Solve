#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define p_b push_back
#define p_f push_front
#define f first
#define s second
#define pii pair< int,int >
#define pll pair< ll,ll >
#define lop(v,n) for(int i = v; i < n; i += 1)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)
#define r_lop(i,v,n,j) for(int i = n-1; i >= 0; i -= j)
#define in freopen("input.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,cost;
    data(){}
    data(int x_,int y_,int cost_) { x = x_,y = y_,cost_ = cost; }
    data(int x_,int y_) { x = x_,y = y_; }
};

const int mx = 1e6;
const ll inf = 1e18;
const ll inf_ = -1e18;

int x[ ] = {0,0,1,-1};
int y[ ] = {1,-1,0,0};
ll cost,total;
int c;

vector< vector < int > > graph;
int val[ 1010 ];
bool vis[ 1010 ];

ll sc(){ ll n; scanf("%lld",&n); return n; }
int sc_() { int n; scanf("%d",&n); return n; }

void dfs(int node){

    if(vis[ node ]) return;

    vis[ node ] = true;

    cost += val[ node ];

    c++;

    for(auto x : graph[ node ]) dfs(x);
}
int main(){

    file();

    ll test = sc_();

    Lop(cs,1,test+1,1){

        int n = sc_(),m = sc_();

        vector < vector < int > > temp( n + 5 );
        swap(temp,graph);

        total = 0;
        ll equal_ = 0;

        lop(1,n+1) val[ i ] = sc(),total += val[ i ];

        while( m-- ){

            int x = sc_(),y = sc_();
            graph[ x ].p_b( y );
            graph[ y ].p_b( x );
        }

        cout << "Case " << cs << ": ";

        if(total < n) {

            cout << "No" << endl;

            continue;
        }
        if(total >= n ) {

            equal_ = total / n;

            if(n * equal_ < total) {

                cout << "No" << endl;

                continue;
            }
        }

        bool f = 1;

        memset(vis,false,sizeof vis);

        lop(1,n+1) {

            if(!vis[ i ]){

                c = 0;
                cost = 0;
                dfs(i);

                if(cost / c != equal_) f = 0;
            }
            if( !f ) break;
        }

        if( f ) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
