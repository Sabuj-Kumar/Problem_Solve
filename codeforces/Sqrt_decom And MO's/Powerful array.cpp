#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define p_b push_back
#define p_f push_front
#define lop(i,v,n,j) for(int i = v; i < n; i += j)
#define lop_(i,v,n,j) for(int i = n-1; i >= 0; i -= j)
#define in freopen("input.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    ll x,y,index;
    data() {}
    data(int x_,int y_) { x = x_, y = y_; }
    data(int x_,int y_,int index_) { x = x_,y = y_,index = index_; }

//    bool operator < (const data &a) const{
//
//        return cost > a.cost;
//    }
};

const int mx = 2e6;
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
ll block = 0,L = 0,R = -1,C = 0;
ll v[ mx ],mp[ mx ];

int sc() { int n; scanf("%d",&n); return n; }
ll scc() { ll n; scanf("%I64d",&n); return n; }
void pf(ll ans) { printf("%I64d\n",ans); }

bool cmp(data a,data b){

    int block_a = a.x / block,block_b = b.x / block;

    if(block_a == block_b) return a.y < b.y;

    else return block_a < block_b;
}

/**ull result(){ ......TLE.....

    int size_ = V.size();
    ll ans = 0;

    //lop(i,0,size_,1) cout << V[ i ] << " " << mp[ V[ i ] ] << endl;

    lop(i,0,size_,1) ans += ( V[ i ] * pow(mp[ V[ i ] ],2) );

    return ans;
}**/
void add(ll index){

    C += (2 * mp[ v[ index ] ] + 1) * v[ index ];

    mp[ v[index ] ]++;
}
void remove_(ll index){

    mp[ v[ index ] ]--;

    C -= (2 * mp[ v[ index ] ] + 1) * v[ index ];
    ///if(mp[ v[ index] ] <= 0 && flag[ v[ index ] ] ) flag[ v[ index ] ] = 0,V.erase(remove(V.begin(),V.end(),v[ index ]),V.end());
}
int main(){

    file();

    ll n = scc(),m = scc();
    block = sqrt( n );
    ll ans[ m + 5 ];
    data q[ m + 5 ];

    lop(i,0,n,1) v[ i ] = ( scc() );

    lop(i,0,m,1) {

        ll x = scc(),y = scc();
        x--,y--;
        q[ i ] = data(x,y,i);
    }

    sort(q,q+m,cmp);

    lop(i,0,m,1) {

        while(L > q[ i ].x) add(--L);
        while(R < q[ i ].y) add(++R);
        while(L < q[ i ].x) remove_(L++);
        while(R > q[ i ].y) remove_(R--);
        ans[ q[ i ].index ] = C;
    }

    lop(i,0,m,1) pf(ans[ i ]);

    return 0;
}
