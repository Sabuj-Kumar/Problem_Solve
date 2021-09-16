#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define pb push_back
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
struct data {

    int x,y,cost;
    data(){}
    data(int x_,int y_) { x = x_,y = y_; }
    data(int x_,int y_,int cost_) { x = x_,y = y_,cost = cost_; }
///    bool operator < (const data &a ) const {
///
///        return cost > a.cost;
///    }
};
const int mx = 1e6;
const int mx_ = 1e9;
const ll mx__ = 1e18;
int tree[ 3*mx ];
int X[ ] = { 0,0,1,-1 };
int Y[ ] = { 1,-1,0,0 };
int X_[ ] = { 0,0,1,-1,1,-1,1,-1 };
int Y_[ ] = { 1,-1,0,0,-1,1,1,-1 };
vector<int> ans;
int sc(){ int n; cin >> n; return n; }
ll sc_() { ll n; cin >> n; return n; }
string sc__() { string s; cin >> s; return s; }
string sc___() { string s; getline(cin,s); return s; }
int pf(vector< int > &ans,int n) {

    lop(i,1,n+1,1) {

         if(i == 1) cout << ans[ i ];
         else cout << " " << ans[ i ];
    }
}
void build(int node,int L,int R){

    if(L == R){

        tree[ node ] = 1;
        return;
    }
    int mid = (L + R) >> 1;
    build(node * 2,L,mid);
    build(node * 2 + 1,mid + 1,R);
    tree[ node ] = 1;
}
void update(int node,int L,int R,int l,int r,int v){

    if(l > r || tree[ node ] == 0) return;

    if(L == R){

        ans[ l ] = v;
        tree[ node ] = 0;
        return;
    }
    int mid = (L + R) >> 1;
    update(node * 2,L,mid,l,min(mid,r),v);
    update(node * 2 + 1,mid + 1,R,max(mid + 1,l),r,v);
    tree[ node ] = max(tree[ node * 2 ],tree[ node * 2 + 1 ]);
}
int main(){

    file();
    op
    int n = sc(),m = sc();
    ans.resize( n+5 );
    build(1,1,n);
    lop(i,0,m,1){

        int L = sc(),R = sc(),x = sc();
        //cout << L << " " << R << endl;
        update(1,1,n,L,x-1,x);
        update(1,1,n,x+1,R,x);
    }

    pf( ans,n );

    return 0;
}
