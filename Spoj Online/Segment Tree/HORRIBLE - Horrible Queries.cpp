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
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const ll N = 1e5 + 10;
ll tree[ 4 * N ];
ll lazy[ 4 * N ];

void push(ll node,ll l,ll r){

    ll mid = (l + r) / 2;

    tree[ 2 * node ] += (lazy[ node ] * (mid - l + 1)) ;
    tree[ 2 * node + 1 ] += (lazy[ node ] * (r - mid));
    lazy[ 2 * node ] += lazy[ node ];
    lazy[ 2 * node + 1 ] += lazy[ node ];
    lazy[ node ] = 0;
}
void update(ll node,ll L,ll R,ll l,ll r,ll val){

    if(l > r)return;

    if(l == L and r == R){

        tree[ node ] += (r - l + 1) * val;
        lazy[ node ] += val;

        return;
    }

    push(node,L,R);

    ll mid = (L + R) / 2;

    update(2 * node,L,mid,l,min(mid,r),val);
    update(2 * node + 1,mid + 1,R,max(mid + 1,l),r,val);

    tree[ node ] = tree[ 2 * node ] + tree[ 2 * node + 1 ];
}
ll query(ll node,ll L,ll R,ll l,ll r){

    if(l > r) return 0;

    if(l == L and r == R) return tree[ node ];

    ll mid = (L + R) / 2;

    push(node,L,R);

    ll p = query(2 * node,L,mid,l,min(mid,r));
    ll q = query(2 * node + 1,mid + 1,R,max(mid + 1,l),r);

    tree[ node ] = tree[ 2 * node ] + tree[ 2 * node + 1 ];

    return p + q;
}

int main(){

    //file();

    ll t;

    sl( t );

    while(t--){

        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);

        ll n,c;

        sl( n );
        sl( c );

        while(c--){

            ll ck,l,r,v;

            sl( ck );

            if(!ck){

                sl(l);
                sl(r);
                sl(v);

                update(1ll,1,n,l,r,v);
            }
            else{

                sl(l);
                sl(r);

                printf("%lld\n",query(1ll,1,n,l,r));
            }
        }
    }

    return 0;
}

