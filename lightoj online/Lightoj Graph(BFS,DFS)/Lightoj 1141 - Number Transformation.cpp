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
#define Lop(i,v,n,j) for(int i = v; i < n; i += 1)
#define in freopen("input.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}
struct data {

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
bool f;

int X[ ] = { 0,0,1,-1 };
int Y[ ] = { 1,-1,0,0 };
int X_[ ] = { 0,0,1,-1,1,-1,1,-1 };
int Y_[ ] = { 1,-1,0,0,1,-1,-1,1 };

int sc(){ int n; cin >> n; return n; }
ll scl(){ ll n; cin >> n; return n; }
ull scu(){ ull n; cin >> n; return n; }
string scs(){ string s; cin >> s; return s; }
string scss(){ string s; getline(cin,s); return s; }

bool vis[ 2030 ];
vector< int > pr;

void seive(){

    int n = 2010;

    for(int i = 2; i < n; i++)
        if(vis[ i ]){
            pr.p_b( i );
            for(int j = i * i; j < n; j += i)
                vis[ j ] = 0;
        }
}
void bfs(int s,int d){

    memset(vis,true,sizeof vis);

    queue< pii > q;

    q.push({s,0});

    vis[ s ] = false;

    while( !q.empty() ){

        pii p = q.front();

        q.pop();

        vis[ p.f ] = false;

        if(p.f == d) {

            cout << p.s << endl;

            return;
        }
        if(p.f < d){

            for(int i = 0; p.f+pr[ i ] <= d; i++){

                if( (p.f + pr[ i ] == d) && !(p.f % pr[ i ]) && p.f != pr[ i ]){

                    cout << p.s+1 << endl;

                    return;
                }

                if( !( p.f % pr[ i ] ) && vis[ p.f + pr[ i ] ] && p.f != pr[ i ]){

                    q.push( {p.f + pr[ i ],p.s + 1} );
                }
            }
        }
    }
    cout << -1 << endl;
}
int main(){

    memset(vis,true,sizeof vis);
    seive();

    file();
    //op

    int test = sc();

    Lop(cs,1,test+1,1){

        int start = sc(),des = sc();

        cout << "Case " << cs << ": ";

        bfs(start,des);
    }

    return 0;
}

