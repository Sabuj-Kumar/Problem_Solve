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
void pf(ll ans) { cout << ans << endl; }

int block;
int count_ = 0;
vector< int > v( mx );
unordered_map< int,int > a,b;

bool cmp(data a,data b){

    int block_a = a.x / block,block_b = b.x / block;
    if(block_a == block_b) return a.y < b.y;
    else return block_a < block_b;
}

void add(int index){

    b[ v[ index ] ]++;

    if(b[ v[ index ] ] == v[ index ]) a[ v[ index ] ] = 1,count_++;

    else if(b[ v[ index ] ] > v[ index ] && a[ v[ index ] ] ) a[ v[ index ] ] = 0,count_--;
}
void remove_(int index){

    b[ v[ index ] ]--;

    if(b[ v[ index ] ] == v[ index ]) a[ v[ index ] ] = 1,count_++;

    else if( b[ v[ index ] ] < v[ index ] && a[ v[ index ] ]) a[ v[ index ] ] = 0,count_--;
}
int main(){

    file();
   // op
    int n = sc(),m = sc();
    block = sqrt( n ) + 1;
    vector< data > q( m + 1 );
    vector< ll > ans( m+1 );
    int L,R;
    lop(i,1,n+1,1) v[ i ] = sc();

    lop(i,1,m+1,1){

        L = sc();
        R = sc();
        q[ i ] = (data(L,R,i));
    }

    sort(q.begin()+1,q.end(),cmp);

    L = 1,R = 0;

    lop(i,1,m+1,1){

        while(L > q[ i ].x) add(--L);
        while(L < q[ i ].x) remove_(L++);
        while(R < q[ i ].y) add(++R);
        while(R > q[ i ].y) remove_(R--);
        ans[ q[ i ].cost ] = count_;
    }
    lop(i,1,m+1,1) pf(ans[ i ]);

    return 0;
}


