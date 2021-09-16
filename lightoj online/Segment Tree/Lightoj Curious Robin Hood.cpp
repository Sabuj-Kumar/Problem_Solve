#include<bits/stdc++.h>
#define mx 100100

using namespace std;

int a[ mx ];
int tree[ 3 * mx ];

void build(int node,int l,int r){

    if(l == r){

        tree[ node ] = a[ l ];

        return;
    }

    int mid = (l + r) / 2;

    build(node * 2,l,mid);

    build(node * 2 + 1,mid+1,r);

    tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];
}

void update(int node,int left,int right,int pos,int v){

    if(left == right){

        tree[ node ] += v;

        return;
    }

    int mid = (right + left) / 2;

    if(pos <= mid) update(node * 2,left,mid,pos,v);

    else update(node * 2 + 1,mid+1,right,pos,v);

    tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];
}
int query(int node,int left,int right,int l,int r){

    if(l > r) return 0;

    if(l == left && r == right) return tree[ node ];

    int mid = (left + right) / 2;

    int p1 = query(node * 2,left,mid,l,min(mid, r));
    int p2 = query(node * 2+1,mid + 1,right,max(mid+1,l),r);

    return p1 + p2;
}
int main(){

   // freopen("input.txt","r",stdin);

    int ts;

    scanf("%d",&ts);

    for(int cs = 1; cs <= ts; cs++){

        int n,q;

        scanf("%d %d",&n,&q);

        for(int i = 0; i < n; i++) scanf("%d",&a[ i ]);

        build(1,0,n-1);

        printf("Case %d:\n",cs);

        while(q--){

            int p,in1,in2,x = 0;

            scanf("%d",&p);

            if(p == 1){

                scanf("%d",&in1);

                printf("%d\n",a[ in1 ]);

                x = -1 * a[ in1 ];

                a[ in1 ] = 0;

                update(1,0,n-1,in1,x);
            }
            else if(p == 2){

                scanf("%d %d",&in1,&x);

                a[ in1 ] += x;

                update(1,0,n-1,in1,x);
            }
            else {

                scanf("%d %d",&in1,&in2);

                printf("%d\n",query(1,0,n-1,in1,in2));
            }
        }
    }

    return 0;
}
