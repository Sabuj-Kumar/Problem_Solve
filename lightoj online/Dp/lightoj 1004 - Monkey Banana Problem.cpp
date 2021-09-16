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
#define lop(v,n) for(int i = v; i < n; i++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
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

const int inf = -1e9;
const int mx = 1e6;
const int mx_= 1e9;
const ll mx__=1e18;
const int N = 1e6 + 7;
const ll P = 1e8 + 5e4 + 1;
const ll INVP = 678791932; // P inverse modulo M
const ll M = 1e9 + 7;

int X[ ] = { 1,1,1 };
int Y[ ] = { 0,1,-1 };
int X_[ ] = { 0,0,1,-1,1,-1,1,-1 };
int Y_[ ] = { 1,-1,0,0,1,-1,-1,1 };

int sc(){ int n; cin >> n; return n; }
ll scl(){ ll n; cin >> n; return n; }
ull scu(){ ull n; cin >> n; return n; }
string scs(){ string s; cin >> s; return s; }
string scss(){ string s; getline(cin,s); return s; }

vector< vector < int > > grid;
int sz,n;
int dp[ 220 ][ 220 ];

int bandor(int i,int j){

    if(i > sz || j < 0 || j >= grid[ i ].size()) return 0;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    int r = 0;

    r = grid[ i ][ j ] + bandor(i+1,j);

    if(i < n - 1) r = max(r,grid[ i ][ j ] + bandor(i+1,j+1));
    else r = max(r,grid[ i ][ j ] + bandor(i+1,j-1));

    return dp[ i ][ j ] = r;
}
int main(){

    op
    file();

    int t = sc();

    Case( t ){

        n = sc();
        sz = 2 * n - 1;
        vector < vector < int >  >v( 2 * n);
        swap(grid,v);
        int y = 0;
        bool flag = 1;
        lop(0,sz){

            if(y < n && flag) ++y;
            else { flag = 0; --y; }
            Lop(j,0,y) grid[ i ].p_b( sc() );
        }

        memset(dp,-1,sizeof dp);
        cout << "Case " << cs << ": " << bandor(0,0) << endl;
    }

    return 0;
}


