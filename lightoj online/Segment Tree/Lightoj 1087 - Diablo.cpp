#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
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
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 2e5 + 5;
int tree[ 4 * N ],ar[ 2 * N ];
int v[ 2 * N ];
int n,q;

void build(int node,int l,int r){

    if(l == r) {

        tree[ node ] = ar[ l ];

        return;
    }

    int mid = (l + r) / 2;

    build(2 * node,l,mid);
    build(2 * node + 1,mid + 1,r);

    tree[ node ] = tree[ 2 * node ] + tree[ 2 * node + 1 ];
}

int query(int node,int L,int R,int l,int r){

    if(l > r) return 0;

    if(L == l and r == R) return tree[ node ];

    int mid = (L + R) / 2;

    int p = query(2 * node,L,mid,l,min(r,mid));
    int q = query(2 * node + 1,mid + 1,R,max(l,mid+1),r);

    return p + q;
}
void update(int node,int L,int R,int pos,int value){

    if(L == R){

        tree[ node ] = value;

        return;
    }

    int mid = (L + R) / 2;

    if(pos <= mid) update(node * 2,L,mid,pos,value);
    else update(node * 2 + 1,mid + 1,R,pos,value);

    tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];
}
int main(){

    //file();

    int t;

    scanf("%d",&t);

    Case( t ){

        scanf("%d %d",&n,&q);

        int sz = 2 * n;

        memset(ar,0,sizeof ar);

        for(int i = 1; i <= n; i++){

            scanf("%d",&v[ i ]);

            ar[ i ] = 1;
        }

        build(1,1,sz);

        printf("Case %d:\n",cs);

        while(q--){

            int pos;
            char ch;

            getchar();
            scanf("%c",&ch);

            if(ch == 'c'){

                scanf("%d",&pos);

                int l = 1,r = n,mid = 0,ans = 0;

                for(int i = 0; i < 20; i++){

                    mid = (l + r) / 2;

                    int j = query(1,1,sz,1,mid);

                    if( j >= pos ){

                        r = mid - 1;
                        ans = mid;
                    }
                    else l = mid + 1;
                }

                if( ans ) { printf("%d\n",v[ ans ]); update(1,1,sz,ans,0); }
                else printf("none\n");
            }
            else {

                int val;

                scanf("%d",&val);

                n++;

                v[ n ] = val;

                update(1,1,sz,n,1);
            }
        }
    }

    return 0;
}
