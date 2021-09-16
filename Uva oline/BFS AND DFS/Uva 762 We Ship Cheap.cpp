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
#define lop(i,v,n,j) for(int i = v; i < n; i += j)
#define lop_(i,v,n,j) for(int i = n-1; i >= 0; i -= j)
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

vector< int > graph[ mx ];
bool vis[ mx ];
int parent[ mx ];
stack < int > stk;

bool bfs(int s,int d){

    queue< int > q;
    q.push( s );
    vis[ s ] = false;

    while( !q.empty() ){

        int p = q.front();
        q.pop();

        for(auto x : graph[ p ]){

            if(vis[ x ]){

                vis[ x ] = false;
                parent[ x ] = p;
                q.push( x );
            }
            if(x == d) return true;
        }
    }
    return false;
}

void search_parent(int s,int d){

    stk.push( d );

    if(s == d) return;

    else search_parent(s,parent[ d ]);
}
int main(){

    file();

    int n,f = 0;

    while(cin >> n){

        string s,d;
        map<string,int> inp;
        map<int,string> out;
        memset(vis,1,sizeof vis);
        memset(parent,0,sizeof parent);
        lop(i,0,mx,1) graph[ i ].clear();
        int c = 0;
        if( f ) cout << endl;
        f = 1;

        while(n--){

            cin >> s >> d;
            if(!inp[ s ]) inp[ s ] = ++c;
            if(!inp[ d ]) inp[ d ] = ++c;

            out[ inp[ s ] ] = s;
            out[ inp[ d ] ] = d;

            graph[ inp[ s ] ].p_b( inp[ d ] );
            graph[ inp[ d ] ].p_b( inp[ s ] );
        }

        cin >> s >> d;

        if(s == d) {

            cout << s << " " << d << endl;

            continue;
        }

        if( bfs(inp[ s ],inp[ d ]) ){

            search_parent(inp[ s ],inp[ d ]);

            int p = stk.top();

            stk.pop();

            while( !stk.empty() ){

                cout << out [ p ] << " " << out[ stk.top()] << endl;

                p = stk.top();

                stk.pop();
            }
        }
        else cout << "No route" << endl;
    }

    return 0;
}

