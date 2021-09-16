#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
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

const int N = 1e5 + 10;
int a[ N ];
pii tree[ 4 * N ];

void build(int node,int L,int R){

    if(L == R){

        tree[ node ] = {a[ L ],L};

        return;
    }

    int mid = (L + R) / 2;

    build(2 * node,L,mid);
    build(2 * node + 1, mid + 1,R);

    tree[ node ] = max(tree[ 2 * node ],tree[ 2 * node + 1 ]);
}

void update(int node,int L,int R,int pos,int val){

    if(L == R){

        tree[ node ].ft = val;

        a[ L ] = val;

        return;
    }

    int mid = (L + R) / 2;

    if(pos <= mid) update(2 * node,L,mid,pos,val);
    else update(2 * node + 1,mid+1,R,pos,val);

    tree[ node ] = max(tree[ 2 * node ],tree[ 2 * node + 1 ]);
}

pii query(int node,int L,int R,int l,int r){

    if(l > r) return {INT_MIN,0};

    if(L == l and R == r) return tree[ node ];

    int mid = (L + R) / 2;

    pii p = query(node * 2,L,mid,l,min(mid,r));
    pii q = query(2 * node + 1,mid + 1,R,max(mid + 1,l),r);

    return max(p,q);
}
int main(){

   // file();

    int n = I();

    for(int i = 1; i <= n; i++) a[ i ] = Il();

    build(1,1,n);

    int q = I();

    while(q--){

        char ch;

        getchar();

        scanf("%c",&ch);

        if('Q' == ch){

            int l,r;

            scanf("%d %d",&l,&r);

            int ind = query(1,1,n,l,r).sd;
            int sm1 = INT_MIN,sm2 = INT_MIN;

            if(ind != l) sm1 = query(1,1,n,l,ind-1).ft;
            if(ind != r) sm2 = query(1,1,n,ind + 1,r).ft;

            printf("%d\n",a[ ind ] + max(sm1,sm2));
        }
        else{

            int pos;
            ll val;

            scanf("%d %d",&pos,&val);

            update(1,1,n,pos,val);
        }
    }

    return 0;
}
