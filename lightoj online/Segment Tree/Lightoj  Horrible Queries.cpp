#include<bits/stdc++.h>
#define ll long long
#define mx 100010

using namespace std;

ll tree[ 4 * mx ];
ll lazy[ 4 * mx ];

void push(int node,int L,int R){

    int mid = (L + R) >> 1;
    tree[ node * 2 ] += lazy[ node ] * (mid - L + 1);
    tree[ node * 2 + 1 ] += lazy[ node ] * (R - mid);
    lazy[ node * 2 ] += lazy[ node ];
    lazy[ node * 2 + 1 ] += lazy[ node ];
    lazy[ node ] = 0;
}

void update(int node,int L,int R,int x,int y,int v){

    if(x > y) return;

    if(x == L && y == R) {

        tree[ node ] += (y - x + 1) * v;
        lazy[ node ] += v;
        return;
    }

    push( node,L,R );

    int mid = (L + R) / 2;

    update(node * 2,L,mid,x,min(mid,y),v);
    update(node * 2 + 1,mid + 1,R,max(mid+1,x),y,v);
    tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];
}
ll query(int node,int L,int R,int x,int y){

    if(x > y) return 0;

    if(x == L && y == R) return tree[ node ];

    push( node,L,R );

    int mid = (L + R) / 2;

    ll result = (query(node * 2,L,mid,x,min(mid,y)) + query(node * 2 + 1,mid + 1,R,max(x,mid + 1),y));

    tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];

    return result;
}

int main(){

    //freopen("input.txt","r",stdin);

    int test;

    scanf("%d",&test);

    for(int cs = 1; cs <= test; cs++){

        int n,q;

        scanf("%d %d",&n,&q);

        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);

        printf("Case %d:\n",cs);

        while(q--){

            int p,x,y,v;

            scanf("%d",&p);

            if( p ){

                scanf("%d %d",&x,&y);

                ll val = query(1,0,n-1,x,y);

                printf("%lld\n",val);
            }
            else {

                scanf("%d %d %d",&x,&y,&v);

                update(1,0,n-1,x,y,v);
            }
        }
    }

    return 0;
}
