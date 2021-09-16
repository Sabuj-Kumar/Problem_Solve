#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsiged long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define p_b push_back
#define p_f push_front
#define f first
#define s second
#define lop(i,v,n,j) for(int i = v; i < n; i += j)
#define lop_(i,v,n,j) for(int i = n-1; i >= 0; i -= j)
#define in freopen("input.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}
struct data {

    int x,y,cost;
    data(){}
    data(int x_,int y_) { x = x_, y = y_;}
    data(int x_,int y_,int cost_) { x = x_,y = y_,cost_ = cost; }

//    bool operator < (const data &a) const{
//
//        return cost > a.cost;
//    }
};
const int mx = 1e6;
const ll inf = 1e18;
const ll inf_ = -1e18;
const int mod = 1000000007;

int sc() { int n; scanf("%d",&n); return n; }
ll sl() { ll n; scanf("%I64d",&n); return n;}
string ss() { string s; cin >> s; return s; }

ll tree[ 4 * mx ];

bool cmp(pii &a,pii &b){

    if(a.f < b.f) return true;
    else if( a.f == b.f && a.s > b.s) return true;
    else return false;
}

void update(int node,int L,int R,int pos,int val){

    if(L == R) {

        tree[ node ] = (tree[ node ] + val ) % mod;

        return;
    }

    int mid = (L + R) >> 1;

    if(pos <= mid ) update(2 * node,L,mid,pos,val);

    else update(2 * node + 1,mid + 1,R,pos,val);

    tree[ node ] = ( tree[ 2 * node ] + tree[ 2 * node + 1 ] ) % mod;
}
ll query(int node,int L,int R,int l,int r){

    if(l > r) return 0;

    if( L == l && R == r) return tree[ node ];

    int mid = (L + R) >> 1;

    ll q1 = query(2 * node,L,mid,l,min(mid,r));
    ll q2 = query(2 * node + 1,mid + 1,R,max(l,mid+1),r);

    return (q1 + q2) % mod;
}
int main(){

    file();

    int test = sc();
    lop(cs,1,test+1,1){

        memset(tree,0,sizeof tree);
        int n = sc();
        vector< pii > v;

        lop(i,1,n+1,1) v.p_b({sc(),i});

        sort(v.begin(),v.end(),cmp);

        update(1,0,n,0,1);

        lop(i,0,n,1){

            pii p = v[ i ];

            int c = query(1,0,n,0,p.s-1);
            //cout << "range " << p.s-1 << " Query "  << c << " " << endl;
            update(1,0,n,p.s,c);
        }
        //cout << endl;
        ll ans = query(1,0,n-1,0,n-1);
        printf("Case %d: %lld\n",cs,ans-1);
    }

    return 0;
}
