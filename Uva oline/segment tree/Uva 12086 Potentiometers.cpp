#include<bits/stdc++.h>
#define mx 100010
#define ll long long

using namespace std;

int A[ 2 * mx ];
int tree[ 4 * mx ];

void build(int node, int L,int R){

    if(L == R){

        tree[ node ] = A[ L ];

        return;
    }

    int mid = (L + R) >> 1;

    build(node * 2,L,mid);
    build(node * 2 + 1,mid+1,R);
    tree[ node ] = tree[ 2 * node] + tree[ 2 * node + 1 ];
}

void update(int node,int L,int R,int pos,int value){

    if(L == R) {

        tree[ node ] = value;

        return;
    }

    int mid = (L + R) >> 1;

    if(pos <= mid) update(node * 2,L,mid,pos,value);

    else update(node * 2 + 1,mid + 1,R,pos,value);

    tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];
}
ll query(int node,int L,int R,int X,int Y){

    if(X > Y) return 0;

    if(X == L && Y == R) return tree[ node ];

    int mid = (L + R) >> 1;

    ll ans = query(node * 2,L,mid,X,min(mid,Y)) + query(node * 2 + 1,mid + 1,R,max(mid + 1,X),Y);

    return ans;
}
int main(){

   //freopen("input.txt","r",stdin);

    int n,cs = 0,f = 0;

    while(scanf("%d",&n) && n != 0){

        if(f) printf("\n");
        f = 1;
        printf("Case %d:\n",++cs);

        //memset(tree,0,sizeof tree);

        for(int i = 0; i < n; i++) scanf("%d",&A[ i ]);

        build(1,0,n-1);

        char s[ 5 ];

        while(scanf("%s",s)){

            if(strcmp(s,"END") == 0) break;

            if(strcmp(s,"M") == 0) {

                int L,R;

                scanf("%d %d",&L,&R);

                ll ans = query(1,0,n-1,L-1,R-1);

                printf("%lld\n",ans);
            }
            else {

                int pos,value;

                scanf("%d %d",&pos,&value);

                update(1,0,n-1,pos-1,value);
            }
        }
    }
    return 0;
}
