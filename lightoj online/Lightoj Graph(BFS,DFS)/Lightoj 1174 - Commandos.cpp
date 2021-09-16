#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define p_b push_back
#define p_f push_front
#define f first
#define s second
#define pi acos(-1)
#define lop(v,n) for(int i = v; i < n; i += 1)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)
#define in freopen("input.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}
struct data{

    int x,y,cost;
    data(){}
    data(int x_,int y_){ x = x_,y = y_; }
    data(int x_,int y_,int cost_) { x = x_,y = y_,cost = cost_; }

//    bool operator < ( const data &a ) const {
//
//        return cost > a.cost;
//    }
};

ll gcd(ll a,ll b){

    if(b == 0) return a;
    return gcd(b,a%b);
}

const int mx = 1e6;
const int mx_= 1e9;
const ll mx__=1e18;
const int N = 1e6 + 7;
const ll P = 1e8 + 5e4 + 1;
const ll INVP = 678791932; // P inverse modulo M
const ll M = 1e9 + 7;

int X[ ] = { 0,0,1,-1 };
int Y[ ] = { 1,-1,0,0 };
int X_[ ] = { 0,0,1,-1,1,-1,1,-1 };
int Y_[ ] = { 1,-1,0,0,1,-1,-1,1 };

int sc(){ int n; cin >> n; return n; }
ll scl(){ ll n; cin >> n; return n; }
ull scu(){ ull n; cin >> n; return n; }
string scs(){ string s; cin >> s; return s; }
string scss(){ string s; getline(cin,s); return s; }

int n,m;
vector < vector < int > > graph;
int time1[ 110 ];
int time2[ 110 ];

void bfs(int s,int *time){

    queue< int > q;
    q.push( s );
    time[ s ] = 0;

    while( !q.empty() ){

        int p = q.front();

        q.pop();

        for(auto x : graph[ p ]){

            if(time[ x ] == -1){

                time[ x ] = time[ p ] + 1;

                q.push( x );
            }
        }
    }
}
int main(){

    file();
   // op
    int test = sc();

    Lop(cs,1,test+1,1){

        n = sc();
        m = sc();
        vector< vector < int > > g(n + 5);
        swap(graph,g);

        while( m-- ){

            int a = sc(),b = sc();
            graph[ a ].p_b( b );
            graph[ b ].p_b( a );
        }

        int s = sc(), d = sc();

        memset(time1,-1,sizeof time1);
        memset(time2,-1,sizeof time2);

        bfs(s,time1);
        bfs(d,time2);

        int max_ = 0;

        lop(0,n) max_ = max(max_,(time1[ i ] + time2[ i ]));

        cout << "Case " << cs << ": " << max_ << endl;
    }
    return 0;
}


