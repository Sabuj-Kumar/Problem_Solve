#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

ll INF = -1e18;
const int N = 50000;

struct data{

    ll sum;
    ll pre;
    ll suff;
    ll ans;
    ll mx;
};

ll a[ N + 10 ];
data tree[ 4 * N ];

data create_data(ll v){

    data store;

    store.sum = v;
    store.mx = v;

    store.pre = store.suff = store.ans = max(v,0ll);

    return store;
}

data combine(data l,data r){

    data res;

    res.sum = l.sum + r.sum;
    res.pre = max(l.pre,l.sum + r.pre);
    res.suff = max(r.suff,r.sum + l.suff);
    res.ans = max(max(l.ans,r.ans),l.suff + r.pre);
    res.mx = max(l.mx,r.mx);

    return res;
}

void build(int node,int l,int r){

    if(l > r) return;

    if(l == r){

        tree[ node ] = create_data(a[ l ]);

        return;
    }

    int mid = (l + r) / 2;

    build(2 * node,l,mid);
    build(2 * node + 1,mid + 1,r);

    tree[ node ] = combine(tree[ node * 2 ],tree[ node * 2 + 1 ]);
}

void update(int node,int l,int r,ll pos,int val){

    if(l == r){

        tree[ node ] = create_data(val);

        return;
    }

    int mid = (l + r) / 2;

    if(pos <= mid) update(node * 2,l,mid,pos,val);

    else update(node * 2 + 1,mid + 1,r,pos,val);

    tree[ node ] = combine(tree[ node * 2 ],tree[ node * 2 + 1 ]);
}

data query(int node,int L,int R,int l,int r){

    if(l > r) return create_data( 0 );

    if(l == L and r == R) return tree[ node ];

    int mid = (L + R) / 2;

    return combine(query(node * 2,L,mid,l,min(mid,r)),query(node * 2 + 1,mid+1,R,max(mid+1,l),r));
}

ll query1(int node,int L,int R,int l,int r){

    if(l > r) return INF;

    if(l == L and r == R) return tree[ node ].mx;

    int mid = (L + R) / 2;

    return max(query1(node * 2,L,mid,l,min(mid,r)),query1(node * 2 + 1,mid+1,R,max(mid+1,l),r));
}

int main(){

    //file();

    int n,m;

    sc( n );

    for(int i = 1; i <= n; i++) sl( a[ i ] );

    build(1,1,n);

    sc( m );

    while(m--){

        int q,a,b;

        sc(q);
        sc(a);
        sc(b);

        if( q == 1 ){

            data out = query(1,1,n,a,b);

            if(out.ans == 0) printf("%lld\n",query1(1,1,n,a,b));
            else printf("%lld\n",out.ans);
        }
        else  update(1,1,n,a,b);
    }

    return 0;
}
