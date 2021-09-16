#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int >
#define pll pair<ll,ll>
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

const int N = 1e5 + 20;
int a[ N ];

struct node{

    int pv,sv,pc,sc,ans;

}tree[ 4 * N ];

node marge(node a,node b){

    struct node tmp;

    tmp.pv = a.pv;
    tmp.pc = a.pc;
    tmp.sv = b.sv;
    tmp.sc = b.sc;
    tmp.ans = max(a.ans,b.ans);

    if(a.pv == b.pv) tmp.pc = a.pc + b.pc;
    if(a.sv == b.sv) tmp.sc = a.sc + b.sc;
    if(a.sv == b.pv) tmp.ans = max(tmp.ans,a.sc + b.pc);

    return tmp;
}

void build(int node,int L,int R){

    if(L > R) return;

    if(L == R){

        tree[ node ].pv = tree[ node ].sv = a[ L ];
        tree[ node ].pc = tree[ node ].sc = tree[ node ].ans = 1;
        return;
    }

    int mid = (L + R) / 2;

    build(2 * node,L,mid);
    build(2 * node + 1,mid + 1,R);

    tree[ node] = marge(tree[ 2 * node ],tree[ 2 * node + 1 ]);
}

node query(int node,int L,int R,int l,int r){

    struct node tmp;

    tmp.ans = tmp.pc = tmp.pv = tmp.sc = tmp.sv = 0;

    if(l > r) return tmp;

    if(l == L and r == R) return tree[ node ];

    int mid = (L + R) / 2;

    tmp = marge(query(2 * node,L,mid,l,min(mid,r)),query(2 * node + 1,mid + 1,R,max(l,mid + 1),r));

    return tmp;
}
int main(){

    //file();

    int n,q;

    scanf("%d",&n);

    while( n ){

        scanf("%d",&q);

        for(int i = 1; i <= n; i++) scanf("%d",&a[ i ]);

        build(1,1,n);

        while(q--){

            int a,b;

            scanf("%d %d",&a,&b);

            printf("%d\n",query(1,1,n,a,b).ans);
        }

        scanf("%d",&n);
    }

    return 0;
}
