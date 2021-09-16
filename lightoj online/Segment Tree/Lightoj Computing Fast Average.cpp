#include<bits/stdc++.h>
#define ll long long
#define mx 100010

using namespace std;

struct Node{

    ll sum = 0;
    ll lazy = -1;
};

Node tree[ 4 * mx ];

ll GCD(ll x,ll y){

    if(y == 0) return x;

    else return GCD(y,x % y);
}
void push(int node,int L,int R){

    if(tree[ node ].lazy != -1){

        tree[ node ].sum = tree[ node ].lazy * (R - L + 1);

        if(L != R){

            tree[ node * 2 ].lazy = tree[ node ].lazy;
            tree[ node * 2 + 1 ].lazy = tree[ node ].lazy;
        }

        tree[ node ].lazy = -1;
    }
}
void update(int node,int L,int R,int x,int y,int v){

    push(node,L,R);

    if(x > y) return;

    if(L == x && y == R){

        tree[ node ].sum = v * (R - L + 1);
        tree[ node ].lazy = v;
        return;
    }

    int mid = (L + R) >> 1;

    update(node * 2,L,mid,x,min(mid,y),v);
    update(node * 2 + 1,mid + 1,R,max(mid + 1,x),y,v);
    tree[ node ].sum = tree[ node * 2 ].sum + tree[ node * 2 + 1 ].sum;
}

ll query(int node,int L,int R,int x,int y){

    push(node,L,R);

    if(x > y) return 0;

    if(L == x && y == R) return tree[ node ].sum;

    int mid = (L + R) >> 1;

    return query(node * 2,L,mid,x,min(mid,y)) + query(node * 2 + 1,mid + 1,R,max(x,mid + 1),y);
}
int main(){

    //freopen("input.txt","r",stdin);

    int test;

    scanf("%d",&test);

    for(int cs = 1; cs <= test; cs++){

        for(int i = 0; i <= 4 * mx; i++) tree[ i ].sum = 0,tree[ i ].lazy = -1;

        printf("Case %d:\n",cs);

        int n,q;

        scanf("%d %d",&n,&q);

        while( q-- ){

            int p,x,y,v = 0;

            scanf("%d",&p);

            if( p == 1 ){

                scanf("%d %d %d",&x,&y,&v);

                update(1,0,n-1,x,y,v);
            }
            else {

                scanf("%d %d",&x,&y);

                ll result = query(1,0,n-1,x,y);

                ll r = y - x + 1;

                if((result % r) == 0) printf("%lld\n",result/r);

                else {

                    ll gcd = GCD(result,r);

                    printf("%lld/%lld\n",result/gcd,r/gcd);
                }
            }
        }
    }

    return 0;
}
